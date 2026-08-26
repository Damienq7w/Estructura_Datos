#ifndef OBJETO_H
#define OBJETO_H

#include <iostream>
#include <string>
using namespace std;

/*
 * ============================================================
 *  TDA OBJETO
 * ============================================================
 * Representa un objeto fisico (mesa, celular, perilla, etc.)
 * que puede o no tener presencia del virus en su superficie.
 *
 * Un objeto NUNCA se infecta a si mismo: unicamente queda
 * CONTAMINADO cuando una persona infectada estornuda sobre el
 * (ver Persona::estornudarSobreObjeto).
 *
 * ------------------------------------------------------------
 * ESTADO DEL SISTEMA (definido en el enunciado del ejercicio):
 *   contaminado : indica si el objeto tiene presencia del virus
 * ------------------------------------------------------------
 * DATO PRIMITIVO USADO:
 *   bool contaminado;
 *
 *   Se utiliza "bool" porque el estado de un objeto dentro de
 *   este TDA solo admite dos valores logicos posibles:
 *   contaminado (true) o limpio (false). No se necesita una
 *   clase, estructura ni objeto adicional para representar esta
 *   condicion: un bool ocupa 1 byte y vive directamente dentro
 *   de la memoria del propio objeto Objeto (no usa el heap).
 * ============================================================
 */
class Objeto {
private:
    string nombre;       // nombre identificador del objeto (ej: "Mesa")
    bool contaminado;    // DATO PRIMITIVO: estado de contaminacion

public:
    // Constructor: todo objeto se crea limpio (estado inicial = false)
    Objeto(string nombre) {
        this->nombre = nombre;
        this->contaminado = false; // invariante inicial: objeto limpio
    }

    // Marca el objeto como contaminado.
    // Metodo de apoyo usado UNICAMENTE por
    // Persona::estornudarSobreObjeto(), que es quien valida
    // la regla de negocio (solo infectados contaminan).
    void contaminar() {
        contaminado = true;
    }

    // Consulta el estado de contaminacion del objeto
    bool estaContaminado() const {
        return contaminado;
    }

    string getNombre() const {
        return nombre;
    }

    // ------------------------------------------------------------
    // OPERACION DEL TDA: MostrarEstado()
    // Presenta el estado actual del objeto por consola.
    // ------------------------------------------------------------
    void mostrarEstado() const {
        cout << "  Objeto  [" << nombre << "] -> "
             << (contaminado ? "CONTAMINADO" : "limpio") << endl;
    }
};

#endif
