#include "../../header/Player/PlayerController.h"
#include "../../header/Player/PlayerModel.h"
#include "../../header/Player/PlayerView.h"

namespace Player
{
	PlayerController::PlayerController()
	{
		player_model = new PlayerModel();
		player_view = new PlayerView(this);
	}
	PlayerController::~PlayerController()
	{
		destroy();
	}
	
	void PlayerController::initialize()
	{
		player_model->initialize();
		player_view->initialize();
	}
	
	void PlayerController::update()
	{
		player_view->update();
	}
	
	void PlayerController::render()
	{
		player_view->render();
	}
	
	PlayerState PlayerController::getPlayerState()
	{
		return player_model->getPlayerState();
	}
	
	void PlayerController::setPlayerState(PlayerState new_player_state)
	{
		player_model->setPlayerState(new_player_state);
	}

	void PlayerController::destroy()
	{
		delete(player_model);
		delete(player_view);
	}
}