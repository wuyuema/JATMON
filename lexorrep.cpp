#include "lexorrep.hpp"



int main(int argc, char *argv[]) {
//	cout << sek().front() << endl;
//	sek(argv[1]);
//	string target = argv[2], path = argv[1];
	string target = "include.h", path = ".\\"; 
	cout << flfind(path, target) << endl;
	return 0;
}
