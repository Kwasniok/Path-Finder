//
//  Coordinate.hpp
//  Path Finder
//

#ifndef Coordinate_hpp
#define Coordinate_hpp

#include <iostream>

class Coordinate {
private:
	int _x = 0;
	int _y = 0;
	
public:
	Coordinate() { }
	Coordinate(int x, int y) : _x(x), _y(y) { }
	
	int x() const { return _x; }
	int y() const { return _y; }
	
	bool operator==(const Coordinate& rhs) const {return _x == rhs._x && _y == rhs._y;}
	bool operator!=(const Coordinate& rhs) const {return !(*this == rhs);}
	bool operator<(const Coordinate& rhs) const {
		if (_x < rhs._x) return true;
		if (_x == rhs._y) return _y < rhs._y;
		return false;
	}

};

std::ostream& operator<<(std::ostream& os, const Coordinate& c);
std::istream& operator>>(std::istream& is, Coordinate& c);

double distance(const Coordinate& a, const Coordinate& b);

#endif /* Coordinate_hpp */
