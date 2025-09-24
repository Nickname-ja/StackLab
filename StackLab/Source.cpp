#include "Stack.h"
#include <fstream>
#include <Windows.h>
#include <cstring>
int LEN = 255;

bool is_name(char c);
bool is_open_bracket(char c);
bool is_clise_bracket(char c);
bool is_operator(char c);
bool check_bracket(char st, char c);
bool task(char* str);

int main() {
	std::ifstream file("test.txt");
	char str[255] = "";
	while (!file.eof()) {
		file.getline(str, LEN);
		std::cout << str << " == " << (task(str) ? "Yes" : "No") << '\n';
	}
	file.close();
	std::cin.get();
	return 0;
}

bool is_name(char c) {
	return c == 'x' || c == 'y' || c == 'z';
}

bool is_open_bracket(char c)
{
	return c == '(' || c == '[' || c == '{';
}

bool is_clise_bracket(char c) {
	return c == ')' || c == ']' || c == '}';
}

bool is_operator(char c)
{
	return c == '+' || c == '-';
}

bool check_bracket(char st, char c)
{
	return (st == '(' && c == ')') || (st == '[' && c == ']') || (st == '{' && c == '}');
}

bool task(char* str)
{
	bool flag{ true };
	char* c{ str };
	Stack<char> stack;
	bool wait_term{ true };
	while (flag && *c != '\0') {
		if (*c != ' ') {
			if (wait_term && (is_name(*c) || is_open_bracket(*c))) {
				if (is_open_bracket(*c)) {
					stack.push(*c);
				}
				else {
					wait_term = false;
				}
			}
			else if (!wait_term && is_operator(*c)) {
				wait_term = true;
			}
			else if (!wait_term && is_clise_bracket(*c)) {
				if (stack.empty() || !check_bracket(stack.top(), *c)) {
					flag = false;
				}
				stack.pop();
			}
			else
				flag = false;
		}
		++c;
	}
	if (!stack.empty() || wait_term)
		flag = false;
	return flag;
}
