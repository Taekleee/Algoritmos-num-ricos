function [x,err,costeT,costeE] = householder(A,b)
tic
n = size(A,1);
Q = eye(n);
R = A;
I = eye(n);
f = @(s,m,sM,mM,mV) s*1 + m*3 + 10*sM+15*mM + 5*mV;
costeE = 0;
for j = 1:n-1
    x=R(j:n,j);
    v=-sign(x(1))*norm(x)*eye(n-j+1,1)-x;
    costeE = costeE + f(1,2,0,1,0);
    if norm(v)>0
        v=v/norm(v);
        P = I;
        P(j:n,j:n)=P(j:n,j:n)-2*v*v';
        R=P*R;
        Q=Q*P;
        costeE = costeE + f(1,2,1,2,2);
    end
end
y = Q'*b;
x = R\y;
costeT = toc
costeE = costeE;
err = norm(A*x-b);
end