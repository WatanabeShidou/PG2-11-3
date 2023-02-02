#pragma once

class Object 
{
public:
	virtual void Update(char* keys, char* preKeys);
	virtual void Draw();
protected:
	int posX_;
	int posY_;
	int speed_;
	int radius_;
	static int isEnemyAlive_;
};

