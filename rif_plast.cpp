#include "rif_plast.h"

using namespace std;
namespace riciclaggio{
	
	
	void rifiuto_plastica::ck_code(const char* code)throw(bad_code){
		char * temp=new char[strlen(this->get_cod())+1];
		strcpy(temp,this->get_cod());
		if(!(((int)temp[0]==1 || (int)temp[0]==0) && ((int)temp[1]>=0&&(int)temp[1]<=9))){
			throw bad_code(code);
		}
		else rifiuto::set_code(code);
	}
	
	void rifiuto_plastica::set_code(const char* code){
		try{
			ck_code(code);
		}catch(bad_code b){
			cout << "si è verificato un errore! " << b;
		}
	}
	
	double rifiuto_plastica::calcola_valore(const double peso)const{
		if(trasp){
			return 0.01*this->get_peso();
		}
		else return 0.05*this->get_peso();
	}
	
	rifiuto_plastica::rifiuto_plastica(const char* code, const double p, const bool tr) : rifiuto(code,p){
		trasp = tr;
	}
	
	rifiuto_plastica::rifiuto_plastica(const rifiuto_plastica  & rp) : rifiuto(rp){
		trasp=rp.trasp;
	}
	
	const rifiuto_plastica& rifiuto_plastica::operator=(const rifiuto_plastica& rp){
		if(this==&rp) return *this;
		set_code(rp.get_cod());
		rifiuto::set_peso(rp.get_peso());
		trasp=rp.trasp;
		return *this;
	}
	
	
	
	
	
	
}
