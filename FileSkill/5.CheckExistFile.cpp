#include "stdafx.h";
#include "function.cpp"

void lab5() {
	char *fileName = new char[100];
	cout << "input file name (no space): ";
	cin >> fileName;
	cin.ignore();

	fstream file;
	file.open(fileName);
	if (file.fail())
		cout << "File is not exist !";
	else
		cout << "File is exist. Open success !";

	file.close();
}