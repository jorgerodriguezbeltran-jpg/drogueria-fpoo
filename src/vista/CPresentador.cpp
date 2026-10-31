/*
    Proyecto: Drogueria - FPOO - Universidad del Valle
    Módulo: Presentación (GRUPO 4)

    ESTE ARCHIVO ES TUYO: reemplaza los STUB por la implementación real.
*/
#include "CPresentador.h"
using namespace std;

CPresentador::CPresentador(ostream& salida_) : salida(salida_) { 
    while (true) {
        salida << "Ingrese un número (1-5) para la forma de presentación, o cualquier otro número para salir: ";
        int forma;
        cin >> forma;

        if (forma < 1 || forma > 5) {
            salida << "Saliendo del programa." << endl;
            break;
        }

        string texto = formaDePresentacionATexto(forma);
        salida << "La forma de presentación es: " << texto << endl;
    }
}

string CPresentador::formaDePresentacionATexto(int forma) const{
    switch (forma) {
        case 1:
            return "Tableta";
        case 2:
            return "Caja";
        case 3:
            return "Jarabe";
        case 4:
            return "Ampolla";
        case 5:
            return "Crema";
        default:
            return "Desconocida";
    }
}

void CPresentador::mostrarMedicamentos(const vector<CMedicamento>& lista) const{
    switch (lista.size()) {
        case 0:
            salida << "No hay medicamentos." << endl;
            return;
        default:
            break;
    }
    salida << "(sin implementar) " << lista.size() << " medicamento(s)" << endl;
}

void CPresentador::mostrarExito(string mensaje) const{
    string exito = "[OK] " + mensaje;
    
    salida << exito << endl;
}

void CPresentador::mostrarError(string mensaje) const{
    string error = "[ERROR] " + mensaje;
    salida << error  << endl;
}

void CPresentador::mostrarTitulo(string titulo) const{
    // STUB (Grupo 4): implementar
    salida << titulo << endl;
}
