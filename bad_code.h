#ifndef BC_H
#define BC_H
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class bad_code{
	private:
		static string code;
		static string message;
	public:
		bad_code(const string a, const string b){code=a; message=b;}
		bad_code();
		bad_code(const string a){code = a; message = "Errore generico!";}
		friend ostream& operator<<(ostream & os, const bad_code & b){ os << code << ' ' << message << ' '; return os;}
};

#endif //BC_H


