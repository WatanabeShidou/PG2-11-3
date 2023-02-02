#include "EnemyA.h"
#include <Novice.h>

EnemyA::EnemyA()
{
	enemyAPosX_ = 300;
	enemyAPosY_ = 200;
	enemyAPosR_ = 16;
	speed_ = 4;
}

void EnemyA::Update(char* keys, char* preKeys)
{
	enemyAPosX_ += speed_;
	if (enemyAPosX_ >= 1280) {
		speed_ = -4;
	}
	if (enemyAPosX_ <= 0) {
		speed_ = 4;
	}
}

void EnemyA::Draw()
{
	Novice::DrawEllipse(enemyAPosX_, enemyAPosY_, enemyAPosR_, enemyAPosR_, 0.0f, RED, kFillModeSolid);
}
