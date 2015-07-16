/*
 * GameStateManager.cpp
 *
 *  Created on: 16 lip 2015
 *      Author: foczka
 */

#include "GameStateManager.h"

namespace akp {

//***************** STOS *******************//

GameState* GameStateManager::peekState(){

	if( statesStack.empty() ) return nullptr;
	return statesStack.top();

}

void GameStateManager::changeState( GameState* _gameState ){
	if( statesStack.empty() == false )
		this->popState();

	pushState( _gameState );

	return;
}

void GameStateManager::pushState( GameState* _gameState ){
	statesStack.push( _gameState );

	return;
}

void GameStateManager::popState(){
	delete statesStack.top();
	statesStack.pop();

	return;
}

//***************** INNE *******************//

void GameStateManager::startLoop(){

	sf::Clock clock;

	while( this->renderWindow.isOpen() && this->peekState() != nullptr ){
		sf::Time timeElapsed = clock.restart();
		float dt = timeElapsed.asSeconds();

		this->peekState()->handleInput();
		peekState()->updateTime( dt );

		this->renderWindow.clear( sf::Color::Black );

		peekState()->drawFrame();

		this->renderWindow.display();

	}

}

GameStateManager::GameStateManager() {
	this->renderWindow.create( sf::VideoMode( 800, 600), "Akap The Game v.0.01" );
	this->renderWindow.setFramerateLimit(60);
}

GameStateManager::~GameStateManager() {

	while( !statesStack.empty() )
		this->popState();

}

} /* namespace akp */
