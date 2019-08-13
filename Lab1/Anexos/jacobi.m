function[y,err,costeT,costeE]=Jacobi(A,b)
tic
% y es vector solución
% err es el error final
% it es el numero de iteraciones final
% A matriz del sistema
% b vector del sistema
% maxiter es numero máximo de iteraciones
% epsilon es la cota del error
n=length(b);
x=zeros(n,1);
y=zeros(n,1);
[M,N] = size(A);
vector = [];
iter = 1;
f = @(s,m) s*1 + m*3;
costeE = 0;
%for m=1:M
%    row = abs(A(m,:));
%    d = sum(row) - row(m);
%    if row(m) <= d
%        error('A no es diagonal dominante');
%    end
%end
while finalizar(vector)
    for i=1:n
        S=0;
       for j=1:n
       if i~=j
        S=S+A(i,j)*x(j);
        costeE = costeE + f(1,1);
       end
       end
       y(i)=(b(i)-S)/A(i,i);
       costeE = costeE + f(1,1);
    end
    err=norm(x-y,1);
    vector(iter) = err;
    iter = iter+1;
    x=y;
    costeE = costeE+f(1,0);
end
costeT = toc
costeE = costeE
err = norm(A*x-b)
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