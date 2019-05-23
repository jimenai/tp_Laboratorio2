#include <stdio.h>
#include "defines.h"

void showMenu(){
    printf("ABM Empleados\nElija opcion:\n%d-Alta\n%d-Modificar\n%d-Baja\n%d-Informar\n%d-Salir\n", ALTA, MODIFICACION, BAJA, INFORMACION, SALIR);
}

void showSectors(){
    printf("Elija sector:\n%d-Sistemas\n%d-RRHH\n%d-Ventas\n", SECTOR_SISTEMAS, SECTOR_RRHH, SECTOR_VENTAS);
}

void showInformation(){
    printf("Elija sector:\n%d-Mostrar la lista de empleados\n%d-Empleados ordenados alfabeticamente por apellidos\n%d-Empleados ordenados sector\n%d-Total y promedio de salarios. Cantidad de empleados que superan el salario promedio\n", LISTA_EMPLEADOS, LISTA_ORDENADOS_APELLIDO,LISTA_ORDENADOS_SECTOR, TOTAL_PROMEDIO_EMPLEADOS_Y_CANTIDAD_SUPERAN_SALARIO_PROMEDIO);
}
