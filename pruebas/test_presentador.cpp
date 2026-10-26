// Pruebas de CPresentador. Responsable: GRUPO 4
#include <sstream>
#include <vector>
#include "minitest.h"
#include "CPresentador.h"
using namespace std;

int main(){
    SECCION("CPresentador: formaDePresentacionATexto");
    {
        CPresentador p;
        CHECK_EQ(p.formaDePresentacionATexto(1), "Tableta");
        CHECK_EQ(p.formaDePresentacionATexto(2), "Caja");
        CHECK_EQ(p.formaDePresentacionATexto(99), "Desconocida");
    }

    SECCION("CPresentador: mensajes");
    {
        stringstream out;
        CPresentador p(out);
        p.mostrarError("algo salio mal");
        CHECK_CONTIENE(out.str(), "[ERROR] algo salio mal");
    }
    {
        stringstream out;
        CPresentador p(out);
        p.mostrarExito("todo bien");
        CHECK_CONTIENE(out.str(), "[OK] todo bien");
    }

    SECCION("CPresentador: mostrarMedicamentos");
    {
        stringstream out;
        CPresentador p(out);
        vector<CMedicamento> lista;
        lista.push_back(CMedicamento(1, "Acetaminofen", 1, 100, 1000, 2000));
        lista.push_back(CMedicamento(2, "Ibuprofeno", 2, 50, 500, 2500));
        p.mostrarMedicamentos(lista);
        CHECK_CONTIENE(out.str(), "Acetaminofen");
        CHECK_CONTIENE(out.str(), "Ibuprofeno");
        CHECK_CONTIENE(out.str(), "Tableta");
    }

    SECCION("Prueba de decimales en CPresentador"); {
    stringstream out;
    CPresentador presentador(out);

    vector<CMedicamento> lista;
    // Medicamento con precio en decimales: 1250000.75
    lista.push_back(CMedicamento(101, "Acetaminofen", 1, 50, 1500.00, 1250000.75));

    presentador.mostrarMedicamentos(lista);
    string salidaTexto = out.str();

    // Verificas que la salida contenga la representación esperada
    CHECK_CONTIENE(salidaTexto, "$1.250.000");
}
        
    return RESUMEN();
}
