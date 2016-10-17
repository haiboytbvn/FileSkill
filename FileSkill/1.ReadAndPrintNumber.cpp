#include "stdafx.h";
#include "function.cpp"


void lab1() {

	int *arrayInt = readFileToArrayInt("data_in.txt");
	int i = 0;
	while (arrayInt[i] >= 0) {
		cout << arrayInt[i] << " ";
		i++;
	}
}

int* readFileToArrayInt(char *fileName) {
	int *arrayInt = new int[100];
	ifstream file;
	file.open(fileName);
	int i = 0;
	while (!file.eof()) {
		if (file >> arrayInt[i]) {
			i++;
		}
		else {
			cout << "data is not only number !" << endl;
			system("pause");
			exit(0);
		}
	}
	int size = i;
	int* arrayResult = new int[size];
	i = 0;
	while (i < size) {
		arrayResult[i] = arrayInt[i];
		i++;
	}
	return arrayResult;
}