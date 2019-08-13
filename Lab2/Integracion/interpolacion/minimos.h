#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;
long double minimosC(int nDatos,vector <long double>  arrX1,vector <long double> arrY1, string nombreArchivo,vector <long double> f);
void coeficientes(vector <long double>x,vector <long double>y,long double **matriz,int grado,int nDatos);//Llena la matriz del sistema de ecuaciones de los coeficientes.
void recorrido(long double **matriz, int n,bool &op);//Recorre la matriz para resolverla por gauss jordan.
void reduccion (long double **matriz, int i, int j,int n);//Reducción gauss jordan a ceros.
bool mdiagonal(long double **matriz, int n);//Valída la matriz digonal antes de reducirla a unos.
void rauno(long double **matriz,int n);//Reduduccion de la matriz diagonal a unos.
long double imp(long double **matriz, int n,bool op, string nombreArchivo,vector <long double>f);//Impresion de los resultados.

void coeficientes(vector <long double>x,vector <long double>y,long double **matriz,int grado,int nDatos)
{ 
	long double *s=new long double[(2*grado)+1];
	double suma;
    //Se calculan las potencias de los datos
	for(int k=0; k < 2*grado+1; k++){
		suma=0.0;
		for(int i=0; i < nDatos; i++)
			suma+=pow(x[i], k);
		s[k]=suma;
	}
    //Calcula las sumas y se agregan los datos a la matriz
	for(int k=0; k<grado+1; k++){
		suma=0.0;
		for(int i=0; i < nDatos; i++)
			suma+=pow(x[i], k)*y[i];
		matriz[k][grado+1]=suma;
	}  
	for(int i=0; i < grado+1; i++){
		for(int j=0; j < grado+1; j++)
			matriz[i][j]=s[i+j];
	}
}


//Se resuelve la Matriz por Gauss-Jordan
void recorrido(long double **matriz, int n,bool &op){
	int i,j,k=0;
	for (j = 0; j < n-1; ++j){
		for (i = n-1; i >k ; --i){
			if(mdiagonal(matriz,n))
				rauno(matriz,n);
			reduccion(matriz,i,j,n);
		}
		k++;
	}
	for (j = n-1;  j> 0; j--){
		for (i = 0; i < k; ++i){
			if(mdiagonal(matriz,n))
				rauno(matriz,n);
			reduccion(matriz,i,j,n);		
		}
		k--;
	}
	for (i = 0; i < n; ++i){
		if(matriz[i][i]==0)
			op=true;
	}
	if (!op&&mdiagonal(matriz,n))
		rauno(matriz,n);
}

void reduccion(long double **matriz,int i,int j,int n)
{
	long double *ra=new long double[n+1];
	int k;
	for (k = 0; k < n+1; ++k)
		ra[k]=((matriz[i][k]*matriz[j][j])-(matriz[j][k]*matriz[i][j]));
	for (int k = 0; k < n+1; ++k)
		matriz[i][k]=ra[k];
}

//Se verifica que la matriz no tenga diagonal nula, para poder utilizar Gauss-Jordan
bool mdiagonal(long double **matriz, int n)
{
	bool op=false;
	int i;
	for (i = 0; i < n; ++i){
		if(matriz[i][i]!=1)
			op=true;
	}
	for (i = 0; i < n; ++i){
		if (matriz[i][i]==0)
			op=false;
	}
	return op;
}

//La diagonal se reduce a unos
void rauno(long double **matriz,int n)
{
	int i,j;
	long double aux;
	for (i = 0; i < n; ++i){
		aux=matriz[i][i];
		for (j = 0; j < n+1; ++j)
			matriz[i][j]=(matriz[i][j]/aux);
	}
}

//Se imprime el resultado por pantalla
long double imp(long double **matriz, int n,bool op,string nombreArchivo, vector <long double>f){
	long double polinomio[4];
	long double interpolacion;
	long double diferencia; 
	long double sumatoria = 0;
	long double error;
	int k = 0;
		for (int i = 0; i < n; ++i){
				polinomio[i] = matriz[i][n];
			//	cout << polinomio[i] << "\n";

			}
		ofstream archivo(nombreArchivo);
		 if(archivo.is_open()){
			for(double j = -200; j <=200; j = j + 0.05){
				interpolacion = polinomio[0] + polinomio[1]*j + polinomio[2]*pow(j,2) + polinomio[3]* pow(j,3);
				archivo << interpolacion <<"\n";
				//**************CALCULO DEL ERROR**********
				diferencia = pow(f[k] - interpolacion,2);
				sumatoria = sumatoria + diferencia;
				k++;
			//	cout << interpolacion << "\n";

			}

		}
		error = sqrt(diferencia/(k+1));
		//cout << error << "\n";
		archivo.close();
		return error;
	
}


long double minimosC(int nDatos,vector <long double>  arrX1,vector <long double>arrY1, string nombreArchivo, vector <long double> f){
   bool op=false;
        int grado = 3; //Grado del polinomio que se busca 
        long double **matriz=new long double*[grado+1];
        for (int j = 0; j < grado+1; ++j)
            matriz[j]=new long double[grado+2];
        coeficientes(arrX1,arrY1,matriz,grado,nDatos);
        recorrido(matriz,grado+1,op);
        long double error = imp(matriz,grado+1,op, nombreArchivo, f);
        return error;
}


	
