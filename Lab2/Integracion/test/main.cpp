#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include "minimos.h"
#include "diferenciasD.h"
#include "diferenciasF.h"
#include "spline.h"
#include "trapecio.h"
#include "escribir.h"
#include "simpson.h"
#include <armadillo>

using namespace std;
typedef vector< long double> vec;
int main () {

   string entrada;
   int nDatos;
    long double errores[32];
    vec arrX1(41);
    vec arrY1(41);
    vec arrY11(41);
    vec arrX2(81);
    vec arrY2(81);
    vec arrY22(81);
    vec arrX3(401);
    vec arrY3(401);
    vec arrY33(401);
    vec arrX4(801);
    vec arrY4(801);
    vec arrY44(801);
    vec ec1(8001);
    vec ec2(8001);

    int i = 0;
    long double aux = -200;
    while(i<=40){
        arrX1[i] = aux;
        arrY1[i] = exp(aux) + aux - 2;
        arrY11[i] = pow(aux,3) + 4*(pow(aux,2)) - 5*aux + 2;
        aux = aux+10;
        i++;
    }
    
    i = 0; aux = -200;
    while(i<=80){
        arrX2[i] = aux;
        arrY2[i] = exp(aux) + aux - 2;
        arrY22[i] = pow(aux,3) + 4*(pow(aux,2)) - 5*aux + 2;
        //   cout << "arrX2: " << arrX2[i] << " - arr22:  " << arrY2[i] << "  - arry22: " << arrY22[i] << "\n";
        aux = aux+5;
        i++;
    }
    
    aux = -200; i = 0;
    while(i<=400){
        arrX3[i] = aux;
        arrY3[i] = exp(aux) + aux - 2;
        arrY33[i] = pow(aux,3) + 4*(pow(aux,2)) - 5*aux + 2;
      //  cout << "arrX3: " << arrX3[i] << " - arrY3:  " << arrY3[i] << "  - arry33: " << arrY33[i] << "\n";
        aux = aux+1;
        i++;
        
    }
    aux = -200; i = 0;
    while(i<=800){
        arrX4[i] = aux;
        arrY4[i] = exp(aux) + aux - 2;
        arrY44[i] = pow(aux,3) + 4*(pow(aux,2)) - 5*aux + 2;
      //  cout << "arrX3: " << arrX3[i] << " - arrY3:  " << arrY3[i] << "  - arry33: " << arrY33[i] << "\n";
        aux = aux+0.5;
        i++;
        
    }

    aux = -200; i = 0;
    while(aux<=200){
        ec1[i] = exp(aux) + aux - 2;
        ec2[i] = pow(aux,3) + 4*(pow(aux,2)) - 5*aux + 2;
        aux = aux+0.05;
        i++;
    }
  

    
//======================================DIFERENCIAS DIVIDIDAS=================================
 errores[0] =  diferenciasDivididas(41,arrX1,arrY1,"DifD_A1_E1_10.txt",ec1);
 errores[1] =  diferenciasDivididas(41,arrX1,arrY11,"DifD_A2_E2_10.txt",ec2);
 errores[2] =  diferenciasDivididas(81,arrX2,arrY2,"DifD_A3_E1_5.txt",ec1);
 errores[3] =  diferenciasDivididas(81,arrX2,arrY22,"DifD_A4_E2_5.txt",ec2);
 errores[4] =  diferenciasDivididas(401,arrX3,arrY3,"DifD_A5_E1_1.txt",ec1);
 errores[5] =  diferenciasDivididas(401,arrX3,arrY33,"DifD_A6_E2_1.txt",ec2);
// errores[6] =  diferenciasDivididas(801,arrX4,arrY4,"DifD_A7_E1_05.txt",ec1);
// errores[7] =  diferenciasDivididas(801,arrX4,arrY44,"DifD_A8_E2_05.txt",ec2);

   
//======================================DIFERENCIAS DIVIDIDAS=================================
    
//======================================DIFERENCIAS FINITAS===================================
//***************ARREGLAR ERROR****************************************************
errores[8] =  diferenciasFinitas(41,arrX1,arrY1,"DifF_A9_E1_10.txt",ec1);
errores[9] =  diferenciasFinitas(41,arrX1,arrY11,"DifF_A10_E2_10.txt",ec2);
errores[10] =  diferenciasFinitas(81,arrX2,arrY2,"DifF_A11_E1_5.txt",ec1);
errores[11] =  diferenciasFinitas(81,arrX2,arrY22,"DifF_A12_E2_5.txt",ec2);
errores[12]=  diferenciasFinitas(401,arrX3,arrY3,"DifF_A13_E1_1.txt",ec1);
errores[13]= diferenciasFinitas(401,arrX3,arrY33,"DifF_A14_E2_1.txt",ec2);
// errores[14]=  diferenciasFinitas(801,arrX4,arrY4,"DifD_A15_E1_05.txt",ec1);
// errores[15]= diferenciasFinitas(801,arrX4,arrY44,"DifD_A16_E2_05.txt",ec2);

//======================================DIFERENCIAS FINITAS===================================

// =====================================MÍNIMOS CUADRADOS=====================================

 errores[16] = minimosC(41,arrX1,arrY1,"Min_A17_E1_10.txt",ec1);
 errores[17] = minimosC(41,arrX1,arrY11,"Min_A18_E2_10.txt",ec2);
 errores[18] = minimosC(81,arrX2,arrY2,"Min_A19_E1_5.txt",ec1);
 errores[19] = minimosC(81,arrX2,arrY22,"Min_A20_E2_5.txt",ec2);
 errores[20] = minimosC(401,arrX3,arrY3,"Min_A21_E1_1.txt",ec1);
 errores[21] = minimosC(401,arrX3,arrY33,"Min_A22_E2_1.txt",ec2);
 errores[22] = minimosC(801,arrX4,arrY4,"Min_A23_E1_05.txt",ec1);
 errores[23] = minimosC(801,arrX4,arrY44,"Min_A24_E2_05.txt",ec2);


// =====================================FIN MÍNIMOS CUADRADOS=====================================
    
// =====================================SPLINE CÚBICO=============================================


errores[24] =  spline(arrX1, arrY1, 10,"spline_A25_E1_10.txt",ec1);
errores[25] = spline(arrX1, arrY11, 10,"spline_A26_E2_10.txt",ec2);
errores[26] = spline(arrX2, arrY2, 5,"spline_A27_E1_5.txt",ec1);
errores[27] = spline(arrX2, arrY22, 5,"spline_A28_E2_5.txt",ec2);
errores[28] = spline(arrX3, arrY3, 1,"spline_A29_E1_1.txt",ec1);
errores[29] = spline(arrX3, arrY33, 1,"spline_A30_E2_1.txt",ec2);
errores[30] = spline(arrX4, arrY4, 0.5,"spline_A31_E1_05.txt",ec1);
errores[31] = spline(arrX4, arrY44, 0.5,"spline_A32_E2_05.txt",ec2);

 escribirErrores(errores);
// El menor error se produjo en la interpolación de mínimos, por lo cual los datos son ingresados a la
// integral de trapecio para su cálculo. (distancia de 0.5)
   long double tr =  trapecio("InterpolacionMinimosE1.txt");
   long double tr2 =  trapecio("InterpolacionMinimosE2.txt");
   long double simp = simpson("InterpolacionMinimosE1.txt");
  long double simp2 = simpson("InterpolacionMinimosE2.txt");
    escribirIntegrales(tr,tr2,simp,simp2);
    return 0;
    
    
 
}
