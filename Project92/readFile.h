#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

vector<string> readFile(string path);
string createOpenBracket(vector<string> text);
string createCloseBracket(vector<string> text);