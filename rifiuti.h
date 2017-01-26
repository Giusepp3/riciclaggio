#ifndef RIFIUTI_H	
#define RIFIUTI_H
#include <iostream>
#include <cstring>
#include <fstream>
#include "bad_code.h"

using namespace std;

namespace riciclaggio{
	
	class rifiuto{
		private:
			char* cod;
			double peso;
			virtual void print(ostream & of)const;
			virtual void read(istream & in);
			virtual void ck_code(const char* code) throw(bad_code)=0;
		public:
			rifiuto();
			rifiuto(const char* cod, const double peso);
			~rifiuto();
		//	rifiuto(const rifiuto &);
		//	const rifiuto& operator=(const rifiuto&);
			void set_code(const char* code);
			void set_peso(const double p);
			char* get_cod()const{return cod;}
			double get_peso()const{return peso;}
			virtual double calcola_valore(const double peso)const=0;
			
			
	};
	
	
	
	
	
	
	
	
	
}


#endif //RIFIUTI_H
