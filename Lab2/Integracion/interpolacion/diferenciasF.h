//
//  diferenciasF.h
//  
//
//  Created by Catalina Morales on 26-07-18.
//

#include <iostream>
#include <cmath>
#include <fstream>
//Para este caso, los valores ingresados de x deben ser exidistantes
//Este método entrega de manera inmediata el valor del punto ingresado xi, evaluado en la función P(x) encontrada
using namespace std;

long double diferenciasFinitas(int,vector <long double> , vector <long double> , long double *);

long double diferenciasFinitas(int nDatos,vector <long double> x, vector <long double> y,string nombreArchivo, vector <long double> f){
    ofstream archivo(nombreArchivo);
    
    long double tablaDiferencias[nDatos][nDatos]; //Matriz con tabla de diferencia
    long double  xt;
    long double yi;
    
    //Se ingresan los primeros valores a la tabla de diferencias
    for(int i=0; i< nDatos; i++){
        tablaDiferencias[i][0] = y[i]; //Valores iniciales
  //      cout << tablaDiferencias[i][0] << "\n";
    }
    
    for(int j=1; j < nDatos; j++){
        for(int i=0; i<nDatos - j; i++){
            // se calculan los datos de la tabla, reduciendo así los térmminos
            tablaDiferencias[i][j] = (tablaDiferencias[i+1][j-1] - tablaDiferencias[i][j-1]);
           // cout << tablaDiferencias[i][j] << "\n";
        }
    }
    //  cout << "pasa2 \n";
    
    
    //interpolación
    long double interpolacion[8001];
    long double error;

    
    //Calculo de la interpolación
    long double h = x[1] - x[0];
    
    if(archivo.is_open()){
         long double diferencia; 
         long double sumatoria = 0; 
         int i = 0;
        for(long double k = -200; k <= 200; k = k + 0.05){
            long int factorial = 1;
            int expo = 1;
            xt = 1;
            yi = tablaDiferencias[0][0]; //Parte con el primer elemento de la tabla
            //    cout << "pasa3 \n";
            
            for(int j = 0; j < nDatos-1; j++){
                //Se evalúan los valores en el polinomio, mediante la fórmula F[x0,...,...,xn] = (A^(n)y0)/(h^k * k!)
                // h = distancia entre un punto y otro
                // A^(n)y0 =  A^(n-1)y(j+1) - A^(n-1)Yj
                // K = nº puntos - 1
                
                xt = xt*(k-x[j]);
                yi = yi + (tablaDiferencias[0][j+1]*xt)/(pow(h,expo) * factorial);
                factorial = factorial * (factorial + 1);
                expo++;
                
            }
            
           // cout << yi << "\n";
            archivo << yi << endl;
            //********CALCULO DEL ERROR********
            diferencia = pow((f[i] - yi),2);
            sumatoria = sumatoria + diferencia;
            i++;
            //********CALCULO DEL ERROR********
        }
         error = sqrt(sumatoria/(i+1));
       //   cout << error << "\n";
        //**********CALCULO DEL ERROR**********

    }
        archivo.close();
        return error;
        
    }
