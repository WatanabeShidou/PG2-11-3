#include "Player.h"
#include <Novice.h>

Player::Player()
{
	posX_ = 640;
	posY_ = 640;
	radius_ = 32;
	speed_ = 3;
	for (int i = 0; i < PLAYER_MAXSHOT; i++) {
		bulletPosR_[i] = 16;
		bulletPosX_[i] = posX_;
		bulletPosY_[i] = posY_;
	}
}

void Player::Update(char* keys, char* preKeys)
{
	if (isEnemyAlive_ == 1 ) {
		enemyA_.Update(keys, preKeys);
		enemyB_.Update(keys, preKeys);
	}
	//移動
	if (keys[DIK_D]) {
		posX_ += speed_;
	}
	if (keys[DIK_A]) {
		posX_ -= speed_;
	}
	if (keys[DIK_W]) {
		posY_ -= speed_;
	}
	if (keys[DIK_S]) {
		posY_ += speed_;
	}
	//リスポーン
	if (keys[DIK_R]) {
		isEnemyAlive_ = 1;
		
	}
	//弾
	if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
		for (int i = 0; i < PLAYER_MAXSHOT; i++) {
			if (isBulletShot_[i] == 0) {
				isBulletShot_[i] = 1;
				//弾がY座標0を超えたら初期位置に戻す
				bulletPosX_[i] = posX_;
				bulletPosY_[i] = posY_;
				break;
			}
		}
	}
	
	for (int i = 0; i < PLAYER_MAXSHOT; i++) {
		if (isBulletShot_[i] == 1) {
			bulletPosY_[i] -= 6;
		}

		if (isBulletShot_[i] == 0) {
			bulletPosY_[i] = 0;
			bulletPosX_[i] = 0;
		}

		//弾がY座標0を超えたらフラグを0に戻す
		if (bulletPosY_[i] < 0) {
			isBulletShot_[i] = 0;
			bulletPosY_[i] = 0;
			bulletPosX_[i] = 0;
		}
	}
	//判定
	for (int i = 0; i < PLAYER_MAXSHOT; i++) {
		ellipseJudgement_[0] = (bulletPosX_[i] - enemyA_.enemyAPosX_) * (bulletPosX_[i] - enemyA_.enemyAPosX_) +
			(bulletPosY_[i] - enemyA_.enemyAPosY_) * (bulletPosY_[i] - enemyA_.enemyAPosY_);

		if (ellipseJudgement_[0] == (bulletPosR_[0] + enemyA_.enemyAPosR_) * (bulletPosR_[0] + enemyA_.enemyAPosR_)) {
			isEnemyAlive_ = 0;
		}
		if (ellipseJudgement_[0] < (bulletPosR_[0] + enemyA_.enemyAPosR_) * (bulletPosR_[0] + enemyA_.enemyAPosR_)) {
			isEnemyAlive_ = 0;
		}
	}
	
	for (int i = 0; i < PLAYER_MAXSHOT; i++) {
		ellipseJudgement_[1] = (bulletPosX_[i] - enemyB_.enemyBPosX_) * (bulletPosX_[i] - enemyB_.enemyBPosX_) +
			(bulletPosY_[i] - enemyB_.enemyBPosY_) * (bulletPosY_[i] - enemyB_.enemyBPosY_);

		if (ellipseJudgement_[1] == (bulletPosR_[0] + enemyB_.enemyBPosR_) * (bulletPosR_[0] + enemyB_.enemyBPosR_)) {
			isEnemyAlive_ = 0;
		}
		if (ellipseJudgement_[1] < (bulletPosR_[0] + enemyB_.enemyBPosR_) * (bulletPosR_[0] + enemyB_.enemyBPosR_)) {
			isEnemyAlive_ = 0;
			
		}
	}

	
}

void Player::Draw()
{
	Novice::ScreenPrintf(0, 0, "enemyA isEnemyAlive : %d", isEnemyAlive_);
	Novice::ScreenPrintf(0, 20, "enemyB isEnemyAlive : %d", isEnemyAlive_);
	Novice::ScreenPrintf(0, 40, "WASD : player Move");
	Novice::ScreenPrintf(0, 60, "shot : SPACE");
	Novice::ScreenPrintf(0, 80, "enemy respown : R %d", isEnemyAlive_);
	//弾
	for (int i = 0; i < PLAYER_MAXSHOT; i++) {
		if (isBulletShot_[i] == 1) {
			Novice::DrawEllipse(bulletPosX_[i], bulletPosY_[i], bulletPosR_[i], bulletPosR_[0], 0.0f, WHITE, kFillModeSolid);
		}
	}
	//プレイヤー
	Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, GREEN, kFillModeSolid);

	if (isEnemyAlive_ == 1) {
		enemyA_.Draw();
		enemyB_.Draw();
	}
	
}
