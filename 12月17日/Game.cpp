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

	AnimationCount = 0.0f;
	RightMove      = false;
	LeftMove       = false;
	UpMove         = false;
	DownMove       = false;

	std::ifstream* Mapfile = nullptr;
	const char* NewStage = "res/Stage.txt";
	Mapfile = new std::ifstream(NewStage);

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
	if (env.isPressKey(GLFW_KEY_LEFT))
	{
		LamaDrawPos.x() -= 3;
		LeftMove         = true;
		RightMove		 = false;
		UpMove			 = false;
		DownMove		 = false;

		if (LeftMove == true)
		{
			AnimationCount++;
		}
	}

	else if (env.isPressKey(GLFW_KEY_RIGHT))
	{
		LamaDrawPos.x() += 3;
		LeftMove		 = false;
		RightMove		 = true;
		UpMove			 = false;
		DownMove		 = false;

		if (RightMove == true)
		{
			AnimationCount++;
		}
	}

	else if (env.isPressKey(GLFW_KEY_UP))
	{
		LamaDrawPos.y() += 3;
		LeftMove		 = false;
		RightMove		 = false;
		UpMove			 = true;
		DownMove		 = false;

		if (UpMove == true)
		{
			AnimationCount++;
		}
	}

	else if (env.isPressKey(GLFW_KEY_DOWN))
	{
		LamaDrawPos.y() -= 3;
		LeftMove		 = false;
		RightMove		 = false;
		UpMove			 = false;
		DownMove		 = true;

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

void Game::FallBlockUpdate()
{
	if (LamaDrawPos.x() < one.x() + FALL_SIZE)
	{
		LamaDrawPos = Vec2f(-630.0f, -400.0f);
	}
	if (LamaDrawPos.y() < three.y() + FALL_SIZE)
	{
		LamaDrawPos = Vec2f(-630.0f, -400.0f);
	}
}

void Game::Draw()
{
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

}

void Game::DrawFallBlock()
{
	drawFillBox(one.x(), one.y(), BLOCK_SIZE, ONE_BLOCK_SIZE, Color::red);
	drawFillBox(two.x(), two.y(), TWO_BLOCK_SIZE, BLOCK_SIZE, Color::red);
	drawFillBox(three.x(), three.y(), TWO_BLOCK_SIZE, BLOCK_SIZE, Color::red);
	drawFillBox(four.x(), four.y(), BLOCK_SIZE, FOUR_BLOCK_SIZE, Color::red);
	drawFillBox(five.x(), five.y(), SECOND_BLOCK_SIZE, FOUR_BLOCK_SIZE, Color::red);
	drawFillBox(six.x(), six.y(), SECOND_BLOCK_SIZE, FOUR_BLOCK_SIZE, Color::red);
	drawFillBox(seven.x(), seven.y(), THIRD_BLOCK_SIZE, FORTH_BLOCK_SIZE, Color::red);
	drawFillBox(eight.x(), eight.y(), THIRD_BLOCK_SIZE, FIFTH_BLOCK_SIZE, Color::red);
	drawFillBox(nine.x(), nine.y(), SIXTH_BLOCK_SIZE, FIFTH_BLOCK_SIZE, Color::red);
	drawFillBox(ten.x(), ten.y(), FOUR_BLOCK_SIZE - 50, FIFTH_BLOCK_SIZE + 150, Color::red);
}