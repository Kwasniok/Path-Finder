
// main.cpp

#include <list>
#include <iostream>
#include <fstream>

#include "Path.hpp"
#include "Path_Finder.hpp"

using namespace std;

int main() {
	
	Map m;
	string name;
	cout << "Kartenname: ";
	cin >> name;
	
	name += ".txt";
	ifstream f(name);
	
	if (f.fail()) {
		cout << "Die Karte konnte nicht gefunden werden. Stellen Sie sicher, dass diese im gleichen Verzeichnnis wie das Programm liegt und diese auf .txt endet."
			<< endl << endl << "Bsp: 'karte' öffnet die Datei 'karte.txt'" << endl<< endl;
		return EXIT_FAILURE;
	}
	
	f >> m;
	
	if(!f.eof() && f.fail()) {
		cout << "Die Karte hat das flasche Format. Geben Sie nicht die Maße der Karte zu beginn der Datei an. Verwenden Sie keine leeren Zeilen."
			<< endl << endl << "Bsp: " << endl << "XXXXX" << endl << "X...X" << endl << "XXXXX" << endl << endl;
		return EXIT_FAILURE;
	}
	
	f.close();
	
	cout << "eingelesene Karte:" << endl;
	cout << "Y  X -->" << endl << "|" << endl << "|" << endl << "V" << endl << endl;
	cout << m << endl;
	
	Coordinate start;
	Coordinate target;
	
	cout << "eingabe Format: X Y" << endl;
	cout << "Start: ";
	cin >> start;
	cout << "Ziel: ";
	cin >> target;
	
	Path_Finder pf(m);
	
	cout << endl << "First Best:" << endl;
	vector<Coordinate> path = pf.search(start, target, heur_best_first);
	cout << "Laenge:" << path.size() << endl;
	m.print(path);
	
	cout << endl <<  "Dijkstra:" << endl;
	path = pf.search(start, target, heur_dijkstra);
	cout << "Laenge:" << path.size() << endl;
	m.print(path);
	
	cout << endl <<  "A*:" << endl;
	path = pf.search(start, target, heur_a_star);
	cout << "Laenge:" << path.size() << endl;
	m.print(path);
	
	return EXIT_SUCCESS;
}
