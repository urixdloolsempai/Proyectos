🧮 Los Tralaleritos te calculan

Este es un programa en C++ que actúa como una calculadora int

🚀 Funcionalidades

El programa ofrece las siguientes operemáticas mediante un menú dinámico amigable para el usuario.

🚀 Funcionalidades

El programa ofrece las siguientes operaciones:

1. ➕ Suma


2. ➖ Resta


3. ✖️ Multiplicación


4. ➗ División (con validación de división por cero)


5. 🔼 Potencia (usando pow())


6. 📐 Raíz cuadrada (validando que el número no sea negativo)


7. ❌ Salir del programa




---

🛠️ Tecnologías usadas

C++

Librería <iostream>

Librería <cmath> (para uso de pow(), sqrt(), fmod())



---

📌 Estructura del programa

El código se divide en dos partes principales:

✔️ Función menu()

Muestra el menú de opciones en consola.

✔️ Función main()

Controla la ejecución del programa con un ciclo do...while

Recibe la opción del usuario mediante cin

Ejecuta operaciones según el switch(opcion)

Incluye validaciones para errores comunes (ej.: división por cero, raíz negativa)



---

🧠 Validaciones importantes

No se puede dividir por cero → el programa muestra un mensaje de error

No se puede hacer raíz cuadrada de un número negativo

Si la opción ingresada no existe, se muestra un aviso y se vuelve a pedir otra opción



---

▶️ Ejecución

Compilar el programa:

g++ main.cpp -o calculadora

Ejecutarlo:

./calculadora


---

🏁 Salida

Cuando el usuario selecciona la opción 0, el programa se despide con:

👋 Gracias por usar 'Los Tralaleritos te calculan'. ¡Hasta la próxima!


---
