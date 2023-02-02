#pragma once
#include "Object.h"
#include "EnemyB.h"
#include "EnemyA.h"

class Player : public Object
{
public:

	Player();
	EnemyA enemyA_;
	EnemyB enemyB_;
	void Update(char* keys, char* preKeys) override;
	void Draw() override;
	static const int PLAYER_MAXSHOT = 15;
	int bulletPosR_[PLAYER_MAXSHOT] = { 5 };
	int bulletPosX_[PLAYER_MAXSHOT] = { 0 };
	int bulletPosY_[PLAYER_MAXSHOT] = { 0 };
	int isBulletShot_[PLAYER_MAXSHOT] = { 0 };
	
	int ellipseJudgement_[2];
};

