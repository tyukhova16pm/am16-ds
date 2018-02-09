#include "calc_stack.h"
#include "calc_queue.h"

#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

enum token_type {
	NUMBER,
	PLUS,
	MINUS,
	UNAR_MINUS,
	MULTIPLY,
	DIVIDE,
	POW,
	LBRACKET,
	RBRACKET // всего 8
};

struct token {
	token_type m_type;
	int m_value;
};

void lex_analyze (const std::string expression, calc_queue<token> & result);
int PRIORITY (token);
int calculate (calc_queue<token> & infix);
void from_infix_to_postfix (calc_queue<token> & infix, calc_queue<token> & postfix);

int main ()
{
	std::string expr = "";
//	int i;
	getline (std::cin, expr, '\n');
	//std::cout << expr << std::endl;
	calc_queue<token> infix;
	lex_analyze (expr, infix);
	//std::cout << "lex done" << std::endl;
	std::cout << " = " << calculate (infix) << std::endl;
//	std::cin >> i; // это, чтобы окошко не пропадало.
	return 0;
}

void lex_analyze (const std::string expression, calc_queue<token> & result)
{
	token tmp;
	for (int i = 0; i < (int)expression.size (); ++i) {
		switch (expression[i]) {
			case '+':
				tmp.m_type = PLUS; 
				break;
			case '-':
				tmp.m_type = MINUS;
				break;
			case '*':
				tmp.m_type = MULTIPLY; 
				break;
			case '/':
				tmp.m_type = DIVIDE;
				break;
			case '^':
				tmp.m_type = POW; 
				break;
			case '(':
				tmp.m_type = LBRACKET;
				break;
			case ')':
				tmp.m_type = RBRACKET; 
				break;
			case '0': // от 0 до 9
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				tmp.m_type = NUMBER; // 8 - все нужные учли.
				tmp.m_value = expression[i] - '0';
				while ((++i < (int)expression.size ()) && ('0' <= expression[i]) && (expression[i] <= '9')) { // читаем до конца строки и пока число.
					tmp.m_value = tmp.m_value * 10 + expression[i] - '0';
				}
				--i;
				break;
			case ' ':
				continue; // пропускаем разделители
			case '\t':
				continue;
			default:
				std::cout << "Bad symbols in the expression";
				throw std::runtime_error ("Bad symbols in the expression");
		}
		result << tmp;
	}
	return;
}

int PRIORITY (token t)
{
	switch (t.m_type) {
		case LBRACKET:
			return 0;
		case MINUS:
		case PLUS:
			return 1;
		case MULTIPLY:
		case DIVIDE:
			return 2;
		case POW:
			return 3;
		case UNAR_MINUS:
			return 4;
		default: return -1;
	}
}

void from_infix_to_postfix (calc_queue<token> & infix, calc_queue<token> & postfix)
{
	calc_stack<token> st;
	token tmp;
	token prev; // для унарного минуса
	token from_stack;

	prev.m_type = LBRACKET; // инициализируем чем-нибудь, что не NUMBER и не RBRACKET

	while (infix.size () > 0) {
		switch ((tmp = infix.get ()).m_type) {
			case NUMBER:
				postfix << tmp;
				break;
			case LBRACKET:
				st << tmp;
				break;
			case RBRACKET:
				while (LBRACKET != (from_stack = st.pop ()).m_type) {
					postfix << from_stack;
				}
				break;
			case MINUS:
				if ((prev.m_type != NUMBER) && (prev.m_type != RBRACKET)) {
					tmp.m_type = UNAR_MINUS; // меняем тип токена с минуса на унарный минус
					st << tmp;
					break;
				}
				//здесь только проверка на унарный минус, поэтому нет break
			default:
				while (st.size ()) {
					if (PRIORITY (from_stack = st.pop()) >= PRIORITY (tmp)) {
						postfix << from_stack;
					}
					else {
						st << from_stack;
						break;
					}
				}
				st << tmp;
		}
		prev = tmp;
	}
	while (st.size ()) {
		postfix << st.pop ();
	}
	//std::cout << "inf to pref done" << std::endl;
}

int calculate (calc_queue<token> & infix)
{
	calc_queue<token> postfix;
	from_infix_to_postfix (infix, postfix);
	calc_stack<int> st;
	token tmp;
	int calc;

	while (postfix.size () > 0) {
		switch ((tmp = postfix.get ()).m_type) {
			case NUMBER:
				st << tmp.m_value;
				//std::cout << tmp.m_value << std::endl;
				break;
			case UNAR_MINUS:
				if (st.size () < 1) {
					std::cout << "Bad expression 1";
					throw std::runtime_error ("Bad expression");
				}
				st << -st.pop ();
				//std::cout << "u-" << std::endl;
				break;
			case MINUS:
				if (st.size () < 2) {
					std::cout << "Bad expression 2";
					throw std::runtime_error ("Bad expression");
				}
				st << -st.pop () + st.pop (); // знаки такие, потому что достаем из стека
				//std::cout << "-" << std::endl;
				break;
			case PLUS:
				if (st.size () < 2) {
					std::cout << "Bad expression 3";
					throw std::runtime_error ("Bad expression");
				}
				st << st.pop () + st.pop ();
				//std::cout << "+" << std::endl;
				break;
			case MULTIPLY:
				if (st.size () < 2) {
					std::cout << "Bad expression 4";
					throw std::runtime_error ("Bad expression");
				}
				st << st.pop () * st.pop ();
				//std::cout << "*" << std::endl;
				break;
			case DIVIDE:
				if (st.size () < 2) {
					std::cout << "Bad expression 5";
					throw std::runtime_error ("Bad expression");
				}
				calc = st.pop ();
				if (0 == calc) {
					std::cout << "Divivsion by zero";
					throw std::runtime_error ("Division by zero");
				}
				st << st.pop () / calc; // кстати, деление у нас целочисленное, хотя можно было заморочиться с точкой и врубить float
				//std::cout << "/" << std::endl;
				break;
			case POW:
				if (st.size () < 2) {
					std::cout << "Bad expression 6";
					throw std::runtime_error ("Bad expression");
				}
				calc = st.pop ();
				st << (int)pow (st.pop (), calc); // по той же причине степень с отрицательным показателем = 0
				//std::cout << "^" << std::endl;
				break;
		}

	}
	if (1 == st.size()) {
		return st.pop ();
	}
	else {
		std::cout << "Bad expression 7";
		throw std::runtime_error ("Bad expression");
	}
}