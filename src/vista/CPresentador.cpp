/*

    Proyecto: Drogueria - FPOO - Universidad del Valle

    Módulo: Presentación (GRUPO 4)

    ESTE ARCHIVO ES TUYO: reemplaza los STUB por la implementación real (YA EDITÉ)
*/

#include "CPresentador.h"
#include <iomanip> // Librería necesaria para usar setw y left (formato de tablas)
#include <sstream>  // Para ostringstream
#include <algorithm> // Para std::reverse

using namespace std;

// Función auxiliar interna (no pertenece al header ni rompe el contrato)
// Convierte un número double/entero a formato moneda con punto como separador de miles.
// Ejemplo: 1250000 -> "$1.250.000"

static string formatearMoneda(double valor){
    long long entero = static_cast<long long>(valor);
    string str = to_string(entero);
    int n = str.length();

    string formateado = "";
    int contador = 0;

    for (int i = n-1; i >=0; i--) {
        formateado += str[i];
        contador++;
        if (contador % 3 == 0 && i != 0) {
            formateado += '.';
        }
    }

    reverse(formateado.begin(), formateado.end());
    return "$" +  formateado;
}


// Constructor: Inicializa la referencia al flujo de salida (por defecto es cout)
CPresentador::CPresentador(ostream& sal) : salida(sal) {}

// Convierte el número entero de la forma de presentación al texto correspondiente
string CPresentador::formaDePresentacionATexto(int forma) const {
    switch (forma) {
        case 1: return "Tableta";
        case 2: return "Caja";
        case 3: return "Jarabe";
        case 4: return "Ampolla";
        case 5: return "Crema";
        default: return "Desconocida"; // Si ingresan un número fuera del rango 1-5
    }
}

// Muestra la lista de medicamentos formateada en una tabla estructurada
void CPresentador::mostrarMedicamentos(const vector<CMedicamento>& lista) const {
    // 1. Si la lista no tiene elementos, mostramos un mensaje de advertencia
    if (lista.empty()) {
        salida << "No hay medicamentos registrados." << endl;
        return;
    }

    // 2. Encabezado de la tabla:
    // 'left' alinea el texto a la izquierda.
    // 'setw(N)' define un ancho fijo de N caracteres para cada columna.
    salida << left
           << setw(6)  << "ID"
           << setw(25) << "Nombre"
           << setw(15) << "Forma"
           << setw(10) << "Cant."
           << setw(14) << "Costo"
           << setw(14) << "Precio" << endl;

    // Línea divisoria decorativa
    salida << string(84, '-') << endl;

    // 3. Recorremos el vector e imprimimos la información de cada medicamento
    for (const auto& m : lista) {
        salida << left
               << setw(6)  << m.getId()
               << setw(25) << m.getNombre()
               // Convertimos el código numérico de la forma de presentación a texto
               << setw(15) << formaDePresentacionATexto(m.getFormaDePresentacion())
               << setw(10) << m.getCantidadDisponible()
               << setw(14) << formatearMoneda(m.getCostoDeCompra())
               << setw(14) << formatearMoneda(m.getPrecioDeVenta()) << endl;
    }
}

// Imprime un mensaje con el prefijo estandarizado de éxito
void CPresentador::mostrarExito(string mensaje) const {
    salida << "[OK] " << mensaje << endl;
}

// Imprime un mensaje con el prefijo estandarizado de error
void CPresentador::mostrarError(string mensaje) const {
    salida << "[ERROR] " << mensaje << endl;
}

// Formatea e imprime los títulos del sistema con bordes decorativos
void CPresentador::mostrarTitulo(string titulo) const {
    salida << "=== " << titulo << " ===" << endl;
}