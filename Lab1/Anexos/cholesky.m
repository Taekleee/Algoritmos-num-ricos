function [solucion,err,costeT,costeE] = cholesky(A,b)
tic
f = @(s,m,sM,mM) s*1 + m*3 +10*sM+15*mM;
n = length(A);
L = zeros(n,n);
costeE = 0;
for i=1:n
    L(i,i) = sqrt(A(i,i)-L(i,:)*L(i,:)');
    costeE = costeE + f(0,1,1,1);
    for j=(i+1):n
        L(j,i) = (A(j,i) - L(i,:)*L(j,:)')/L(i,i);
        costeE = costeE + f(0,0,1,2);
    end
end

y = L\b;
solucion = L'\y;
costeT = toc
costeE = costeE
err = norm(A*solucion-b)


end

    