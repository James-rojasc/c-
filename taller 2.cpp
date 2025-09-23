// === EJERCICIOS PARA PRACTICAR ===

//1. Crea un programa que encuentre la mediana de un array

#include <iostream>
#include <algorithm>
using namespace std;

double encontrarMediana(int arr[], int n) {
    sort(arr, arr + n);
    if (n % 2 == 0)
        return (arr[n/2 - 1] + arr[n/2]) / 2.0;
    else
        return arr[n/2];
}

int main() {
    int n;
    cout << "Ingrese el tamaño del array: ";
    cin >> n;
    int arr[n];
    cout << "Ingrese los elementos del array:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    double mediana = encontrarMediana(arr, n);
    cout << "La mediana es: " << mediana << endl;

//2. Implementa la búsqueda binaria en un array ordenado

int valor;
cout << "Ingrese el valor a buscar: ";
cin >> valor;

int izquierda = 0, derecha = n - 1, encontrado = -1;
while (izquierda <= derecha) {
    int medio = izquierda + (derecha - izquierda) / 2;
    if (arr[medio] == valor) {
        encontrado = medio;
        break;
    } else if (arr[medio] < valor) {
        izquierda = medio + 1;
    } else {
        derecha = medio - 1;
    }
}

if (encontrado != -1)
    cout << "El valor " << valor << " se encuentra en la posición " << encontrado << endl;
else
    cout << "El valor " << valor << " no se encuentra en el array." << endl;


//3. Desarrolla un programa que calcule la transpuesta de una matriz

int filas, columnas;
cout << "Ingrese el número de filas de la matriz: ";
cin >> filas;
cout << "Ingrese el número de columnas de la matriz: ";
cin >> columnas;

int matriz[100][100], transpuesta[100][100];

// Ingresar la matriz
cout << "Ingrese los elementos de la matriz:\n";
for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
        cin >> matriz[i][j];
    }
}

// Calcular la transpuesta
for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
        transpuesta[j][i] = matriz[i][j];
    }
}

// Mostrar la matriz transpuesta
cout << "La matriz transpuesta es:\n";
for (int i = 0; i < columnas; i++) {
    for (int j = 0; j < filas; j++) {
        cout << transpuesta[i][j] << " ";
    }
    cout << endl;
}

//4. Crea un sistema de inventario simple con arrays

const int MAX_PRODUCTOS = 100;
string nombres[MAX_PRODUCTOS];
int cantidades[MAX_PRODUCTOS];
double precios[MAX_PRODUCTOS];
int totalProductos = 0;

int opcion;
do {
    cout << "\n--- Sistema de Inventario ---\n";
    cout << "1. Agregar producto\n";
    cout << "2. Mostrar inventario\n";
    cout << "3. Salir\n";
    cout << "Seleccione una opcion: ";
    cin >> opcion;
    cin.ignore();

    if (opcion == 1) {
        if (totalProductos < MAX_PRODUCTOS) {
            cout << "Nombre del producto: ";
            getline(cin, nombres[totalProductos]);
            cout << "Cantidad: ";
            cin >> cantidades[totalProductos];
            cout << "Precio: ";
            cin >> precios[totalProductos];
            totalProductos++;
        } else {
            cout << "Inventario lleno.\n";
        }
    } else if (opcion == 2) {
        cout << "\nInventario:\n";
        for (int i = 0; i < totalProductos; i++) {
            cout << i+1 << ". " << nombres[i] << " - Cantidad: " << cantidades[i] << " - Precio: $" << precios[i] << endl;
        }
    }
} while (opcion != 3);

// 5 Implementa el algoritmo de ordenamiento por selección

// Algoritmo de ordenamiento por selección
cout << "Ingrese el tamaño del array para ordenar por selección: ";
int tam;
cin >> tam;
int arrSel[tam];
cout << "Ingrese los elementos del array:\n";
for (int i = 0; i < tam; i++) {
    cin >> arrSel[i];
}

for (int i = 0; i < tam - 1; i++) {
    int min_idx = i;
    for (int j = i + 1; j < tam; j++) {
        if (arrSel[j] < arrSel[min_idx]) {
            min_idx = j;
        }
    }
    if (min_idx != i) {
        int temp = arrSel[i];
        arrSel[i] = arrSel[min_idx];
        arrSel[min_idx] = temp;
    }
}

cout << "Array ordenado por selección:\n";
for (int i = 0; i < tam; i++) {
    cout << arrSel[i] << " ";
}
cout << endl;

// 6 desarrolla un programa que encuentre elementos duplicados

// Encontrar elementos duplicados en un array
cout << "Ingrese el tamaño del array para buscar duplicados: ";
int tamDup;
cin >> tamDup;
int arrDup[tamDup];
cout << "Ingrese los elementos del array:\n";
for (int i = 0; i < tamDup; i++) {
    cin >> arrDup[i];
}

cout << "Elementos duplicados encontrados:\n";
bool hayDuplicados = false;
for (int i = 0; i < tamDup; i++) {
    bool yaMostrado = false;
    for (int k = 0; k < i; k++) {
        if (arrDup[i] == arrDup[k]) {
            yaMostrado = true;
            break;
        }
    }
    if (yaMostrado) continue;
    for (int j = i + 1; j < tamDup; j++) {
        if (arrDup[i] == arrDup[j]) {
            cout << arrDup[i] << endl;
            hayDuplicados = true;
            break;
        }
    }
}
if (!hayDuplicados) {
    cout << "No se encontraron elementos duplicados." << endl;
}

// 7. Crea un juego de tres en raya usando arrays bidimensionales

char tablero[3][3];
for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
        tablero[i][j] = ' ';

int jugador = 1;
int movimientos = 0;
bool ganador = false;

auto mostrarTablero = [&]() {
    cout << "  0 1 2\n";
    for (int i = 0; i < 3; i++) {
        cout << i << " ";
        for (int j = 0; j < 3; j++) {
            cout << tablero[i][j];
            if (j < 2) cout << "|";
        }
        cout << endl;
        if (i < 2) cout << "  -+-+-\n";
    }
};

auto verificarGanador = [&]() -> char {
    for (int i = 0; i < 3; i++) {
        if (tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2] && tablero[i][0] != ' ')
            return tablero[i][0];
        if (tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i] && tablero[0][i] != ' ')
            return tablero[0][i];
    }
    if (tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2] && tablero[0][0] != ' ')
        return tablero[0][0];
    if (tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0] && tablero[0][2] != ' ')
        return tablero[0][2];
    return ' ';
};

cout << "\n--- Tres en Raya ---\n";
while (movimientos < 9 && !ganador) {
    mostrarTablero();
    int fila, columna;
    char simbolo = (jugador == 1) ? 'X' : 'O';
    cout << "Turno del jugador " << jugador << " (" << simbolo << "). Ingrese primero la fila y luego la columna: ";
    cin >> fila >> columna;
    if (fila < 0 || fila > 2 || columna < 0 || columna > 2 || tablero[fila][columna] != ' ') {
        cout << "Movimiento inválido. Intente de nuevo.\n";
        continue;
    }
    tablero[fila][columna] = simbolo;
    movimientos++;
    char ganadorSimbolo = verificarGanador();
    if (ganadorSimbolo != ' ') {
        mostrarTablero();
        cout << "¡El jugador " << ((ganadorSimbolo == 'X') ? 1 : 2) << " (" << ganadorSimbolo << ") gana!\n";
        ganador = true;
    } else if (movimientos == 9) {
        mostrarTablero();
        cout << "¡Empate!\n";
    } else {
        jugador = 3 - jugador;
    }
}
}