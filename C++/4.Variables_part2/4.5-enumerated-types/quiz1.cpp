#include <iostream>

int main ()
{
	enum MonsterType
	{
		ORCS_MONSTER,
		GOBLINS_MONSTER,
		TROLLS_MONSTER,
		OGRES_MONSTER,
		SKELETONS_MONSTER
	};
	
	MonsterType eMonster = TROLLS_MONSTER;
	std::cout << eMonster << std::endl;
	
	return 0;
}
