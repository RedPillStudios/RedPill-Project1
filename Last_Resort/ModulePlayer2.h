#ifndef __ModulePlayer2_H__
#define __ModulePlayer2_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"
#include "ModuleSceneLvl1.h"

struct SDL_Texture;
struct Collider;
struct Mix_Chunk;
enum ShootsP2
{
	BASICSHOOTP2,
	BASICLASERSHOOTP2,
	LASERSHOOTP2,
	MISSILESP2,
	LASERSHOOTAREAP2,
	MISSILES2P2,
	BOMBSHOOTP2

};

class ModulePlayer2 : public Module {

public:

	ModulePlayer2();
	~ModulePlayer2();

	update_status Update();

	void OnCollision(Collider *c1, Collider *c2);


public:

	bool Start();
	bool CleanUp();
	bool AppearAnim;
	bool Dead;
	bool Player2Activated = false;
	bool ToBeDeleted = false;
	bool GOD = false;
	bool flickering;
public:
	//Timer
	int ShootTimer1;
	int ShootTimer2;
	int ShootTimer3;
	int ShootTimer4;
	int counterApearing;

public:

	SDL_Rect Ship2;
	SDL_Rect UI_ship2;

	SDL_Texture* graphicsp2 = nullptr;
	SDL_Texture* Entry_God = nullptr;
	SDL_Texture* Normal = nullptr;

	Animation Up;
	Animation Down;
	Animation Appear2;
	Animation Standard;
	Animation idle;
	Animation DestroyShip;

	Animation* current_animation2 = nullptr;

	iPoint positionp2;

	Collider *Ship2Collider;

public:
	float speed;
	bool startAnim = true;
	bool shooted = false;

	Mix_Chunk*Shot_Sound = nullptr;
	Mix_Chunk*MissilePower_Sound = nullptr;
	Mix_Chunk*LasserBeam_Sound = nullptr;

public:

	SDL_Rect setFirePos2() {

		SDL_Rect FirePos2;

		FirePos2.x = positionp2.x + 31;
		FirePos2.y = positionp2.y + 1;

		return FirePos2;
	}

	void resetPosition2() {
		positionp2.x = App->scene1background->position_min_limit + 20;
		positionp2.y = SCREEN_HEIGHT / 4;

	};

	//shoot selector here
	int WeaponTypeP2 = 0;
	void ShootSelector(uint shoot);

	//POWERUP Levels
	bool Lvl0 = true;
	bool Lvl1 = false;
	bool Lvl2 = false;
	bool Lvl3 = false;
};

#endif