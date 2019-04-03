#include "readFile.h"

vector<string> readFile(string path) {
	ifstream fin("test.txt");
	vector<string> text;
	if (!fin.is_open()) {
		cout << "Не вдалося відкрити файл" << endl;
		system("pause");
	}
	else {
		string temp;
		while (!fin.eof()) {
			getline(fin, temp);
			text.push_back(temp);
			temp.clear();
		}
	}
	for (unsigned i = 0; i < text.size(); i++) {
		cout << text[i] << endl;
	}
	return text;
}

string createOpenBracket(vector<string> text) {
	string openBracket="";
	for (unsigned i = 0; i < text[1].size(); i += 2) {
		openBracket += text[1][i];
	}
	return openBracket;
}
string createCloseBracket(vector<string> text) {
	string closeBracket = "";
	for (unsigned i = 1; i < text[1].size(); i += 2) {
		closeBracket += text[1][i];
	}
	return closeBracket;
}