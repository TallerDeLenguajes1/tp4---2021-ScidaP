#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct Tarea {
    int tareaID;
    char *descripcion;
    int duracion; // Entre 10 y 100
}tarea;

tarea *cargarTareas(tarea * tarea, int cant) {
    srand(time(NULL));
    char *descripciones[] = {"Completar hoy", "Para el jefe", "Terminar antes de mayo", "Solicitar ayuda"};
    for (int i = 0; i < cant; i++) {
        (tarea + i)->tareaID = rand() % (100 - 0 + 1) + 0;
        (tarea + i)->duracion = rand() % (100 - 10 + 1) + 10;
        (tarea + i)->descripcion = (char*) malloc(sizeof(char)*80);
        (tarea + i)->descripcion = (char*)(descripciones + rand() % (4 - 0 + 1) + 0);
        //(Cliente + i)->productos->tipoProducto = (char*) malloc(sizeof(char)*20);
        //(Cliente + i)->productos->tipoProducto = (tiposProductos + rand() % (5 - 0 + 1) + 0);
    }
    return tarea;
}

void mostrarTareas(tarea * tarea, int cant) {
    for (int j = 0; j < cant; j++) {
        printf("--- Mostrando la tarea N %d ---\n", j+1);
        printf("-ID de la tarea: %d-\n", (tarea + j)->tareaID);
        printf("-Descripción de la tarea: %s-\n", (tarea + j)->descripcion);
        printf("-Duracion de la tarea:%d-\n", (tarea + j)->duracion);
    }
}

int main() {
    int cantTareas;
    printf("Ingrese cuantas tareas desea cargar.\n");
    scanf("%d", &cantTareas);
    tarea * tareas = (tarea*) malloc(cantTareas*sizeof(tarea));
    cargarTareas(tareas, cantTareas);
    mostrarTareas(tareas, cantTareas);
    getchar();
    return 0;
}