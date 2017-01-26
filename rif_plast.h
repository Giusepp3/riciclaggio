#ifndef RIF_PLAST_H
#define RIF_PLAST_H
#include <iostream>
#include <cstring>
#include <fstream>
#include "rifiuti.h"
#include "bad_code.h"

using namespace std;

namespace riciclaggio{
	
	class rifiuto_plastica : public rifiuto{
		private:
			bool trasp;
			virtual void ck_code(const char* code)throw(bad_code);
		public:
			rifiuto_plastica(const char*, const double, const bool);
			rifiuto_plastica(const rifiuto_plastica &);
			const rifiuto_plastica& operator=(const rifiuto_plastica&);
			virtual double calcola_valore(const double peso)const;
			void set_code(const char* code);
			void set_trasp(const bool t){trasp=t;}
			bool get_trasp()const{return trasp;}
		
		
	};
	
	
	
	
	
	
	
	
	
	
	
	
	
}


#endif //RIF_PLAST_H
