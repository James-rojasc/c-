#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// ejercicio 1 
void leer_arreglo(int *a, size_t n) {
    for (size_t i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
}
void min_max_prom(const int *a, size_t n, int *minv, int *maxv, double *prom) {
    *minv = *maxv = a[0];
    long long suma = 0;
    for (size_t i = 0; i < n; i++) {
        if (*(a + i) < *minv) *minv = *(a + i);
        if (*(a + i) > *maxv) *maxv = *(a + i);
        suma += *(a + i);
    }
    *prom = (double)suma / n;
}
void ejercicio1() {
    printf("\n ejercicio 1: estadisticas basicas \n");
    size_t n;
    printf("Cantidad de elementos: ");
    scanf("%zu", &n);
    
    if (n == 0 || n > 100000) {
        printf("n fuera de rango\n");
        return;
    }
    
    int *arr = (int*)malloc(n * sizeof(int));
    if (!arr) {
        printf("error asignando memoria\n");
        return;
    }
    
    printf("Ingresa %zu enteros: ", n);
    leer_arreglo(arr, n);
    
    int minimo, maximo;
    double promedio;
    min_max_prom(arr, n, &minimo, &maximo, &promedio);
    
    printf("min=%d max=%d prom=%.2f\n", minimo, maximo, promedio);
    
    free(arr);
}
// ejercicio 2
void reverse(int *a, size_t i, size_t j) {
    while (i < j) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        i++;
        j--;
    }
}
void rotar_derecha(int *a, size_t n, size_t k) {
    if (n == 0) return;
    k = k % n;
    if (k == 0) return;
    
    reverse(a, 0, n - 1);
    reverse(a, 0, k - 1);
    reverse(a, k, n - 1);
}
void ejercicio2() {
    printf("\n ejercicio 2: rotacion circular \n");
    size_t n, k;
    printf("tamaño del arreglo y posiciones a rotar: ");
    scanf("%zu %zu", &n, &k);
    
    int *arr = (int*)malloc(n * sizeof(int));
    if (!arr) return;
    
    printf("Ingresa %zu enteros: ", n);
    for (size_t i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    rotar_derecha(arr, n, k);
    
    printf("Arreglo rotado: ");
    for (size_t i = 0; i < n; i++) {
        printf("%d%c", arr[i], i == n-1 ? '\n' : ' ');
    }
    
    free(arr);
}
// ejercicio 3 
size_t normalizar_espacios(const char *in, char *out, size_t outcap) {
    const char *p = in;
    char *q = out;
    size_t written = 0;
    int en_espacio = 1;
    
    while (*p && written < outcap - 1) {
        if (isspace((unsigned char)*p)) {
            if (!en_espacio) {
                *q++ = ' ';
                written++;
                en_espacio = 1;
            }
        } else {
            *q++ = *p;
            written++;
            en_espacio = 0;
        }
        p++;
    }
    
    if (written > 0 && *(q-1) == ' ') {
        q--;
        written--;
    }
    
    *q = '\0';
    return written;
}
void ejercicio3() {
    printf("\n ejercicio 3: normalizar cadenas \n");
    char entrada[1001];
    char salida[1001]; 
    printf("ingresa una cadena se vale tener espacios de mas: ");
    getchar(); // limpia el buffer
    if (!fgets(entrada, sizeof(entrada), stdin)) {
        printf("error leyendo entrada\n");
        return;
    }
    size_t len = strlen(entrada);
    if (len > 0 && entrada[len-1] == '\n') {
        entrada[len-1] = '\0';
    }
    size_t final_len = normalizar_espacios(entrada, salida, sizeof(salida));
    printf("Resultado: \"%s\" (longitud %zu)\n", salida, final_len);
}
// ejercicio 4 
int **mat_crear(size_t m, size_t n) {
    int **A = (int**)malloc(m * sizeof(int*));
    if (!A) return NULL;
    
    for (size_t i = 0; i < m; i++) {
        A[i] = (int*)malloc(n * sizeof(int));
        if (!A[i]) {
            for (size_t k = 0; k < i; k++) free(A[k]);
            free(A);
            return NULL;
        }
    }
    return A;
} 
void mat_destruir(int **A, size_t m) {
    for (size_t i = 0; i < m; i++) {
        free(A[i]);
    }
    free(A);
}
void mat_sumas(int **A, size_t m, size_t n, int *sumF, int *sumC) {
    for (size_t i = 0; i < m; i++) {
        sumF[i] = 0;
        for (size_t j = 0; j < n; j++) {
            sumF[i] += A[i][j];
        }
    }
    for (size_t j = 0; j < n; j++) {
        sumC[j] = 0;
        for (size_t i = 0; i < m; i++) {
            sumC[j] += A[i][j];
        }
    }
}
void ejercicio4() {
    printf("\n ejercicio 4: sumas de matriz \n");
    size_t m, n;
    printf("filas y columnas: ");
    scanf("%zu %zu", &m, &n);
    int **mat = mat_crear(m, n);
    if (!mat) return;
    
    printf("Ingresa los %zu elementos (fila por fila):\n", m*n);
    for (size_t i = 0; i < m; i++) {
        for (size_t j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    int *sumF = (int*)malloc(m * sizeof(int));
    int *sumC = (int*)malloc(n * sizeof(int));
    if (!sumF || !sumC) {
        mat_destruir(mat, m);
        free(sumF);
        free(sumC);
        return;
    }
    mat_sumas(mat, m, n, sumF, sumC);

    printf("sumF: [");
    for (size_t i = 0; i < m; i++) {
        printf("%d%s", sumF[i], i == m-1 ? "]\n" : ",");
    }
    
    printf("sumC: [");
    for (size_t j = 0; j < n; j++) {
        printf("%d%s", sumC[j], j == n-1 ? "]\n" : ",");
    }
    
    free(sumF);
    free(sumC);
    mat_destruir(mat, m);
}
// ejercicio 5 
typedef struct {
    char nombre[40];
    int edad;
    double promedio;
} Estudiante;
int cmp_prom_desc(const void *a, const void *b) {
    Estudiante *ea = (Estudiante*)a;
    Estudiante *eb = (Estudiante*)b;
    if (ea->promedio < eb->promedio) return 1;
    if (ea->promedio > eb->promedio) return -1;
    return 0;
}
int buscar_nombre(Estudiante *v, size_t n, const char *clave) {
    for (size_t i = 0; i < n; i++) {
        if (strcmp(v[i].nombre, clave) == 0) {
            return (int)i;
        }
    }
    return -1;
}
void ejercicio5() {
    printf("\n Ejercicio 5: registro de estudiantes \n");
    size_t n;
    printf("Cantidad de estudiantes: ");
    scanf("%zu", &n);   
    Estudiante *est = (Estudiante*)malloc(n * sizeof(Estudiante));
    if (!est) return;

    printf("ingresa: nombre, edad y promedio (uno por línea):\n");
    for (size_t i = 0; i < n; i++) {
        scanf("%39s %d %lf", est[i].nombre, &est[i].edad, &est[i].promedio);
    }
    qsort(est, n, sizeof(Estudiante), cmp_prom_desc);
    
    printf("\nTop-3 por promedio:\n");
    size_t top = n < 3 ? n : 3;
    for (size_t i = 0; i < top; i++) {
        printf("%zu. %s (edad %d, promedio %.2f)\n", 
               i+1, est[i].nombre, est[i].edad, est[i].promedio);
    }
    
    char buscar[40];
    printf("\nBuscar estudiante por nombre: ");
    scanf("%39s", buscar);
    
    int idx = buscar_nombre(est, n, buscar);
    if (idx != -1) {
        printf("Encontrado en posición %d (ordenada): %s, edad %d, promedio %.2f\n",
               idx, est[idx].nombre, est[idx].edad, est[idx].promedio);
    } else {
        printf("No encontrado\n");
    }
    
    free(est);
}
// ejercicio 6
typedef struct Nodo {
    int x;
    struct Nodo *sig;
} Nodo;
typedef struct {
    Nodo *cabeza;
    Nodo *cola;
    size_t tam;
} Lista;
void lista_init(Lista *L) {
    L->cabeza = L->cola = NULL;
    L->tam = 0;
}
void push_front(Lista *L, int val) {
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    if (!nuevo) return;
    nuevo->x = val;
    nuevo->sig = L->cabeza;
    L->cabeza = nuevo;
    if (!L->cola) L->cola = nuevo;
    L->tam++;
}
void push_back(Lista *L, int val) {
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    if (!nuevo) return;
    nuevo->x = val;
    nuevo->sig = NULL;   
    if (!L->cola) {
        L->cabeza = L->cola = nuevo;
    } else {
        L->cola->sig = nuevo;
        L->cola = nuevo;
    }
    L->tam++;
}
void pop_front(Lista *L) {
    if (!L->cabeza) return;
    Nodo *temp = L->cabeza;
    L->cabeza = L->cabeza->sig;
    if (!L->cabeza) L->cola = NULL;
    free(temp);
    L->tam--;
}
size_t lista_size(Lista *L) {
    return L->tam;
}
void lista_clear(Lista *L) {
    while (L->cabeza) {
        pop_front(L);
    }
}
void lista_print(Lista *L) {
    Nodo *p = L->cabeza;
    while (p) {
        printf("%d%s", p->x, p->sig ? " " : "\n");
        p = p->sig;
    }
    if (!L->cabeza) printf("(vacia)\n");
}
void ejercicio6() {
    printf("\n ejercicio 6: lista enlazada \n");
    Lista L;
    lista_init(&L);
    
    printf("Comandos: pf <val> | pb <val> | pop | size | print | fin\n");   
    char cmd[10];
    int val;
    while (1) {
        printf("> ");
        if (scanf("%9s", cmd) != 1) break;
        if (strcmp(cmd, "pf") == 0) {
            scanf("%d", &val);
            push_front(&L, val);
        } else if (strcmp(cmd, "pb") == 0) {
            scanf("%d", &val);
            push_back(&L, val);
        } else if (strcmp(cmd, "pop") == 0) {
            pop_front(&L);
        } else if (strcmp(cmd, "size") == 0) {
            printf("Tamaño: %zu\n", lista_size(&L));
        } else if (strcmp(cmd, "print") == 0) {
            printf("Contenido: ");
            lista_print(&L);
        } else if (strcmp(cmd, "fin") == 0) {
            break;
        }
    }
    
    printf("\ncontenido final: ");
    lista_print(&L);
    lista_clear(&L);
}
// ejercicio 7
int doble(int x) {
    return x * 2;
}
int cuadrado(int x) {
    return x * x;
}
void aplicar(int *a, size_t n, int (*op)(int)) {
    for (size_t i = 0; i < n; i++) {
        a[i] = op(a[i]);
    }
}
void ejercicio7() {
    printf("\n ejercicio 7: punteros a funcion \n");
    size_t n;
    printf("tamaño del arreglo: ");
    scanf("%zu", &n);
    int *arr = (int*)malloc(n * sizeof(int));
    if (!arr) return;
    
    printf("Ingresa %zu enteros: ", n);
    for (size_t i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int opcion;
    printf("operacion (1=doble, 2=cuadrado): ");
    scanf("%d", &opcion);
    if (opcion == 1) {
        aplicar(arr, n, doble);
    } else if (opcion == 2) {
        aplicar(arr, n, cuadrado);
    } else {
        printf("opcion invalida\n");
        free(arr);
        return;
    }
    
    printf("Resultado: ");
    for (size_t i = 0; i < n; i++) {
        printf("%d%c", arr[i], i == n-1 ? '\n' : ' ');
    }
    free(arr);
}
// ejercicio 8
typedef struct {
    char prod[32];
    int unidades;
    double precio;
} Venta;
void ejercicio8() {
    printf("\n ejercicio 8: estadisticas de ventas \n");
    FILE *f = fopen("ventas.csv", "r");
    if (!f) {
        printf("Error abriendo archivo ventas.csv\n");
        printf("Crea un archivo ventas.csv con formato: producto,unidades,precio\n");
        return;
    }
    Venta *ventas = NULL;
    size_t capacidad = 10;
    size_t n = 0;
    ventas = (Venta*)malloc(capacidad * sizeof(Venta));
    if (!ventas) {
        fclose(f);
        return;
    }
    char linea[128];
    while (fgets(linea, sizeof(linea), f)) {
        if (n >= capacidad) {
            capacidad *= 2;
            Venta *temp = (Venta*)realloc(ventas, capacidad * sizeof(Venta));
            if (!temp) {
                free(ventas);
                fclose(f);
                return;
            }
            ventas = temp;
        }   
        char *prod = strtok(linea, ",");
        char *unid = strtok(NULL, ",");
        char *prec = strtok(NULL, ",");
        if (prod && unid && prec) {
            strncpy(ventas[n].prod, prod, 31);
            ventas[n].prod[31] = '\0';
            ventas[n].unidades = atoi(unid);
            ventas[n].precio = atof(prec);
            n++;
        }
    }
    fclose(f);
    if (n == 0) {
        printf("No hay ventas\n");
        free(ventas);
        return;
    }
    double total = 0;
    int max_unidades = ventas[0].unidades;
    size_t idx_max = 0;
    for (size_t i = 0; i < n; i++) {
        total += ventas[i].unidades * ventas[i].precio;
        if (ventas[i].unidades > max_unidades) {
            max_unidades = ventas[i].unidades;
            idx_max = i;
        }
    }
    double ticket_prom = total / n;

    printf("Total vendido: $%.2f\n", total);
    printf("Producto más vendido: %s (%d unidades)\n", 
           ventas[idx_max].prod, ventas[idx_max].unidades);
    printf("Ticket promedio: $%.2f\n", ticket_prom);
    
    free(ventas);
}
// menu 
int main() {
    int opcion;
    do {
        printf("\n Menu del taller integral \n");
        printf("  1. Estadisticas basicas\n");
        printf("  2. Rotacion circular\n");
        printf("  3. Normalizar cadenas\n");
        printf("  4. Sumas de matriz\n");
        printf("  5. Registro de estudiantes\n");
        printf("  6. Lista enlazada dinamica\n");
        printf("  7. Punteros a funcion \n");
        printf("  8. Estadisticas de ventas \n");
        printf("  0. Salir\n");
        printf("\nElige ejercicio: ");

        if (scanf("%d", &opcion) != 1) {
            printf("Entrada inválida\n");
            break;
        }
        switch(opcion) {
            case 1: ejercicio1(); break;
            case 2: ejercicio2(); break;
            case 3: ejercicio3(); break;
            case 4: ejercicio4(); break;
            case 5: ejercicio5(); break;
            case 6: ejercicio6(); break;
            case 7: ejercicio7(); break;
            case 8: ejercicio8(); break;
            case 0: printf("\nHasta luego.\n"); break;
            default: printf("Opcion no valida\n");
        }
        
    } while (opcion != 0);
    
    return 0;
}

