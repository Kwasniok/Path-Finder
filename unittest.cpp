

#include <list>
#include <iostream>
#include <fstream>

#include "Path_Finder.hpp"

int main() {

	std::cout << "###########################################################\n";
	std::cout << "Teste Koordinate:\n";
	Coordinate c12(1, 2);
	Coordinate c43(4, 3);
	Coordinate c15(1, 5);
	
	std::cout << "(1,2) == (1,2)" << ((c12 == c12) ? "ok" : "error") << std::endl;
	std::cout << "(1,2) != (1,2)" << ((c12 != c12) ? "error" : "ok") << std::endl;
	std::cout << "(1,2) < (1,2)" << ((c12 < c12) ? "error" : "ok") << std::endl;
	std::cout << "(1,2) == (4,3)" << ((c12 == c43) ? "error" : "ok") << std::endl;
	std::cout << "(1,2) != (4,3)" << ((c12 != c43) ? "ok" : "error") << std::endl;
	
	std::cout << "(1,2) =? " << c12 << std::endl;
	Coordinate x;
	std::cout << "Geben Sie 5 7 ein:" << std::endl;
	std::cin >> x;
	std::cout << x << " == " << Coordinate(5, 7)
		<< ((x == Coordinate(5, 7)) ? "ok" : "error") << std::endl;
	
	std::cout << "###########################################################\n";
	std::cout << "Teste Karte:\n";
	Map map;
	std::cout << "Abstand " << c12 << " und " << c12 << ":"
		<< distance(c12, c12) << " "
		<< ((distance(c12, c12) == 0) ? "ok" : "error") << std::endl;
	std::cout << "Abstand " << c12 << " und " << c43 << ":"
		<< distance(c12, c43) << " "
		<< ((distance(c12, c43) == 4) ? "ok" : "error") << std::endl;
	std::cout << "Abstand " << c43 << " und " << c12 << ":"
		<< distance(c43, c12) << " "
		<< ((distance(c43, c12) == 4) ? "ok" : "error") << std::endl;
	std::cout << "Abstand " << c12 << " und " << c15 << ":"
		<< distance(c12, c15) << " "
		<< ((distance(c12, c15) == 3) ? "ok" : "error") << std::endl;
	
	std::ifstream f("karte.txt");
	f >> map;
	f.close();
	std::cout << "Eingelesene Karte:\n";
	std::cout << map;
	
	std::cout << "Karte mit Pfad:\n";
	std::vector<Coordinate> testPfad = {Coordinate(1, 2), Coordinate(1, 3),
		Coordinate(1, 4)};
	map.print(testPfad);
	
	Coordinate kn(13, 5);
	std::vector<Coordinate> nachbarn = map.get_traversable_environment(kn);
	std::cout << "Nachbarn von " << kn << ":";
	for (auto i = nachbarn.begin(); i != nachbarn.end(); ++i) {
		std::cout << *i << " ";
	}
	std::cout << std::endl;
}
