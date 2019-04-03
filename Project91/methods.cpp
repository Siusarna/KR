#include "tree.h"
#include "fileMethods.h"

void sort_table(vector<element*> &elements) {
	for (int i = 0; i < elements.size(); i++) {
		for (int j = i; j < elements.size(); j++) {
			if (elements[j]->amount > elements[i]->amount) {
				element *temp = new element;
				temp = elements[j];
				elements[j] = elements[i];
				elements[i] = temp;
			}
		}
	}
}

bool compare(element *first, element *second){
	return first->amount < second->amount;
}

element *min(vector <element*> el){
	element *min = el[0];
	unsigned int erase_position = 0;
	for (unsigned int i = 1; i < el.size(); i++)
		if (!compare(min, el[i]))
		{
			min = el[i];
			erase_position = i;
		}
	el.erase(el.begin() + erase_position);
	return min;
}

element *add(element *l, element *r){
	element *new_top = new element;
	new_top->amount = l->amount + r->amount;
	if (compare(l, r))
	{
		new_top->left = l;
		new_top->right = r;
	}
	else
	{
		new_top->left = r;
		new_top->right = l;
	}
	return new_top;
}

char tree::find(const string &code, int &counter){
	element *p = this->top;
	for (int i = 0; p, i < code.length(); i++)
		if (code[i] == '0'){
			counter++;
			p = p->left;
		}
		else if (code[i] == '1'){
			counter++;
			p = p->right;
		}
		else exit(1);
		if (!p || p->left || p->right) return '\0';
		return p->data;
}

element *haffman_algorithm(vector< element* > &el){
	while (el.size() > 1) {
		element *root = new element;
		root->amount = 0;
		root->right = el.back();
		root->amount += el.back()->amount;
		el.pop_back();
		root->left = el.back();
		root->amount += el.back()->amount;
		el.pop_back();
		el.push_back(root);
		sort_table(el);
	}
	return el[0];
}

void infix(element *top)
{
	if (!top) return;
	infix(top->left);
	if (!(top->left && top->right))
		cout << top->data <<" "<<top->code << endl;
	infix(top->right);
}

void prefix(element *top)
{
	if (!top) return;
	cout << top->data << " ";
	infix(top->left);
	infix(top->right);
}

int height(tree b) {
	element *p = b.top;
	if (p == NULL) {
		return -1;
	}

	int lefth = height(p->left);
	int righth = height(p->right);

	if (lefth > righth) {
		return lefth + 1;
	}
	else {
		return righth + 1;
	}
}

vector <element*> getElements(vector<letter> table){
	vector <element*> elements(table.size());
	for (int i = 0; i < table.size(); i++){
		elements[i]= new element(table[i].symbol, table[i].frequency);
	}
	return elements;
}

void traverse(element *node, string code)
{
	if (node->left == NULL && node->right == NULL)
	{
		node->code = code;
	}
	else
	{
		traverse(node->left, code + '0');
		traverse(node->right, code + '1');
	}
}

void calculate_huffman_codes(element *root)
{
	traverse(root, "");
}

void create_table_with_code(element *top,vector<node_with_code*> &code_string) {
	if (!top) return;
	create_table_with_code(top->left,code_string);
	if (!(top->left && top->right))
		code_string.push_back(new node_with_code(top->data, top->code));
	create_table_with_code(top->right,code_string);
}

void codding_text(vector<node_with_code*> code_string, vector <string> text) {
	string temp;
	char ch;
	int k;
	ofstream file("codding_text.txt", ios::trunc);
	for (unsigned i = 0; i < text.size(); i++) {
		temp = text[i];
		for (unsigned j = 0; j < temp.size(); j++) {
			ch = temp[j];
			ch = tolower(temp[j]);
			k = 0;
			while (code_string[k]->data != ch) {
				k++;
			}
			file << code_string[k]->code<<" ";
		}
		file << '\n';
	}
	file.close();
}

void from_code_to_text(string path,tree b) {
	int counter = 0;
	string temp;
	char ch;
	vector<string> text = getText(path);
	ofstream output("Result.txt");
	for(unsigned i =0;i<text.size();i++){
		for (unsigned j = 0; j < text[i].size(); j++) {
			ch = text[i][j];
			if (ch == ' ') {
				output << b.find(temp, counter);
				temp.clear();
			}
			else temp += text[i][j];
		}
		output << '\n';
	}
	output.close();
}

int tree::getAverageLength(vector<node_with_code*> table){
	int counter = 0;
	int sum = 0;
	for (int i = 0; i < table.size(); i++){
		find(table[i]->code, counter);
		sum += counter;
		counter = 0;
	}
	return sum / table.size();
}

int max_depth(element *n)
{
	if (!n) return 0;
	return 1 + std::max(max_depth(n->left), max_depth(n->right));
}

void prt(element *n)
{
	struct node_depth
	{
		element *n;
		int lvl;
		node_depth(element *n, int lvl) : n(n), lvl(lvl) {}
	};

	int depth = max_depth(n);

	char buf[102400];
	int last_lvl = 0;
	int offset = depth*10;

	// using a queue means we perform a breadth first iteration through the tree
	list<node_depth> q;

	q.push_back(node_depth(n, last_lvl));
	while (q.size())
	{
		const node_depth& nd = *q.begin();

		// moving to a new level in the tree, output a new line and calculate new offset
		if (last_lvl != nd.lvl)
		{
			cout << "\n";

			last_lvl = nd.lvl;
			offset = (1 << (depth - nd.lvl)) - 1;
		}

		// output <offset><data><offset>
		if (nd.n)
			sprintf(buf, " %*s %d %*s ", offset, " ", nd.n->data, offset, " ");
		else
			sprintf(buf, "%*s", offset << 1, " ");
		std::cout << buf;

		if (nd.n)
		{
			q.push_back(node_depth(nd.n->left, last_lvl + 1));
			q.push_back(node_depth(nd.n->right, last_lvl + 1));
		}

		q.pop_front();
	}
	std::cout << "\n";
}