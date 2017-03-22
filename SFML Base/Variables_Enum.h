#pragma once

enum GameScenes {
	SPLASH,
	MAINMENU,
	GAME,
	LOAD,
	OPTIONS,
	INSTRUCTIONS,
};

enum ActionState {
	Search_for_Castle,
	Castle_Sighted,
	Castle_in_Range,
	Castle_Dead,
	Attack_Castle,

	ENUMSIZE
};