#ifndef RIF_CART_H
#define RIF_CART_H
#include <iostream>
#include <cstring>
#include <fstream>
#include "rifiuti.h"
#include "bad_code.h"

using namespace std;

namespace riciclaggio{
	
	class rifiuto_carta : public rifiuto{
		private:
			bool umida;
			virtual void ck_code(const char* code)throw(bad_code);
		public:
			rifiuto_carta(const char* code, const double peso, const bool um);
			rifiuto_carta(const rifiuto_carta &);
			const rifiuto_carta & operator=(const rifiuto_carta&);
			void set_code(const char* code);
			void set_umid(const bool um){umida = um;}
			bool get_umid()const{return umida;}
			virtual double calcola_valore(const double peso)const;
			
	};
	
	
	
	
	
	
}

#endif //RIF_CART_H
