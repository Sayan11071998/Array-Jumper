#pragma once


namespace Player
{
	enum class PlayerState
	{
		ALIVE,
		DEAD
	};

	class PlayerModel
	{
	private: 
			
		const int max_lives = 3;

		PlayerState player_state;
		int current_position;
		int current_lives;
			
	public:

		void initialize();
			
		PlayerState getPlayerState();
		void setPlayerState(PlayerState new_player_state);
		
		void resetPlayer();
		void resetPosition();
		int getCurrentPosition();
		void setCurrentPosition(int new_position);
		void decreamentLife();
		int getCurrentLives();
	};
}