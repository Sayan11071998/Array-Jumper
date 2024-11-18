#include "../../header/Level/LevelModel.h"
#include "../../header/Level/LevelConfiguration.h"

namespace Level
{
	LevelModel::LevelModel() {}
	LevelModel::~LevelModel() {}

	BlockType LevelModel::getCurrentBoxValue(int currentPosition)
	{
		return level_configuration.levels[current_level_index].level_boxes[currentPosition];
	}

	void LevelModel::loadNextLevel()
	{
		current_level_index++;
	}

	int LevelModel::getCurrentLevelNumber()
	{
		return current_level_index + 1;
	}

	bool LevelModel::isLastLevel()
	{
		if (current_level_index == LevelConfiguration::NUMBER_OF_LEVELS - 1)
			return true;
		return false;
	}

	void LevelModel::reset()
	{
		current_level_index = 0;
	}
}

