/*
 * functions.hpp
 *
 *  Created on: 02-01-2012
 *      Author: herop-kde
 */

#ifndef FUNCTIONS_HPP_
#define FUNCTIONS_HPP_
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <stack>

using namespace std;

#define D2C(x) (x + 48)	//Digit to character
#define C2D(x) (x - 48)	//Character to digit

class big_num {
public:
	string number;
	int sign;

	//Constructors
	big_num();
	big_num(int n);
	big_num(string &str);
	big_num(const char* c_str);

	//Retrieve value from an integer
	void set(int n);
	void reset();

	//Overloading operators
	big_num operator=(big_num op2);
	big_num operator+(big_num op2);
	big_num operator+(int op2);
	big_num operator-(big_num op2);
	big_num operator*(big_num op2);
	big_num operator*(int op2);
	big_num operator/(big_num op2);

	//Destructor
	~big_num();
};
#ifndef OSTREAM_OP
#define OSTREAM_OP
ostream &operator<<(ostream &out, const big_num& op);
#endif /*OSTREAM_OP*/

//LEXICAL ANALYSE
enum TYPE {no, op};
class lex_sequence {
public:
	big_num number;
	char math_op;
	TYPE element;
};
ostream &operator<<(ostream &stream, const lex_sequence op);
vector<lex_sequence> lex_analyse(const string& str);
big_num evaluate(const string &str);

//MISC
int abs_compare(big_num n1, big_num n2);
int s2n (const string& str);
int prior (char op1, char op2);
void do_math(char op, stack<big_num>& number);

#endif /* FUNCTIONS_HPP_ */
