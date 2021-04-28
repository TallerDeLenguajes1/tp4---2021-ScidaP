#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

typedef struct Tarea {
    int tareaID;
    char *descripcion;
    int duracion; // Entre 10 y 100
}tarea;

typedef struct nodo {
    tarea tareas;
    nodo *sig;
}nodo;

nodo * listaVacia() {
    return NULL;
}

void *cargarTareas(tarea ** tareas, int cant) {
    char descripciones[4][80] = {"Completar hoy", "Para el jefe", "Terminar antes de mayo", "Solicitar ayuda"};
    for (int i = 0; i < cant; i++) {
        tareas[i] = (tarea*) malloc(sizeof(tarea));
        tareas[i]->tareaID = rand() % (100 - 0 + 1) + 0;
        tareas[i]->duracion = rand() % (100 - 10 + 1) + 10;
        tareas[i]->descripcion = (char*) malloc(sizeof(char)*80);
        strcpy(tareas[i]->descripcion, descripciones[0 + (rand() % 3 - 0 + 1)]);
        //100 + (rand() % 999 - 100 + 1); //valini + (rand() % valfinal - valini + 1);
        //(Cliente + i)->productos->tipoProducto = (char*) malloc(sizeof(char)*270);
        //(Cliente + i)->productos->tipoProducto = (tiposProductos + rand() % (5 - 0 + 1) + 0);
    }
}

void categorizarTareas(tarea ** tareas, int cant) {
    nodo * start1 = listaVacia();
    nodo * start2 = listaVacia();
    for (int j = 0; j < cant; j++) {
        puts("-------------------------");
        printf("--- Mostrando la tarea N %d ---\n", j+1);
        printf("- ID de la tarea: %d -\n", tareas[j]->tareaID);
        printf("- Duracion de la tarea: %d minutos -\n", tareas[j]->duracion);
        printf("- Descripcion de la tarea: %s -\n", tareas[j]->descripcion);
        puts("|-------------------------|\n");
        char completada;
        printf("Considera la tarea N %d como terminada? Use S/N\n", j+1);
        fflush(stdin);
        scanf("%c", &completada);
        completada = toupper(completada); // Transforma a mayúscula el carácter ingresado.
        while (completada != 'S' && completada != 'N') {
            printf("Caracter no reconocido: %c ...\n", completada);
            puts("Intente nuevamente.");
            printf("Considera la tarea N %d como terminada? S/N\n", j+1);
            fflush(stdin);
            scanf("%c", &completada);
        }
        if (completada = 'S') {
            cargarTareasTerminadas(start1, tareas[j]);
        } else if (completada = 'N') {
            /* cargarTareasPendientes(tareas[j]); */
        }
    }
}

void cargarTareasTerminadas(nodo * start, tarea * tarea) {
    nodo * nuevoNodo = crearNodo();
    start->sig = nuevoNodo;
    nuevoNodo->tareas = (*tarea);
}

nodo * CrearNodo() {	
	nodo * NuevoNodo =	(nodo*)malloc(sizeof(nodo));	
	NuevoNodo->sig = NULL;
	return NuevoNodo;
}

int main() {
    srand(time(NULL));
    int cantTareas;
    printf("Ingrese cuantas tareas desea cargar.\n");
    scanf("%d", &cantTareas);
    tarea ** tareas = (tarea**) malloc(cantTareas*sizeof(tarea*));
    cargarTareas(tareas, cantTareas);
    /* mostrarTareas(tareas, cantTareas); */
    categorizarTareas(tareas, cantTareas);
    getchar();
    getchar();
    getchar();
    getchar();
    return 0;
}