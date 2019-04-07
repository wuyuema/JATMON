#include "include.h"
//////////////////////////////
///////Introduction///////////
/*////////////////////////////
kitten is a file-checking toolkit.
produced by wuyuema, 2019
*/////////////////////////////

//////////////////////////////
///////ReadText///////////////
//////////////////////////////
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
/*////////////////////////////
string filename;
filename = ReadText(".\\calibdata.txt", ShowNum);
IplImage *image = NULL;
if (image)
	cvReleaseImage(&image);
image = cvLoadImage(filename.c_str(), 0);
*/////////////////////////////

