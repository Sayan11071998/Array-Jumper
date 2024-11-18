#include "../../header/Graphics/GraphicService.h"
#include "../../header/Global/Config.h"

namespace Graphics
{
	using namespace Global;
	
	GraphicService::GraphicService()
	{
		game_window = nullptr;
	}

	GraphicService::~GraphicService()
	{
		onDestroy();
	}

	void GraphicService::initialize()
	{
		createGameWindow();
		setFrameRate(frame_rate);
	}

	void GraphicService::update() {}
	void GraphicService::render() {}

	sf::RenderWindow* GraphicService::createGameWindow()
	{
		configureVideoMode();
		game_window = new sf::RenderWindow(video_mode, game_window_title, sf::Style::Fullscreen);
		return game_window;
	}

	void GraphicService::configureVideoMode()
	{
		video_mode = *(new sf::VideoMode(game_window_width, game_window_height, sf::VideoMode::getDesktopMode().bitsPerPixel));
	}

	void GraphicService::setFrameRate(int frame_rate_to_set)
	{
		game_window->setFramerateLimit(frame_rate_to_set);
	}

	bool GraphicService::isGameWindowOpen()
	{
		return game_window->isOpen();
	}

	sf::RenderWindow* GraphicService::getGameWindow()
	{
		return game_window;
	}

	void GraphicService::onDestroy()
	{
		delete(game_window);
	}
}