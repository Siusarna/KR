#include "fileMethods.h"
#include "tree.h"

vector <string> getText(string path){
	vector <string> text;
	string row;
	ifstream input(path);
	while (input.good()){
		getline(input, row);
		text.push_back(row);
		row.clear();
	}
	input.close();
	return text;
}

void print(vector <string> text){
	for (int i = 0; i < text.size(); i++){
		cout << text[i] << endl;
	}
}

vector <letter> getLetters(vector <string> text){
	vector<letter>letters;
	char alphabet[57] = { 'a', 'A', 'b', 'B', 'c', 'C', 'd', 'D', 'e', 'E', 'f', 'F', 'g', 'G', 'h', 'H', 'i', 'I', 'j', 'J', 'k', 'K', 'l', 'L', 'm', 'M', 'n', 'N', 'o', 'O', 'p', 'P', 'q', 'Q', 'r', 'R', 's', 'S', 't', 'T', 'u', 'U', 'v', 'V', 'w', 'W', 'x', 'X', 'y', 'Y', 'z', 'Z','.',',','?',';',' ' };
	int frequency = 0;
	for (int i = 0; i < 57; i += 2){
		for (int j = 0; j < text.size(); j++){
			for (int k = 0; k < text[j].size(); k++){
				if (alphabet[i] == text[j][k] || alphabet[i + 1] == text[j][k]){
					frequency++;
				}
			}
		}
		letters.push_back(letter(alphabet[i], frequency));
		frequency = 0;
	}
	return letters;
}

void printTable(vector<letter> table){
	for (int i = 0; i < table.size(); i++){
		cout << table[i].symbol << "     " << table[i].frequency << endl;
	}
}