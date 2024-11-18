#pragma once
#include "../../header/UI/UIElement/ImageView.h"
#include "../../header/UI/UIElement/ButtonView.h"
#include "../../header/UI/UIElement/TextView.h"

namespace UI
{
	namespace Instructions
	{
		class InstructionsUIController
		{
		private:
			// Constants:
			const float button_width = 400.f;
			const float button_height = 140.f;

			const float menu_button_y_position = 800.f;
			const float background_alpha = 85.f;

			static const int number_of_instructions = 4;
			const float top_offset = 250.f;
			const float text_spacing = 100.f;
			const int font_size = 50;

			const sf::Color text_color = sf::Color::White;

			sf::String instructions[number_of_instructions] = { "Move with 'Left' and 'Right' arrow key",
																"Hold 'Space' while moving to 'JUMP'",
																"Your player will 'JUMP' forward or backward by the value of your current cell",
																"Reach the target cell to 'Win' the game"};

			UIElement::ImageView* background_image;
			UIElement::ButtonView* menu_button;

			std::vector<UIElement::TextView*> instructions_text_list;

			void createImage();
			void createButtons();
			void createText();
			void initializeBackgroundImage();
			void initializeButtons();
			void initializeTexts();
			void registerButtonCallback();

			void menuButtonCallback();

			void destroy();

		public:
			InstructionsUIController();
			~InstructionsUIController();

			void initialize();
			void update();
			void render();
			void show();
		};
	}
}