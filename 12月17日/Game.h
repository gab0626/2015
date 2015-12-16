#pragma once
#include "Singleton.h"
enum Map
{
	NULL_BLOCK,
	FALL_BLOCK,
	MOVE_BLOCK
};

enum Block
{
	FALL_SIZE = 60,
	SECOND_BLOCK_SIZE = 70,
	BLOCK_SIZE = 100,
	THIRD_BLOCK_SIZE = 200,
	SIXTH_BLOCK_SIZE = 270,
	FIFTH_BLOCK_SIZE = 300,
	FORTH_BLOCK_SIZE = 320,
	FOUR_BLOCK_SIZE = 700,
	ONE_BLOCK_SIZE = 1000,
	TWO_BLOCK_SIZE = 1500,
};

enum MapChip
{
	MAP_HEIGHT = 10,
	MAP_WIDTH  = 15
};

class Game
{
private:
	Texture BlueGirl;
	Texture RedGirl;
	Texture Lama;
	Texture Life;
	Texture GameBack;
public:
	Game();
	void Setup();
	void SoundSet();
	void Update();
	void FallBlockUpdate();
	void Draw();
	void DrawFallBlock();

	Vec2f LamaDrawPos;
	Vec2f LamaSize;
	Vec2f TextureDrawCos;
	Vec2f MapPos[MAP_HEIGHT][MAP_WIDTH];
	Vec2f Mpos = Vec2f(-750, -540);
	Vec2f one = Vec2f(-760, -500);
	Vec2f two = Vec2f(-750, 370);
	Vec2f three = Vec2f(-750, -550);
	Vec2f four = Vec2f(670, -300);
	Vec2f five = Vec2f(-530, -470);
	Vec2f six = Vec2f(-335, -300);
	Vec2f seven = Vec2f(-270, 100);
	Vec2f eight = Vec2f(470,80);
	Vec2f nine = Vec2f(70, -50);
	Vec2f ten = Vec2f(-120, -500);
	
	float AnimationCount;

	bool RightMove;
	bool LeftMove;
	bool UpMove;
	bool DownMove;

	int MapChip[MAP_HEIGHT][MAP_WIDTH];

};