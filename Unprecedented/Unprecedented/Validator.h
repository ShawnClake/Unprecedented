#ifndef __VALIDATOR__
#define __VALIDATOR__

using namespace std;

class Validator
{
	string numeric = "0123456789";
	string alpha = "abcdefghijklmnopqrstuvwxyz";
	string alphanumeric = numeric + alpha;
	string symbols = "!@#$%^&*()-=_+[]{}\|;':,./<>?~`";
	string english = alphanumeric + symbols;

public:

	static bool validate(const string& input, const string& regex)
	{
		auto passed = true;
		for (auto i = 0; i < int(input.length()); i++)
		{
			if (regex.find(input[i]) == string::npos)
			{
				passed = false;
				i = int(input.length());
			}
		}
		return passed;
	}

	bool isNumeric(const string& input) const
	{
		return validate(input, numeric);
	}

	bool isAlpha(const string& input) const
	{
		return validate(input, alpha);
	}

	bool isAlphaNumeric(const string& input) const
	{
		return validate(input, alphanumeric);
	}

	bool isSymbols(const string& input) const
	{
		return validate(input, symbols);
	}

	bool isEnglish(const string& input) const
	{
		return validate(input, english);
	}

	string strNumeric() const
	{
		return numeric;
	}

	string strAlpha() const
	{
		return alpha;
	}

	string strAlphaNumeric() const
	{
		return alphanumeric;
	}

	string strSymbols() const
	{
		return symbols;
	}

	string strEnglish() const
	{
		return english;
	}
};


#endif
