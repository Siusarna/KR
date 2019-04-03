#include <vector>
#include <string>
#include <locale>
#include "readFile.h"
#include "task.h"
#include <fstream>
using namespace std;

void main() {
	ofstream out("result.txt",ios::trunc);
	setlocale(LC_CTYPE, "rus");
	string path = "test.txt";
	vector<string> text = readFile(path);
	string openBracket = createOpenBracket(text);
	string closeBracket = createCloseBracket(text);
	if (task(text, openBracket, closeBracket)) out << "����� �����������";
	else out << "����� �� �����������";
	out.close();
	system("pause");
}