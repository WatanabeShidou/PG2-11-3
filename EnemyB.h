#pragma once
#include "Object.h"

class EnemyB : public Object
{
public:
	EnemyB();
	int enemyBPosX_;
	int enemyBPosY_;
	int enemyBPosR_;
	
	void Update(char* keys, char* preKeys) override;
	void Draw() override;
};

