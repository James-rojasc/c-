/*
TALLER DE PROGRAMACION ORIENTADA A OBJETOS - C++
Ejercicios: Getters, Setters y Herencia - VERSION INTERACTIVA
Autor: James rojas
Fecha: 27 de Noviembre del 2025
*/

#include <iostream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

// NIVEL 1: GETTERS Y SETTERS

// Ejercicio 1.1: Clase Vehiculo 
class Vehiculo {
private:
    string marca;
    string modelo;
    int anio;
    double velocidadMaxima;

public:
    // Constructor
    Vehiculo(string m, string mod, int a, double vel) {
        marca = m;
        modelo = mod;
        setAnio(a);
        setVelocidadMaxima(vel);
    }

    // Getters
    string getMarca() { return marca; }
    string getModelo() { return modelo; }
    int getAnio() { return anio; }
    double getVelocidadMaxima() { return velocidadMaxima; }

    // Setters con validaciones
    void setMarca(string m) { marca = m; }
    void setModelo(string mod) { modelo = mod; }
    
    void setAnio(int a) {
        if (a > 1886) {
            anio = a;
        } else {
            cout << "Error: El año debe ser mayor a 1886" << endl;
            anio = 1886;
        }
    }
    
    void setVelocidadMaxima(double vel) {
        if (vel > 0) {
            velocidadMaxima = vel;
        } else {
            cout << "Error: La velocidad debe ser positiva" << endl;
            velocidadMaxima = 0;
        }
    }

    // Metodo mostrarInfo
    virtual void mostrarInfo() {
        cout << "   Información del Vehículo   " << endl;
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Año: " << anio << endl;
        cout << "Velocidad Máxima: " << velocidadMaxima << " km/h" << endl;
        cout << "================================" << endl;
    }

    // Método acelerar
    void acelerar(double incremento) {
        velocidadMaxima += incremento;
        cout << "Velocidad incrementada en " << incremento << " km/h" << endl;
    }
};

//  Ejercicio 1.2: Clase Producto 
class Producto {
private:
    string codigo;
    string nombre;
    double precio;
    int cantidad;

public:
    // Constructor
    Producto(string cod, string nom, double prec, int cant) {
        codigo = cod;
        nombre = nom;
        setPrecio(prec);
        setCantidad(cant);
    }

    // Getters
    string getCodigo() { return codigo; }
    string getNombre() { return nombre; }
    double getPrecio() { return precio; }
    int getCantidad() { return cantidad; }

    // Setters con validaciones
    void setCodigo(string cod) { codigo = cod; }
    void setNombre(string nom) { nombre = nom; }
    
    void setPrecio(double prec) {
        if (prec >= 0) {
            precio = prec;
        } else {
            cout << "Error: El precio no puede ser negativo" << endl;
            precio = 0;
        }
    }
    
    void setCantidad(int cant) {
        if (cant >= 0) {
            cantidad = cant;
        } else {
            cout << "Error: La cantidad no puede ser negativa" << endl;
            cantidad = 0;
        }
    }

    // Metodo calcularValorTotal
    double calcularValorTotal() {
        return precio * cantidad;
    }

    // Método aplicarDescuento
    void aplicarDescuento(double porcentaje) {
        double descuento = precio * (porcentaje / 100.0);
        precio -= descuento;
        cout << "Descuento del " << porcentaje << "% aplicado" << endl;
    }

    // Método mostrarInfo
    void mostrarInfo() {
        cout << "   Información del Producto   " << endl;
        cout << "Código: " << codigo << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Precio: $" << precio << endl;
        cout << "Cantidad: " << cantidad << endl;
        cout << "================================" << endl;
    }
};


// NIVEL 2: HERENCIA SIMPLE


//  Ejercicio 2.1: Auto y Motocicleta 
class Auto : public Vehiculo {
private:
    int numeroPuertas;
    string tipoCombustible;

public:
    // Constructor
    Auto(string m, string mod, int a, double vel, int puertas, string comb)
        : Vehiculo(m, mod, a, vel) {
        numeroPuertas = puertas;
        tipoCombustible = comb;
    }

    // Getters
    int getNumeroPuertas() { return numeroPuertas; }
    string getTipoCombustible() { return tipoCombustible; }

    // Setters
    void setNumeroPuertas(int puertas) { numeroPuertas = puertas; }
    void setTipoCombustible(string comb) { tipoCombustible = comb; }

    // Override mostrarInfo
    void mostrarInfo() override {
        cout << "   Información del Auto   " << endl;
        cout << "Marca: " << getMarca() << endl;
        cout << "Modelo: " << getModelo() << endl;
        cout << "Año: " << getAnio() << endl;
        cout << "Velocidad Máxima: " << getVelocidadMaxima() << " km/h" << endl;
        cout << "Número de Puertas: " << numeroPuertas << endl;
        cout << "Tipo de Combustible: " << tipoCombustible << endl;
        cout << "============================" << endl;
    }
};

class Motocicleta : public Vehiculo {
private:
    bool tieneAleron;
    int cilindrada;

public:
    // Constructor
    Motocicleta(string m, string mod, int a, double vel, bool aleron, int cilin)
        : Vehiculo(m, mod, a, vel) {
        tieneAleron = aleron;
        cilindrada = cilin;
    }

    // Getters
    bool getTieneAleron() { return tieneAleron; }
    int getCilindrada() { return cilindrada; }

    // Setters
    void setTieneAleron(bool aleron) { tieneAleron = aleron; }
    void setCilindrada(int cilin) { cilindrada = cilin; }

    // Override mostrarInfo
    void mostrarInfo() override {
        cout << "   Informacion de la Motocicleta   " << endl;
        cout << "Marca: " << getMarca() << endl;
        cout << "Modelo: " << getModelo() << endl;
        cout << "Año: " << getAnio() << endl;
        cout << "Velocidad Máxima: " << getVelocidadMaxima() << " km/h" << endl;
        cout << "Tiene Alerón: " << (tieneAleron ? "Sí" : "No") << endl;
        cout << "Cilindradaje: " << cilindrada << " cc" << endl;
        cout << "=====================================" << endl;
    }
};

//  Ejercicio 2.2: Sistema de Empleados 
class Empleado {
protected:
    string nombreCompleto;
    string numeroEmpleado;
    double salarioBase;

public:
    // Constructor
    Empleado(string nombre, string numero, double salario) {
        nombreCompleto = nombre;
        numeroEmpleado = numero;
        salarioBase = salario;
    }

    // Getters
    string getNombreCompleto() { return nombreCompleto; }
    string getNumeroEmpleado() { return numeroEmpleado; }
    double getSalarioBase() { return salarioBase; }

    // Setters
    void setNombreCompleto(string nombre) { nombreCompleto = nombre; }
    void setNumeroEmpleado(string numero) { numeroEmpleado = numero; }
    void setSalarioBase(double salario) { salarioBase = salario; }

    // Metodo virtual
    virtual void mostrarInfo() {
        cout << "Nombre: " << nombreCompleto << endl;
        cout << "Número de Empleado: " << numeroEmpleado << endl;
        cout << "Salario Base: $" << salarioBase << endl;
    }
};

class EmpleadoTiempoCompleto : public Empleado {
private:
    string beneficios;
    double bono;

public:
    // Constructor
    EmpleadoTiempoCompleto(string nombre, string numero, double salario, 
                           string benef, double bon)
        : Empleado(nombre, numero, salario) {
        beneficios = benef;
        bono = bon;
    }

    // Getters y Setters
    string getBeneficios() { return beneficios; }
    double getBono() { return bono; }
    void setBeneficios(string benef) { beneficios = benef; }
    void setBono(double bon) { bono = bon; }

    // Calcular salario total
    double calcularSalarioTotal() {
        return salarioBase + bono;
    }

    // Override mostrarInfo
    void mostrarInfo() override {
        cout << "   Empleado Tiempo Completo   " << endl;
        Empleado::mostrarInfo();
        cout << "Beneficios: " << beneficios << endl;
        cout << "Bono: $" << bono << endl;
        cout << "================================" << endl;
    }
};

class EmpleadoPorHoras : public Empleado {
private:
    int horasTrabajadas;
    double tarifaPorHora;

public:
    // Constructor
    EmpleadoPorHoras(string nombre, string numero, double salario, 
                     int horas, double tarifa)
        : Empleado(nombre, numero, salario) {
        horasTrabajadas = horas;
        tarifaPorHora = tarifa;
    }

    // Getters y Setters
    int getHorasTrabajadas() { return horasTrabajadas; }
    double getTarifaPorHora() { return tarifaPorHora; }
    void setHorasTrabajadas(int horas) { horasTrabajadas = horas; }
    void setTarifaPorHora(double tarifa) { tarifaPorHora = tarifa; }

    // Calcular salario total
    double calcularSalarioTotal() {
        return horasTrabajadas * tarifaPorHora;
    }

    // Override mostrarInfo
    void mostrarInfo() override {
        cout << "   Empleado Por Horas   " << endl;
        Empleado::mostrarInfo();
        cout << "Horas Trabajadas: " << horasTrabajadas << endl;
        cout << "Tarifa por Hora: $" << tarifaPorHora << endl;
        cout << "==========================" << endl;
    }
};


// NIVEL 3: HERENCIA MULTINIVEL


//  Ejercicio 3.1: Jerarquía de Animales 
class Animal {
protected:
    string nombre;
    int edad;
    double peso;

public:
    // Constructor
    Animal(string nom, int ed, double p) {
        nombre = nom;
        edad = ed;
        peso = p;
    }

    // Getters
    string getNombre() { return nombre; }
    int getEdad() { return edad; }
    double getPeso() { return peso; }

    // Setters
    void setNombre(string nom) { nombre = nom; }
    void setEdad(int ed) { edad = ed; }
    void setPeso(double p) { peso = p; }

    // Metodos virtuales
    virtual void hacerSonido() {
        cout << "El animal hace un sonido" << endl;
    }

    virtual void mostrarInfo() {
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << " años" << endl;
        cout << "Peso: " << peso << " kg" << endl;
    }
};

class Mamifero : public Animal {
protected:
    bool tieneColaMamifero;

public:
    // Constructor
    Mamifero(string nom, int ed, double p, bool cola)
        : Animal(nom, ed, p) {
        tieneColaMamifero = cola;
    }

    // Getter y Setter
    bool getTieneCola() { return tieneColaMamifero; }
    void setTieneCola(bool cola) { tieneColaMamifero = cola; }

    // Override
    void mostrarInfo() override {
        Animal::mostrarInfo();
        cout << "Tiene Cola: " << (tieneColaMamifero ? "Sí" : "No") << endl;
    }
};

class Ave : public Animal {
protected:
    double envergaduraAlas;

public:
    // Constructor
    Ave(string nom, int ed, double p, double env)
        : Animal(nom, ed, p) {
        envergaduraAlas = env;
    }

    // Getter y Setter
    double getEnvergaduraAlas() { return envergaduraAlas; }
    void setEnvergaduraAlas(double env) { envergaduraAlas = env; }

    // Override
    void mostrarInfo() override {
        Animal::mostrarInfo();
        cout << "Envergadura de Alas: " << envergaduraAlas << " m" << endl;
    }
};

class Perro : public Mamifero {
public:
    // Constructor
    Perro(string nom, int ed, double p, bool cola)
        : Mamifero(nom, ed, p, cola) {}

    // Override
    void hacerSonido() override {
        cout << "¡Guau guau!🐕" << endl;
    }

    void mostrarInfo() override {
        cout << "   Información del Perro   " << endl;
        Mamifero::mostrarInfo();
        cout << "=============================" << endl;
    }
};

class Gato : public Mamifero {
public:
    // Constructor
    Gato(string nom, int ed, double p, bool cola)
        : Mamifero(nom, ed, p, cola) {}

    // Override
    void hacerSonido() override {
        cout << "¡Miau miau!🐈" << endl;
    }

    void mostrarInfo() override {
        cout << "   Información del Gato   " << endl;
        Mamifero::mostrarInfo();
        cout << "============================" << endl;
    }
};

class Loro : public Ave {
public:
    // Constructor
    Loro(string nom, int ed, double p, double env)
        : Ave(nom, ed, p, env) {}

    // Override
    void hacerSonido() override {
        cout << "¡Quiere cacao!🦜" << endl;
    }

    void mostrarInfo() override {
        cout << "   Información del Loro   " << endl;
        Ave::mostrarInfo();
        cout << "=============================" << endl;
    }
};

class Aguila : public Ave {
public:
    // Constructor
    Aguila(string nom, int ed, double p, double env)
        : Ave(nom, ed, p, env) {}

    // Override
    void hacerSonido() override {
        cout << "¡Chillido agudo!🦅" << endl;
    }

    void mostrarInfo() override {
        cout << "   Información del Águila   " << endl;
        Ave::mostrarInfo();
        cout << "===============================" << endl;
    }
};

//  Ejercicio 3.2: Sistema Bancario 
class Cuenta {
protected:
    string numeroCuenta;
    string propietario;
    double saldo;

public:
    // Constructor
    Cuenta(string num, string prop, double sal) {
        numeroCuenta = num;
        propietario = prop;
        setSaldo(sal);
    }

    // Getters
    string getNumeroCuenta() { return numeroCuenta; }
    string getPropietario() { return propietario; }
    double getSaldo() { return saldo; }

    // Setters
    void setNumeroCuenta(string num) { numeroCuenta = num; }
    void setPropietario(string prop) { propietario = prop; }
    void setSaldo(double sal) {
        if (sal >= 0) {
            saldo = sal;
        } else {
            cout << "Error: Saldo no puede ser negativo" << endl;
            saldo = 0;
        }
    }

    // Métodos virtuales
    virtual void depositar(double monto) {
        if (monto > 0) {
            saldo += monto;
            cout << "Depósito exitoso: $" << monto << endl;
        } else {
            cout << "Error: Monto debe ser positivo" << endl;
        }
    }

    virtual bool retirar(double monto) {
        if (monto > 0 && monto <= saldo) {
            saldo -= monto;
            cout << "Retiro exitoso: $" << monto << endl;
            return true;
        } else {
            cout << "Error: Fondos insuficientes o monto inválido" << endl;
            return false;
        }
    }

    virtual void mostrarInfo() {
        cout << "Número de Cuenta: " << numeroCuenta << endl;
        cout << "Propietario: " << propietario << endl;
        cout << "Saldo: $" << saldo << endl;
    }
};

class CuentaAhorro : public Cuenta {
private:
    double tasaInteres;

public:
    // Constructor
    CuentaAhorro(string num, string prop, double sal, double tasa)
        : Cuenta(num, prop, sal) {
        tasaInteres = tasa;
    }

    // Getter y Setter
    double getTasaInteres() { return tasaInteres; }
    void setTasaInteres(double tasa) { tasaInteres = tasa; }

    // Método generarInteres
    void generarInteres() {
        double interes = saldo * tasaInteres;
        saldo += interes;
        cout << "Interés generado: $" << interes << endl;
    }

    // Override mostrarInfo
    void mostrarInfo() override {
        cout << "   Cuenta de Ahorro   " << endl;
        Cuenta::mostrarInfo();
        cout << "Tasa de Interés: " << (tasaInteres * 100) << "%" << endl;
        cout << "========================" << endl;
    }
};

class CuentaCorriente : public Cuenta {
private:
    double limiteDescubierto;

public:
    // Constructor
    CuentaCorriente(string num, string prop, double sal, double limite)
        : Cuenta(num, prop, sal) {
        limiteDescubierto = limite;
    }

    // Getter y Setter
    double getLimiteDescubierto() { return limiteDescubierto; }
    void setLimiteDescubierto(double limite) { limiteDescubierto = limite; }

    // Override retirar
    bool retirar(double monto) override {
        if (monto > 0 && (saldo + limiteDescubierto) >= monto) {
            saldo -= monto;
            cout << "Retiro exitoso: $" << monto << endl;
            if (saldo < 0) {
                cout << "Advertencia: Usando descubierto" << endl;
            }
            return true;
        } else {
            cout << "Error: Excede el límite de descubierto" << endl;
            return false;
        }
    }

    // Método solicitarDescubierto
    void solicitarDescubierto(double monto) {
        if (monto > limiteDescubierto) {
            cout << "Solicitud de descubierto rechazada" << endl;
        } else {
            limiteDescubierto = monto;
            cout << "Nuevo límite de descubierto: $" << limiteDescubierto << endl;
        }
    }

    // Override mostrarInfo
    void mostrarInfo() override {
        cout << "   Cuenta Corriente   " << endl;
        Cuenta::mostrarInfo();
        cout << "Límite descubierto: $" << limiteDescubierto << endl;
        cout << "Saldo disponible: $" << (saldo + limiteDescubierto) << endl;
        cout << "========================" << endl;
    }
};


// NIVEL 4: DESAFÍO - SISTEMA DE UNIVERSIDADES


// Clase Curso para el sistema universitario
class Curso {
private:
    string codigo;
    string nombre;
    int creditos;
    string profesor;

public:
    // Constructor
    Curso(string cod, string nom, int cred, string prof) {
        codigo = cod;
        nombre = nom;
        creditos = cred;
        profesor = prof;
    }

    // Getters
    string getCodigo() { return codigo; }
    string getNombre() { return nombre; }
    int getCreditos() { return creditos; }
    string getProfesor() { return profesor; }

    // Setters
    void setCodigo(string cod) { codigo = cod; }
    void setNombre(string nom) { nombre = nom; }
    void setCreditos(int cred) { creditos = cred; }
    void setProfesor(string prof) { profesor = prof; }

    void mostrarInfo() {
        cout << "Curso: " << nombre << " (" << codigo << ")" << endl;
        cout << "Créditos: " << creditos << " | Profesor: " << profesor << endl;
    }
};

// Clase base Persona
class Persona {
protected:
    string nombre;
    int edad;
    string cedula;

public:
    // Constructor
    Persona(string nom, int ed, string ced) {
        nombre = nom;
        edad = ed;
        cedula = ced;
    }

    // Getters
    string getNombre() { return nombre; }
    int getEdad() { return edad; }
    string getCedula() { return cedula; }

    // Setters
    void setNombre(string nom) { nombre = nom; }
    void setEdad(int ed) { edad = ed; }
    void setCedula(string ced) { cedula = ced; }

    // Método virtual
    virtual void mostrarInfo() {
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
        cout << "Cédula: " << cedula << endl;
    }
};

// Clase Estudiante
class Estudiante : public Persona {
private:
    string carrera;
    double promedio;
    int semestre;
    vector<Curso> cursosMatriculados;

public:
    // Constructor
    Estudiante(string nom, int ed, string ced, string carr, double prom, int sem)
        : Persona(nom, ed, ced) {
        carrera = carr;
        promedio = prom;
        semestre = sem;
    }

    // Getters
    string getCarrera() { return carrera; }
    double getPromedio() { return promedio; }
    int getSemestre() { return semestre; }

    // Setters
    void setCarrera(string carr) { carrera = carr; }
    void setPromedio(double prom) { promedio = prom; }
    void setSemestre(int sem) { semestre = sem; }

    // Matricular curso
    void matricularCurso(Curso curso) {
        cursosMatriculados.push_back(curso);
        cout << "Curso " << curso.getNombre() << " matriculado exitosamente" << endl;
    }

    // Calcular promedio actual
    double calcularPromedioActual() {
        return promedio;
    }

    // Ver cursos matriculados
    void verCursos() {
        cout << "\n   Cursos Matriculados   " << endl;
        if (cursosMatriculados.empty()) {
            cout << "No hay cursos matriculados" << endl;
        } else {
            for (size_t i = 0; i < cursosMatriculados.size(); i++) {
                cout << (i + 1) << ". ";
                cursosMatriculados[i].mostrarInfo();
            }
        }
    }

    // Override mostrarInfo
    void mostrarInfo() override {
        cout << "   Información del Estudiante   " << endl;
        Persona::mostrarInfo();
        cout << "Carrera: " << carrera << endl;
        cout << "Promedio: " << promedio << endl;
        cout << "Semestre: " << semestre << endl;
        cout << "==================================" << endl;
    }
};

// Clase Profesor
class Profesor : public Persona {
private:
    string especialidad;
    int aniosExperiencia;
    int numeroEstudiantes;

public:
    // Constructor
    Profesor(string nom, int ed, string ced, string esp, int exp, int numEst)
        : Persona(nom, ed, ced) {
        especialidad = esp;
        aniosExperiencia = exp;
        numeroEstudiantes = numEst;
    }

    // Getters
    string getEspecialidad() { return especialidad; }
    int getAniosExperiencia() { return aniosExperiencia; }
    int getNumeroEstudiantes() { return numeroEstudiantes; }

    // Setters
    void setEspecialidad(string esp) { especialidad = esp; }
    void setAniosExperiencia(int exp) { aniosExperiencia = exp; }
    void setNumeroEstudiantes(int num) { numeroEstudiantes = num; }

    // Método estaDisponible
    bool estaDisponible(int horaDelDia) {
        // Disponible entre 8am y 6pm
        return (horaDelDia >= 8 && horaDelDia <= 18);
    }

    // Override mostrarInfo
    void mostrarInfo() override {
        cout << "   Información del Profesor   " << endl;
        Persona::mostrarInfo();
        cout << "Especialidad: " << especialidad << endl;
        cout << "Años de Experiencia: " << aniosExperiencia << endl;
        cout << "Número de Estudiantes: " << numeroEstudiantes << endl;
        cout << "================================" << endl;
    }
};

// Clase Personal
class Personal : public Persona {
private:
    string puesto;
    string departamento;
    double salario;

public:
    // Constructor
    Personal(string nom, int ed, string ced, string pues, string dep, double sal)
        : Persona(nom, ed, ced) {
        puesto = pues;
        departamento = dep;
        salario = sal;
    }

    // Getters
    string getPuesto() { return puesto; }
    string getDepartamento() { return departamento; }
    double getSalario() { return salario; }

    // Setters
    void setPuesto(string pues) { puesto = pues; }
    void setDepartamento(string dep) { departamento = dep; }
    void setSalario(double sal) { salario = sal; }

    // Calcular salario mensual
    double calcularSalarioMensual() {
        return salario;
    }

    // Override mostrarInfo
    void mostrarInfo() override {
        cout << "   Información del Personal   " << endl;
        Persona::mostrarInfo();
        cout << "Puesto: " << puesto << endl;
        cout << "Departamento: " << departamento << endl;
        cout << "Salario Mensual: $" << salario << endl;
        cout << "================================" << endl;
    }
};


// FUNCIONES INTERACTIVAS PARA ENTRADA DE DATOS


void limpiarBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

//  NIVEL 1 
void pruebaVehiculoInteractiva() {
    cout << "\n CREAR VEHICULO " << endl;
    string marca, modelo;
    int anio;
    double velocidad, incremento;
    
    cout << "Ingrese la marca: ";
    limpiarBuffer();
    getline(cin, marca);
    
    cout << "Ingrese el modelo: ";
    getline(cin, modelo);
    
    cout << "Ingrese el año: ";
    cin >> anio;
    
    cout << "Ingrese la velocidad máxima (km/h): ";
    cin >> velocidad;
    
    Vehiculo auto1(marca, modelo, anio, velocidad);
    auto1.mostrarInfo();
    
    cout << "\n¿Cuánto desea incrementar la velocidad? ";
    cin >> incremento;
    auto1.acelerar(incremento);
    auto1.mostrarInfo();
}

void pruebaProductoInteractiva() {
    cout << "\n CREAR PRODUCTO " << endl;
    string codigo, nombre;
    double precio, porcentaje;
    int cantidad;
    
    cout << "Ingrese el código del producto: ";
    limpiarBuffer();
    getline(cin, codigo);
    
    cout << "Ingrese el nombre del producto: ";
    getline(cin, nombre);
    
    cout << "Ingrese el precio: $";
    cin >> precio;
    
    cout << "Ingrese la cantidad: ";
    cin >> cantidad;
    
    Producto prod(codigo, nombre, precio, cantidad);
    prod.mostrarInfo();
    cout << "Valor total: $" << prod.calcularValorTotal() << endl;
    
    cout << "\n¿Qué porcentaje de descuento desea aplicar? ";
    cin >> porcentaje;
    prod.aplicarDescuento(porcentaje);
    prod.mostrarInfo();
}

// NIVEL 2 
void pruebaAutoMotocicletaInteractiva() {
    cout << "\n CREAR AUTO " << endl;
    string marca, modelo, combustible;
    int anio, puertas;
    double velocidad;
    
    cout << "Ingrese la marca: ";
    limpiarBuffer();
    getline(cin, marca);
    
    cout << "Ingrese el modelo: ";
    getline(cin, modelo);
    
    cout << "Ingrese el año: ";
    cin >> anio;
    
    cout << "Ingrese la velocidad máxima (km/h): ";
    cin >> velocidad;
    
    cout << "Ingrese el número de puertas: ";
    cin >> puertas;
    
    cout << "Ingrese el tipo de combustible: ";
    limpiarBuffer();
    getline(cin, combustible);
    
    Auto miAuto(marca, modelo, anio, velocidad, puertas, combustible);
    miAuto.mostrarInfo();
    
    cout << "\n CREAR MOTOCICLETA " << endl;
    int cilindrada;
    char tieneAleron;
    
    cout << "Ingrese la marca: ";
    getline(cin, marca);
    
    cout << "Ingrese el modelo: ";
    getline(cin, modelo);
    
    cout << "Ingrese el año: ";
    cin >> anio;
    
    cout << "Ingrese la velocidad máxima (km/h): ";
    cin >> velocidad;
    
    cout << "¿Tiene alerón? (s/n): ";
    cin >> tieneAleron;
    
    cout << "Ingrese la cilindrada (cc): ";
    cin >> cilindrada;
    
    Motocicleta miMoto(marca, modelo, anio, velocidad, 
                       (tieneAleron == 's' || tieneAleron == 'S'), cilindrada);
    miMoto.mostrarInfo();
}

void pruebaEmpleadosInteractiva() {
    int tipo;
    cout << "\n SISTEMA DE EMPLEADOS " << endl;
    cout << "1. Empleado Tiempo Completo" << endl;
    cout << "2. Empleado Por Horas" << endl;
    cout << "Seleccione el tipo de empleado: ";
    cin >> tipo;
    
    string nombre, numero;
    double salarioBase;
    
    cout << "\nIngrese el nombre completo: ";
    limpiarBuffer();
    getline(cin, nombre);
    
    cout << "Ingrese el número de empleado: ";
    getline(cin, numero);
    
    if (tipo == 1) {
        string beneficios;
        double bono;
        
        cout << "Ingrese el salario base: $";
        cin >> salarioBase;
        
        cout << "Ingrese los beneficios: ";
        limpiarBuffer();
        getline(cin, beneficios);
        
        cout << "Ingrese el bono: $";
        cin >> bono;
        
        EmpleadoTiempoCompleto emp(nombre, numero, salarioBase, beneficios, bono);
        emp.mostrarInfo();
        cout << "Salario Total: $" << emp.calcularSalarioTotal() << endl;
    } else {
        int horas;
        double tarifa;
        
        cout << "Ingrese las horas trabajadas: ";
        cin >> horas;
        
        cout << "Ingrese la tarifa por hora: $";
        cin >> tarifa;
        
        EmpleadoPorHoras emp(nombre, numero, 0, horas, tarifa);
        emp.mostrarInfo();
        cout << "Salario Total: $" << emp.calcularSalarioTotal() << endl;
    }
}

// NIVEL 3 
void pruebaAnimalesInteractiva() {
    int tipo;
    cout << "\n CREAR ANIMAL " << endl;
    cout << "1. Perro" << endl;
    cout << "2. Gato" << endl;
    cout << "3. Loro" << endl;
    cout << "4. Águila" << endl;
    cout << "Seleccione el tipo de animal: ";
    cin >> tipo;
    
    string nombre;
    int edad;
    double peso;
    
    cout << "\nIngrese el nombre: ";
    limpiarBuffer();
    getline(cin, nombre);
    
    cout << "Ingrese la edad (años): ";
    cin >> edad;
    
    cout << "Ingrese el peso (kg): ";
    cin >> peso;
    
    if (tipo == 1 || tipo == 2) {
        char tieneCola;
        cout << "¿Tiene cola? (s/n): ";
        cin >> tieneCola;
        
        if (tipo == 1) {
            Perro perro(nombre, edad, peso, (tieneCola == 's' || tieneCola == 'S'));
            perro.mostrarInfo();
            perro.hacerSonido();
        } else {
            Gato gato(nombre, edad, peso, (tieneCola == 's' || tieneCola == 'S'));
            gato.mostrarInfo();
            gato.hacerSonido();
        }
    } else {
        double envergadura;
        cout << "Ingrese la envergadura de alas (m): ";
        cin >> envergadura;
        
        if (tipo == 3) {
            Loro loro(nombre, edad, peso, envergadura);
            loro.mostrarInfo();
            loro.hacerSonido();
        } else {
            Aguila aguila(nombre, edad, peso, envergadura);
            aguila.mostrarInfo();
            aguila.hacerSonido();
        }
    }
}

void pruebaSistemaBancarioInteractivo() {
    int tipo;
    cout << "\n SISTEMA BANCARIO " << endl;
    cout << "1. Cuenta de Ahorro" << endl;
    cout << "2. Cuenta Corriente" << endl;
    cout << "Seleccione el tipo de cuenta: ";
    cin >> tipo;
    
    string numero, propietario;
    double saldo;
    
    cout << "\nIngrese el número de cuenta: ";
    limpiarBuffer();
    getline(cin, numero);
    
    cout << "Ingrese el nombre del propietario: ";
    getline(cin, propietario);
    
    cout << "Ingrese el saldo inicial: $";
    cin >> saldo;
    
    if (tipo == 1) {
        double tasa;
        cout << "Ingrese la tasa de interés (ej. 0.02 para 2%): ";
        cin >> tasa;
        
        CuentaAhorro cuenta(numero, propietario, saldo, tasa);
        cuenta.mostrarInfo();
        
        char opcion;
        cout << "\n¿Desea realizar operaciones? (s/n): ";
        cin >> opcion;
        
        if (opcion == 's' || opcion == 'S') {
            int operacion;
            double monto;
            
            cout << "\n1. Depositar" << endl;
            cout << "2. Retirar" << endl;
            cout << "3. Generar Interés" << endl;
            cout << "Seleccione: ";
            cin >> operacion;
            
            switch(operacion) {
                case 1:
                    cout << "Ingrese el monto a depositar: $";
                    cin >> monto;
                    cuenta.depositar(monto);
                    break;
                case 2:
                    cout << "Ingrese el monto a retirar: $";
                    cin >> monto;
                    cuenta.retirar(monto);
                    break;
                case 3:
                    cuenta.generarInteres();
                    break;
            }
            
            cuenta.mostrarInfo();
        }
    } else {
        double limite;
        cout << "Ingrese el límite de descubierto: $";
        cin >> limite;
        
        CuentaCorriente cuenta(numero, propietario, saldo, limite);
        cuenta.mostrarInfo();
        
        char opcion;
        cout << "\n¿Desea realizar operaciones? (s/n): ";
        cin >> opcion;
        
        if (opcion == 's' || opcion == 'S') {
            int operacion;
            double monto;
            
            cout << "\n1. Depositar" << endl;
            cout << "2. Retirar" << endl;
            cout << "Seleccione: ";
            cin >> operacion;
            
            cout << "Ingrese el monto: $";
            cin >> monto;
            
            if (operacion == 1) {
                cuenta.depositar(monto);
            } else {
                cuenta.retirar(monto);
            }
            
            cuenta.mostrarInfo();
        }
    }
}

//  NIVEL 4 
void pruebaSistemaUniversitarioInteractivo() {
    int tipo;
    cout << "\n SISTEMA UNIVERSITARIO " << endl;
    cout << "1. Crear Estudiante" << endl;
    cout << "2. Crear Profesor" << endl;
    cout << "3. Crear Personal" << endl;
    cout << "Seleccione: ";
    cin >> tipo;
    
    string nombre, cedula;
    int edad;
    
    cout << "\nIngrese el nombre: ";
    limpiarBuffer();
    getline(cin, nombre);
    
    cout << "Ingrese la edad: ";
    cin >> edad;
    
    cout << "Ingrese la cédula: ";
    limpiarBuffer();
    getline(cin, cedula);
    
    if (tipo == 1) {
        string carrera;
        double promedio;
        int semestre, numCursos;
        
        cout << "Ingrese la carrera: ";
        getline(cin, carrera);
        
        cout << "Ingrese el promedio: ";
        cin >> promedio;
        
        cout << "Ingrese el semestre: ";
        cin >> semestre;
        
        Estudiante est(nombre, edad, cedula, carrera, promedio, semestre);
        
        cout << "\n¿Cuántos cursos desea matricular? ";
        cin >> numCursos;
        
        limpiarBuffer();
        for (int i = 0; i < numCursos; i++) {
            string codigo, nombreCurso, profesor;
            int creditos;
            
            cout << "\n--- Curso " << (i+1) << " ---" << endl;
            cout << "Código: ";
            getline(cin, codigo);
            
            cout << "Nombre: ";
            getline(cin, nombreCurso);
            
            cout << "Créditos: ";
            cin >> creditos;
            limpiarBuffer();
            
            cout << "Profesor: ";
            getline(cin, profesor);
            
            Curso curso(codigo, nombreCurso, creditos, profesor);
            est.matricularCurso(curso);
        }
        
        est.mostrarInfo();
        est.verCursos();
        cout << "\nPromedio Actual: " << est.calcularPromedioActual() << endl;
        
    } else if (tipo == 2) {
        string especialidad;
        int experiencia, numEstudiantes, hora;
        
        cout << "Ingrese la especialidad: ";
        getline(cin, especialidad);
        
        cout << "Años de experiencia: ";
        cin >> experiencia;
        
        cout << "Número de estudiantes: ";
        cin >> numEstudiantes;
        
        Profesor prof(nombre, edad, cedula, especialidad, experiencia, numEstudiantes);
        prof.mostrarInfo();
        
        cout << "\nIngrese una hora para verificar disponibilidad (0-23): ";
        cin >> hora;
        cout << "¿Disponible? " << (prof.estaDisponible(hora) ? "Sí" : "No") << endl;
        
    } else {
        string puesto, departamento;
        double salario;
        
        cout << "Ingrese el puesto: ";
        getline(cin, puesto);
        
        cout << "Ingrese el departamento: ";
        getline(cin, departamento);
        
        cout << "Ingrese el salario: $";
        cin >> salario;
        
        Personal pers(nombre, edad, cedula, puesto, departamento, salario);
        pers.mostrarInfo();
        cout << "Salario Mensual: $" << pers.calcularSalarioMensual() << endl;
    }
}


// FUNCIÓN MAIN - MENÚ INTERACTIVO


void mostrarMenuPrincipal() {
    cout << " TALLER DE OBJETOS - MENÚ PRINCIPAL    " << endl;
    cout << " 1. Nivel 1.1: Vehículo                " << endl;
    cout << " 2. Nivel 1.2: Producto                " << endl;
    cout << " 3. Nivel 2.1: Auto y Motocicleta      " << endl;
    cout << " 4. Nivel 2.2: Sistema de Empleados    " << endl;
    cout << " 5. Nivel 3.1: Jerarquía de Animales   " << endl;
    cout << " 6. Nivel 3.2: Sistema Bancario        " << endl;
    cout << " 7. Nivel 4.1: Sistema Universitario   " << endl;
    cout << " 0. Salir                              " << endl;
    cout << "Seleccione una opción: ";
}

int main() {
    int opcion;
    
    cout << "  TALLER DE PROGRAMACIÓN ORIENTADA A OBJETOS        " << endl;
    cout << "  Getters, Setters y Herencia - Versión Interactiva " << endl;
    
    do {
        mostrarMenuPrincipal();
        cin >> opcion;
        
        switch(opcion) {
            case 1:
                pruebaVehiculoInteractiva();
                break;
            case 2:
                pruebaProductoInteractiva();
                break;
            case 3:
                pruebaAutoMotocicletaInteractiva();
                break;
            case 4:
                pruebaEmpleadosInteractiva();
                break;
            case 5:
                pruebaAnimalesInteractiva();
                break;
            case 6:
                pruebaSistemaBancarioInteractivo();
                break;
            case 7:
                pruebaSistemaUniversitarioInteractivo();
                break;
            case 0:
                cout << "\nHasta la proxima " << endl;
                break;
            default:
                cout << "\nOpcion invalida. Intentelo nuevamente." << endl;
        }
        
        if (opcion != 0) {
            cout << "\n\nPresione Enter para continuar...";
            cin.ignore();
            cin.get();
        }
        
    } while(opcion != 0);
    
    return 0;
}