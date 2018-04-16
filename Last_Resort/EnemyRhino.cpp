#include "Application.h"
#include "EnemyRhino.h"
#include "ModuleCollision.h"

Enemy_Rhino::Enemy_Rhino(int x, int y) : Enemy(x, y)
{
	fly.PushBack({ 64,211,48,45 });
	fly.PushBack({ 112,211,48,45 });
	fly.PushBack({ 160,211,48,45 });
	fly.PushBack({ 208,211,48,45 });
	fly.PushBack({ 160,211,48,45 });
	fly.PushBack({ 112,211,48,45 });
	fly.PushBack({ 64,211,48,45 });
	fly.speed = 0.04f;
	fly.loop = true;
	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 48, 45 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_y = y;
}

void Enemy_Rhino::Move()
{
	if (going_up)
	{
		if (wave > 1.0f)
			going_up = false;
		else
			wave += 0.05f;
	}
	else
	{
		if (wave < -1.0f)
			going_up = true;
		else
			wave -= 0.05f;
	}

	position.y = int(float(original_y) + (69.0f * sinf(wave)));
	position.x -= 0.9f;
}