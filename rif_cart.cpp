#include "rif_cart.h"

using namespace std;

namespace riciclaggio{
	
	rifiuto_carta::rifiuto_carta(const char* code, const double p, const bool um) : rifiuto(code,p){
		umida=um;
	}
	
	rifiuto_carta::rifiuto_carta(const rifiuto_carta & rc) : rifiuto(rc){
		umida=rc.umida;
	}
	
	const rifiuto_carta& rifiuto_carta::operator=(const rifiuto_carta & rc){
		if(this==&rc) return *this;
		set_code(rc.get_cod());
		set_peso(rc.get_peso());
		umida=rc.umida;
		return *this;
	} 
	
	
	void rifiuto_carta::ck_code(const char* code)throw(bad_code){
		char * temp=new char[strlen(this->get_cod())+1];
		strcpy(temp,this->get_cod());
		if(!(((int)temp[0]==2 || (int)temp[0]==3) && ((int)temp[1]>=0&&(int)temp[1]<=9))){
			throw bad_code(code);
		}
		else rifiuto::set_code(code);
	}
	
	void rifiuto_carta::set_code(const char* code){
		try{
			ck_code(code);
		}catch(bad_code b){
			cout << "si è verificato un errore! " << b;
		}
	}
	
	
	
	double rifiuto_carta::calcola_valore(const double peso)const{
		if(umida){
			return 0.10*(this->get_peso()/1000);
		}
		else return 0.01*this->get_peso();
	}
	
}
