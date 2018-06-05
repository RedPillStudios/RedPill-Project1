#ifndef ModuleUI_H
#define ModuleUI_H

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"
#include "SDL/include/SDL_pixels.h"

#include "SDL_mixer/include/SDL_mixer.h"
#pragma comment(lib,"SDL_mixer/libx86/SDL2_mixer.lib")
#include <stdio.h>
#include <cstdio>

#define MAX_FONTS 10
#define MAX_FONT_CHARS 256

struct SDL_Texture;

struct Font {

	char table[MAX_FONT_CHARS];
	SDL_Texture* graphic = nullptr;

	uint rows, len, char_w, char_h, row_chars;
};

struct rank {

	char name[4] = "NON";
	int score = 0;
};

class ModuleUI : public Module {

public:

	ModuleUI();
	~ModuleUI();

	bool Start();
	update_status Update();
	bool CleanUp();


public:

	int LoadFont(const char* texture_path, const char *characters, uint rows = 1);
	void UnLoadFont(int font_id);
	void BlitText(int x, int y, int bmp_font_id, const char *text) const;

	Mix_Chunk *Insert_Coin = nullptr;	

public:

	//Scores & UI
	//uint TopScoreP1(uint Score1, uint TopScore);
	SDL_Texture* Bar_Texture = nullptr;
	Animation Bar;
	iPoint Pos_Bar1;
	iPoint Pos_Bar2;
	iPoint PosCharge1;
	iPoint PosCharge2;
	int WidhtCharge1;
	int WidthCharge2;
	Animation*Current_Bar;
	SDL_Rect Charge_Controller;

	Animation*Current_Charge1;
	Animation*Current_Charge2;
	Animation Charge1;
	Animation Charge2;

	bool Spawned;
	bool TimeCounter = true;
	int Chargebar;

	uint AppearTime;
	uint current_time = SDL_GetTicks();

	SDL_Texture*UI_Main_Menu = nullptr;

	//Font id
	int font = -1;

	//P1 Score
	char score_text[10];
	uint ScoreP1;

	//P2 Score
	char score_text2[10];
	uint ScoreP2;

	//Top Score
	char top_score[10];
	uint TopScore;

	//P1 Life
	char life_text[10];
	uint P1Life;

	//P2 Life
	char life2_text[10];
	uint P2Life;

	//Coins
	int coins;
	char coins_text[10];

	//Checkpoints
	bool Checkpoint1 = false;

	//RANKING
	FILE *Ranking;
	struct rank ranking[9];
	int countFile(FILE *pFile, char *path);
	void ChangeRanking(FILE *pFile, char *path, int Score);
	

private:

	Font fonts[MAX_FONTS];
};

#endif