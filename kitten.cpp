#include "include.h"

string ReadText(string filename, int line, const int maxLine) {
	ifstream fin;
	fin.open(filename, ios::in);
	string strVec[maxLine];
	int i = 0;
	while (!fin.eof()) {
		string inbuf;
		getline(fin, inbuf, '\n');
		strVec[i++] = inbuf;
	}
	fin.close();
	return strVec[line - 1];
}

int main(int argc, char *argv[]) {
	string sdir;
	sdir = argv[1];
	for (int i = 0; i < sdir.length(); ++i) {
		if (sdir[i] == '\\') sdir.insert(i++, "\\");
	}
	cout << ReadText(sdir, atoi(argv[2]), 10);
	return 0;
}
