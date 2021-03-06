#ifndef ENEMY_H
#define ENEMY_H

#include "p2Point.h"
#include "Animation.h"
#include "ModuleTextures.h"
#include "ModuleEnemies.h"

struct SDL_Textures;
struct Collider;

class Enemy {

protected:


	Collider *collider = nullptr;


public:

	Animation *animation = nullptr;
	fPoint position;
	SDL_Texture *sprites;

	Enemy(int x, int y);
	virtual ~Enemy();

	const Collider* GetCollider() const;

	ENEMY_TYPES type;
	bool reached;
	int life;
	uint score;
	bool PowerUp;
	fPoint toGo;
	bool hit;
	bool touched;

public:

	virtual void Move() {};
	virtual void Draw(SDL_Texture *sprites);
	virtual void OnCollision(Collider *collider);

};


#endif

