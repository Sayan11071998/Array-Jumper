#pragma once
#include <SFML/Graphics.hpp>
#include "../../header/Sound/SoundService.h"
#include "../../header/UI/UIElement/ImageView.h"
#include "../../header/UI/UIElement/ButtonView.h"

namespace UI
{
	namespace MainMenu
	{
		class MainMenuUIController
		{
		private:
			// Constants:
			const float button_width = 400.f;
			const float button_height = 140.f;

			const float play_button_y_position = 400.f;
			const float instructions_button_y_position = 600.f;
			const float quit_button_y_position = 800.f;

			const float background_alpha = 85.f;

			// UI Elements:
			UIElement::ImageView* background_image;
			UIElement::ButtonView* play_button;
			UIElement::ButtonView* instructions_button;
			UIElement::ButtonView* quit_button;

			void createImage();
			void createButtons();
			void initializeBackgroundImage();
			void initializeButtons();
			void registerButtonCallback();

			void playButtonCallback();
			void instructionsButtonCallback();
			void quitButtonCallback();

			void destroy();

		public:
			MainMenuUIController();
			~MainMenuUIController();

			void initialize();
			void update();
			void render();
			void show();
		};
	}
}