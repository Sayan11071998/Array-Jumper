#pragma once
#include <SFML/Graphics.hpp>
#include "../../header/UI/UIElement/AnimatedImageView.h"

namespace UI
{
	namespace SplashScreen
	{
		/*class SoundService;*/

		class SplashScreenUIController
		{
		private:
			// Constants:
			const float logo_animation_duration = 2.0f;
			const float logo_width = 600.f;
			const float logo_height = 134.f;

			// UI Elements:
			UIElement::AnimatedImageView* outscal_logo_view;

			void initializeOutscalLogo();
			void fadeInAnimationCallback();
			void fadeOutAnimationCallback();
			sf::Vector2f getLogoPosition();

		public:
			SplashScreenUIController();
			~SplashScreenUIController();

			void initialize();
			void update();
			void render();
			void show();
		};
	}
}