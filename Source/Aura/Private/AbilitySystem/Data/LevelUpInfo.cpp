// Copyright Marc Tremblay


#include "AbilitySystem/Data/LevelUpInfo.h"

int32 ULevelUpInfo::FindLevelUpInfoForXP(int32 XP) const
{
	// int Level = 1;
	// bool bSearching = true;
	//
	// while (bSearching)
	// {
	// 	// LevelUpInformation 1-indexed
	// 	// LevelUpInformation[1] = Level 1 Info
	// 	// LevelUpInformation[2] = Level 2 Info
	// 	if (LevelUpInformation.Num() - 1 <= Level) { return Level; }
	//
	// 	if (XP >= LevelUpInformation[Level].LevelUpRequirement)
	// 	{
	// 		++Level;
	// 	}
	// 	else
	// 	{
	// 		bSearching = false;
	// 	}
	// }
	//
	// return Level;

	// xp = 500
	// [ na, 300, 900, 1800], num = 4
	// i = 1, i < 3

	for (int lvl = 1; lvl < LevelUpInformation.Num(); ++lvl)
	{
		if (XP < LevelUpInformation[lvl].LevelUpRequirement)
		{
			return lvl;
		}
	}

	return 1;
}
