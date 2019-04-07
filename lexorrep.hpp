#include "include.h"
//////////////////////////////
///////Introduction///////////
/*////////////////////////////
lexorrep is a  file-managing solution.
produced by wuyuema, 2019
*/////////////////////////////


string pathConv(string& source) {
	for (int i = 0; i < source.length(); ++i) {
		if (source[i] == '\\') source.insert(i++, "\\");
	}
	return source;
}


//////////////////////////////
///////ls/////////////////////
//////////////////////////////
vector<string> sek(string path_name = ".\\", bool need_input = 0, bool disp = 0) {
	DIR *_dir;
	if (need_input) cin >> path_name;
	pathConv(path_name);
	_dir = opendir(path_name.data());
	struct dirent *ptr;
	vector<string> rlist;
	rlist.clear();
	while ((ptr = readdir(_dir)) != NULL) {
		if (strcmp(ptr->d_name, ".") && strcmp(ptr->d_name, "..")) {
			if (disp) cout << ptr->d_name << endl;
			rlist.push_back(ptr->d_name);
		}
	}
	closedir(_dir);
	return rlist;
}


//////////////////////////////
///////finder/////////////////
//////////////////////////////
int flfind(string path_name = ".\\", string file_name = "") {
	vector<string> rlist = sek(path_name);
	int cnt = 0;
	for (vector<string>::iterator it = rlist.begin(); it != rlist.end(); ++it) {
		if (*it == file_name) break;
		cnt++;
	}
	return cnt;
}
