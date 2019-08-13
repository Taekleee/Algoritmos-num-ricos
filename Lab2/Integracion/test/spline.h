#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<fstream>

using namespace std;

typedef vector< long double> vec;

struct SplineSet{
    long double a;
    long double b;
    long double c;
    long double d;
    long double x;
};

long double spline(vec &x, vec &y, double distancia,string nombreArchivo, vec &f)
{
    int n = x.size()-1;
    vec a;
    a.insert(a.begin(), y.begin(), y.end());
    vec b(n);
    vec d(n);
    vec h;

    for(int i = 0; i < n; ++i)
        h.push_back(x[i+1]-x[i]);

    vec alpha;
    for(int i = 0; i < n; ++i)
     alpha.push_back( 3*(a[i+1]-a[i])/h[i] - 3*(a[i]-a[i-1])/h[i-1]  );

    vec c(n+1);
    vec l(n+1);
    vec mu(n+1);
    vec z(n+1);
    l[0] = 1;
    mu[0] = 0;
    z[0] = 0;

    for(int i = 1; i < n; ++i)
    {
        l[i] = 2 *(x[i+1]-x[i-1])-h[i-1]*mu[i-1];
        mu[i] = h[i]/l[i];
        z[i] = (alpha[i]-h[i-1]*z[i-1])/l[i];
    }

    l[n] = 1;
    z[n] = 0;
    c[n] = 0;

    for(int j = n-1; j >= 0; --j)
    {
        c[j] = z [j] - mu[j] * c[j+1];
        b[j] = (a[j+1]-a[j])/h[j]-h[j]*(c[j+1]+2*c[j])/3;
        d[j] = (c[j+1]-c[j])/3/h[j];
    }

    vector<SplineSet> output_set(n);
    for(int i = 0; i < n; ++i)
    {
        output_set[i].a = a[i];
        output_set[i].b = b[i];
        output_set[i].c = c[i];
        output_set[i].d = d[i];
        output_set[i].x = x[i];
    }
    long double diferencia; 
    long double sumatoria = 0; 
    long double error;
    ofstream archivo(nombreArchivo);
    long double resultado;
    long double valor = -200;
    int i = 0; int j = 0;
     while(valor <=200){
        if( x[i] <= valor && valor <= x[i] + distancia){
            //cout << "valor: " << valor << " xi " << x[i] <<"\n";

            resultado = output_set[i].a + output_set[i].b*valor + output_set[i].c* pow(valor,2) + output_set[i].d*pow(valor,3);
           // cout  << resultado << "\n";
            diferencia = pow((f[j] - resultado),2);
            sumatoria = sumatoria + diferencia;
            archivo << resultado <<"\n";
            //cout << output_set[i].a << "\t" << output_set[i].b << "\t" << output_set[i].c << "\t" << output_set[i].d << endl;
          //  cout << "valor: " << valor << "resultado " << resultado <<"\n";
            valor= valor + 0.05;
            j++;
        }
        else{
            i++;
        }

        //CALCULO DEL ERROR

}
 error = sqrt(sumatoria/j);
// cout << error << "\n";
 return error;
archivo.close();
}








