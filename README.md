# 🦠 TDA Coronavirus — Simulación de Transmisión por Contacto

¡Bienvenidos al repositorio de nuestro proyecto grupal para la materia de **Estructura de Datos**!

---

## 📌 ¿De qué trata el proyecto?

Este proyecto busca modelar y simular, a través de un **Tipo de Dato Abstracto (TDA)**, cómo se propaga el coronavirus en situaciones cotidianas de contacto indirecto y directo.

El flujo básico que representamos es:
1. Una **persona infectada** estornuda sobre un **objeto** y lo contamina.
2. Otra persona sana toca ese objeto y **se contamina las manos** (¡pero ojo! tener las manos sucias aún no significa estar enfermo).
3. Si esa persona se **toca el rostro** con las manos contaminadas, el virus entra al organismo y pasa a estar **infectada**.
4. Si decide **lavarse las manos a tiempo**, corta la cadena y se mantiene sana.

Desarrollamos la solución en **Java** y **C++** para verificar que las reglas funcionen exactamente igual en ambos y comparar cómo maneja la memoria cada lenguaje.

---

## 🎯 Objetivos

* **General:** Diseñar, construir y comprobar el TDA Coronavirus en Java y C++, aplicando el análisis de estados, operaciones e invariantes visto en clase, y comparar el rendimiento de memoria entre ambos.
* **Específicos:**
  * Identificar claramente los estados, operaciones e invariantes del sistema.
  * Diseñar el diagrama de clases en UML.
  * Programar la solución completa tanto en Java como en C++.
  * Analizar el uso de tipos primitivos (`boolean` / `bool`) y el impacto en memoria (JVM vs. código nativo).

---

## 🧠 ¿Cómo diseñamos el TDA?

Seguimos paso a paso la metodología vista en clase:

### 1. Estados y atributos
* **Persona:**
  * `nombre` (Identificador)
  * `infectada` (`boolean`/`bool`): Si tiene la enfermedad.
  * `manosContaminadas` (`boolean`/`bool`): Si transporta el virus temporalmente.
* **Objeto:**
  * `nombre` (Identificador)
  * `contaminado` (`boolean`/`bool`): Si tiene carga viral en la superficie.

### 2. Reglas clave (Invariantes)
Para que el programa sea coherente con la realidad médica, se deben cumplir siempre estas reglas:
* Solo una persona que **ya está infectada** puede contaminar un objeto al estornudar.
* Tocar un objeto limpio nunca contamina las manos.
* Manos contaminadas $\neq$ estar infectado.
* El contagio solo se produce al tocarse los ojos, nariz o boca (rostro) con las manos sucias.
* Lavarse las manos elimina el virus y rompe la cadena de contagio.

---

## 👥 Equipo de Trabajo

| Integrante | Rol | ¿Qué hace en el proyecto? |
| :--- | :--- | :--- |
| **Cunalata Mendoza Damian Alexander** | Líder Técnico & Integrador | Gestión del repositorio en GitHub, revisión de ramas y Pull Requests, integración general, compilación y pruebas finales. |
| **Tacuri Santillan Mónica Sara** | Documentación Teórica | Redacción de la introducción, planteamiento del problema, objetivos, metodología y definición de estados/operaciones. |
| **Camacho Monta Josue Jampier** | Documentación Técnica | Explicación detallada de invariantes, elaboración del diagrama UML, casos de prueba, conclusiones y bibliografía. |
| **Chalco Tasna Kenneth Mateo** | Programador Java (Entidades) | Construcción de las clases base `Persona.java` y `Objeto.java` con sus métodos y pruebas unitarias. |
| **Silva Camuendo Luis Alexander** | Programador Java (Lógica y Main) | Desarrollo de `CadenaTransmision.java` y la simulación completa en `Main.java` validando las reglas de contagio. |
| **Tisalema Guashco Darwin Joel** | Programador C++ & Memoria | Implementación de todo el código en C++ (`Persona.cpp`, `Objeto.cpp`, `CadenaTransmision.cpp`, `main.cpp`) y análisis del uso de memoria (Java vs. C++). |

---

## 📂 Organización de Carpetas

El repositorio está estructurado de la siguiente manera:

```text
Estructura_Datos/
├── java/
│   └── Transmision/
│       ├── Persona.java              # Clase Persona
│       ├── Objeto.java               # Clase Objeto
│       ├── CadenaTransmision.java    # Lógica de interacción
│       └── Main.java                 # Simulación en consola Java
│
├── cpp/
│   └── Transmision/
│       ├── Persona.cpp               # Clase Persona (C++)
│       ├── Objeto.cpp                # Clase Objeto (C++)
│       ├── CadenaTransmision.cpp     # Lógica e interacciones (C++)
│       └── main.cpp                  # Simulación en consola C++
│
├── docs/
│   ├── Informe_TDA_Coronavirus.docx  # Documento editable
│   ├── Informe_TDA_Coronavirus.pdf   # Informe final para entrega
│   ├── Diagrama_UML.png              # Diagrama de clases
│   ├── Ejecucion_Java.png            # Captura de consola Java
│   └── Ejecucion_CPP.png             # Captura de consola C++
│
├── .gitignore
└── README.md
