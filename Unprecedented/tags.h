#ifndef __TAGS__
#define __TAGS__



class Tags {

private:


public:
	bool IsOpen(char symbol)
	{
		if (symbol == '(' || symbol == '{' || symbol == '[' || symbol == '<')
			return true;
		else
			return false;
	}

	bool IsClosed(char symbol)
	{
		if (symbol == ')' || symbol == '}' || symbol == ']' || symbol == '>')
			return true;
		else
			return false;
	}

	bool Matches(char symbol, char openSymbol)
	{
		return  ((openSymbol == '(' && symbol == ')')
			|| (openSymbol == '{' && symbol == '}')
			|| (openSymbol == '[' && symbol == ']')
			|| (openSymbol == '<' && symbol == '>'));
	}

};


#endif
