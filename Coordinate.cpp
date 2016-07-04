//
//  Coordinate.cpp
//  Path Finder
//

#include <math.h>
#include "Coordinate.hpp"

double distance(const Coordinate& a, const Coordinate& b) {return abs(a.x() - b.x()) + abs(a.y() - b.y());} // sqrt(pow(a.x()-b.x(),2) + pow(a.y()-b.y(), 2))

std::ostream& operator<<(std::ostream& os, const Coordinate& c) {
	os << "(" << c.x() << "," << c.y() << ")";
	return os;
}

std::istream& operator>>(std::istream& is, Coordinate& c) {
	int x,y;
	is >> x >> y;
	
	if (is.good())
		c = {x, y};
	
	return is;
}
