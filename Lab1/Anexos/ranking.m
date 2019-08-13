function [tiempos,errores]= ranking(A,B,eficiencia,eficacia)
tiempos=[];
errores=[];
ranking=[];
eficiencia = eficiencia/100;
eficacia = eficacia/100;
tolerancia = 0;
[solucionLU,errorLU,tiempoLU,costoELU ]=LUdoolitle(A,B); %B
[solucion,errorCH,tiempoCH,costoECH] = cholesky(A,B); %B
[solucion,errorJ,tiempoJ,costoEJ]=jacobi(A,B)
[solucion,errorGS,tiempoGS,costoEGS]=gseidel(A,B) %B
[solucion,errorQR,tiempoQR,costoEQR] = metodo_QR(A,B)
[solucion,errorH,tiempoH,costoEH] = householder(A,B)
[solucion,errorG,tiempoG,costoEG] = givens(A,B) %B
metodos = {'LU','Cholesky','Jacobi','Gauss-Seidel','QR','Householder','Givens'}
tiempos=[tiempoLU,tiempoCH,tiempoJ,tiempoGS,tiempoQR,tiempoH,tiempoG]
errores=[errorLU,errorCH,errorJ,errorGS,errorQR,errorH,errorG]
costosE=[costoELU, costoECH,costoEJ,costoEGS,costoEQR,costoEH,costoEG]
maxT= max(tiempos);
maxE= max(costosE);
errorMax = max(errores);
i=0;
for i=1:7
    tiempos(i) = tiempos(i)/maxT;
    costosE(i) = costosE(i)/maxE;
    ranking = [ranking,errores(i)*eficiencia/errorMax + (tiempos(i)*(eficacia/2))+(costosE(i)*(eficacia/2))];
    %ranking = [ranking,errores(i)*perErr/errorMaximo + costesT(i)*perEf];
end
maximoR = max(ranking);
for i=1:7
    ranking(i) = (1-ranking(i)/maximoR);
    costosE = [costosE,tiempos(i)+costosE(i)];
end
bar(ranking)
set(gca,'XTickLabel',metodos);
title('Ranking métodos para matriz 289');

%bar(tiempos)
%set(gca,'XTickLabel',metodos);
%title('Tiempos métodos para matriz 289');


%bar(errores)
%set(gca,'XTickLabel',metodos);
%title('Errores métodos para matriz 289');
