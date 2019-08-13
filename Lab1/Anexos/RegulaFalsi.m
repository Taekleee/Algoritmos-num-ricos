function[salida] = RegulaFalsi(a,b,nIters,fIn,tolerancia)
salida= []; 
tic

if fIn(a)*fIn(b)< 0
    disp('No existe raíz');
else 
    disp('Existe raiz');
end

c = abs((a*fIn(b)-b*fIn(a))/(fIn(b)-fIn(a)));
contador = 1;
while abs(fIn(c)) > tolerancia  && contador < nIters
    if fIn(a)*fIn(c)<0
        disp('Existe raiz parte izq');
        b = c;
    end
    if fIn(b)*fIn(c)<0
        disp('Existe raiz parte der');
        a = c;
    end
    d= c
    c = abs((a*fIn(b)-b*fIn(a))/(fIn(b)-fIn(a)));
    
    salida = [salida,c];
    contador = contador+1;
end
error= d-c
time=toc
iteraciones= contador
end
