#pragma once
#include "../../header/UI/UIElement/ImageView.h"

namespace Player
{
	using namespace UI::UIElement;
	class PlayerController;
	
	class PlayerView
	{
	private:
		UI::UIElement::ImageView* player_image;
		sf::RenderWindow* game_window;
		PlayerController* player_controller;
		
		float player_height;
		float player_width;

		void initializePlayerImage(); //Initialize player_image
		void drawPlayer(); //Called every frame to render the sprite on the screen
		void loadPlayer(); //Loads the information needed to render the player
		void calculatePlayerDimension(); //Calculate the size of image
		void updatePlayerPosition(); //Updates the Player Sprite's position on each frame
		sf::Vector2f calculatePlayerPosition();

	public:
		PlayerView(PlayerController* controller);
		~PlayerView();

		void initialize();
		void update();
		void render();
	};
}