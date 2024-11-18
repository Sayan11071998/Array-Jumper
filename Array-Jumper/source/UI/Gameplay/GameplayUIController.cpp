#include "../../../header/UI/Gameplay/GameplayUIController.h"
#include "../../../header/Global/ServiceLocator.h"

#include <sstream>
#include <iomanip>

namespace UI
{
	namespace GameplayUI
	{
		using namespace Global;
		using namespace UIElement;

		GameplayUIController::GameplayUIController()
		{
			createTexts();
		}

		GameplayUIController::~GameplayUIController()
		{
			destroy();
		}

		void GameplayUIController::initialize()
		{
			initializeTexts();
		}

		void GameplayUIController::update()
		{
			updateLifeCountText();
			updateLevelNumberText();
		}

		void GameplayUIController::render()
		{
			life_count_text->render();
			level_number_text->render();
		}

		void GameplayUIController::createTexts()
		{
			life_count_text = new TextView();
			level_number_text = new TextView();
		}

		void GameplayUIController::initializeTexts()
		{
			initializeLifeCountText();
			initializeLevelNumberText();
		}

		void GameplayUIController::initializeLifeCountText()
		{
			float windowWidth = ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->getSize().x;
			float x_position = (static_cast<float>(windowWidth) - right_offset);
			float y_position = top_offset;

			life_count_text->initialize("0", sf::Vector2f(x_position, y_position), FontType::BUBBLE_BOBBLE, font_size, sf::Color::White);
		}

		void GameplayUIController::initializeLevelNumberText()
		{
			sf::Vector2f position(left_offset, top_offset);
			level_number_text->initialize("0", position, FontType::BUBBLE_BOBBLE, font_size, sf::Color::White);
		}

		void GameplayUIController::updateLifeCountText()
		{
			int life_count = ServiceLocator::getInstance()->getPlayerService()->getCurrentLives();

			std::string life_count_string =  "LIFE: " + std::to_string(life_count);

			life_count_text->setText(life_count_string);
			life_count_text->update();
		}

		void GameplayUIController::updateLevelNumberText()
		{
			int level_number = ServiceLocator::getInstance()->getLevelService()->getCurrentLevelNumber();

			std::string level_number_string =  "LEVEL: " + std::to_string(level_number);

			level_number_text->setText(level_number_string);
			level_number_text->update();
		}

		void GameplayUIController::destroy()
		{
			delete(life_count_text);
			delete(level_number_text);
		}
	}
}