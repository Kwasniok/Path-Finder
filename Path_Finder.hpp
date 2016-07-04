//
//  Path_Finder.hpp
//  Path Finder
//


#ifndef Path_Finder_hpp
#define Path_Finder_hpp

#include "Map.hpp"

#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

using Heuristic_t = double(const Knot&);

class Path_Finder {
public:
	Path_Finder(const Map& m);

	std::vector<Coordinate> search(Coordinate start, Coordinate target, Heuristic_t& f);
	
private:
	const Map& _map;
};

class HeuristikVergleich {
public:
	HeuristikVergleich(Heuristic_t& f) : f_(f) {}
	bool operator()(const Knot& a, const Knot& b) { return f_(a) < f_(b); }
private:
	 Heuristic_t& f_;
};

// program a-star
//     // Initialisierung der Open List, die Closed List ist noch leer
//     // (die Priorität bzw. der f Wert des Startknotens ist unerheblich)
//     openlist.enqueue(startknoten, 0)
//     // diese Schleife wird durchlaufen bis entweder
//     // - die optimale Lösung gefunden wurde oder
//     // - feststeht, dass keine Lösung existiert
//     repeat
//         // Knoten mit dem geringsten Heuristik(f) Wert aus der Open List
//         entfernen
//         currentNode := openlist.removeMin()
//         // wurde das Ziel gefunden?
//         if (currentNode == zielknoten) then
//             return PathFound
//         // Nachfolgeknoten auf die Open List setzen
//         expandNode(currentNode)
//         // der aktuelle Knoten ist nun abschließend untersucht
//         closedlist.add(currentNode)
//     until openlist.isEmpty()
//     // die Open List ist leer, es existiert kein Pfad zum Ziel
//     return NoPathFound
// end

// // überprüft alle Nachfolgeknoten und fügt sie der Open List hinzu, wenn
// entweder
// // - der Nachfolgeknoten zum ersten Mal gefunden wird oder
// // - ein besserer Weg zu diesem Knoten gefunden wird
// function expandNode(currentNode)
//     foreach successor of currentNode
//         // wenn der Nachfolgeknoten bereits auf der Closed List ist - tue
//         nichts
//         if closedlist.contains(successor) then
//             continue
//         // Heuristik (f) Wert für den neuen Weg berechnen:
//         // wenn der Nachfolgeknoten bereits auf der Open List ist,
//         // aber der neue Weg länger ist als der alte - tue nichts
//         if openlist.contains(successor) and f > openlist.find(successor).f
//         then
//             continue
//         // Vorgängerzeiger setzen
//         successor.predecessor := currentNode
//         // f Wert des Knotens in der Open List aktualisieren
//         // bzw. Knoten mit f Wert in die Open List einfügen
//         if openlist.contains(successor) then
//             openlist.decreaseKey(successor, f)
//         else
//             openlist.enqueue(successor, f)
//     end
// end

#endif /* Path_Finder_hpp */
