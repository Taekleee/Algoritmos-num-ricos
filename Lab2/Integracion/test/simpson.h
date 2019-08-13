#include <iostream>
#include <vector>
vector<long double> abrirArchivo2(string );

long double simpson(string nombre);

 // a y b son los valores iniciales y finales del intervalo respectivamente
//Tamaño corresponde al numero de particiones que se generan
 long double simpson(string nombre){
    vector<long double> y = abrirArchivo2(nombre);
    long double b = 200;
    long double a =-200;
    int tamano = 8000;

    long double sum = 0;
    if(tamano%2 == 0){
        long double factor = 3.0*(b - a)/(tamano*8.0);
        for(int i = 0; i+1 < tamano; i+=3){
            sum+=y[i] + 3*y[i+1] + 3*y[i+2] + y[i+3];
        }
        return sum*factor;
    }
    else{
        long double factor = (b - a)/(tamano*3.0);
        for(int i = 0; i+1 < tamano; i+=2){
            sum+=y[i] + 4*y[i+1] + y[i+2];
        }
        long double resultado = sum*factor;
        return resultado;
    }
}
vector<long double> abrirArchivo2(string nombre){
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
