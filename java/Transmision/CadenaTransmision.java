package Transmision;
/*
 * ============================================================
 *  TDA CADENATRANSMISION
 * ============================================================ * ============================================================
 */
public class CadenaTransmision {

    private static final int MAX_PERSONAS = 10;
    private static final int MAX_OBJETOS = 10;

    private Persona[] personas; // arreglo estatico de referencias a Persona
    private Objeto[] objetos;   // arreglo estatico de referencias a Objeto
    private int totalPersonas;  // cantidad de personas registradas
    private int totalObjetos;   // cantidad de objetos registrados

    public CadenaTransmision() {
        personas = new Persona[MAX_PERSONAS];
        objetos = new Objeto[MAX_OBJETOS];
        totalPersonas = 0;
        totalObjetos = 0;
    }

    // Registra una persona dentro de la cadena de transmision
    public void registrarPersona(Persona p) {
        if (totalPersonas < MAX_PERSONAS) {
            personas[totalPersonas] = p;
            totalPersonas++;
        } else {
            System.out.println("No se pueden registrar mas personas (limite alcanzado).");
        }
    }

    // Registra un objeto dentro de la cadena de transmision
    public void registrarObjeto(Objeto o) {
        if (totalObjetos < MAX_OBJETOS) {
            objetos[totalObjetos] = o;
            totalObjetos++;
        } else {
            System.out.println("No se pueden registrar mas objetos (limite alcanzado).");
        }
    }
    // OPERACION DEL TDA: MostrarEstado()
    // Presenta el estado de [personas y objetos], es decir,
    // recorre los arreglos estaticos e invoca el mostrarEstado()
    // de cada Persona y cada Objeto registrados.
    public void mostrarEstado() {
        System.out.println("\n===== ESTADO DE LA CADENA DE TRANSMISION =====");
        System.out.println("-- Personas --");
        for (int i = 0; i < totalPersonas; i++) {
            personas[i].mostrarEstado();
        }
        System.out.println("-- Objetos --");
        for (int i = 0; i < totalObjetos; i++) {
            objetos[i].mostrarEstado();
        }
        System.out.println("================================================\n");
    }
}