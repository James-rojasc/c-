// Sección A — Opción múltiple (10 × 3 pts = 30 pts)

// 1) ¿Cuál declara y define una variable entera con valor 10? 
// R/ B

// 2) ¿Qué imprime? std::cout << 7/2 << " " << 7/2.0; 
// R/ B

//3) Con bool a=true, b=false; ¿Qué imprime? std::cout << (a&&b) << " " << (a||b) << " " << (!b);  
// R/ C

//4) Dado int x=3; if (x=0) { ... } else { ... } ¿qué ocurre? 
// R/ C

//5) do-while respecto a while: 
// R/ B

//6) ¿Cuál lee dos enteros separados por espacio? 
// R/ C

//7) ¿Qué imprime?
// R/ A

//8) ¿Cuál firma pasa un entero por referencia?
// R/ B

//9) ¿Qué hace continue en un for?
// R/ B

//10) ¿Cuál condición es verdadera?
// R/ A

// Sección B — Predice la salida (5 × 6 pts = 30 pts)
// Escribe exactamente lo que se imprime (respeta espacios y saltos de línea).

// 1) R/ 11

// 2) R/ 0 1 2

// 3) R/ par

// 4) R/ 3210

// 5) R/ 2 200

// Sección C — Implementación de funciones (4 × 10 pts = 40 pts)
// Programa solo las funciones pedidas. Puedes probar mentalmente con casos de ejemplo.

// C1
#include <iostream>
using namespace std;


int max3(int a, int b, int c) {
    if (a >= b && a >= c)
        return a;
    else if (b >= a && b >= c)
        return b;
    else
        return c;
}

// C2 
int sumaRango(int a, int b) {
    int suma = 0;
    for (int i = a; i <= b; ++i)
        suma += i;
    return suma;
}

//C3
bool contieneDigito(int n, int d) {
    if (n == 0 && d == 0)
        return true;
    while (n > 0) {
        if (n % 10 == d)
            return true;
        n /= 10;
    }
    return false;
}

//C4 
void tablaMultiplicar(int n) {
    for (int i = 1; i <= 10; ++i)
        std::cout << n << " x " << i << " = " << n * i << std::endl;
}
