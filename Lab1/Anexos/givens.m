function [x,error,costeT,costeE] = givens(A,b)
tic
[M,N] = size(A);
Q = eye(M);
R = A;
for i=1:N
    for k=i+1:M
        if R(k,i) ~= 0
            raiz  = sqrt(R(k,i)^2+R(i,i)^2);
            S = -R(k,i)/raiz;
            C = R(i,i)/raiz;
            G = eye(M);
            G(i,i)=C;
            G(k,k)=C;
            G(k,i)=-S;
            G(i,k)=S;
            Q = Q*G;
            R=G'*R;
        end
    end
end

Y = Q'*b;
x = R\Y;
costeT=toc
costeE=M*(2*M+7+2*M^2);
error = norm(A*x-b);
end