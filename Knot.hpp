//
//  Knot.hpp
//  Path Finder
//

#ifndef Knot_hpp
#define Knot_hpp

#include "Coordinate.hpp"

class Knot : public Coordinate {
private:
	double _paths_costs_from_start, _distance_to_target;
	Coordinate _prev;
	
public:
	Knot(Coordinate c, double g, double h, Coordinate prev)
		: Coordinate(c), _paths_costs_from_start(g), _distance_to_target(h), _prev(prev) { }
	
	double g() const {return _paths_costs_from_start;}
	double h() const {return _distance_to_target;}
	
	Coordinate prev() const {return _prev;}
};

#endif /* Knot_hpp */
