#include "CBuscador.h"
#include <algorithm>
#include <cctype>

using namespace std;

// Función auxiliar para convertir a minúsculas
static string aMinusculas(string str) {
    for (char &c : str) {
        c = static_cast<char>(tolower(static_cast<unsigned char>(c)));
    }
    return str;
}

CBuscador::CBuscador(const CInventario& inv) : inventario(inv) {}

const CMedicamento* CBuscador::porId(int id) const {
    for (const auto& m : inventario.getMedicamentos()) {
        if (m.getId() == id) {
            return &m;
        }
    }
    return nullptr;
}

vector<CMedicamento> CBuscador::porNombre(string texto) const {
    vector<CMedicamento> resultado;
    if (texto.empty()) {
        return resultado;
    }
    string busqueda = aMinusculas(texto);
    for (const auto& m : inventario.getMedicamentos()) {
        string nombreMed = aMinusculas(m.getNombre());
        if (nombreMed.find(busqueda) != string::npos) {
            resultado.push_back(m);
        }
    }
    return resultado;
}

vector<CMedicamento> CBuscador::porRangoPrecio(float minimo, float maximo) const {
    vector<CMedicamento> resultado;
    for (const auto& m : inventario.getMedicamentos()) {
        float precio = m.getPrecioDeVenta();
        if (precio >= minimo && precio <= maximo) {
            resultado.push_back(m);
        }
    }
    return resultado;
}

vector<CMedicamento> CBuscador::conPocoStock(int umbral) const {
    vector<CMedicamento> resultado;
    for (const auto& m : inventario.getMedicamentos()) {
        if (m.getCantidadDisponible() <= umbral) {
            resultado.push_back(m);
        }
    }
    return resultado;
}