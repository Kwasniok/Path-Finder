//
//  Path.hpp
//  Path Finder
//

#ifndef Path_hpp
#define Path_hpp

#include "Knot.cpp"

double heur_a_star(const Knot& k);
double heur_dijkstra(const Knot& k);
double heur_best_first(const Knot& k);

#endif /* Path_hpp */
