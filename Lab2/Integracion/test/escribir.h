#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

void escribirErrores(long double );
void escribirIntegrales(long double ec1Trapecio, long double ec2Trapecio);

void escribirErrores(long double  errores[24]){
	ofstream archivo("errores.txt");
	if(archivo.is_open()){
		archivo <<"DifD_A1_E1_10:  "<< errores[0] << "\n";
		archivo <<"DifD_A2_E2_10:  "<< errores[1] << "\n";
		archivo <<"DifD_A3_E1_5:  "<< errores[2] << "\n";
		archivo <<"DifD_A4_E2_5:  "<< errores[3] << "\n";
		archivo <<"DifD_A5_E1_1:  "<< errores[4] << "\n";
		archivo <<"DifD_A6_E2_1:  "<< errores[5] << "\n";
		archivo <<"DifD_A7_E1_05:  "<< "errores[6]" << "\n";
		archivo <<"DifD_A8_E2_05:  "<< "errores[7]" << "\n";

		archivo <<"DifF_A9_E1_10:  "<< errores[8] << "\n";
		archivo <<"DifF_A10_E2_10:  "<< errores[9] << "\n";
		archivo <<"DifF_A11_E1_5:  "<< errores[10] << "\n";
		archivo <<"DifF_A12_E2_5:  "<< errores[11] << "\n";
		archivo <<"DifF_A13_E1_1:  "<< errores[12] << "\n";
		archivo <<"DifF_A14_E2_1:  "<< errores[13] << "\n";
		archivo <<"DifF_A15_E1_05:  "<< "errores[14]" << "\n";
		archivo <<"DifF_A16_E2_05:  "<< "errores[15]" << "\n";

        archivo << "Min_A17_E1_10:  " <<errores[16] << "\n";
        archivo << "Min_A18_E2_10:  " <<errores[17] << "\n";
        archivo << "Min_A19_E1_5:  " <<errores[18] << "\n";
        archivo << "Min_A20_E2_5:  " <<errores[19] << "\n";
        archivo << "Min_A21_E1_1:  " <<errores[20] << "\n";
        archivo << "Min_A22_E2_1:  " <<errores[21] << "\n";
        archivo << "Min_A23_E1_05:  " <<errores[22] << "\n";
        archivo << "Min_A24_E2_05:  " <<errores[23] << "\n"; 

        archivo << "sp_A25_E1_10:  " << errores[24] << "\n";
        archivo << "sp_A26_E2_10:  " << errores[25] << "\n";
        archivo << "sp_A27_E1_5:  " <<  errores[26] << "\n";
        archivo << "sp_A28_E2_5:  " <<  errores[27] << "\n";
        archivo << "sp_A29_E1_1:  " <<  errores[28] << "\n";
        archivo << "sp_A30_E2_1:  " <<  errores[29] << "\n";
        archivo << "sp_A31_E1_05:  " << errores[30] << "\n";
        archivo << "sp_A32_E2_05:  " << errores[31] << "\n";


	}
	archivo.close();

}


void escribirIntegrales(long double ec1Trapecio, long double ec2Trapecio, long double simpson, long double simpson2){
    ofstream archivo("Trapecio.txt");
    if(archivo.is_open()){
        archivo << "Calculo  exponencial mediante trapecio: " << ec1Trapecio << "\n";
        archivo << "Calculo polinomio mediante trapecio: " << ec2Trapecio << "\n";
        archivo << "Calculo exponencial mediante simpson: " << simpson << "\n";
        archivo << "Calculo polinomio mediante simpson: " << simpson2 << "\n";

    }
    archivo.close();
    
}
