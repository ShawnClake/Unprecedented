#ifndef __VALIDATOR__
#define __VALIDATOR__

#include <string>

using namespace std;

class Validator {

private:
	string numeric = "0123456789";
	string alpha = "abcdefghijklmnopqrstuvwxyz";
	string alphanumeric = numeric + alpha;
	string symbols = "!@#$%^&*()-=_+[]{}\|;':,./<>?~`";
	string english = alphanumeric + symbols;

public:

	bool validate(const string& input, const string& regex) { bool passed = true; for (int i = 0; i < (int)input.length(); i++) { if (regex.find(input[i]) == string::npos) { passed = false; i = (int)input.length(); } } return passed; }
	bool isNumeric(const string& input) { return validate(input, numeric); }
	bool isAlpha(const string& input) { return validate(input, alpha); }
	bool isAlphaNumeric(const string& input) { return validate(input, alphanumeric); }
	bool isSymbols (const string& input) { return validate(input, symbols); }
	bool isEnglish(const string& input) { return validate(input, english); }

	string strNumeric() {

		return numeric;

	}

	string strAlpha() {

		return alpha;

	}

	string strAlphaNumeric() {

		return alphanumeric;

	}

	string strSymbols() {

		return symbols;

	}

	string strEnglish() {

		return english;

	}



};


#endif