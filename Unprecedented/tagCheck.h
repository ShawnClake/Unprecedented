#ifndef __TAG_CHECK__
#define __TAG_CHECK__

#include <string>
#include <stack>
#include "tags.h"

using namespace std;

class TagCheck : public Tags {

private:
	bool balanced;

public:
	TagCheck(const string& input)
	{

		char symbol;
		balanced = true;
		char openSymbol;
		stack<char> stack;

		for (int i = 0; i < (int)input.length(); i++) {

			symbol = input[i];

			if (IsOpen(symbol))
				stack.push(symbol);

			else if (IsClosed(symbol))
			{
				if (stack.empty())
					balanced = false;
				else
				{
					openSymbol = stack.top();
					stack.pop();
					balanced = Matches(symbol, openSymbol);
				}
			}

			if (!balanced) {
				i = (int)input.length();
			}

		}

		if (!stack.empty())
			balanced = false;

		/*if (balanced)
			cout << "Expression is well formed." << endl;
		else
			cout << "Expression is not well formed." << endl;
		return 0;*/
	}

	bool isBalanced() {

		return balanced;

	}

private: 


};


#endif