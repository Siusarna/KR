#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct letter {
	char symbol;
	int frequency;
	letter(char symbol, int frequency){
		this->symbol = symbol;
		this->frequency = frequency;
	}
};

vector <letter> getLetters(vector <string> text);
vector <string> getText(string path);
void print(vector <string> text);
void printTable(vector<letter> table);