function [x,err,costeT,costeE]=gseidel(A,b)
n=max(size(A));         % Obtenemos de la matriz A
                        % el número de ecuaiones
                        % y por ende de incognitas.
c=diag(A);              % Almacenamos en 'c' los elementos
                        % de la diagonal principal.
d=1;
i=1;
while (d~=0)&&(i<n)     % revisamos si en la diagonal principal 'c'
    d=c(i,1)*c(i+1,1);  % existe algún elemento igual a 0.
    i=i+1;              % En caso de que lo haya
end                     % salir del bucle y d=0.

while d==0              % Si se ha detectado algún cero en la
    B(1,:)=A(n,:);      % diagonal principal se entra en este bucle
    U(1,1)=b(n,1);      % para así cambiar las filas. Se alternarán
    for i=2:n           % las filas hasta que todos los elementos
        B(i,:)=A(i-1,:);% de la diagonal principal
        U(i,1)=b(i-1,1);% sean distintos de cero.
    end                 % Todo esto para evitar una división
    A=B;                % por cero. Aunque se recomienda
    b=U;                % siempre ordenar las ecuaciones apriori.
    c=diag(A);
    d=1;i=1;
    while (d~=0)&&(i<n)
        d=c(i,1)*c(i+1,1);
        i=i+1;
    end
end

% Se selecciona un vector X(n,1) sólo para evaluar
% el error en la primera iteración.
for i=1:n
    X(i,1)=b(i,1)/A(i,i);
end
tic
costeE = 0;
f = @(s,m) s*1 + m*3;
% se sespecifica el vector x(n,1) con valores iguales a cero
% para iniciar las iteraciones.
x=zeros(n,1);
iter=1;
vector = [];
% Se inician las iteraciones
while finalizar(vector)
    for i=1:n
        if i==1
            sum=0;
            for j=i+1:n
                sum=A(i,j)*x(j,1)+sum;
                costeE = costeE + f(1,1);
            end
            x(i,1)=(b(i,1)-sum)/A(i,i);
            costeE = costeE + f(1,1); 
        end
        if i==n
            sum=0;
            for j=i-1:-1:1
                sum=A(i,j)*x(j,1)+sum;
                costeE = costeE + f(1,1);
            end
            x(i,1)=(b(i,1)-sum)/A(i,i);
            costeE = costeE + f(1,1);
        end
        if 2<=i<=n-1
            sum1=0;
            for j=i+1:n
                sum1=A(i,j)*x(j,1)+sum1;
                costeE = costeE + f(1,1);
            end
            sum2=0;
            for j=i-1:-1:1
                sum2=A(i,j)*x(j,1)+sum2;
                costeE = costeE + f(1,1);
            end
            x(i,1)=(b(i,1)-sum1-sum2)/A(i,i);
            costeE = costeE + f(2,1);
        end
    end

    err=norm(x-X,1);
    vector(iter) = err;
    X=x;
    iter=iter+1;
end
costeE = costeE
costeT = toc
err = norm(A*x - b)

end




function bool = finalizar(vector)
format long
if length(vector)>2
    c = length(vector);
    if norm(vector(c)) == norm(vector(c-1))
        bool = false;
    else
        bool = true;
    end
else
    bool = true;
end
end