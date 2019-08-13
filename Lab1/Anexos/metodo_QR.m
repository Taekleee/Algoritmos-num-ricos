function [X,err,costeT,costeE] = metodo_QR(A,b)
tic
f = @(s,m,sM,mM) s*1 + m*3+10*sM+15*mM;
[m, n] = size(A);
R = zeros(n, n);
V = A;
Q=zeros(m, n);
costeE = 0;
for i =1:n
    R(i,i)= norm(V(:,i));
    Q(:,i)= V(:,i)/R(i,i);
    costeE = costeE + f(1,0,0,1);
    for j=i+1:n
       R(i,j)= (Q(:,i)')*V(:,j);
       V(:,j)=V(:,j) - R(i,j)*Q(:,i);
       costeE = costeE + f(0,0,1,2);
    end
   
end

Y = Q'*b;
X = R\Y;
costeT=toc
costeE= costeE;
err = norm(A*X-b);
end
    