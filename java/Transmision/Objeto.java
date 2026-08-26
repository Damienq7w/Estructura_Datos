package Transmision;

/*
 * ============================================================
 *  TDA OBJETO
 * ============================================================
 * Representa un objeto fisico (mesa, celular, perilla, etc.)
 * que puede o no tener presencia del virus en su superficie.
 *
 * Un objeto nunca se infecta a si mismo: unicamente queda
 * contaminado cuando una persona infectada estornuda sobre el.
 * ------------------------------------------------------------
 * DATO PRIMITIVO USADO:
 *   boolean contaminado;
 * ============================================================
 */
public class Objeto {

    private String nombre;    // nombre identificador del objeto (ej: "Mesa")
    private boolean contaminado; // DATO PRIMITIVO: estado de contaminacion

    // Constructor: todo objeto se crea limpio (estado inicial = false)
    public Objeto(String nombre) {
        this.nombre = nombre;
        this.contaminado = false; // invariante inicial: objeto limpio
    }

    // Marca el objeto como contaminado.
    // Metodo de apoyo usado UNICAMENTE por
    // Persona.estornudarSobreObjeto(), que es quien valida
    // la regla de negocio (solo infectados contaminan).
    public void contaminar() {
        contaminado = true;
    }

    // Consulta el estado de contaminacion del objeto
    public boolean estaContaminado() {
        return contaminado;
    }

    public String getNombre() {
        return nombre;
    }

    // ------------------------------------------------------------
    // OPERACION DEL TDA: MostrarEstado()
    // Presenta el estado actual del objeto por consola.
    // ------------------------------------------------------------
    public void mostrarEstado() {
        System.out.println("  Objeto  [" + nombre + "] -> "
                + (contaminado ? "CONTAMINADO" : "limpio"));
    }
}