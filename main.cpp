/*
 * BIG CALCULATOR
 *
 *  Created on: 02-01-2012
 *      Author: herop-kde
 */

#include "functions.hpp"
#include <ctime>

int main()
{
#ifdef EG1
	int i;
	big_num a;
	big_num b = 1;
	clock_t start = clock();
	for (i = 1; i < 1000; i++)
	{
		cout << i << '\r' << flush;
		a.set(i);
		b = b * a;
	}
	std::cout << ((double)clock() - start)/CLOCKS_PER_SEC << endl;
	std::cout << b;
#endif
	//string a = "3 + 5 - 2 * 5 *(3 + 4)";

	string a;
	cout << "Type a mathematical expression: ";
	getline(cin, a);

	cout << "Standardized expression: ";
	vector<lex_sequence> lexed = lex_analyse(a);
	for (unsigned int i = 0; i < lexed.size(); i++)
		cout << lexed.at(i)<< " "<<flush;

	big_num b = evaluate(a);
	cout << endl << "Result: " << b;
}
