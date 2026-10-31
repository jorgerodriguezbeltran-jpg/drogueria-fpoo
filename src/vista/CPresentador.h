/**
 * @file CPresentador.h
 * @brief CONTRATO del módulo de presentación (GRUPO 4).
 *
 * ATENCION: ESTE ARCHIVO ES UN CONTRATO. NO SE EDITA.
 * Si crees que falta algo o hay un error, abre un issue en el repositorio padre.
 *
 * Estándar CRC:
 *   Clase: CPresentador
 *   Responsabilidades:
 *     - Dar formato a lo que se muestra al usuario (tablas, mensajes, títulos).
 *     - NO calcula nada ni lee datos: solo muestra.
 *   Colaboradores:
 *     - CMedicamento: se leen sus datos (getters) para mostrarlos.

 * REGLAS DEL CONTRATO:
 *   - formaDePresentacionATexto(forma): 1="Tableta", 2="Caja", 3="Jarabe",
 *       4="Ampolla", 5="Crema"; cualquier otro valor="Desconocida".
 *   - mostrarMedicamentos(lista): tabla con columnas alineadas (id, nombre, forma como
 *       TEXTO, cantidad, costo, precio) con encabezado. Si la lista está vacía muestra
 *       un mensaje que diga que no hay medicamentos.
 *   - mostrarExito(mensaje): imprime "[OK] " + mensaje.
 *   - mostrarError(mensaje): imprime "[ERROR] " + mensaje.
 *   - mostrarTitulo(titulo): imprime el título destacado (por ejemplo, con líneas de ===).
 */
#ifndef _CPRESENTADOR_H_
#define _CPRESENTADOR_H_
#include <iostream>
#include <string>
#include <vector>
#include "CMedicamento.h"
using namespace std;

class CPresentador
{
  private:
    ostream& salida;

  public:
    CPresentador(ostream& salida = cout);
    string formaDePresentacionATexto(int forma) const;
    void mostrarMedicamentos(const vector<CMedicamento>& lista) const;
    void mostrarExito(string mensaje) const; 
    void mostrarError(string mensaje) const;
    void mostrarTitulo(string titulo) const;
};
#endif
