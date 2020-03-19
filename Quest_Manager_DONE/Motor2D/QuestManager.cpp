#include "QuestManager.h"
#include "Module.h"
#include "Point.h"
#include "Log.h"
#include <vector>
#include "App.h"


Quest_Manager::Quest_Manager() {}


Quest_Manager::~Quest_Manager() {

	for (std::list <Quest*>::iterator it = preparedQuests.begin(); it != preparedQuests.end(); it++) {
		preparedQuests.erase(it);
	}		
	for (std::list <Quest*>::iterator it = activatedQuests.begin(); it != activatedQuests.end(); it++) {
		activatedQuests.erase(it);
	}
	for (std::list <Quest*>::iterator it = endedQuests.begin(); it != endedQuests.end(); it++) {
		endedQuests.erase(it);
	}	
}


bool Quest_Manager::Awake(pugi::xml_node& config) {
	LOG("STARTING QUESTMANAGER");
	return true;
}


bool Quest_Manager::Start() {

	bool ret = true;
	/*TODO 2:
	We will need to read in the QuestManager Start the own xml file that will contain all the necessary data
	for quests and events. As in config.xml, a specific myApp function has been created for read this file.
	The function is called LoadQuestsXML.
	*/
	pugi::xml_node questNode;
	questNode = myApp->LoadQuestsXML(xmlfile);  //Loads the xml file that you pass in the "xmlfile" and returns a node

	if (questNode == NULL) {
		LOG("Could not load questsfile.xml");
	}else 

	for (questNode = questNode.child("quest"); questNode; questNode = questNode.next_sibling("quest")) {
		/*TODO 3:
		Respecting the structure that has been seen in the xml in TODO 1, all the data will have to be read and equaled
		with those of a new Quest that we will create.
		To do this, we will create a loop that goes through all the quests in the questData file. Inside the loop, a new
		quest will be created (with the class that was created previously) and its DNI and Reward will be taken from the xml file.
		*/

		Quest* newQuest = new Quest();
		newQuest->DNI = questNode.attribute("DNI").as_int();
		newQuest->Reward = questNode.attribute("Reward").as_int();
		
		/*TODO 5:
		Now the function seen in the last TODO is applied. As you can see, it is matched with the activationEvent of the quest. Now you have
		to do the same but with all the subEvent presented by the quests, so you will have to create a for going through all the subEvent
		and entering them in the list of subMissions within the quest itself.
		To introduce them we can use the push_back() function and pass it as parameter the new event (created with the createEvent function).
		*/

		newQuest->activationEvent = createEvent(questNode.child("ActivationEvent"));

		pugi::xml_node subEventNode;
		for (subEventNode = questNode.child("SubEvent"); subEventNode; subEventNode = subEventNode.next_sibling("SubEvent")) {
			newQuest->subMissions.push_back(createEvent(subEventNode));
		}
		
		preparedQuests.push_back(newQuest);
	}

	return ret;
}


Event* Quest_Manager::createEvent(pugi::xml_node &xmlReader) {

	/*TODO 4:
	See how the createEvent() function works
	*/

	int Type = xmlReader.attribute("Type").as_int();

	if(Type == 1){
		TouchEvent* ret = new TouchEvent();

		ret->Object.x = xmlReader.child("Object").attribute("x").as_int();
		ret->Object.y = xmlReader.child("Object").attribute("y").as_int();
		ret->Object.w = xmlReader.child("Object").attribute("w").as_int();
		ret->Object.h = xmlReader.child("Object").attribute("h").as_int();
		
		return ret;
	}
}