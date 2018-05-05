#include "Application.h"
#include "ModuleStageFunctionality.h"
#include "ModuleInput.h"
#include "ModuleEnemies.h"
#include "Player1.h"

ModuleStageFunctionality::ModuleStageFunctionality()
{

}

ModuleStageFunctionality::~ModuleStageFunctionality()
{

}

update_status ModuleStageFunctionality::PreUpdate()
{
	Debugging();
	return UPDATE_CONTINUE;
}

void ModuleStageFunctionality::Debugging()
{
	//if (App->input->keyboard[SDL_SCANCODE_F1] == KEY_DOWN)  //win
	//{
	//	App->fade->FadeToBlack(this, App->stage01, 0.5f);
	//}
	//if (App->input->keyboard[SDL_SCANCODE_F2] == KEY_DOWN)  //win
	//{
	//	App->fade->FadeToBlack(this, App->stage02, 0.5f);
	//}
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
		LOG("%i", App->player1->position.x + 100);
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