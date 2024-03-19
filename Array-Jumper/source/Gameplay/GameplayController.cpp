#include "../../header/Gameplay/GameplayController.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Level/LevelData.h"
#include "../../header/Sound/SoundService.h"
#include "../../header/Main/GameService.h"

namespace Gameplay
{
	using namespace Global;
	using namespace Level;
	using namespace Sound;
	using namespace Main;

	void GameplayController::intialize() { /*Not Implemented */ }

	void GameplayController::update() { /* Not Implemented */ }

	void GameplayController::render() { /* Not Implemented */ }

	void GameplayController::onPositionChanged(int position)
	{
		int value = ServiceLocator::getInstance()->getLevelService()->getCurrentBoxValue(position);

		if (isObstacle(value))
			processObstacle();
		if (isEndBlock(position))
			processEndBlock();
	}

	void GameplayController::onDeath()
	{
		gameOver();
	}



	bool GameplayController::isObstacle(int value)
	{
		if (value == -1 || value == -2)
			return true;
		return false;
	}

	bool GameplayController::isEndBlock(int position)
	{
		if (position == LevelData::NUMBER_OF_BOXES - 1)
			return true;
		return false;
	}

	void GameplayController::processObstacle()
	{
		ServiceLocator::getInstance()->getPlayerService()->takeDamage();
		ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::DEATH);
	}

	void GameplayController::processEndBlock()
	{
		ServiceLocator::getInstance()->getPlayerService()->levelComplete();
		ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::LEVEL_COMPLETE);


		if(isLastLevel())
		{
			gameWon();
			return;
		}

		loadNextLevel();
	}
	
	bool GameplayController::isLastLevel()
	{
		return ServiceLocator::getInstance()->getLevelService()->isLastLevel();
	}

	void GameplayController::startGame()
	{
		GameService::setGameState(GameState::GAMEPLAY);
		return ServiceLocator::getInstance()->getLevelService()->resetLevels();
		return ServiceLocator::getInstance()->getPlayerService()->resetPlayer();

	}

	void GameplayController::gameWon()
	{
		GameService::setGameState(GameState::CREDITS);
		ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::GAME_WON);

	}

	void GameplayController::loadNextLevel()
	{
		ServiceLocator::getInstance()->getLevelService()->loadNextLevel();
	}


	void GameplayController::gameOver()
	{
		GameService::setGameState(GameState::CREDITS);
		ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::DEATH);
	}
}