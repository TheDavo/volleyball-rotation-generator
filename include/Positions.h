#ifndef _POSITIONS_H_
#define _POSITIONS_H_

#include <iostream>
#include <string>

enum class Position {
	Setter = 0,
	Libero,
	Middle,
	Outside,
	Opposite
};

std::string position_as_str(Position p);

#endif
