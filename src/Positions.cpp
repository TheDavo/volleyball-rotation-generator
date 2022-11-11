#include <string>

#include "../include/Positions.h"


std::string position_as_str(Position p){
	std::string position = "";
	switch (p) {
		case Position::Setter:
			position = "Setter";
			break;
		case Position::Libero:
			position = "Libero";
			break;
		case Position::Middle:
			position = "Middle";
			break;
		case Position::Outside:
			position = "Outside";
			break;
		case Position::Opposite:
			position = "Opposite";
			break;
		default:
			position = "";
			break;
	}
	return position;
}