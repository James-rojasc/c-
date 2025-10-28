#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// ========== PUNTO 1: STRUCT CON CONSTRUCTORES ==========
namespace Punto1 {
    struct Producto {
        string nombre;
        double precio;
        int stock;
        
        Producto(string n = "", double p = 0.0, int s = 0) {
            nombre = n;
            precio = p;
            stock = s;
        }
    };
    
    void ejecutar() {
        cout << "\n=== PUNTO 1: Struct con constructores ===" << endl;
        Producto p1;
        Producto p2("Laptop", 1500.0);
        Producto p3("Mouse", 25.5, 50);
        
        cout << "Producto 1: " << p1.nombre << " | Precio: $" << p1.precio << " | Stock: " << p1.stock << endl;
        cout << "Producto 2: " << p2.nombre << " | Precio: $" << p2.precio << " | Stock: " << p2.stock << endl;
        cout << "Producto 3: " << p3.nombre << " | Precio: $" << p3.precio << " | Stock: " << p3.stock << endl;
    }
}

// ========== PUNTO 2: MÉTODOS CONST Y VALIDACIÓN ==========
namespace Punto2 {
    struct Producto {
        string nombre;
        double precio;
        int stock;
        
        Producto(string n = "", double p = 0.0, int s = 0) : nombre(n), precio(p), stock(s) {}
        
        bool disponible() const { return stock > 0; }
        bool esValido() const { return precio >= 0 && !nombre.empty(); }
    };
    
    void ejecutar() {
        cout << "\n=== PUNTO 2: Métodos const y validación ===" << endl;
        vector<Producto> productos = {
            Producto("Teclado", 45.0, 10),
            Producto("", 30.0, 5),
            Producto("Monitor", -100, 2),
            Producto("Ratón", 20.0, 0),
            Producto("USB", 10.0, 15)
        };
        
        productos.erase(
            remove_if(productos.begin(), productos.end(), 
                [](const Producto& p) { return !p.esValido(); }),
            productos.end()
        );
        
        cout << "Productos válidos y disponibles:" << endl;
        for (const auto& p : productos) {
            if (p.disponible()) {
                cout << p.nombre << " | $" << p.precio << " | Stock: " << p.stock << endl;
            }
        }
    }
}

// ========== PUNTO 3: OPERADORES == Y < ==========
namespace Punto3 {
    struct Producto {
        string nombre;
        double precio;
        int stock;
        
        Producto(string n = "", double p = 0.0, int s = 0) : nombre(n), precio(p), stock(s) {}
        
        bool operator==(const Producto& otro) const {
            string n1 = nombre, n2 = otro.nombre;
            transform(n1.begin(), n1.end(), n1.begin(), ::tolower);
            transform(n2.begin(), n2.end(), n2.begin(), ::tolower);
            return n1 == n2;
        }
        
        bool operator<(const Producto& otro) const {
            if (precio != otro.precio) return precio < otro.precio;
            return nombre < otro.nombre;
        }
    };
    
    void ejecutar() {
        cout << "\n=== PUNTO 3: Operadores == y < ===" << endl;
        vector<Producto> productos = {
            Producto("Mouse", 25.0, 10),
            Producto("Teclado", 45.0, 5),
            Producto("USB", 10.0, 20),
            Producto("Monitor", 200.0, 3),
            Producto("mouse", 30.0, 8)
        };
        
        sort(productos.begin(), productos.end());
        
        cout << "Productos ordenados por precio:" << endl;
        for (const auto& p : productos) {
            cout << p.nombre << " | $" << p.precio << endl;
        }
        
        Producto buscado("MOUSE");
        auto it = find(productos.begin(), productos.end(), buscado);
        
        cout << "\nBúsqueda de 'MOUSE':" << endl;
        if (it != productos.end()) {
            cout << "Encontrado: " << it->nombre << " | $" << it->precio << endl;
        }
    }
}

// ========== PUNTO 4: POLINOMIO ==========
namespace Punto4 {
    struct Polinomio {
        vector<double> coeficientes;
        
        Polinomio(vector<double> coefs = {}) : coeficientes(coefs) {}
        
        double evaluar(double x) const {
            double resultado = 0.0;
            for (size_t i = 0; i < coeficientes.size(); i++) {
                resultado += coeficientes[i] * pow(x, i);
            }
            return resultado;
        }
        
        void imprimir() const {
            bool primero = true;
            for (int i = coeficientes.size() - 1; i >= 0; i--) {
                if (coeficientes[i] == 0) continue;
                
                if (!primero && coeficientes[i] > 0) cout << " + ";
                else if (coeficientes[i] < 0) cout << " - ";
                
                if (abs(coeficientes[i]) != 1 || i == 0) 
                    cout << abs(coeficientes[i]);
                
                if (i > 0) cout << "x";
                if (i > 1) cout << "^" << i;
                
                primero = false;
            }
            cout << endl;
        }
        
        Polinomio operator+(const Polinomio& otro) const {
            size_t maxTam = max(coeficientes.size(), otro.coeficientes.size());
            vector<double> resultado(maxTam, 0.0);
            
            for (size_t i = 0; i < coeficientes.size(); i++)
                resultado[i] += coeficientes[i];
            
            for (size_t i = 0; i < otro.coeficientes.size(); i++)
                resultado[i] += otro.coeficientes[i];
            
            return Polinomio(resultado);
        }
    };
    
    void ejecutar() {
        cout << "\n=== PUNTO 4: Polinomio ===" << endl;
        Polinomio p1({1, 2, 3});
        Polinomio p2({0, 4, 0, 5});
        
        cout << "P1(x) = "; p1.imprimir();
        cout << "P2(x) = "; p2.imprimir();
        cout << "\nP1(2) = " << p1.evaluar(2) << endl;
        
        Polinomio suma = p1 + p2;
        cout << "\nP1 + P2 = "; suma.imprimir();
    }
}

// ========== PUNTO 5: INVENTARIO COMPLEJO ==========
namespace Punto5 {
    struct Producto {
        string nombre;
        double precio;
        int stock;
        string categoria;
        
        Producto(string n, double p, int s, string c) 
            : nombre(n), precio(p), stock(s), categoria(c) {}
        
        bool disponible() const { return stock > 0; }
    };
    
    struct Inventario {
        vector<Producto> productos;
        
        void agregar(const Producto& p) { productos.push_back(p); }
        
        void vender(const string& nombre, int cantidad) {
            for (auto& p : productos) {
                if (p.nombre == nombre) {
                    if (p.stock >= cantidad) {
                        p.stock -= cantidad;
                        cout << "Venta exitosa: " << cantidad << " unidades de " << nombre << endl;
                    } else {
                        cout << "Stock insuficiente para " << nombre << endl;
                    }
                    return;
                }
            }
            cout << "Producto no encontrado: " << nombre << endl;
        }
        
        void reabastecer(const string& nombre, int cantidad) {
            for (auto& p : productos) {
                if (p.nombre == nombre) {
                    p.stock += cantidad;
                    cout << "Reabastecido: " << nombre << " (+" << cantidad << ")" << endl;
                    return;
                }
            }
        }
        
        void mostrarPorCategoria(const string& cat) const {
            cout << "\n=== Categoría: " << cat << " ===" << endl;
            for (const auto& p : productos) {
                if (p.categoria == cat) {
                    cout << p.nombre << " | $" << p.precio << " | Stock: " << p.stock << endl;
                }
            }
        }
        
        double valorTotal() const {
            double total = 0.0;
            for (const auto& p : productos) {
                total += p.precio * p.stock;
            }
            return total;
        }
    };
    
    void ejecutar() {
        cout << "\n=== PUNTO 5: Sistema de inventario ===" << endl;
        Inventario inv;
        
        inv.agregar(Producto("Laptop", 1200.0, 5, "Electrónica"));
        inv.agregar(Producto("Mouse", 25.0, 50, "Accesorios"));
        inv.agregar(Producto("Monitor", 300.0, 8, "Electrónica"));
        inv.agregar(Producto("Teclado", 45.0, 30, "Accesorios"));
        
        inv.mostrarPorCategoria("Electrónica");
        inv.mostrarPorCategoria("Accesorios");
        
        inv.vender("Mouse", 10);
        inv.vender("Laptop", 6);
        inv.reabastecer("Laptop", 10);
        
        cout << "\nValor total del inventario: $" << inv.valorTotal() << endl;
    }
}

// ========== PUNTO 6: FRACCIONES ==========
namespace Punto6 {
    int mcd(int a, int b) {
        a = abs(a); b = abs(b);
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    
    struct Fraccion {
        int numerador, denominador;
        
        Fraccion(int num = 0, int den = 1) : numerador(num), denominador(den) {
            if (denominador == 0) {
                cout << "Error: denominador cero, ajustando a 1" << endl;
                denominador = 1;
            }
            simplificar();
        }
        
        void simplificar() {
            int divisor = mcd(numerador, denominador);
            numerador /= divisor;
            denominador /= divisor;
            if (denominador < 0) {
                numerador = -numerador;
                denominador = -denominador;
            }
        }
        
        Fraccion operator+(const Fraccion& otra) const {
            return Fraccion(numerador * otra.denominador + otra.numerador * denominador, 
                          denominador * otra.denominador);
        }
        
        Fraccion operator-(const Fraccion& otra) const {
            return Fraccion(numerador * otra.denominador - otra.numerador * denominador, 
                          denominador * otra.denominador);
        }
        
        Fraccion operator*(const Fraccion& otra) const {
            return Fraccion(numerador * otra.numerador, denominador * otra.denominador);
        }
        
        Fraccion operator/(const Fraccion& otra) const {
            return Fraccion(numerador * otra.denominador, denominador * otra.numerador);
        }
        
        void imprimir() const {
            if (denominador == 1) cout << numerador;
            else cout << numerador << "/" << denominador;
        }
        
        double decimal() const { return (double)numerador / denominador; }
    };
    
    void ejecutar() {
        cout << "\n=== PUNTO 6: Fracciones ===" << endl;
        Fraccion f1(3, 4), f2(2, 5);
        
        cout << "f1 = "; f1.imprimir(); cout << " = " << f1.decimal() << endl;
        cout << "f2 = "; f2.imprimir(); cout << " = " << f2.decimal() << endl;
        
        Fraccion suma = f1 + f2;
        cout << "\nf1 + f2 = "; suma.imprimir(); cout << endl;
        
        Fraccion resta = f1 - f2;
        cout << "f1 - f2 = "; resta.imprimir(); cout << endl;
        
        Fraccion producto = f1 * f2;
        cout << "f1 * f2 = "; producto.imprimir(); cout << endl;
        
        Fraccion division = f1 / f2;
        cout << "f1 / f2 = "; division.imprimir(); cout << endl;
    }
}

// ========== PUNTO 7: AGENDA DE CONTACTOS ==========
namespace Punto7 {
    struct Contacto {
        string nombre, telefono, email, categoria;
        
        Contacto(string n, string t, string e, string c = "general")
            : nombre(n), telefono(t), email(e), categoria(c) {}
        
        void imprimir() const {
            cout << "Nombre: " << nombre << " | Tel: " << telefono 
                 << " | Email: " << email << " | Cat: " << categoria << endl;
        }
        
        bool operator<(const Contacto& otro) const {
            return nombre < otro.nombre;
        }
    };
    
    struct Agenda {
        vector<Contacto> contactos;
        
        void agregar(const Contacto& c) {
            contactos.push_back(c);
            sort(contactos.begin(), contactos.end());
        }
        
        void eliminar(const string& nombre) {
            auto it = remove_if(contactos.begin(), contactos.end(),
                [&nombre](const Contacto& c) { return c.nombre == nombre; });
            
            if (it != contactos.end()) {
                contactos.erase(it, contactos.end());
                cout << "Contacto eliminado: " << nombre << endl;
            } else {
                cout << "Contacto no encontrado: " << nombre << endl;
            }
        }
        
        void buscar(const string& nombre) const {
            cout << "\nResultados de búsqueda para '" << nombre << "':" << endl;
            bool encontrado = false;
            
            for (const auto& c : contactos) {
                if (c.nombre.find(nombre) != string::npos) {
                    c.imprimir();
                    encontrado = true;
                }
            }
            
            if (!encontrado) cout << "No se encontraron coincidencias." << endl;
        }
        
        void mostrarPorCategoria(const string& cat) const {
            cout << "\n=== Contactos - " << cat << " ===" << endl;
            for (const auto& c : contactos) {
                if (c.categoria == cat) c.imprimir();
            }
        }
        
        void listarTodos() const {
            cout << "\n=== Todos los contactos ===" << endl;
            for (const auto& c : contactos) c.imprimir();
        }
    };
    
    void ejecutar() {
        cout << "\n=== PUNTO 7: Gestión de contactos ===" << endl;
        Agenda agenda;
        
        agenda.agregar(Contacto("Juan Pérez", "555-1234", "juan@mail.com", "trabajo"));
        agenda.agregar(Contacto("María López", "555-5678", "maria@mail.com", "familia"));
        agenda.agregar(Contacto("Carlos Ruiz", "555-9012", "carlos@mail.com", "amigos"));
        agenda.agregar(Contacto("Ana García", "555-3456", "ana@mail.com", "trabajo"));
        
        agenda.listarTodos();
        agenda.buscar("Carlos");
        agenda.mostrarPorCategoria("trabajo");
        agenda.eliminar("María López");
        agenda.listarTodos();
    }
}

// ========== MENÚ PRINCIPAL ==========
int main() {
    int opcion;
    
    do {
        cout << "\n========================================" << endl;
        cout << "  TALLER STRUCT EN C++ - MENÚ PRINCIPAL" << endl;
        cout << "========================================" << endl;
        cout << "1. Struct con constructores y valores por defecto" << endl;
        cout << "2. Métodos const y validación" << endl;
        cout << "3. Operadores == y < para ordenar y buscar" << endl;
        cout << "4. Estructura para representar un polinomio" << endl;
        cout << "5. Sistema de inventario más complejo" << endl;
        cout << "6. Estructura para representar una fracción" << endl;
        cout << "7. Sistema de gestión de contactos" << endl;
        cout << "0. Salir" << endl;
        cout << "\nSelecciona una opción: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1: Punto1::ejecutar(); break;
            case 2: Punto2::ejecutar(); break;
            case 3: Punto3::ejecutar(); break;
            case 4: Punto4::ejecutar(); break;
            case 5: Punto5::ejecutar(); break;
            case 6: Punto6::ejecutar(); break;
            case 7: Punto7::ejecutar(); break;
            case 0: cout << "\nSaliendo del programa..." << endl; break;
            default: cout << "\nOpción no válida, intenta de nuevo." << endl;
        }
        
        if (opcion != 0) {
            cout << "\nPresiona Enter para volver al menú...";
            cin.ignore();
            cin.get();
        }
        
    } while(opcion != 0);
    
    return 0;
}
