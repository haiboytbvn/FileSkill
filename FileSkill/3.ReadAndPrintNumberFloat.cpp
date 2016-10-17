#include "stdafx.h";
#include "function.cpp"


void lab3() {

	float *arrayFloat = readFileToArrayFloatNotLoop("data_in.txt");
	int i = 0;
	while (arrayFloat[i] >= 0) {
		cout << arrayFloat[i] << " ";
		i++;
	}
}

float* readFileToArrayFloatNotLoop(char *fileName) {
	float *arrayFloat = new float[100];
	ifstream file;
	file.open(fileName);
	int i = 0;
	while (!file.eof()) {
		if (file >> arrayFloat[i]) {
			i++;
		}
		else {
			cout << "data is not only number !" << endl;
			system("pause");
			exit(0);
		}
	}


	int size = i;
	float* arrayResult = new float[size];
	i = 0;
	int j = 0;
	int k;
	while (i < size) {
		for (k = 0; k < j; k++) {
			if (arrayFloat[i] == arrayResult[k]) {
				break;
			}
		}
		if (k == j) {
			arrayResult[j] = arrayFloat[i];
			j++;
		}

		i++;
	}
	return arrayResult;
}