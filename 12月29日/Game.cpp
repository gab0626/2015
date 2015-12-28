#include "Game.h"
#include <iostream>

Game::Game()
{
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int k = 0; k < MAP_WIDTH; k++)
		{
			MapPos[i][k] = Vec2f(BLOCK_SIZE * k, BLOCK_SIZE * i);
		}
	}


	BlueGirl = Texture("res/BlueGirlMotion.png");
	RedGirl  = Texture("res/GirlMotion.png");
	Lama     = Texture("res/Lama.png");
	Life     = Texture("res/life.png");
	GameBack = Texture("res/haikei.png");
}

void Game::Setup()
{
	LamaDrawPos    = Vec2f(-630.0f, -400.0f);
	LamaSize       = Vec2f(64.0f, 120.0f);
	TextureDrawCos = Vec2f(64.0f, 128.0f); 
	RedGirlPos[0]  = Vec2f(-350.0f,-50.0f);
	RedGirlPos[1]  = Vec2f(-260.0f,-500.0f);
	RedGirlPos[2]  = Vec2f(350.0f,-100.0f);
	RedGirlPos[3]  = Vec2f(260.0f,-25.0f);
	

	BlueGirlPos[0] = Vec2f(-650.0f,-500.0f);
	BlueGirlPos[1] = Vec2f(-450.0f,470.0f);
	
	GirlDrawCos    = Vec2f(256.0f,256.0f);

	GirlSize       = Vec2f(100.0f,128.0f);

	AnimationCount = 0.0f;
	RightMove      = false;
	LeftMove       = false;
	UpMove         = false;
	DownMove       = false;
	for (int i = 0; i < 6; i++)
	{
		EnemyMoveFlag[i] = false;
	}

	std::ifstream* Mapfile	= nullptr;
	const char* NewStage	= "res/Stage.txt";
	Mapfile					= new std::ifstream(NewStage);

	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int k = 0; k < MAP_WIDTH; k++)
		{
			*Mapfile >> MapChip[i][k];
		}
	}

	
}

void Game::SoundSet()
{

}

void Game::Update()
{
	LamaAnimation();
	FallBlockUpdate();
	EnemyAnimation();
}

void Game::LamaAnimation()
{
	if (env.isPressKey(GLFW_KEY_LEFT))
	{
		LamaDrawPos.x() -= 3;
		LeftMove = true;
		RightMove = false;
		UpMove = false;
		DownMove = false;

		if (LeftMove == true)
		{
			AnimationCount++;
		}
	}

	else if (env.isPressKey(GLFW_KEY_RIGHT))
	{
		LamaDrawPos.x() += 3;
		LeftMove = false;
		RightMove = true;
		UpMove = false;
		DownMove = false;

		if (RightMove == true)
		{
			AnimationCount++;
		}
	}

	else if (env.isPressKey(GLFW_KEY_UP))
	{
		LamaDrawPos.y() += 3;
		LeftMove = false;
		RightMove = false;
		UpMove = true;
		DownMove = false;

		if (UpMove == true)
		{
			AnimationCount++;
		}
	}

	else if (env.isPressKey(GLFW_KEY_DOWN))
	{
		LamaDrawPos.y() -= 3;
		LeftMove = false;
		RightMove = false;
		UpMove = false;
		DownMove = true;

		if (DownMove == true)
		{
			AnimationCount++;
		}
	}

	if (AnimationCount >= 60 || env.isPullKey(GLFW_KEY_UP) || env.isPullKey(GLFW_KEY_DOWN) || env.isPullKey(GLFW_KEY_RIGHT) || env.isPullKey(GLFW_KEY_LEFT))
	{
		AnimationCount = 0;
	}
}

void Game::LamaresetPos()
{
	LamaDrawPos = Vec2f(-630.0f, -400.0f);
	LifeFlag = true;
}

void Game::LamaLife()
{

}

void Game::FallBlockUpdate()
{
	if (LamaDrawPos.x() < one.x() + FALL_SIZE)
	{
		Game::LamaresetPos();
	}
	if (LamaDrawPos.y() < three.y() + FALL_SIZE)
	{
		Game::LamaresetPos();
	}
	if (LamaDrawPos.y() > two.y() - FALL_SIZE)
	{
		Game::LamaresetPos();
	}
	if (LamaDrawPos.x() > four.x() - FALL_SIZE)
	{
		if (LamaDrawPos.y() > four.y() && LamaDrawPos.y() < FOUR_BLOCK_SIZE)
		{
			Game::LamaresetPos();
		}
	}

	if (LamaDrawPos.x() > five.x() && LamaDrawPos.x() < five.x() + SECOND_BLOCK_SIZE)
	{
		if (LamaDrawPos.y() > five.y() && LamaDrawPos.y() < five.x()+FOUR_BLOCK_SIZE)
		{
			Game::LamaresetPos();
		}
	}

	if (LamaDrawPos.x() > six.x() && LamaDrawPos.x() < six.x() + SECOND_BLOCK_SIZE)
	{
		if (LamaDrawPos.y() > six.y() && LamaDrawPos.y() < six.y() + FOUR_BLOCK_SIZE)
		{
			Game::LamaresetPos();
		}
	}

	if (LamaDrawPos.x() > seven.x() && LamaDrawPos.x() < seven.x() + THIRD_BLOCK_SIZE)
	{
		if (LamaDrawPos.y() > seven.y() && LamaDrawPos.y() < seven.y() + FORTH_BLOCK_SIZE)
		{
			Game::LamaresetPos();
		}
	}

	if (LamaDrawPos.x() > eight.x() && LamaDrawPos.x() < eight.x() + THIRD_BLOCK_SIZE)
	{
		if (LamaDrawPos.y() > eight.y() && LamaDrawPos.y() < eight.y() + FIFTH_BLOCK_SIZE)
		{
			Game::LamaresetPos();
		}
	}
	if (LamaDrawPos.x() > nine.x() && LamaDrawPos.x() < nine.x() + SIXTH_BLOCK_SIZE)
	{
		if (LamaDrawPos.y() > nine.y() && LamaDrawPos.y() < nine.y() + FIFTH_BLOCK_SIZE)
		{
			Game::LamaresetPos();
		}
	}

	if (LamaDrawPos.x() > ten.x() && LamaDrawPos.x() < ten.x() + FOUR_BLOCK_SIZE - 50)
	{
		if (LamaDrawPos.y() > ten.y() && LamaDrawPos.y() < ten.y() + FIFTH_BLOCK_SIZE + 150)
		{
			Game::LamaresetPos();
		}
	}
}

void Game::EnemyResetPos()
{
	RedGirlPos[0] = Vec2f(-350.0f, -50.0f);
	RedGirlPos[1] = Vec2f(-260.0f, -500.0f);
	RedGirlPos[2] = Vec2f(350.0f, -100.0f);
	RedGirlPos[3] = Vec2f(260.0f, -25.0f);
	BlueGirlPos[0] = Vec2f(-650.0f, -500.0f);
	BlueGirlPos[1] = Vec2f(-450.0f, 470.0f);
}

void Game::EnemyAnimation()
{
	if (EnemyMoveFlag[0] == true)
	{
		RedGirlPos[0].x() += 3;
	}

	if (EnemyMoveFlag[1] == true)
	{
		RedGirlPos[1].y() -= 3;
	}

	if (EnemyMoveFlag[2] == true)
	{
		RedGirlPos[2].y() += 3;
	}
	if (EnemyMoveFlag[3] == true)
	{
		RedGirlPos[3].x() += 3;
	}
	if (EnemyMoveFlag[4] == true)
	{
		BlueGirlPos[0].y() += 3;
	}
	if (EnemyMoveFlag[5] == true)
	{
		BlueGirlPos[1].y() += 3;
	}
}

void Game::HitAction()
{

	for (int i = 0; i < 4; i++)
	{
		LamaWidthHit[i]  = LamaDrawPos.x() - RedGirlPos[i].x();
		LamaHeightHit[i] = LamaDrawPos.y() - RedGirlPos[i].y();
	}

	for (int i = 0; i < 2; i++)
	{
		LamaWidthBlueHit[i] = LamaDrawPos.x() - BlueGirlPos[i].x();
		LamaHeightBlueHit[i] = LamaDrawPos.y() - BlueGirlPos[i].y();
	}

	for (int i = 0; i < 4; i++)
	{
		if (LamaWidthHit[i] * LamaWidthHit[i] + LamaHeightHit[i] * LamaHeightHit[i] <= 100 * 100)
		{
			Game::LamaresetPos();
			Game::EnemyResetPos();
		}
	}

	for (int i = 0; i < 2; i++)
	{
		if (LamaWidthBlueHit[i] * LamaWidthBlueHit[i] + LamaHeightBlueHit[i] * LamaHeightBlueHit[i] < 100 * 100)
		{
			Game::LamaresetPos();
			Game::EnemyResetPos();
		}
	}
	
}

void Game::StartEnemyAnimation()
{
	for (int i = 0; i < 6; i++)
	{
		if (LamaDrawPos.y() >= 200)
		{
			EnemyMoveFlag[0] = true;
		}
	}
}

void Game::Draw()
{

	drawTextureBox(-750.0f, -500.0f, 1500.0f, 1000.0f, 0.0f, 0.0f, 2048.0f, 1024.0f, GameBack);

	for (int i = MAP_HEIGHT; i >= 0; i--)
	{
		for (int k = 0; k < MAP_WIDTH; k++)
		{

			switch (MapChip[i][k])
			{
			case FALL_BLOCK:
				
				break;

			case MOVE_BLOCK:
				drawFillBox(MapPos[i][k].x()+Mpos.x(), MapPos[i][k].y() + Mpos.y(), BLOCK_SIZE, BLOCK_SIZE, Color::white);
				break;
			}
		}
	}

	if (LeftMove == true)
	{
		if (AnimationCount >= 0 && AnimationCount < 15)
		{
			drawTextureBox(LamaDrawPos.x(), LamaDrawPos.y(), LamaSize.x(), LamaSize.y(), 0.0f, 128.0f, TextureDrawCos.x(), TextureDrawCos.y(), Lama);
		}
		if (AnimationCount >= 15 && AnimationCount < 30)
		{
			drawTextureBox(LamaDrawPos.x(), LamaDrawPos.y(), LamaSize.x(), LamaSize.y(), 64.0f, 128.0f, TextureDrawCos.x(), TextureDrawCos.y(), Lama);
		}
		if (AnimationCount >= 30 && AnimationCount < 45)
		{
			drawTextureBox(LamaDrawPos.x(), LamaDrawPos.y(), LamaSize.x(), LamaSize.y(), 128.0f, 128.0f, TextureDrawCos.x(), TextureDrawCos.y(), Lama);
		}
		if (AnimationCount >= 45 && AnimationCount <= 60)
		{
			drawTextureBox(LamaDrawPos.x(), LamaDrawPos.y(), LamaSize.x(), LamaSize.y(), 192.0f, 128.0f, TextureDrawCos.x(), TextureDrawCos.y(), Lama);
		}
	}

	else if (RightMove == true)
	{
		if (AnimationCount >= 0 && AnimationCount < 15)
		{
			drawTextureBox(LamaDrawPos.x(), LamaDrawPos.y(), LamaSize.x(), LamaSize.y(), 0.0f, 256.0f, TextureDrawCos.x(), TextureDrawCos.y(), Lama);
		}
		if (AnimationCount >= 15 && AnimationCount < 30)
		{
			drawTextureBox(LamaDrawPos.x(), LamaDrawPos.y(), LamaSize.x(), LamaSize.y(), 64.0f, 256.0f, TextureDrawCos.x(), TextureDrawCos.y(), Lama);
		}
		if (AnimationCount >= 30 && AnimationCount < 45)
		{
			drawTextureBox(LamaDrawPos.x(), LamaDrawPos.y(), LamaSize.x(), LamaSize.y(), 128.0f, 256.0f, TextureDrawCos.x(), TextureDrawCos.y(), Lama);
		}
		if (AnimationCount >= 45 && AnimationCount <= 60)
		{
			drawTextureBox(LamaDrawPos.x(), LamaDrawPos.y(), LamaSize.x(), LamaSize.y(), 192.0f, 256.0f, TextureDrawCos.x(), TextureDrawCos.y(), Lama);
		}
	}

	else if (UpMove == true)
	{
		if (AnimationCount >= 0 && AnimationCount < 15)
		{
			drawTextureBox(LamaDrawPos.x(), LamaDrawPos.y(), LamaSize.x(), LamaSize.y(), 0.0f, 384.0f, TextureDrawCos.x(), TextureDrawCos.y(), Lama);
		}
		if (AnimationCount >= 15 && AnimationCount < 30)
		{
			drawTextureBox(LamaDrawPos.x(), LamaDrawPos.y(), LamaSize.x(), LamaSize.y(), 64.0f, 384.0f, TextureDrawCos.x(), TextureDrawCos.y(), Lama);
		}
		if (AnimationCount >= 30 && AnimationCount < 45)
		{
			drawTextureBox(LamaDrawPos.x(), LamaDrawPos.y(), LamaSize.x(), LamaSize.y(), 128.0f, 384.0f, TextureDrawCos.x(), TextureDrawCos.y(), Lama);
		}
		if (AnimationCount >= 45 && AnimationCount <= 60)
		{
			drawTextureBox(LamaDrawPos.x(), LamaDrawPos.y(), LamaSize.x(), LamaSize.y(), 192.0f, 384.0f, TextureDrawCos.x(), TextureDrawCos.y(), Lama);
		}
	}

	else if (DownMove == true)
	{
		if (AnimationCount >= 0 && AnimationCount < 15)
		{
			drawTextureBox(LamaDrawPos.x(), LamaDrawPos.y(), LamaSize.x(), LamaSize.y(), 0, 0.0f, TextureDrawCos.x(), TextureDrawCos.y(), Lama);
		}
		if (AnimationCount >= 15 && AnimationCount < 30)
		{
			drawTextureBox(LamaDrawPos.x(), LamaDrawPos.y(), LamaSize.x(), LamaSize.y(), 64.0f, 0.0f, TextureDrawCos.x(), TextureDrawCos.y(), Lama);
		}
		if (AnimationCount >= 30 && AnimationCount < 45)
		{
			drawTextureBox(LamaDrawPos.x(), LamaDrawPos.y(), LamaSize.x(), LamaSize.y(), 128.0f, 0.0f, TextureDrawCos.x(), TextureDrawCos.y(), Lama);
		}
		if (AnimationCount >= 45 && AnimationCount <= 60)
		{
			drawTextureBox(LamaDrawPos.x(), LamaDrawPos.y(), LamaSize.x(), LamaSize.y(), 192.0f, 0.0f, TextureDrawCos.x(), TextureDrawCos.y(), Lama);
		}
	}

	else
	{
		drawTextureBox(LamaDrawPos.x(), LamaDrawPos.y(), LamaSize.x(), LamaSize.y(), 0.0f, 256.0f, TextureDrawCos.x(), TextureDrawCos.y(), Lama);
	}

	EnemyDraw();

}

void Game::EnemyDraw()
{
		drawTextureBox(RedGirlPos[0].x(), RedGirlPos[0].y(), GirlSize.x(), GirlSize.y(), 256.0f, 0.0f, GirlDrawCos.x(), GirlDrawCos.y(), RedGirl);
		drawTextureBox(RedGirlPos[1].x(), RedGirlPos[1].y(), GirlSize.x(), GirlSize.y(), 256.0f, 256.0f, GirlDrawCos.x(), GirlDrawCos.y(), RedGirl);
		drawTextureBox(RedGirlPos[2].x(), RedGirlPos[2].y(), GirlSize.x(), GirlSize.y(), 256.0f, 256.0f, GirlDrawCos.x(), GirlDrawCos.y(), RedGirl);
		drawTextureBox(RedGirlPos[3].x(), RedGirlPos[3].y(), GirlSize.x(), GirlSize.y(), 256.0f, 0.0f, GirlDrawCos.x(), GirlDrawCos.y(), RedGirl);
		drawTextureBox(BlueGirlPos[0].x(), BlueGirlPos[0].y(), GirlSize.x(), GirlSize.y(), 256.0f, 256.0f, GirlDrawCos.x(), GirlDrawCos.y(), BlueGirl);
		drawTextureBox(BlueGirlPos[1].x(), BlueGirlPos[1].y(), GirlSize.x(), GirlSize.y(), 0.0f, 256.0f, GirlDrawCos.x(), GirlDrawCos.y(), BlueGirl);
	}

void Game::DrawFallBlock()
{
	
}