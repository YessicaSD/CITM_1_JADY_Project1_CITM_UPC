#ifndef __ModuleStageFunctionality_H__
#define __ModuleStageFunctionality_H__

#include "Module.h"
#include "Globals.h"

class ModuleStageFunctionality : public Module
{
public:

	ModuleStageFunctionality();
	~ModuleStageFunctionality();

	bool Start();
	update_status PreUpdate();
	bool CleanUp();

	void Debugging();

public:
	int enemyToSpawn = 0;
	int powerupToSpawn = 0;
	Module * currentStage = nullptr;
};

#endif // __ModuleStageFunctionality_H_H__
