function [x,err,costeT,costeE]=LUdoolitle(a,b)
tic
f = @(s,m) s*1 + m*3 ;
n=length(a);
l=a*0; u=a*0;
costeE = 0;

for k=1:n

    u(k,k:n)=a(k,k:n)-l(k,1:k-1)*u(1:k-1,k:n);

    l(k,k)=1;

    l(k+1:n,k)=(a(k+1:n,k)-l(k+1:n,1:k-1)*u(1:k-1,k))/u(k,k);
    costeE = costeE + f((n-k)*2,(n-k)*4);

end

y = l\b;
x = u\y;
costeT=toc
costeE=costeE
err = norm(a*x-b)
end