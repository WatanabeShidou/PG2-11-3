#include "EnemyB.h"
#include <Novice.h>

EnemyB::EnemyB()
{
	enemyBPosX_ = 10;
	enemyBPosY_ = 400;
	enemyBPosR_ = 16;
	speed_ = 4;
}

void EnemyB::Update(char* keys, char* preKeys)
{
	enemyBPosX_ += speed_;
	if (enemyBPosX_ >= 1280) {
		speed_ = -4;
	}
	if (enemyBPosX_ <= 0) {
		speed_ = 4;
	}
}

void EnemyB::Draw()
{
	Novice::ScreenPrintf(0, 100, "%d", isEnemyAlive_);
	Novice::DrawEllipse(enemyBPosX_, enemyBPosY_, enemyBPosR_, enemyBPosR_, 0.0f, RED, kFillModeSolid);
}
