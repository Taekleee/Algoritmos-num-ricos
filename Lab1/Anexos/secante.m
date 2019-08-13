function [salida4]=secante(f,x0,x1,it,tol)
salida4 = [];
tic
error =100;
n = 0;
x2 = 0;
while error>tol && n<it
    n = n+1
    x2 = x1 -(x1-x0)*f(x1)/(f(x1)-f(x0));
    error = abs(f(x2));
    x0 = x1;
    x1 = x2;
    salida4 = [salida4,x2];

end
error= x1-x0
time=toc