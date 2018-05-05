#include "Application.h"
#include "ModuleStageFunctionality.h"
#include "ModuleInput.h"
#include "ModuleEnemies.h"
#include "Player1.h"
#include "Player2.h"
#include "ModuleParticles.h"
#include "ModuleCollision.h"
#include "ModulePowerups.h"
#include "ModuleUnit.h"
#include "ModuleFadeToBlack.h"
#include "ModuleStage01.h"
#include "ModuleStage02.h"
#include "ModuleStage05.h"
#include "ModuleStageClear.h"
#include "ModuleGameOver.h"

ModuleStageFunctionality::ModuleStageFunctionality()
{

}

ModuleStageFunctionality::~ModuleStageFunctionality()
{

}

bool ModuleStageFunctionality::Start()
{
	App->player1->Enable();
	App->player2->Enable();
	App->particles->Enable();
	App->collision->Enable();
	App->enemies->Enable();
	App->powerups->Enable();
	//App->ui->ShowUi();
	//App->ui->current_stage = this;
	return true;
}

bool ModuleStageFunctionality::CleanUp()
{
	App->player1->Disable();
	App->player2->Disable();
	App->particles->Disable();
	App->collision->Disable();
	App->enemies->Disable();
	App->powerups->Disable();
	return true;
}

update_status ModuleStageFunctionality::PreUpdate()
{
	Debugging();
	return UPDATE_CONTINUE;
}

void ModuleStageFunctionality::Debugging()
{
	//GO TO ANOTHER SCENE
	if (App->input->keyboard[SDL_SCANCODE_F1] == KEY_DOWN)  //win
	{
		App->fade->FadeToBlack(currentStage, App->stage01, 0.5f);
	}
	if (App->input->keyboard[SDL_SCANCODE_F2] == KEY_DOWN)  //win
	{
		App->fade->FadeToBlack(currentStage, App->stage02, 0.5f);
	}

	if (App->input->keyboard[SDL_SCANCODE_F5] == KEY_DOWN)  //win
	{
		App->fade->FadeToBlack(currentStage, App->stage05, 0.5f);
	}

	if (App->input->keyboard[SDL_SCANCODE_F3] == KEY_DOWN)  //win
	{
		if (App->player1->winlvl == false && App->player2->winlvl == false)
		{
			App->player1->winlvl = App->player2->winlvl = true;
			App->player1->numLvlwin = App->player2->numLvlwin = 1;
		}
		App->fade->FadeToBlack(currentStage, App->stageclearScene, 3.5f);
		App->unit1->Disable();
		App->unit2->Disable();
		currentStage = nullptr;
	}

	if (App->input->keyboard[SDL_SCANCODE_F4] == KEY_DOWN)  //lose
	{
		App->fade->FadeToBlack(currentStage, App->gameoverScene, 3.5f);
		App->unit1->Disable();
		App->unit2->Disable();
		currentStage = nullptr;
	}

	//SPAWN ENEMIES
	//- Go to the next enemy
	if (App->input->keyboard[SDL_SCANCODE_F6] == KEY_DOWN)
	{
		enemyToSpawn++;
		//If we reach the last enemy, we go back to the first one
		if (enemyToSpawn >= ENEMY_TYPES::MAX_ENEMY) { enemyToSpawn = 0; }
	}
	//- Spawn enemy
	if (App->input->keyboard[SDL_SCANCODE_F7] == KEY_DOWN)
	{
		App->enemies->AddEnemy((ENEMY_TYPES)enemyToSpawn, App->player1->position.x + 100, App->player1->position.y);
	}

	//SPAWN POWERUPS
	//- Go to the next powerup
	if (App->input->keyboard[SDL_SCANCODE_F8] == KEY_DOWN)
	{
		powerupToSpawn++;
		//If we reach the last powerup, we go back to the first one
		if (powerupToSpawn >= POWERUP_TYPE::MAX_POWERUP) { powerupToSpawn = 0; }
	}
	//- Spawn powerup
	if (App->input->keyboard[SDL_SCANCODE_F9] == KEY_DOWN)
	{
		App->powerups->AddPowerup(App->player1->position.x + 100, App->player1->position.y, (POWERUP_TYPE)powerupToSpawn);
	}
}