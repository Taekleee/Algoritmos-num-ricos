#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

long double trapecio(string nombreArchivo);
vector<long double> abrirArchivo(string nombre);

long double trapecio(string nombreArchivo){
	vector <long double> f = abrirArchivo(nombreArchivo);
    int largo;
    double h = 0.5;
		largo=8000;

		long double suma= f[0]+ f[largo-1];
		for(int i=1; i<largo-1;i++){
			suma+=2*f[i];
		}
		long double resultado= h*suma/2;
		//cout << resultado;
		return resultado;

}


vector<long double> abrirArchivo(string nombre){
		  string line;
          int largo = 8000;
		  ifstream myfile(nombre.c_str());
		  vector<long double> info (largo);
		  if (myfile.is_open())
		  {
		  	int i=0;
		    while ( getline (myfile,line) ){
		   	  long double numero = atof(line.c_str());
		      info[i] = numero;
		      i++;
		    }
		    myfile.close();
		  }
		  else
		  	 cout << "Unable to open file";
		  return info;
		}
