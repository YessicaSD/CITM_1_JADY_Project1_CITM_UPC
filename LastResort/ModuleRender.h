#ifndef __ModuleRenderer_H__
#define __ModuleRenderer_H__

#include "Module.h"
#include "p2Point.h"

struct SDL_Renderer;
struct SDL_Texture;

class ModuleRender : public Module
{
public:
	ModuleRender();
	~ModuleRender();

	bool Init();
	update_status PostUpdate();
	update_status Update();
	update_status PreUpdate();
	bool CleanUp();

	/*void Render(SDL_Texture* Texture, SDL_Rect* section);*/
<<<<<<< HEAD
	bool Blit(SDL_Texture* texture, int x, int y, SDL_Rect* section);
=======
	bool Blit(SDL_Texture* texture, int x, int y, SDL_Rect* section, float speed = 1.0f, bool use_camera=false);
>>>>>>> 5cc6718d8fb420287a3d34853a09d46bb125f484
	bool FlippedBlit(SDL_Texture* texture, int x, int y, SDL_Rect* section, float speed = 1.0f,bool use_camera = true);
	bool DrawQuad(const SDL_Rect& rect, Uint8 r, Uint8 g, Uint8 b, Uint8 a, bool use_camera = true);
	float getCameraPosition(int position,float speed);


public:
	SDL_Renderer* renderer = nullptr;
	SDL_Rect camera; //textures camera 
	iPoint r_camera; //relative camera
	int const cameraspeed = SCREEN_SIZE;
};

#endif //__ModuleRenderer_H__