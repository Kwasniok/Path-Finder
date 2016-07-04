//
//  Path.cpp
//  Path Finder
//

#include "Path.hpp"

double heur_a_star(const Knot& k) {return k.g() + k.h();}
double heur_dijkstra(const Knot& k) {return k.g();}
double heur_best_first(const Knot& k) {return k.h();}
