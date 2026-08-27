#ifndef OBJETO_H
#define OBJETO_H

#include <iostream>
#include <string>
using namespace std;

/*
 * Representa un objeto fisico (mesa, celular, perilla, etc.)
 * que puede o no tener presencia del virus en su superficie.
 *
 * Un objeto NUNCA se infecta a si mismo: unicamente queda
 * CONTAMINADO cuando una persona infectada estornuda sobre el
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

    // OPERACION MostrarEstado()
    // Presenta el estado actual del objeto por consola.

    void mostrarEstado() const {
        cout << "  Objeto  [" << nombre << "] -> "
             << (contaminado ? "CONTAMINADO" : "limpio") << endl;
    }
};

#endif
