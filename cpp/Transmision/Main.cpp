  //Una persona infectada contamina un objeto, otra persona lo
 //toca, transporta el virus en sus manos y puede
 //infectarse al tocarse el rostro.
 //Este main.cpp simula paso a paso el escenario descrito en el
 //enunciado, mostrando el estado del sistema ANTES y DESPUES de
 //cada operacion, para evidenciar el cumplimiento de las 5
 //invariantes/reglas del TDA.
*/

#include <iostream>
#include <cstdlib>   // necesario para system("pause")
#include "Persona.h"
#include "Objeto.h"
#include "CadenaTransmision.h"
using namespace std;

int main() {

    // 0. LECTURA DE DATOS POR TECLADO
    //    Se solicitan al usuario los nombres de las 3 personas
    //    y de los 2 objetos que participaran en la simulacion.
    //    La persona 1 sera siempre la que inicia infectada, (paciente cero)
    string nombrePersona1, nombrePersona2, nombrePersona3;
    string nombreObjeto1, nombreObjeto2;

    cout << "===== INGRESO DE DATOS =====" << endl;
    cout << "Nombre de la persona 1 (sera el paciente cero / infectada): ";
    getline(cin, nombrePersona1);

    cout << "Nombre de la persona 2: ";
    getline(cin, nombrePersona2);

    cout << "Nombre de la persona 3: ";
    getline(cin, nombrePersona3);

    cout << "Nombre del objeto 1 (sera contaminado por la persona 1): ";
    getline(cin, nombreObjeto1);

    cout << "Nombre del objeto 2 (permanecera limpio): ";
    getline(cin, nombreObjeto2);
    cout << "=============================\n" << endl;

    // 1. CREACION DEL ESTADO INICIAL
    //    La persona 1 nace INFECTADA (paciente cero).
    //    Las personas 2 y 3 nacen sanas, sin el virus.

    Persona persona1(nombrePersona1, true);   // true = infectada desde el inicio
    Persona persona2(nombrePersona2);        // sana por defecto
    Persona persona3(nombrePersona3);       // sana por defecto

    Objeto objeto1(nombreObjeto1);
    Objeto objeto2(nombreObjeto2);


    CadenaTransmision cadena;
    cadena.registrarPersona(&persona1);
    cadena.registrarPersona(&persona2);
    cadena.registrarPersona(&persona3);
    cadena.registrarObjeto(&objeto1);
    cadena.registrarObjeto(&objeto2);

    cout << "ESTADO INICIAL" << endl;
    cadena.mostrarEstado();

    // 2. La persona 1 (infectada) estornuda sobre el objeto 1
    // Invariante 1: solo un infectado contamina un objeto

    persona1.estornudarSobreObjeto(objeto1);

    // 3. La persona 2 toca el objeto 1 (contaminado)
    // El virus pasa del objeto a sus manos

    persona2.tocarObjeto(objeto1);

    // 4. La persona 3 toca el objeto 2, que sigue LIMPIO
    // Invariante 2: tocar un objeto limpio no contamina
    
    persona3.tocarObjeto(objeto2);

    cout << "\nESTADO TRAS EL CONTACTO CON LOS OBJETOS" << endl;
    cadena.mostrarEstado();

    // 5. La persona 2 (manos contaminadas) tiene contacto con la persona 3
    // Transmite el virus a las manos de la persona 3
    
    persona2.tenerContacto(persona3);

    // 6. La persona 2 todavia NO esta infectada, solo tiene las manos
    //    contaminadas Invariante 3
    
    cout << "\n¿La persona 2 esta infectada antes de tocarse el rostro? "
         << (persona2.estaInfectada() ? "SI" : "NO") << endl;

    // 7. La persona 2 se toca el rostro con las manos contaminadas
    // Invariante 4: ahora SI se infecta
    
    persona2.tocarRostro();

    // 8. La persona 3 decide lavarse las manos ANTES de tocarse el rostro
    // Invariante 5: se interrumpe la cadena, la persona 3 no se infecta
    
    persona3.lavarManos();
    persona3.tocarRostro();

    cout << "\nESTADO FINAL" << endl;
    cadena.mostrarEstado();

    system("pause");

    return 0;
}
