#include "SDL\include\SDL.h"
#include "Player1.h"
#include "Player2.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"
#include "ModuleFadeToBlack.h"
#include "ModuleContinue.h"
#include "ModuleParticles.h"
#include "ModuleCollision.h"
#include "ModuleGameOver.h"
#include "ModuleStageClear.h"
#include "ModuleStage05.h"
#include "ModuleStage01.h"
#include "ModuleStage02.h"
#include "ModuleStageFunctionality.h"
#include "ModuleEnemies.h"
#include "ModuleUnit.h"


Module5lvlScene::Module5lvlScene()
{

}

bool Module5lvlScene::Start()
{
	bool ret = true;
	//Enable ---------------------------------------------------------------------
	App->stageFunctionality->Enable();
	App->stageFunctionality->currentStage = this;

	//"Reset ship position when fadetoblackends"----------------------------------
	App->player1->Reset_Positions();
	App->player2->Reset_Positions();

	//Texture ---------------------------------------------------------------------------------------------------
	StarsTexture = App->textures->Load("Assets/lvl5/background/backgroundstars.png");

	//Music -----------------------------------------------------------------------------------------------------
	lvl5Music = App->audio->LoadMUS("Assets/lvl5/07-DON-T-TOUCH-ME-BABY-STAGE-5-1-_-FEAR-STAGE-5-2-_-LEGE.ogg");
	App->audio->ControlMUS(lvl5Music, PLAY_AUDIO);
	return ret;
}

update_status Module5lvlScene::Update()
{
	scroll -= 5;
	if (scroll <= -SCREEN_WIDTH)
		scroll = 0;
	StarsRect = { scroll,0,SCREEN_WIDTH,SCREEN_HEIGHT };
	SDL_RenderCopy(App->render->renderer, StarsTexture, nullptr, &StarsRect);
	StarsRect.x += SCREEN_WIDTH;
	SDL_RenderCopy(App->render->renderer, StarsTexture, nullptr, &StarsRect);

	// Fade to ... ---------------------------------------------------------------------------
	if (App->input->keyboard[SDL_SCANCODE_F1] == KEY_DOWN)  //win
	{
		App->fade->FadeToBlack(this, App->stage01, 0.5f);
	}
	if (App->input->keyboard[SDL_SCANCODE_F2] == KEY_DOWN)  //win
	{
		App->fade->FadeToBlack(this, App->stage02, 0.5f);
	}
	
	return UPDATE_CONTINUE;
}

bool Module5lvlScene::CleanUp() {

	LOG("Unloading stage 05 scene");
	//audios------------------------------------------------------------------------
	App->audio->ControlMUS(lvl5Music, STOP_AUDIO);
	App->audio->UnloadMUS(lvl5Music);
	//Modules-----------------------------------------------------------------------
	App->stageFunctionality->Disable();
	return true;
}
