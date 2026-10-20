/*

    Proyecto: Drogueria - FPOO - Universidad del Valle

    Módulo: Presentación (GRUPO 4)



    ESTE ARCHIVO ES TUYO: reemplaza los STUB por la implementación real.

*/

#include "CPresentador.h"

using namespace std;



CPresentador::CPresentador(ostream& salida_) : salida(salida_) {

}



string CPresentador::formaDePresentacionATexto(int forma) const{

    // STUB (Grupo 4): implementar

    return "?";

}



void CPresentador::mostrarMedicamentos(const vector<CMedicamento>& lista) const{

    // STUB (Grupo 4): implementar

    salida << "(sin implementar) " << lista.size() << " medicamento(s)" << endl;

}



void CPresentador::mostrarExito(string mensaje) const{


    salida << "[OK] " << mensaje << endl;

}



void CPresentador::mostrarError(string mensaje) const{

    
    salida << "[ERROR] " << mensaje << endl;
    

}



void CPresentador::mostrarTitulo(string titulo) const{

    // STUB (Grupo 4): implementar

    salida << titulo << endl;

}