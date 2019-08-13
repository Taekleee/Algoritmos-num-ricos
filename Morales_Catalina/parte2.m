%n = cantidad de intervalos
%a = número de filas matriz
%constante = -(g0*r^2)/k
%te = temperatura de la superficie 
%Luego de despejar, se sabe que G0/k = 50
n = 20;
a = 2;
b = 1;
constante = -((1/n)^2)*50;
te=50;

%Se crea la matriz que contendrá los valores de los coeficientes.
%vector es b
matriz = zeros(n,n);
vector = zeros(n,1);

% se llena la matriz con los valores iniciales, asumiendo que t1-t0 = A/2
matriz(1,1) = -1;
matriz(1,2) = 1;
vector(1,1) = constante/2;

%Se llena la matriz, variando el valor de las columnas, mediante la
%ecuación n*ti+1 - 2*nTi + nTi-1 + Ti+1 -Ti = -n*G0(delta r)/K
%Por lo que parte ti = -2nTi - Ti => -2n-1
% ti+1 = Ti+1 + nTi+1 => 1 + n
% ti-1 = nTi-1 => n
while a < n
    matriz(a,b+1) = -2*(a-1)-1;
    matriz(a,b+2) = a;
    matriz(a,b) = a-1;
    vector(a,1) = constante*(a-1);
    b = b+1;
    a = a+1;
end

%Se llenan los últimos valores de la matriz, junto con el último valor del
% vector que es conocido, lo cual permite resolver la ecuación Ax = b
%  -(N-1) - Te*N (a == n)
matriz(a,b) = a-1;
matriz(a,b+1) = -2*(a-1)-1;
vector(a,1) = (a-1)*constante-a*te;

matriz;
vector;
%Se resuelve el sistema de ecuaciones
x = linsolve(matriz,vector)
%Se grafica
cylinder(x)
