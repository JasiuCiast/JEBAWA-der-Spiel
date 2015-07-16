/*
 * GameStateManager.h
 *
 *  Created on: 16 lip 2015
 *      Author: foczka
 */

#ifndef CLASSES_STATEMANAGER_GAMESTATEMANAGER_H_
#define CLASSES_STATEMANAGER_GAMESTATEMANAGER_H_

#include <stack>
#include <SFML/Graphics.hpp>
#include "GameState.h"

namespace akp {

class GameStateManager {
public:

	// G³owny ekran do renderowania grafiki
	sf::RenderWindow renderWindow;

	void startLoop();

	//***************** STOS *****************//

	// Stos do przechowywania stanow gry
	std::stack< GameState* > statesStack;

	// Zwroc wierzcholek stosu
	GameState* peekState();

	// Zmien wiercholek stosu na inny
	void changeState( GameState* );

	void pushState( GameState* );
	void popState();

	//***************** KONSTR/DESTR *********//

	GameStateManager();
	virtual ~GameStateManager();
};

} /* namespace akp */

#endif /* CLASSES_STATEMANAGER_GAMESTATEMANAGER_H_ */
