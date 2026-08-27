#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <string>
#include "Objeto.h"
using namespace std;

/*
 * Representa a una persona dentro de la cadena de transmision
 * por contacto.
 *
 * DATOS PRIMITIVOS USADOS:
 *   bool infectada;
 *   bool manosContaminadas;
 */
class Persona {
private:
    string nombre;
    bool infectada;           // DATO PRIMITIVO
    bool manosContaminadas;   // DATO PRIMITIVO

public:
    // El parametro infectada permite crear el "paciente cero"
    //Ppor defecto una persona nace sana.
    Persona(string nombre, bool infectada = false) {
        this->nombre = nombre;
        this->infectada = infectada;
        this->manosContaminadas = false; // invariante inicial: manos limpias
    }

    // OPERACION: estornudarSobreObjeto()
    // Descripcion: una persona infectada contamina un objeto.
    // INVARIANTE 1: Solamente una persona infectada puede
    // contaminar un objeto mediante el estornudo.

    void estornudarSobreObjeto(Objeto &obj) {
        if (infectada) {
            obj.contaminar();
            cout << nombre << " estornuda sobre " << obj.getNombre()
                 << " -> objeto CONTAMINADO." << endl;
        } else {
            cout << nombre << " no esta infectada, "
                 << obj.getNombre() << " permanece limpio." << endl;
        }
    }

    // OPERACION: tocarObjeto()
    // Descripcion: el virus pasa del objeto a las manos.
    //
    // INVARIANTE 2: tocar un objeto limpio NO contamina las manos.
    
    void tocarObjeto(Objeto &obj) {
        if (obj.estaContaminado()) {
            manosContaminadas = true;
            cout << nombre << " toca " << obj.getNombre()
                 << " -> sus manos quedan CONTAMINADAS." << endl;
        } else {
            cout << nombre << " toca " << obj.getNombre()
                 << " (limpio) -> sus manos siguen limpias." << endl;
        }
    }

    // OPERACION: lavarManos()
    // Descripcion: elimina el virus e interrumpe la cadena.
    //
    // INVARIANTE 5: lavarse las manos elimina la contaminacion
    // y evita continuar con la transmision.
    
    void lavarManos() {
        manosContaminadas = false;
        cout << nombre << " se lava las manos -> manos limpias, "
             << "cadena de transmision interrumpida." << endl;
    }

    // OPERACION: tenerContacto()
    // Descripcion: una persona con las manos contaminadas
    // transmite el virus a otra persona o a un objeto.
    
    void tenerContacto(Persona &otra) {
        if (this->manosContaminadas) {
            otra.manosContaminadas = true;
            cout << nombre << " tiene contacto con " << otra.nombre
                 << " -> le contamina las manos." << endl;
        } else {
            cout << nombre << " tiene contacto con " << otra.nombre
                 << " -> no hay transmision (manos limpias)." << endl;
        }
    }

    // OPERACION: tocarRostro()
    // Descripcion: si las manos estan contaminadas, la persona
    // se infecta.
    //
    // INVARIANTE 3: tener las manos contaminadas NO significa
    // estar infectada.
    // INVARIANTE 4: la infeccion ocurre al tocar ojos, nariz o
    // boca con las manos contaminadas.
    
    void tocarRostro() {
        if (manosContaminadas) {
            infectada = true;
            cout << nombre << " se toca el rostro con las manos "
                 << "contaminadas -> SE INFECTA." << endl;
        } else {
            cout << nombre << " se toca el rostro con las manos "
                 << "limpias -> no ocurre infeccion." << endl;
        }
    }

    // Geter, Necesarios para el main y para tenerContacto()
    bool estaInfectada() const { return infectada; }
    bool tieneManosContaminadas() const { return manosContaminadas; }
    string getNombre() const { return nombre; }

    // OPERACION  MostrarEstado()
    // Presenta el estado actual de la persona por consola.
    
    void mostrarEstado() const {
        cout << "  Persona [" << nombre << "] -> Infectada: "
             << (infectada ? "SI " : "NO ")
             << "| Manos contaminadas: "
             << (manosContaminadas ? "SI" : "NO") << endl;
    }
};

#endif
