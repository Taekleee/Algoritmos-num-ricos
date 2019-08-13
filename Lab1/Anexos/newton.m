function [salida5] = newton(a,f,fder,it,tol)
salida5 = [];
tic
error =75;
n = 0;
while n<it && error>tol
    b= a;
    a = a-(f(a)/fder(a));
    n = n+1
    error = abs(f(a));
    salida5 = [salida5,a];
end
error= b-a
time= toc
contador=n
end