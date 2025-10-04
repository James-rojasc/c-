#include <iostream> 

using namespace std;

int main() {

// pregunta 1.1 

int items = 17;
int numero = 4;
float precio = 50.000;
float metros = 1.78;
char inicial = 'q';

cout << "edad: " << items << endl;
cout << "numero: " << numero << endl;
cout << "precio: " << precio << endl;
cout << "metros: " << metros << endl;
cout << "inicial: " << inicial << endl;

// pregunta 1.2 

// el int almacena numeros enteros osea positivos, negativos o en su defecto 0.
// el float almacena numeros con parte decimal, ejemmplo: 1.3333 
// el char almacena un solo caracter ejemplo: (j)
// cuando usar cada uno
// int se usa cuando necesitamos representar cantidades enteras como: edad, items, etc
// el float se usa cuando se requiere decimales como: promedios, porcentajes, etc
// el char se usa cuando se necesite un caracter individual como: A, 7; ?

// pregunta 2.1 

int a, b;
cout << "--- Operadores ---\n";
cout << "Ingrese el primer numero: ";
cin >> a;
cout << "Ingrese el segundo numero: ";
cin >> b;

cout << "Suma: " << (a + b) << endl;
cout << "Resta: " << (a - b) << endl;
cout << "Multiplicacion: " << (a * b) << endl;

if (b != 0) {
    cout << "Division: " << (a / b) << endl;
    cout << "Modulo: " << (a % b) << endl;
} else {
    cout << "No se puede dividir entre cero." << endl;
}

// pregunta 2.2 y 2.3 

    if (a == b) cout << "a y b son iguales\n";
    if (a != b) cout << "a y b son distintos\n";

    int x = 5;
    if (x > 0 && x < 10) cout << "x esta entre 1 y 9\n";
    if (x < 0 || x > 100) cout << "x esta fuera de rango\n";
    if (!(x == 5)) cout << "x no es 5\n";

// pregunta 3.1 

cout << "--- Condicionales ---\n";
    int edad;
    cout << "Ingrese su edad: ";
    cin >> edad;

    if (edad >= 18) {
        cout << "Eres mayor de edad.\n";
    } else {
        cout << "Eres menor de edad.\n";
    }

//pregunta 3.2

// funcion de if sirve para evaluar varias condiciones de forma secuencial
int nota;
    cout << "Ingrese una nota (1.0-5.0): ";
    cin >> nota;

    if (nota >= 5.0) cout << "Excelente\n";
    else if (nota >= 3.0) cout << "Aprobado\n";
    else cout << "Reprobado\n";


//pregunta 4.1 
cout << "Numeros del 1 al 10 con for:\n";
    for (int i = 1; i <= 10; i++) {
        cout << i << " ";
    }
    cout << endl;
    
//pregunta 4.2 
 cout << "Numeros del 10 al 1 con while:\n";
    int i = 10;
    while (i >= 1) {
        cout << i << " ";
        i--;
    }
    cout << endl;

//pregunta 4.3
 cout << "Numeros pares entre 1 y 20 con do-while:\n";
    i = 2;
    do {
        cout << i << " ";
        i += 2;
    } while (i <= 20);
    cout << endl;

//pregunta 5.1

 int numeros[5];
    cout << "Ingrese 5 numeros enteros:\n";
    for (int i = 0; i < 5; i++) {
        cin >> numeros[i];
    }
    cout << "Los numeros ingresados son:\n";
    for (int i = 0; i < 5; i++) {
        cout << numeros[i] << " ";
    }
    cout << endl;

//pregunta 5.2

// es una colección de datos organizados en forma de tabla
int matriz2x3[2][3] = {{1,2,3},{4,5,6}};
    cout << "Ejemplo array bidimensional 2x3:\n";
    cout << "Elemento en fila 0, columna 1: " << matriz2x3[0][1] << endl;

}