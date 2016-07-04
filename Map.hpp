//
//  Map.hpp
//  Path Finder
//

#ifndef Map_hpp
#define Map_hpp

#include <algorithm>
#include <vector>
#include <list>
#include <iostream>
#include "Knot.hpp"

class Map {
	
private:
	std::vector<std::vector<bool>> _grid;
	
public:
	Map() { }
	Map(int w, int h);
	
	bool append_line(const std::vector<bool>&);
	bool append_line(std::vector<bool>&&);
	
	bool is_traversable(const Coordinate& c) const {return is_traversable(c.x(), c.y());}
	bool is_traversable(const int x, const int y) const {return _grid[y][x];}
	
	int height() const {return static_cast<int>(_grid.size());}
	int width() const {return static_cast<int>(_grid.size() ? _grid[0].size() : 0);}
	
	void print(const std::vector<Coordinate>& pfad) const;
	
	std::vector<Coordinate> get_traversable_environment(const Coordinate& c) const;
};

std::ostream& operator<<(std::ostream& os, const Map& m);
std::istream& operator>>(std::istream& is, Map& m);


#endif /* Map_hpp */
