#include "App.h"
#include "Input.h"
#include "Textures.h"
#include "Render.h"
#include "Window.h"
#include "Scene.h"
#include "QuestManager.h"
#include <iterator>

Scene::Scene() : Module()
{
	name.assign("scene");
}

// Destructor
Scene::~Scene()
{}

// Called before render is available
bool Scene::Awake()
{
	LOG("Loading Scene");
	bool ret = true;

	return ret;
}

// Called before the first frame
bool Scene::Start()
{
	backgroundrect.x = 0;
	backgroundrect.y = 0;
	backgroundrect.w = 1024;
	backgroundrect.h = 768;

	playerrect.x = 0;
	playerrect.y = 0;
	playerrect.w = 100;
	playerrect.h = 100;

	docrect = playerrect;
	pillosurect = playerrect;

	myApp->render->SetBackgroundColor({ 255,255,255 });
	marc_tex = myApp->tex->Load("Assets/Marc.png");
	pillosu_tex = myApp->tex->Load("Assets/Ricard.png");
	pillosu_boss_tex = myApp->tex->Load("Assets/RicardBoss.png");
	doc_tex = myApp->tex->Load("Assets/Documentation.png");
	background_tex = myApp->tex->Load("Assets/Background.png");

	position.x = 460;
	position.y = 180;

	ValidArea.x = 400;
	ValidArea.y = 350;
	ValidArea.w = 100;
	ValidArea.h = 100;

	return true;
}

// Called each loop iteration
bool Scene::PreUpdate()
{
	return true;
}

// Called each loop iteration
bool Scene::Update(float dt)
{
	GetInputPlayer();

	ValidArea.x = (int)position.x;
	ValidArea.y = (int)position.y;
	
	//Draw Background and Player
	myApp->render->Blit(background_tex, 0, 0, &backgroundrect);
	myApp->render->Blit(marc_tex, ValidArea.x, ValidArea.y, &playerrect);

	LookPreparedQuestsList();
	LookActivatedQuestsList();

	return true;
}

// Called each loop iteration
bool Scene::PostUpdate()
{
	bool ret = true;

	if(myApp->input->GetKey(SDL_SCANCODE_ESCAPE) == KEY_DOWN)
		ret = false;

	return ret;
}

// Called before quitting
bool Scene::CleanUp()
{
	LOG("Freeing scene");

	return true;
}

void::Scene::LookPreparedQuestsList() {

	//LOOKING THE PREPARED_QUESTS LIST
	for (std::list <Quest*>::iterator it = myApp->quests->preparedQuests.begin(); it != myApp->quests->preparedQuests.end(); it++) {
		//DRAWING RICARD PILLOSU BOSS IF ACTIVATION EVENT IS NOT COMPLETED
		if ((*it)->activationEvent->completed == false) {
			myApp->render->Blit(pillosu_tex, (*it)->activationEvent->Object.x, (*it)->activationEvent->Object.y, &pillosurect);
		}

		if ((*it)->activationEvent->completed == false){
			if ((*it)->activationEvent->type == TOUCH_EVENT) {
				if (((*it)->activationEvent->Object.x - ValidArea.x) < ValidArea.w && ((*it)->activationEvent->Object.x - ValidArea.x) > -ValidArea.w && ((*it)->activationEvent->Object.y - ValidArea.y) < ValidArea.h && ((*it)->activationEvent->Object.y - ValidArea.y) > -ValidArea.h) {
					(*it)->activationEvent->completed = true;

					/*TODO 6:
					Pass the quest that has already made the activation event from the list of preparedQuests to activatedQuests 
					(we can put the quest on the list using the push_back() function and we remove it from the previous list with the erase() function.
					*/

					myApp->quests->activatedQuests.push_back((*it));
					myApp->quests->preparedQuests.erase(it);
				}
			}
		}
	}

}

void::Scene::LookActivatedQuestsList() {

	//LOOKING THE ACTIVATED QUESTS
	for (std::list <Quest*>::iterator it = myApp->quests->activatedQuests.begin(); it != myApp->quests->activatedQuests.end(); it++) {
		//DRAWING RICARD PILLOSU BOSS WHEN QUEST IS ACTIVATED
		myApp->render->Blit(pillosu_boss_tex, (*it)->activationEvent->Object.x, (*it)->activationEvent->Object.y, &pillosurect);

		for (std::list<Event*>::iterator it_ = (*it)->subMissions.begin(); it_ != (*it)->subMissions.end(); it_++) {
			//LOOKING IF THERE ARE SUBMISSIONS LEFT
			int counter = 0;
			for (std::list<Event*>::iterator it_ = (*it)->subMissions.begin(); it_ != (*it)->subMissions.end(); it_++) {
				if ((*it_)->completed == false) {
					counter++;
				}
			}
			//IF THERE ARE SUBMISSIONS LEFT
			if (counter != 0) {
				//LOOK IF THE SQUARES ARE INSIDE
				myApp->render->Blit(doc_tex, (*it_)->Object.x, (*it_)->Object.y, &docrect);

				if ((*it_)->completed == false) {
					if ((*it_)->type == TOUCH_EVENT) {
						if (((*it_)->Object.x - ValidArea.x) < ValidArea.w && ((*it_)->Object.x - ValidArea.x) > -ValidArea.w && ((*it_)->Object.y - ValidArea.y) < ValidArea.h && ((*it_)->Object.y - ValidArea.y) > -ValidArea.h) {
							(*it_)->completed = true;

							if (it_ != (*it)->subMissions.end()) {
								/*TODO 7:
								Add to the heights and ampoules of the ValidArea and Playerrect rectangles the reward of the SubMission.
								Then remove the already completed subMission from the list.
								(remember that it can be done with the erase () function)
								*/
								ValidArea.h += (*it)->Reward;
								ValidArea.w += (*it)->Reward;
								playerrect.h += (*it)->Reward;
								playerrect.w += (*it)->Reward;
								(*it)->subMissions.erase(it_);
							}

							if (it_ == prev((*it)->subMissions.end())) {
								(*it)->subMissions.erase(it_);
								/*TODO 8:
								Moving the already completed activated quests into the list of endedQuests
								and removing it from the list of activatedQuests (very similar to TODO 6)
								*/
								myApp->quests->endedQuests.push_back((*it));
								myApp->quests->activatedQuests.erase((it));

							}
						}
					}
				}
			}
		}
	}

}

void::Scene::GetInputPlayer() {

	if (myApp->input->GetKey(SDL_SCANCODE_W) == KEY_REPEAT) {

		position.y -= 0.3;
	}
	if (myApp->input->GetKey(SDL_SCANCODE_S) == KEY_REPEAT) {

		position.y += 0.3;
	}
	if (myApp->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT) {

		position.x -= 0.3;
	}
	if (myApp->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT) {

		position.x += 0.3;
	}
}