#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "defines.h"
#include "funcionesAuxiliares.h"
#include "menu.h"


int main()
{
    eEmployee employees[TAMANIO_EMPLEADO];
    initEmployees(employees, TAMANIO_EMPLEADO);
    int option;
    int cantidadEmployee = 0;

    do{
        showMenu();
        scanf("%d", &option);

        switch(option){

            case ALTA:
                darDeAltaEmpleado(employees, TAMANIO_EMPLEADO);
                cantidadEmployee = cantidadEmpleados(employees, TAMANIO_EMPLEADO);
                break;

            case MODIFICACION:
                if(cantidadEmployee <= 0){
                    printf("No hay empleados ingresados para modificar\n");
                    break;
                }
                modificarEmpleado(employees, TAMANIO_EMPLEADO);
                break;

            case BAJA:
                if(cantidadEmployee <= 0){
                    printf("No hay empleados ingresados para dar de baja\n");
                    break;
                }
                darDeBaja(employees, TAMANIO_EMPLEADO);
                break;

            case INFORMACION:
                if(cantidadEmployee <= 0){
                    printf("No hay empleados para mostrar\n");
                    break;
                }
                informarDatosEmpleados(employees, TAMANIO_EMPLEADO);
                //informarDatosEmpleados(employees, TAMANIO_EMPLEADO);
                break;
            default:
                 // para cualquier otra opcion no hacemos nada
                break;
        }

    }
    while(option != SALIR);

    return 0;
}
