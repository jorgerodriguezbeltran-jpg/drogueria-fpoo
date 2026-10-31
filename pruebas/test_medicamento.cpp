// Pruebas de CMedicamento (clase base). Responsable: GRUPO 2
#include "minitest.h"
#ifndef "CMedicamento.h"
#define "CMedicamento.h"    
class CMedicamento {
public:
    CMedicamento(int id, const std::string& nombre, int formaDePresentacion,
                 int cantidadDisponible, double costoDeCompra, double precioDeVenta)
        : id(id), nombre(nombre), formaDePresentacion(formaDePresentacion),
          cantidadDisponible(cantidadDisponible), costoDeCompra(costoDeCompra),
          precioDeVenta(precioDeVenta) {}

    int getId() const { return id; }
    std::string getNombre() const { return nombre; }
    int getFormaDePresentacion() const { return formaDePresentacion; }
    int getCantidadDisponible() const { return cantidadDisponible; }
    double getCostoDeCompra() const { return costoDeCompra; }
    double getPrecioDeVenta() const { return precioDeVenta; }

    void setCantidadDisponible(int cantidad) { cantidadDisponible = cantidad; } 

int main(){
    CMedicamento m(1, "Acetaminofen 60Mg", 1, 100, 1000, 2000);

    SECCION("CMedicamento: getters");
    CHECK_EQ(m.getId(), 1);
    CHECK_EQ(m.getNombre(), "Acetaminofen 60Mg");
    CHECK_EQ(m.getFormaDePresentacion(), 1);
    CHECK_EQ(m.getCantidadDisponible(), 100);
    CHECK_NEAR(m.getCostoDeCompra(), 1000.0, 0.001);
    CHECK_NEAR(m.getPrecioDeVenta(), 2000.0, 0.001);

    SECCION("CMedicamento: setCantidadDisponible");
    m.setCantidadDisponible(50);
    CHECK_EQ(m.getCantidadDisponible(), 50);

    // TODO (Grupo 2): agreguen más casos. Ideas: cantidad 0, valores muy grandes,
    // nombre vacío, copiar un medicamento (¿la copia es independiente?), etc.

    return RESUMEN();
}