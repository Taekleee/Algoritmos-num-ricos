
#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <unistd.h>
using namespace std;

long double funcion(long double x);
long double tra(long double a,long double b);
long double s3(long double a,long  double b);


long double funcion(long double x){
	//return sqrt(x);
	return pow(2,x) - 2*x;
}
//Fórmula trapecio = (b-a) * (f(a) + f(b))/2
long double tra(long double a,long double b){
	long double I = (b-a)*(funcion(a) + funcion(b))/2;
	return I;
}

//Fórmula de simpson 1/3 = (b-a)*(f(a) + 4f(m) + f(b))/(3*n)
long double s3(long double a,long  double b){
	long double c = (b+a)/2;
	long double h = (b-a)/2;
	long double I = h*(funcion(a) + funcion(b) + 4*funcion(c))/3;
	return I;
}

//Fórmula de simpson 3/8 = (3h/8)*[f(a) + f(b) + 3f(a+2*b/3) + 3f(2a + b/3)] 
long double s8(long double a,long  double b){
	long double c = (2*a + b)/3;
	long double d = (a + 2*b)/3;
	long double h = (b-a)/3;
	long double I = 3*h*(funcion(a) + funcion(b) + 3*funcion(c) + 3*funcion(d))/8;
	return I;
}


/*Se ingresa el valor del intervalo y la tolerancia. De manera recursiva se comprueba si 
	S(a,b) = s(a,m) + s(m,b), ya que si el calculo del valor de la integral es igual, implica que el intervalo
	que se está utilizando no puede ser más exacto. En caso de que no se cumpla esto, se llama nuevamente a la funcion
	pero con los nuevos intervalos [a,m] y [m,b], siendo m el punto medio entre ambos.
	Cuando se llama nuevamente a la función, la tolerancia con la que se compara corresponde a la mitad de la anterior.
	Simpson adaptativo 1/3, 3/8 y trapecio funcionan de la misma manera, siendo trapecio el método que genera
	la mayor cantidad de iteraciones para llegar a la tolerancia solicitada


 */
long double simpsonAdaptativo(long double a,long  double b,long double tolerancia,int &contadorSimpson3){
	contadorSimpson3++;
	long double m = (a + b)/2;
	long double simpson = abs(s3(a,b)- s3(a,m) - s3(m,b));

	if(simpson < tolerancia){
		return s3(a,m) + s3(m,b);
	}
	else{
		return simpsonAdaptativo(a,m,tolerancia/2,contadorSimpson3) + simpsonAdaptativo(m,b,tolerancia/2,contadorSimpson3);
	}
}

long double simpsonAdaptativo8(long double a,long double b, long double tolerancia,int &contadorSimpson8){
	contadorSimpson8++;
	long double m = (a + b)/2;
	long double simpson = abs(s8(a,b)- s8(a,m) - s8(m,b));

	if(simpson < tolerancia){
		return s8(a,m) + s8(m,b);
	}
	else{
		return simpsonAdaptativo8(a,m,tolerancia/2,contadorSimpson8) + simpsonAdaptativo8(m,b,tolerancia/2,contadorSimpson8);
	}

}

long double trapecioAdaptativo(long double a, long double b, long double tolerancia,int &contadorTrapecio){
	contadorTrapecio++;
	long double m = (a+b)/2;
	long double trapecio = abs(tra(a,b) - tra(a,m) - tra(m,b));

	if(trapecio < tolerancia){
		return tra(a,m) + tra(m,b);
	}
	else{
		return trapecioAdaptativo(a,m,tolerancia/2,contadorTrapecio) + trapecioAdaptativo(m,b,tolerancia/2,contadorTrapecio);
	}
}




int main(int argc, char *argv[]){
	int d;
	long double inicio,final,tolerancia;
	string I;
    while( (d = getopt(argc, argv, "t:a:b:I:")) != -1){
      switch(d){
      	case 'I':
          I = optarg;
          break;
        case 't':
          tolerancia = atof(optarg);
          break;
        case 'a':
          inicio = atof(optarg);
          break;
        case 'b':
          final = atof(optarg);
          break;
        case '?':
          printf("Opción desconocida: %c\n",d);
        default:
          printf("parametros mal ingresados\n");
          return 1;
      }
  }
	int contadorTrapecio = 0;
	int contadorSimpson3 = 0;
	int contadorSimpson8 = 0;
	if(I.compare("trap")==0){
			long double b = trapecioAdaptativo(inicio,final,tolerancia,contadorTrapecio);
			cout << "Integral trapecio adaptativo: " <<b << "\n";
			cout << "Iteraciones trapecio adaptativo: " << contadorTrapecio<<"\n";
			}
	else if(I.compare("sim3") == 0){
			long double a = simpsonAdaptativo(inicio,final,tolerancia,contadorSimpson3);
			cout << "Integral Simpson adaptativo: " << a << "\n";
			cout << "Iteraciones simpson adaptativo 1/3: " << contadorSimpson3<<"\n";
			}
	else if(I.compare("sim8") == 0){
		long double c = simpsonAdaptativo8(inicio,final,tolerancia,contadorSimpson8);
		cout << "Integral Simpson adaptativo 3/8: " << c << "\n";
		cout << "Iteraciones simpson adaptativo 3/8: " << contadorSimpson8<<"\n";
		}


	return 0;

}