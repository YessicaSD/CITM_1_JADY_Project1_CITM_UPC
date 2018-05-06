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
	int scroll = 0;
	SDL_Texture * StarsTexture = nullptr;
	SDL_Texture *shipTex = nullptr;
	SDL_Rect shipRect;
	SDL_Rect StarsRect;

	Mix_Music* lvl5Music = nullptr;
};

#endif
