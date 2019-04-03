#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctype.h>
#include <algorithm>
#include <list>
#include <stdio.h>
using namespace std;

struct element
{
	char data;
	int amount;
	string code;
	element *left, *right;
	element(char value = '\0', int am = 0) : left(NULL),right(NULL), data(value), amount(am),code() {}
};

struct node_with_code
{
	char data;
	string code;
	node_with_code(char value = '\0', string codee = "0") :  data(value), code(codee) {}
};

struct tree
{
	element *top;
	tree(element* t = 0) : top(t){}
	
	char find(const string &code, int &counter);
	int getAverageLength(vector<node_with_code*> table);

};

struct letter;

bool compare(element *first, element *second);
element *min(vector <element*> el);
element *add(element *l, element *r);
element *haffman_algorithm(vector< element* > &el);
void infix(element *top);
int height(tree b);
vector <element*> getElements(vector<letter> table);
void prefix(element *top);
void calculate_huffman_codes(element *root);
void create_table_with_code(element *top, vector<node_with_code*> &code_string);
void codding_text(vector<node_with_code*> code_string, vector <string> text);
void from_code_to_text(string path, tree b);
void prt(element *n);