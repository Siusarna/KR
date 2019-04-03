#include "task.h"

bool find(string bracket, char ch) {
	for (unsigned i = 0; i < bracket.size(); i++){
		if (ch == bracket[i]) return true;
	}
	return false;
}


bool task(vector<string> text, string openBracket, string closeBracket) {
	vector<char> stack;
	int index;
	char op;
	char el;
	string temp = text[0];
	for (unsigned i = 0; i < temp.size(); i++) {
		if (find(openBracket, temp[i])) stack.push_back(temp[i]);
		if (find(closeBracket, temp[i])) {
			if (stack.empty()) return false;
			index = closeBracket.find(temp[i]);
			op = openBracket[index];
			el = stack.back();
			if (el == op) {
				stack.pop_back();
			}
			else return false;
		}
	}
	if (!stack.empty()) return false;
	else return true;
}