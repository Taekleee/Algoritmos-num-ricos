#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <armadillo>
//Este método entrega de manera inmediata el valor del punto ingresado xi, evaluado en la función P(x) encontrada
using namespace std;

long double diferenciasDivididas(int,vector <long double> , vector <long double>,string,vector<long double> );

long double diferenciasDivididas(int nDatos,vector <long double> x, vector <long double> y,string nombreArchivo,vector <long double>  f){
    ofstream archivo(nombreArchivo);
    
	long double tablaDiferencias[nDatos][nDatos]; //Matriz con tabla de diferencia
	long double  xt;
	long double yi;

//Se ingresan los primeros valores a la tabla de diferencias
	for(int i=0; i< nDatos; i++){
		tablaDiferencias[i][0] = y[i]; //Valores iniciales
	}

	for(int j=1; j < nDatos; j++){
		for(int i=0; i<nDatos - j; i++){
			// se calculan los datos de la tabla, reduciendo así los térmminos
			// de manera "diagonal"
			tablaDiferencias[i][j] = (tablaDiferencias[i+1][j-1] - tablaDiferencias[i][j-1])/ (x[i+j] - x[i]);
		}
	}


	//interpolación
    long double interpolacion[8001];
    
  long double diferencia; 
  long double sumatoria = 0; 
  long double error;
    
  if(archivo.is_open()){
      int i = 0;
      // Se toman los datos de la tabla y se reemplazan en P(x) = f[x] + f[x0,x1](x-x0) + ...+ f[x0,...,xn](x-x0)(x-xn) para entregar la interpolación.
      for(long double k = -200; k <= 200; k = k + 0.05){
      xt = 1;
      yi = tablaDiferencias[0][0]; //Parte con el primer elemento de la tabla

      for(int j = 0; j < nDatos-1; j++){
          xt = xt*(k-x[j]);
          yi = yi + tablaDiferencias[0][j+1]*xt;
          
      }
      //  cout << yi << "\n";
          archivo << yi << "\n";

          //********CALCULO DEL ERROR********
          diferencia = pow((f[i] - yi),2);
          sumatoria = sumatoria + diferencia;
          i++;
          //********CALCULO DEL ERROR********
      }
      error = sqrt(sumatoria/(i+1));
     // cout << error << "\n";

      //**********CALCULO DEL ERROR**********
    }
       archivo.close();
  	return error;

  }
