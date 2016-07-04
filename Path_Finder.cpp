//
//  Path_Finder.cpp
//  Path Finder
//


#include "Path_Finder.hpp"

Path_Finder::Path_Finder(const Map& m) : _map(m) { }

std::vector<Coordinate> Path_Finder::search(Coordinate start, Coordinate target, Heuristic_t& heur) {
	
	std::list<Knot> _open;
	std::list<Knot> _closed;
	
	HeuristikVergleich vergleicheHeuristik(heur);
	
	Knot knot_start {start, 0, distance(start, target), start};
	_open.push_back(knot_start);
	
	do {
		auto minele = min_element(_open.begin(), _open.end(), vergleicheHeuristik);
		const Knot& knot_prev= *minele;
		_open.remove(knot_prev);
		_closed.push_back(knot_prev);
		
		if (knot_prev == target) break;
		
		std::vector<Coordinate> env = _map.get_traversable_environment(knot_prev);
		for (auto it=env.begin(); it!=env.end(); ++it) {
			Coordinate& coord_env = *it;
			
			bool has = false;
			for (auto k : _closed) {
				if (coord_env == k) {
					has = true;
					break;
				}
			}
			if (has) continue;
			
			double g, h;
			g = knot_prev.g() + 1;
			h = distance(coord_env, target);
			
			Knot knot_env {coord_env, g, h, knot_prev};
			
			has = false;
			for (auto k : _open) {
				if (coord_env == k) {
					has = true;
					break;
				}
			}
			
			if(has && g >= knot_prev.g()) continue;
			
			if (has) {
				_open.remove(knot_env);
				_open.push_back(knot_env);
			}
			else
				_open.push_back(knot_env);
		}
	
	} while (!_open.empty());
	
	
	
	std::vector<Coordinate> path_reverse;
	Coordinate prev;
	
	for (auto k : _closed) {
		if (k == target) {
			path_reverse.push_back(k);
			prev = k.prev();
			_closed.remove(k);
			break;
		}
	}
	
	if (!path_reverse.empty()) {
		while (prev != start) {
			for (auto k : _closed) {
				if (prev == k) {
					path_reverse.push_back(k);
					prev = k.prev();
					_closed.remove(k);
					break;
				}
			}
		}
	}
	
	if (!path_reverse.empty() && path_reverse[path_reverse.size()-1] != start)
		path_reverse.push_back(start);
	
	std::vector<Coordinate> path;
	for (long i=path_reverse.size()-1; i >=0; --i)
		path.push_back(path_reverse[i]);
	
	std::cout << "Pfadlaenge:" << path.size()
	<< "\tKnoten in offener Liste:       " << _open.size()
	<< "\tKnoten in geschlossener Liste: " << _closed.size() << std::endl;
	
	return path;
}
