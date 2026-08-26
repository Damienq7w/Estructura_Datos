package Transmision;
/*
 * ============================================================
 *  TDA PERSONA
 * ============================================================
 * Representa a una persona dentro de la cadena de transmision
 * por contacto.
 * ------------------------------------------------------------
 * ESTADO DEL SISTEMA :
 *   infectada         : indica si la persona esta infectada
 *   manosContaminadas : indica si tiene el virus en las manos
 *                        (una persona puede tener las manos
 *                        contaminadas sin estar infectada)
 * ------------------------------------------------------------
 * DATOS PRIMITIVOS USADOS:
 *   boolean infectada;
 *   boolean manosContaminadas;
 * ============================================================
 */
public class Persona {

    private String nombre;
    private boolean infectada;         // DATO PRIMITIVO
    private boolean manosContaminadas; // DATO PRIMITIVO

    // Constructor sin estado de infeccion: la persona nace sana.
    public Persona(String nombre) {
        this(nombre, false);
    }

    // El parametro infectada permite crear el "paciente cero"
    // de la simulacion (por defecto una persona nace sana).
    public Persona(String nombre, boolean infectada) {
        this.nombre = nombre;
        this.infectada = infectada;
        this.manosContaminadas = false; // invariante inicial: manos limpias
    }

    // ------------------------------------------------------------
    // OPERACION: estornudarSobreObjeto()
    // Descripcion (tabla del enunciado): una persona infectada
    // contamina un objeto.
    //
    // INVARIANTE 1: Solamente una persona infectada puede
    // contaminar un objeto mediante el estornudo.
    // ------------------------------------------------------------
    public void estornudarSobreObjeto(Objeto obj) {
        if (infectada) {
            obj.contaminar();
            System.out.println(nombre + " estornuda sobre " + obj.getNombre()
                    + " -> objeto CONTAMINADO.");
        } else {
            System.out.println(nombre + " no esta infectada, "
                    + obj.getNombre() + " permanece limpio.");
        }
    }

    // ------------------------------------------------------------
    // OPERACION: tocarObjeto()
    // Descripcion: el virus pasa del objeto a las manos.
    //
    // INVARIANTE 2: tocar un objeto limpio NO contamina las manos.
    // ------------------------------------------------------------
    public void tocarObjeto(Objeto obj) {
        if (obj.estaContaminado()) {
            manosContaminadas = true;
            System.out.println(nombre + " toca " + obj.getNombre()
                    + " -> sus manos quedan CONTAMINADAS.");
        } else {
            System.out.println(nombre + " toca " + obj.getNombre()
                    + " (limpio) -> sus manos siguen limpias.");
        }
    }

    // ------------------------------------------------------------
    // OPERACION: lavarManos()
    // Descripcion: elimina el virus e interrumpe la cadena.
    //
    // INVARIANTE 5: lavarse las manos elimina la contaminacion
    // y evita continuar con la transmision.
    // ------------------------------------------------------------
    public void lavarManos() {
        manosContaminadas = false;
        System.out.println(nombre + " se lava las manos -> manos limpias, "
                + "cadena de transmision interrumpida.");
    }

    // ------------------------------------------------------------
    // OPERACION: tenerContacto()
    // Descripcion: una persona con las manos contaminadas
    // transmite el virus (por ejemplo, mediante un saludo de
    // mano) a las manos de otra persona.
    // ------------------------------------------------------------
    public void tenerContacto(Persona otra) {
        if (this.manosContaminadas) {
            otra.manosContaminadas = true; // acceso valido: mismo tipo (Persona)
            System.out.println(nombre + " tiene contacto con " + otra.nombre
                    + " -> le contamina las manos.");
        } else {
            System.out.println(nombre + " tiene contacto con " + otra.nombre
                    + " -> no hay transmision (manos limpias).");
        }
    }

    // ------------------------------------------------------------
    // OPERACION: tocarRostro()
    // Descripcion: si las manos estan contaminadas, la persona
    // se infecta.
    //
    // INVARIANTE 3: tener las manos contaminadas NO significa
    // estar infectada (son estados independientes hasta este
    // punto).
    // INVARIANTE 4: la infeccion ocurre al tocar ojos, nariz o
    // boca con las manos contaminadas.
    // ------------------------------------------------------------
    public void tocarRostro() {
        if (manosContaminadas) {
            infectada = true;
            System.out.println(nombre + " se toca el rostro con las manos "
                    + "contaminadas -> SE INFECTA.");
        } else {
            System.out.println(nombre + " se toca el rostro con las manos "
                    + "limpias -> no ocurre infeccion.");
        }
    }

    // Metodos de consulta (getters), no forman parte de la tabla
    // de operaciones pero son necesarios para el main y para
    // tenerContacto()
    public boolean estaInfectada() {
        return infectada;
    }

    public boolean tieneManosContaminadas() {
        return manosContaminadas;
    }

    public String getNombre() {
        return nombre;
    }

    // ------------------------------------------------------------
    // OPERACION DEL TDA: MostrarEstado()
    // Presenta el estado actual de la persona por consola.
    // ------------------------------------------------------------
    public void mostrarEstado() {
        System.out.println("  Persona [" + nombre + "] -> Infectada: "
                + (infectada ? "SI " : "NO ")
                + "| Manos contaminadas: "
                + (manosContaminadas ? "SI" : "NO"));
    }
}