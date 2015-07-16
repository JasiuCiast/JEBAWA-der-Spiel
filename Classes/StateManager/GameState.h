/*
 * GameState.h
 *
 *  Created on: 16 lip 2015
 *      Author: foczka
 */

#ifndef CLASSES_STATEMANAGER_GAMESTATE_H_
#define CLASSES_STATEMANAGER_GAMESTATE_H_

#include "GameStateManager.h"

namespace akp {

class GameStateManager;

class GameState
{
	public:

	GameStateManager* manager;

	virtual void drawFrame() = 0;
	virtual void updateTime( const float _deltaTime ) = 0;
	virtual void handleInput() = 0;

	virtual void ~GameState();
};

} /* namespace akp */

#endif /* CLASSES_STATEMANAGER_GAMESTATE_H_ */
