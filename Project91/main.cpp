#include "fileMethods.h"
#include "tree.h"

void main(){
	tree t;
	vector <string> text = getText("text.txt");
	print(text);
	vector <letter> frequencyTable = getLetters(text);
	printTable(frequencyTable);
	vector <element*> elements = getElements(frequencyTable);
	
	t.top = haffman_algorithm(elements);
	calculate_huffman_codes(t.top);
	infix(t.top);
	prt(t.top);
	/*vector<node_with_code*> code_string;
	create_table_with_code(t.top, code_string);
	codding_text(code_string, text);
	from_code_to_text("codding_text.txt", t);
	cout << "Height = " << height(t) << endl;
	cout << "Average path length = " << t.getAverageLength(code_string) << endl;*/
	system("pause");
}
