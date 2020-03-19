#ifndef SCENE_H
#define SCENE_H
#include "SDL/include/SDL_rect.h"
#include "Module.h"

struct SDL_Texture;

class Scene : public Module
{
public:

	Scene();

	// Destructor
	virtual ~Scene();

	// Called before render is available
	bool Awake();

	// Called before the first frame
	bool Start();

	// Called before all Updates
	bool PreUpdate();

	// Called each loop iteration
	bool Update(float dt);

	// Called before all Updates
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();

	void GetInputPlayer();

	//Look Quests List
	void LookPreparedQuestsList();
	void LookActivatedQuestsList();

private:
	SDL_Rect playerrect;
	SDL_Rect pillosurect;
	SDL_Rect docrect;
	SDL_Rect backgroundrect;

	SDL_Texture* marc_tex;
	SDL_Texture* pillosu_boss_tex;
	SDL_Texture* pillosu_tex;
	SDL_Texture* doc_tex;
	SDL_Texture* background_tex;

	SDL_Rect ValidArea;
	fPoint position;
};

#endif // SCENE_H