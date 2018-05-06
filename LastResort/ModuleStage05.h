#ifndef __MODULE5LVLSCENE_H__
#define __MODULE5LVLSCENE_H__

#include "Application.h"
#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "SDL\include\SDL.h"
typedef struct _Mix_Music Mix_Music;
class Module5lvlScene : public Module
{
public:
	Module5lvlScene();
	~Module5lvlScene() {

	};

	bool Start();
	update_status Update();
	bool CleanUp();
public:
	//Stars Background variables -----------------------------------------------------
	SDL_Texture * StarsTexture;
	SDL_Rect StarsRect;
	iPoint scroll;
	enum typeScroll
	{
		SCROLL_HORIZONTAL,
		SCROLL_UP,
		SCROLL_DOWN
	};
	typeScroll ScrollState;
	


	Mix_Music* lvl5Music = nullptr;

};

#endif
