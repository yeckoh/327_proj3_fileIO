/*============================================================================
Name        : FileIO.cpp
Author      : wchang 00960978
Prof        : K. Perkins @ CNU
Version     : 26 Oct 2k19
Project	    : cs327 - p4: classes, pointers, libraries
============================================================================*/
#include <fstream>
#include <vector>
#include "../327_proj3_test/includes/FileIO.h"
#include "../327_proj3_test/includes/constants.h"

using namespace std;

int KP_FileIO::getFileContents(const string &filename, string &contents)
{
	ifstream fin;

	fin.open(filename.c_str());
	if(!fin.is_open())
		return COULD_NOT_OPEN_FILE_TO_READ;

	string line = "";

	while(!fin.eof()) {
		getline(fin, line);
		contents.append(line);
	}

	fin.close();
	return SUCCESS;
}


int KP_FileIO::writeVectortoFile(const string filename, vector<string> &myEntryVector)
{
	ofstream fout(filename.c_str());

	if(!fout.is_open())
		return COULD_NOT_OPEN_FILE_TO_WRITE;

	for(int i = 0;i < myEntryVector.size();++i) {
		fout << myEntryVector[i] << endl;
	}
	fout.close();
	return SUCCESS;
}


