package Transmision;

import java.util.Scanner;

/*
 * ================================================================
 *  EJERCICIO CORONAVIRUS - TDA CADENA DE TRANSMISION POR CONTACTO
 *  Version: Java
 * ================================================================
 * Problema:
 *   Una persona infectada contamina un objeto, otra persona lo
 *   toca, transporta temporalmente el virus en sus manos y puede
 *   infectarse al tocarse el rostro.
 *
 * Este Main.java simula paso a paso el escenario descrito en el
 * enunciado, mostrando el estado del sistema ANTES y DESPUES de
 * cada operacion, para evidenciar el cumplimiento de las 5
 * invariantes/reglas del TDA.
 * ================================================================
 */
public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        // ------------------------------------------------------------
        // 0. LECTURA DE DATOS POR TECLADO
        //    Se solicitan al usuario los nombres de las 3 personas
        //    y de los 2 objetos que participaran en la simulacion.
        //    La persona 1 sera siempre la que inicia infectada
        //    (paciente cero), tal como pide el enunciado.
        // ------------------------------------------------------------
        System.out.println("===== INGRESO DE DATOS =====");

        System.out.print("Nombre de la persona 1 (sera el paciente cero / infectada): ");
        String nombrePersona1 = sc.nextLine();

        System.out.print("Nombre de la persona 2: ");
        String nombrePersona2 = sc.nextLine();

        System.out.print("Nombre de la persona 3: ");
        String nombrePersona3 = sc.nextLine();

        System.out.print("Nombre del objeto 1 (sera contaminado por la persona 1): ");
        String nombreObjeto1 = sc.nextLine();

        System.out.print("Nombre del objeto 2 (permanecera limpio): ");
        String nombreObjeto2 = sc.nextLine();
        System.out.println("=============================\n");

        // ------------------------------------------------------------
        // 1. CREACION DEL ESTADO INICIAL
        //    La persona 1 nace INFECTADA (paciente cero).
        //    Las personas 2 y 3 nacen sanas, sin el virus.
        // ------------------------------------------------------------
        Persona persona1 = new Persona(nombrePersona1, true); // true = infectada desde el inicio
        Persona persona2 = new Persona(nombrePersona2);       // sana por defecto
        Persona persona3 = new Persona(nombrePersona3);       // sana por defecto

        Objeto objeto1 = new Objeto(nombreObjeto1);
        Objeto objeto2 = new Objeto(nombreObjeto2);

        // El administrador del TDA agrupa a todas las personas y objetos
        CadenaTransmision cadena = new CadenaTransmision();
        cadena.registrarPersona(persona1);
        cadena.registrarPersona(persona2);
        cadena.registrarPersona(persona3);
        cadena.registrarObjeto(objeto1);
        cadena.registrarObjeto(objeto2);

        System.out.println("ESTADO INICIAL");
        cadena.mostrarEstado();

        // ------------------------------------------------------------
        // 2. La persona 1 (infectada) estornuda sobre el objeto 1
        //    -> Invariante 1: solo un infectado contamina un objeto
        // ------------------------------------------------------------
        persona1.estornudarSobreObjeto(objeto1);

        // ------------------------------------------------------------
        // 3. La persona 2 toca el objeto 1 (contaminado)
        //    -> El virus pasa del objeto a sus manos
        // ------------------------------------------------------------
        persona2.tocarObjeto(objeto1);

        // ------------------------------------------------------------
        // 4. La persona 3 toca el objeto 2, que sigue LIMPIO
        //    -> Invariante 2: tocar un objeto limpio no contamina
        // ------------------------------------------------------------
        persona3.tocarObjeto(objeto2);

        System.out.println("\nESTADO TRAS EL CONTACTO CON LOS OBJETOS");
        cadena.mostrarEstado();

        // ------------------------------------------------------------
        // 5. La persona 2 (manos contaminadas) tiene contacto con la persona 3
        //    -> Transmite el virus a las manos de la persona 3
        // ------------------------------------------------------------
        persona2.tenerContacto(persona3);

        // ------------------------------------------------------------
        // 6. La persona 2 todavia NO esta infectada, solo tiene las manos
        //    contaminadas -> Invariante 3
        // ------------------------------------------------------------
        System.out.println("\n¿La persona 2 esta infectada antes de tocarse el rostro? "
                + (persona2.estaInfectada() ? "SI" : "NO"));

        // ------------------------------------------------------------
        // 7. La persona 2 se toca el rostro con las manos contaminadas
        //    -> Invariante 4: ahora SI se infecta
        // ------------------------------------------------------------
        persona2.tocarRostro();

        // ------------------------------------------------------------
        // 8. La persona 3 decide lavarse las manos ANTES de tocarse el rostro
        //    -> Invariante 5: se interrumpe la cadena, la persona 3 no se infecta
        // ------------------------------------------------------------
        persona3.lavarManos();
        persona3.tocarRostro();

        System.out.println("\nESTADO FINAL");
        cadena.mostrarEstado();

        sc.close();
    }
}