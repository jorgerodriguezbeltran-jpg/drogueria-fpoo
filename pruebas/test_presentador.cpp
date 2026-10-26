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
        CHECK_EQ(p.formaDePresentacionATexto(5), "Crema");
        CHECK_EQ(p.formaDePresentacionATexto(0), "Desconocida");
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
    {
        stringstream out;
        CPresentador p(out);
        p.mostrarTitulo("INVENTARIO");
        CHECK_CONTIENE(out.str(), "INVENTARIO");
        CHECK_CONTIENE(out.str(), "====");
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
    {   // lista vacía
        stringstream out;
        CPresentador p(out);
        p.mostrarMedicamentos(vector<CMedicamento>());
        CHECK_CONTIENE(out.str(), "No hay medicamentos");
    }
    {   // nombre muy largo: se recorta
        stringstream out;
        CPresentador p(out);
        vector<CMedicamento> lista;
        string largo = "Medicamento con un nombre absurdamente largo para la tabla";
        lista.push_back(CMedicamento(1, largo, 3, 10, 100, 200));
        p.mostrarMedicamentos(lista);
        CHECK(out.str().find(largo) == string::npos);
        CHECK_CONTIENE(out.str(), "...");
    }

    SECCION("Extra Grupo 4: Formato de moneda con separador de miles");
    {
        stringstream out;
        CPresentador p(out);
        vector<CMedicamento> lista;
        // Medicamento con precio/costo elevado para verificar puntos de miles
        lista.push_back(CMedicamento(101, "Acetaminofen", 1, 50, 1500.00, 1250000.75));

        p.mostrarMedicamentos(lista);
        string salidaTexto = out.str();

        // Verificas que la salida contenga el formato $1.250.000 o $1.500
        CHECK_CONTIENE(salidaTexto, "$1.250.000");
    }
        
    return RESUMEN();
}
