#ifndef CADENATRANSMISION_H
#define CADENATRANSMISION_H

#include <iostream>
#include "Persona.h"
#include "Objeto.h"
using namespace std;

const int MAX_PERSONAS = 10;
const int MAX_OBJETOS  = 10;

/** 
 * Permite consultar el estado GENERAL del sistema mediante
 * MostrarEstado().
 *
 * Se implementa con ARREGLOS ESTATICOS de punteros (Persona* y
 * Objeto*) de tamano fijo,para el manejo de colecciones con datos primitivos
 */
class CadenaTransmision {
private:
    Persona* personas[MAX_PERSONAS]; // arreglo estatico de punteros a Persona
    Objeto*  objetos[MAX_OBJETOS];   // arreglo estatico de punteros a Objeto
    int totalPersonas;               // cantidad de personas registradas
    int totalObjetos;                // cantidad de objetos registrados

public:
    CadenaTransmision() {
        totalPersonas = 0;
        totalObjetos = 0;
    }

    // Registra una persona dentro de la cadena de transmision
    void registrarPersona(Persona* p) {
        if (totalPersonas < MAX_PERSONAS) {
            personas[totalPersonas] = p;
            totalPersonas++;
        } else {
            cout << "No se pueden registrar mas personas (limite alcanzado)." << endl;
        }
    }

    // Registra un objeto dentro de la cadena de transmision
    void registrarObjeto(Objeto* o) {
        if (totalObjetos < MAX_OBJETOS) {
            objetos[totalObjetos] = o;
            totalObjetos++;
        } else {
            cout << "No se pueden registrar mas objetos (limite alcanzado)." << endl;
        }
    }

    // Presenta el estado de [personas y objetos],
    // recorre los arreglos estaticos e invoca el mostrarEstado()
    // de cada Persona y cada Objeto registrados.
    void mostrarEstado() const {
        cout << "\n===== ESTADO DE LA CADENA DE TRANSMISION =====" << endl;
        cout << "-- Personas --" << endl;
        for (int i = 0; i < totalPersonas; i++) {
            personas[i]->mostrarEstado();
        }
        cout << "-- Objetos --" << endl;
        for (int i = 0; i < totalObjetos; i++) {
            objetos[i]->mostrarEstado();
        }
        cout << "================================================\n" << endl;
    }
};

#endif
