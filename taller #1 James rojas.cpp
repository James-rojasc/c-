// Parte 1: Variables y Operadores
#include<iostream>
using namespace std;
int main(){

//1. Declara dos variables enteras a y b, asigna valores y muestra en pantalla la suma, resta,multiplicación y división.
int a, b;
cout<< " ingrese un numero entero: ";
cin>> a;
cout<< " ingrese otro numero entero: ";
cin>> b; 
cout << "Suma: " << (a + b) << endl;
cout << "Resta: " << (a - b) << endl;
cout << "Multiplicacion: " << (a * b) << endl;
cout << "Division: " << (a / b) << endl;

// 2. Calcula el área y el perímetro de un rectángulo dado su base y altura
int base, altura;
cout << "Ingrese la base del rectangulo: ";
cin >> base;
cout << "Ingrese la altura del rectangulo: ";
cin >> altura;
int area = base * altura;
int perimetro = 2 * (base + altura);
cout << "Area del rectangulo: " << area << endl;
cout << "Perimetro del rectangulo: " << perimetro << endl;

//3. Dado un número en grados Celsius, conviértelo a Fahrenheit. Fórmula: F = (C × 9/5) + 32
int celsius;
cout << "Ingrese la temperatura en grados Celsius: ";
cin >> celsius;
float fahrenheit = (celsius * 9.0 / 5.0) + 32;
cout << celsius << " grados Celsius son " << fahrenheit << " grados Fahrenheit." << endl;

//4. Escribe un programa que reciba 3 notas de un estudiante y calcule el promedio.
float nota1, nota2, nota3;
cout << "Ingrese la primera nota: ";
cin >> nota1;
cout << "Ingrese la segunda nota: ";
cin >> nota2;
cout << "Ingrese la tercera nota: ";
cin >> nota3;
float promedio = (nota1 + nota2 + nota3) / 3;
cout << "El promedio de las notas es: " << promedio << endl;

//Parte 2: Condicionales

//5. Dado un número entero, determina si es par o impar
int numero;
cout << "Ingrese un numero entero: ";
cin >> numero;
if (numero % 2 == 0) {
    cout << "El numero es par." << endl;
} else {
    cout << "El numero es impar." << endl;
}

//6. Pide la edad de una persona e imprime si es menor de edad o mayor de edad.
int edad;
cout << "Ingrese su edad: ";
cin >> edad;
if (edad < 18) {
    cout << "Es menor de edad." << endl;
} else { edad >=18;
    cout << "Es mayor de edad." << endl;
}

//7. Crea un programa que reciba el sueldo de un trabajador y calcule el aumento...
float sueldo, aumento, nuevo_sueldo;
cout << "Ingrese el sueldo del trabajador: ";
cin >> sueldo;

if (sueldo < 1000) {
    aumento = sueldo * 0.15;
} else if (sueldo <= 2000) {
    aumento = sueldo * 0.10;
} else {
    aumento = sueldo * 0.05;
}

nuevo_sueldo = sueldo + aumento;
cout << "El aumento es: " << aumento << endl;
cout << "El nuevo sueldo es: " << nuevo_sueldo << endl;

// 8. Un programa que pida tres números y muestre el mayor de ellos.
int num1, num2, num3;
cout << "Ingrese el primer numero: ";
cin >> num1;
cout << "Ingrese el segundo numero: ";
cin >> num2;
cout << "Ingrese el tercer numero: ";
cin >> num3;

int mayor = num1;
if (num2 > mayor) {
    mayor = num2;
}
if (num3 > mayor) {
    mayor = num3;
}
cout << "El mayor de los tres numeros es: " << mayor << endl;

//Parte 3: Bucles
//9. Imprime los números del 1 al 10 con un bucle for
for (int i = 1; i <= 10; i++) {
    cout << i << endl;
}

//10. Calcula la suma de los primeros n números naturales (ingresados por teclado).
int n, suma = 0;
cout << "Ingrese un numero n para sumar los primeros n numeros naturales: ";
cin >> n;
for (int i = 1; i <= n; i++) {
    suma += i;
}
cout << "La suma de los primeros " << n << " numeros naturales es: " << suma << endl;

//11. Dado un número, muestra su tabla de multiplicar (del 1 al 10)
int numero_tabla;
cout << "Ingrese un numero para mostrar su tabla de multiplicar: ";
cin >> numero_tabla;
cout << "Tabla de multiplicar del " << numero_tabla << ":" << endl;
for (int i = 1; i <= 10; i++) {
    cout << numero_tabla << " x " << i << " = " << (numero_tabla * i) << endl;
}

//12. Crea un programa que pida una palabra y cuente cuántas vocales tiene
string palabra;
cout << "Ingrese una palabra: ";
cin >> palabra;
int contador_vocales = 0;
for (char c : palabra) {
    c = tolower(c);
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        contador_vocales++;
    }
}
cout << "La palabra tiene " << contador_vocales << " vocal(es)." << endl;

//13. Usa un bucle while para pedir al usuario un número positivo. El programa solo termina cuando lo ingrese correctamente.
int numero_positivo;
do {
    cout << "Ingrese un numero positivo: ";
    cin >> numero_positivo;
    if (numero_positivo <= 0) {
        cout << "El numero no es positivo. Intente de nuevo." << endl;
    }
} while (numero_positivo <= 0);
cout << "Ha ingresado el numero positivo: " << numero_positivo << endl;

//Parte 4: Ejercicios Integradores
//14. Crea un programa que simule un cajero automático: Muestra un menú con opciones (consultar saldo, depositar, retirar, salir). Usa variables, condicionales y bucles.
float saldo = 1000.0; // Saldo inicial
int opcion;
do {
    cout << "\n--- Cajero Automatico ---" << endl;
    cout << "1. Consultar saldo" << endl;
    cout << "2. Depositar dinero" << endl;
    cout << "3. Retirar dinero" << endl;
    cout << "4. Salir" << endl;
    cout << "Seleccione una opcion: ";
    cin >> opcion;

    switch (opcion) {
        case 1:
            cout << "Su saldo actual es: $" << saldo << endl;
            break;
        case 2: {
            float deposito;
            cout << "Ingrese la cantidad a depositar: ";
            cin >> deposito;
            if (deposito > 0) {
                saldo += deposito;
                cout << "Deposito exitoso. Nuevo saldo: $" << saldo << endl;
            } else {
                cout << "Cantidad invalida." << endl;
            }
            break;
        }
        case 3: {
            float retiro;
            cout << "Ingrese la cantidad a retirar: ";
            cin >> retiro;
            if (retiro > 0 && retiro <= saldo) {
                saldo -= retiro;
                cout << "Retiro exitoso. Nuevo saldo: $" << saldo << endl;
            } else if (retiro > saldo) {
                cout << "Fondos insuficientes." << endl;
            } else {
                cout << "Cantidad invalida." << endl;
            }
            break;
        }
        case 4:
            cout << "Gracias por usar el cajero automatico." << endl;
            break;
        default:
            cout << "Opcion no valida. Intente de nuevo." << endl;
    }
} while (opcion != 4);

//15. Realiza un programa que pida un número n y genere la secuencia Fibonacci hasta n términos.
int n_fibo;
cout << "Ingrese el numero de terminos de la secuencia Fibonacci: ";
cin >> n_fibo;
int t1 = 0, t2 = 1;
cout << "Secuencia Fibonacci: ";
for (int i = 1; i <= n_fibo; i++) {
    cout << t1;
    if (i < n_fibo) cout << ", ";
    int siguiente = t1 + t2;
    t1 = t2;
    t2 = siguiente;
}
cout << endl;
}