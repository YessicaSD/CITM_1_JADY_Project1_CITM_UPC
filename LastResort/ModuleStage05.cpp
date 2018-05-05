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


Module5lvlScene::Module5lvlScene()
{

}

bool Module5lvlScene::Start()
{
	bool ret = true;

	//Enable
	App->player1->Enable();
	App->player2->Enable();
	
	lvl5Music = App->audio->LoadMUS("Assets/lvl5/07-DON-T-TOUCH-ME-BABY-STAGE-5-1-_-FEAR-STAGE-5-2-_-LEGE.ogg");
	App->audio->ControlMUS(lvl5Music, PLAY_AUDIO);
	return ret;
}
update_status Module5lvlScene::Update() {


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
	App->player1->Disable();
	App->player2->Disable();

	return true;
}
