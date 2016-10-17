#include "stdafx.h";
#include "function.cpp"


void lab2() {

	int *arrayInt = readFileToArrayIntNotLoop("data_in.txt");
	int i = 0;
	while (arrayInt[i] >= 0) {
		cout << arrayInt[i] << " ";
		i++;
	}
}

int* readFileToArrayIntNotLoop(char *fileName) {
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
	int j = 0;
	int k;
	while (i < size) {
		for (k = 0; k < j; k++) {
			if (arrayInt[i] == arrayResult[k]) {
				break;
			}
		}
		if (k == j) {
			arrayResult[j] = arrayInt[i];
			j++;
		}
	
		i++;
	}
	return arrayResult;
}