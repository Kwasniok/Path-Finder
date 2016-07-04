//
//  Map.cpp
//  Path Finder
//

#include "Map.hpp"
#include <math.h>

Map::Map(int w, int h) : _grid(w) {
	for (int y=0; y<h ; ++y) {
		_grid[y] = std::vector<bool>(w);
	}
}

bool Map::append_line(const std::vector<bool> & line) {
	if (_grid.size() == 0 || line.size() == width()) {_grid.push_back(line); return true;}
	else return false;
}

bool Map::append_line(std::vector<bool> && line) {
	if (_grid.size() == 0 || line.size() == width()) {_grid.push_back(std::move(line)); return true;}
	else return false;
}

std::vector<Coordinate> Map::get_traversable_environment(const Coordinate& c) const {
	std::vector<Coordinate> ret;
	
	int x = c.x();
	int y = c.y();
	
	if (x>0         && y>0          && is_traversable(x-1, y-1)) ret.push_back({x-1,y-1});
	if (x>0                         && is_traversable(x-1, y  )) ret.push_back({x-1,y });
	if (x>0         && y<height()-1 && is_traversable(x-1, y+1)) ret.push_back({x-1,y+1});
	if (               y>0          && is_traversable(x  , y-1)) ret.push_back({x  ,y-1});
	if (               y<height()-1 && is_traversable(x  , y+1)) ret.push_back({x  ,y+1});
	if (x<width()-1 && y>0          && is_traversable(x+1, y-1)) ret.push_back({x+1,y-1});
	if (x<width()-1                 && is_traversable(x+1, y  )) ret.push_back({x+1,y });
	if (x<width()-1 && y<height()-1 && is_traversable(x+1, y+1)) ret.push_back({x+1,y+1});
	
	return ret;
}

void Map::print(const std::vector<Coordinate>& path) const {
	
	for (int y = 0; y < height(); ++y) {
		for (int x = 0; x < width(); ++x) {
			Coordinate c(x, y);
			
			if (find(path.begin(), path.end(), c) != path.end()) {
				std::cout << 'p';
			} else {
				std::cout << (is_traversable(c) ? '.' : 'X');
			}
		}
		std::cout << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Map& m) {
	
	for (int y = 0; y < m.height(); ++y) {
		for (int x = 0; x < m.width(); ++x) {
			os << (m.is_traversable(x, y) ? '.' : 'X');
		}
		os << std::endl;
	}
	
	return os;
}

std::istream& operator>>(std::istream& is, Map& m) {
	
	Map tmp;
	std::string line;
	
	while (std::getline(is, line), is.good() && !line.empty()) {
		std::vector<bool> grid_line (line.size());
		for (int i=0; i<line.size(); ++i) {
			grid_line[i]= line[i] != 'X';
		}
		if (!tmp.append_line(grid_line)) {
			is.setstate(std::ios_base::failbit);
			return is;
		}
	}
	
	m = std::move(tmp);
	return is;
}
