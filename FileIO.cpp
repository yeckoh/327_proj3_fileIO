/*
 * FileReader.cpp
 *
 *  Created on: Oct 8, 2017
 *      Author: keith
 */
#include <iostream>
#include <fstream>
#include "../327_proj3_test/includes/FileIO.h"
#include "../327_proj3_test/includes/constants.h"

using namespace std;

//trys to open filename, and return its contents in contents
//it will strip out only \n's (char return\line feed)
//returns:
//SUCCESS all worked, contents string contains all in the file
//COULD_NOT_OPEN_FILE_TO_READ contents string is cleared
int KP_FileIO::getFileContents(const string &filename, string &contents)
{
	fstream fin;

	fin.open(filename.c_str());
	if(!fin.is_open())
		return COULD_NOT_OPEN_FILE_TO_READ;

	contents = "";
	string line = "";
	while(!fin.eof()) {
		getline(fin, line);
		contents.append(line);
	}
	fin.close();
	return SUCCESS;
}

//trys to open filename, and serialize  myEntryVector contents to it
//returns:
//SUCCESS all worked, filename contains myEntryVector strings
//COULD_NOT_OPEN_FILE_TO_WRITE
int KP_FileIO::writeVectortoFile(const string filename, vector<string> &myEntryVector)
{
	fstream fout;

	fout.open(filename.c_str());
	if(!fout.is_open())
		return COULD_NOT_OPEN_FILE_TO_WRITE;

	for(int i = 0;i < myEntryVector.size();++i) {
		if(myEntryVector[i] == "")
			continue;
		fout << myEntryVector[i] << endl;
	}
	fout.close();
	return SUCCESS;
}


