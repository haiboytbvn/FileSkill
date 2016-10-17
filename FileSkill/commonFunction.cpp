#include "stdafx.h";
#include "function.cpp"




void writeFile() {
	/*char *fileName = new char[100];
	cout << "input file name (no space): ";
	cin >> fileName;
	cin.ignore();*/

	ofstream file;
	file.open("data_out.txt");
	cout << "input data (double Enter to Finish): " << endl;
	char *data;
	while (true) {
		data = input();
		if (data[0] == '\0')
			break;
		file << endl << data;
	}
	cout << "Finish !";
	file.close();
}

char *input() {
	char *str;
	str = new char[100];
	cin.get(str, 100);
	cin.ignore();

	return str;
}