#ifndef __ModuleStageFunctionality_H__
#define __ModuleStageFunctionality_H__

#include "Module.h"
#include "Globals.h"

class ModuleStageFunctionality : public Module
{
public:

	ModuleStageFunctionality();
	~ModuleStageFunctionality();

	update_status PreUpdate();
	void Debugging();

public:
	int enemyToSpawn = 0;
	int powerupToSpawn = 0;
};

#endif // __ModuleStageFunctionality_H_H__
