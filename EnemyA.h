#pragma once
#include "Object.h"

class EnemyA: public Object
{
public:
	EnemyA();
	int enemyAPosX_;
	int enemyAPosY_;
	int enemyAPosR_;
	
	void Update(char* keys, char* preKeys) override;
	void Draw() override;
};

