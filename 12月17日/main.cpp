#include "lib/framework.hpp"
#include "Game.h"



int main() {
 
	env;
	Game game;
	game.Setup();
  while (env.isOpen()) {
    // 開始
	
    env.begin();
	game.Update();
	game.FallBlockUpdate();
	game.DrawFallBlock();
	game.Draw();
	
	
    env.end();
  }
}
