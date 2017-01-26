#include "rifiuti.h"

using namespace std;

namespace riciclaggio{
	
	rifiuto::rifiuto(){
		cod = new char[1];
		strcpy(cod,"");
		peso = 0.0;
	}
	
	rifiuto::rifiuto(const char* code, const double p){
		cod = new char[strlen(cod)+1];
		strcpy(cod,code);
		peso = p;
	}
	
	rifiuto::~rifiuto(){
		delete [] cod;
	}
	
	void rifiuto::set_peso(const double p){
		peso = p;
	}
	
	void rifiuto::print(ostream & of)const{
		of << cod << ' ' << peso << ' ';
	}
	
	void rifiuto::read(istream & in){
		char buff[800];
		in.getline(buff,799);
		set_code(buff);
		in >> peso;
	}
	
	void rifiuto::set_code(const char* code){
		if(cod) delete [] cod;
		cod = new char[strlen(code)+1];
		strcpy(cod,code);
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
