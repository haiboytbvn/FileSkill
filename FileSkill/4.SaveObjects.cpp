#include "stdafx.h";
#include "function.cpp"


void lab4() {
	//input data
	cout << "Choose number of object: ";
	int number;
	cin >> number;
	struct data *dataIn;
	dataIn = new struct data[number];
	
	for (int i = 0; i < number; i++) {
		cout << endl;
		cout << "Object" << i + 1 << endl;
		cout << "type (int): ";  cin >> dataIn[i].type;  cin.ignore();
		cout <<  "val (float): ";  cin >> dataIn[i].val;  cin.ignore();
		cout <<  "buf (string): ";  cin.get(dataIn[i].buf, 100);  cin.ignore();
	}
	cout << endl << "Finish!";


	//write data
	ofstream writeFile;
	writeFile.open("save.bak");
	writeFile << number;
	for (int i = 0; i < number; i++) {
		writeFile << endl;
		writeFile << dataIn[i].type << " ";
		writeFile << dataIn[i].val << " ";
		writeFile << dataIn[i].buf;
	}
	writeFile.close();


	//read data
	ifstream readFile;
	readFile.open("save.bak");
	int numberOut;
	readFile >> numberOut;
	struct data *dataOut;
	dataOut = new struct data[numberOut];
	int i = 0;
	while (!readFile.eof()) {
		readFile >> dataOut[i].type;
		readFile >> dataOut[i].val;
		readFile >> dataOut[i].buf;
		i++;
	}
	readFile.close();


	//print data
	cout << endl << "File has " << numberOut << " objects:";
	cout << endl << "Object" << setw(20) << "type(int)" << setw(20) << "val(float)" << setw(20) << "buf(string)";
	for (i = 0; i < numberOut; i++) {
		cout << endl << setw(6) << i + 1 << setw(20) << dataOut[i].type << setw(20) << dataOut[i].val << setw(20) << dataOut[i].buf;
	}
}

