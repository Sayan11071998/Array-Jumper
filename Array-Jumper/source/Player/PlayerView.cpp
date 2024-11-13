#include <iostream>
#include "../../header/Global/Config.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Player/PlayerView.h"

using namespace Global;
using namespace UI::UIElement;

namespace Player
{
	PlayerView::PlayerView()
	{
		game_window = nullptr;
		player_image = new ImageView();
	}
	
	PlayerView::~PlayerView()
	{
	}
	
	void PlayerView::initialize()
	{
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		loadPlayer();
	}
	
	void PlayerView::update()
	{
		updatePlayerPosition();
	}
	
	void PlayerView::render()
	{
	}

	void PlayerView::initializePlayerImage()
	{
		player_image->initialize(Config::character_texture_path, player_width, player_height, sf::Vector2f(0, 0));
	}

	void PlayerView::drawPlayer()
	{
		player_image->render();
	}

	void PlayerView::loadPlayer()
	{
		calculatePlayerDimension();
		initializePlayerImage();
	}

	void PlayerView::calculatePlayerDimension()
	{
		player_height = 1000.f;
		player_width = 1000.f;
	}

	void PlayerView::updatePlayerPosition()
	{
		player_image->setPosition(calculatePlayerPosition());
	}
	
	sf::Vector2f PlayerView::calculatePlayerPosition()
	{
		return sf::Vector2f(0, 0);
	}
}