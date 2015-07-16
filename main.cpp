
#include <iostream>

//*********** AKP INCLUDES **********//
#include <Classes/StateManager/GameStateManager.h>

int main(int arg, char* argc[]){

	std::cout << "Akap Game v0.01" << std::endl;

	akp::GameStateManager game;

	game.startLoop();

	return 0;
}
