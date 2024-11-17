#pragma once
#include "BlockType.h"

namespace Level
{
	struct LevelData
	{
		static const int number_of_boxes = 10;
		BlockType level_boxes[number_of_boxes] = {
			BlockType::ONE,
			BlockType::TWO,
			BlockType::OBSTACLE_ONE,
			BlockType::TWO,
			BlockType::THREE,
			BlockType::ONE,
			BlockType::OBSTACLE_TWO,
			BlockType::TWO,
			BlockType::ONE,
			BlockType::TARGET
		};
	};
}