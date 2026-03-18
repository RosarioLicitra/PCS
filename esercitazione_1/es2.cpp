#include <iostream>
#include <fstream>
#include <string>



int main(int argc, const char *argv[])
{
	if(argc < 2) {
		std::cerr << "Errore: Nome File non passato da linea di comando\n";
		return 1;
		} //Controllo che il nome del file sia passato da linea di comando
	
	std::ifstream ifs(argv[1]);
	
	if(!ifs.is_open()){
		std::cerr << "Errore nell'apertura del file" << argv[1] << std::endl;
		return 1;
	} //Controllo che il file si apra
	std::string citta;
	double t1, t2, t3, t4;
	while( ifs >> citta >> t1 >> t2 >> t3 >> t4 ){
		
		double media = (t1+t2+t3+t4)/4.0;
		std::cout << "La temperatura media di " << citta << ":" << media << "\n";
		
		}
	
return 0;
}