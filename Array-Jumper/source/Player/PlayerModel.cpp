#include "../../header/Player/PlayerModel.h"

namespace Player
{
	void Player::PlayerModel::initialize()
	{
		//Yet to implement
	}

	PlayerState PlayerModel::getPlayerState()
	{
		return player_state;
	}

	void PlayerModel::setPlayerState(PlayerState new_player_state)
	{
		player_state = new_player_state;
	}

	void PlayerModel::resetPlayer()
	{
		current_position = 0;
		player_state = PlayerState::ALIVE;
		current_lives = max_lives;
	}

	void PlayerModel::resetPosition()
	{
		current_position = 0;
	}

	int PlayerModel::getCurrentPosition() {	return current_position; }
	void PlayerModel::setCurrentPosition(int new_position) { current_position = new_position; }
	void PlayerModel::decreamentLife() { current_lives--; }
	int PlayerModel::getCurrentLives() { return current_lives; }
}


