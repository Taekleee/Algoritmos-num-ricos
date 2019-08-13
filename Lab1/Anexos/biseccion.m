function [salida] = biseccion(a,b,nIters,fIn,tolerancia)
salida= []; 
tic

if fIn(a)*fIn(b)< 0
    disp('No existe raíz')
else 
    disp('Existe raiz')
end

h = (b+a)/2; 
contador = 1;
while abs(fIn(h)) > tolerancia && contador < nIters
    if fIn(a)*fIn(h)<0
        disp('Existe raiz parte izq')
        b = h;
    end
    if fIn(b)*fIn(h)<0
        disp('Existe raiz parte der')
        a = h;
    end
    c=h;
    h = (b+a)/2;
    salida = [salida,h];
    contador = contador+1;
end
error= c-h
final = h
time=toc
nIters= contador
end
