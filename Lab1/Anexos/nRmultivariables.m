%Para tres variables solo es necesario agregar una variable.
function [jac] = nRmultivariables(f1,f2,x,y,tol)
tic
c = [];
error = 100;
%Como h debe tender a 0, se le asigna un valor pequeño para así simular la
%derivada
h = 0.000000000000005    
%Se genera una matriz llamada jac, la cual representa al jacobiano evaluado
%en el punto
it=1;
while error > tol
    jac = [(f1(x+h,y)-(f1(x,y)))/h (f1(x,y+h)-(f1(x,y)))/h ;(f2(x+h,y)-(f2(x,y)))/h (f2(x,y+h)-(f2(x,y)))/h ];
    inversa =inv(jac);
    fev = [f1(x,y); f2(x,y)];
    fila = 2;
    columna = 2;
    %Se calcula la multiplicación de la matriz jacobiana inversa por las
    %funciones evaluadas en los puntos
        for i=1:fila
            suma = 0;
            for j = 1:columna
                suma= suma + inversa(i,j)*fev(j,1); 
            end
            c = [suma];
        end

        num = [x; y];
        resul = num - c;
        x = resul(1)
        y = resul(2)
        error = abs(sum(c))
        it=it+1
end
time= toc
end