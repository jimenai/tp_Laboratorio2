#include "ArrayEmployees.h"
#include "funcionesAuxiliares.h"
#include "defines.h"
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void initEmployees(eEmployee employees[], int tam){
    for(int i = 0; i < tam; i++){
        employees[i].isEmpty = TRUE;
        employees[i].id = -1;
        employees[i].name[0] = 0;
        employees[i].lastName[0] = 0;
        employees[i].salary = 0;
        employees[i].sector = 0;
    }
}

int findEmployeeById(eEmployee employees[], int tam, int id){
    int index = -1;
    for(int i = 0; i < tam; i++){
        // buscamos el empleado por id y ademas que no este dado de baja
        if(employees[i].id == id && employees[i].isEmpty == FALSE){
                index = i;
                break;
        }
    }
    return index;
}

int findSpaceInEmployeeList(eEmployee employees[], int tam){
     int index = -1;
    for(int i = 0; i < tam; i++){
        if(employees[i].isEmpty){
                index = i;
                break;
        }
    }
    return index;
}

void printEmployee(eEmployee employee){

    printf("%d   ---   %s   ---   %s   ---   %.2f   ---   %d\n", employee.id, employee.name, employee.lastName, employee.salary, employee.sector );

}

void printAllEmployees(eEmployee employees[], int tam){

    printf("ID   ---   NOMBRE   ---   APELLIDO   ---   SALARIO   ---   SECTOR\n");
    for(int i = 0; i < tam; i++){
        if(employees[i].isEmpty == FALSE){
            printEmployee(employees[i]);

        }
    }
}

float totalSalaryEmployees(eEmployee employees[], int tam){
    float totalSalario = 0;
    for(int i = 0; i < tam; i++){
        if(employees[i].isEmpty == FALSE){
            float salarioEmpleado = employees[i].salary;
            totalSalario += salarioEmpleado;
        }
    }
    return totalSalario;
}
int cantidadEmpleados(eEmployee employees[], int tam){
    int cantidadEmpleados = 0;
    for(int i = 0; i < tam; i++){
        if(employees[i].isEmpty == FALSE){
            cantidadEmpleados++;
        }
    }
    return cantidadEmpleados;
}

/*float promedioSalarioEmpleados(eEmployee employees[], int tam){
    float promedio = totalSalaryEmployees(employees, tam)/ cantidadEmpleados(employees, tam);
    return promedio;
}*/
int getIdForNewEmployee(eEmployee* employees, int tam){
    int idAux = employees[0].id;

    for(int i = 0; i < tam; i++){
        if(idAux < employees[i].id){
            idAux = employees[i].id;
        }
    }
    if(idAux < 0)
        return 1;

    return idAux+1;
}

int addEmployee(eEmployee employees[], int tam, int id, char name[], char lastName[], float salary, int sector)
{
    int posicion;

    posicion = findSpaceInEmployeeList(employees, tam);
    if(posicion == -1){
        printf("No hay espacio suficiente para dar de alta. De de baja algun empleado.\n");
        return FALSE;
    }

    employees[posicion].id = id;
    strcpy(employees[posicion].name, name);
    strcpy(employees[posicion].lastName, lastName);
    employees[posicion].salary = salary;
    employees[posicion].sector = sector;
    employees[posicion].isEmpty = FALSE;

    return TRUE;
}

//funcion cargar datos:

void darDeAltaEmpleado(eEmployee employees[], int tam){
    int id;
   // int contadorEmpleados = 0;

    id = getIdForNewEmployee(employees, tam);
    //hacer do while
    printf("Ingrese el nombre del empleado:\n");
    char nombre[51];
    fflush(stdin);
    gets(nombre);
    while(justString(nombre) == -1)
    {
        printf("Reingrese nombre: \n");
        gets(nombre);
    }



    printf("Ingrese el apellido del empleado:\n");
    char apellido[51];
    fflush(stdin);
    gets(apellido);
    while(justString(apellido) == -1)
    {
        printf("Reingrese apellido: \n");
        gets(apellido);
    }


    char number[20];
    float salario;
    printf("Ingreseel salario del empleado:\n");
    gets(number);
    while(numeroFlotante(number) == -1){
        printf("Reingrese salario: \n");
        scanf("%s", number);
    }
    salario = strtod(number,NULL);


    showSectors();
    int sector = pedirSector();
    while(sector < 1 || sector > 3){
            printf("Sector invalido. Reingrese sector:\n");
            scanf("%d", &sector);
    }

    if(addEmployee(employees, tam, id, nombre, apellido, salario, sector))
        printf("El empleado ha sido dado de alta corretamente.\n");


}



int pedirIdPorPantalla(){
    int id;
    printf("Ingrese el ID del empleado o 0 si quiere volver al menu\n");
    //fflush(stdin);
    scanf("%d", &id);

    return id;
}

int pedirSector(){
    int sector;
    printf("Ingrese el sector del empleado\n");
    scanf("%d", &sector);

    return sector;
}

int confirmWithMessage(char * mensaje){
    printf(mensaje);
    char confirma[3];
    char confirmaLower[3];
    scanf("%s", confirma);
    to_lower(confirma, confirmaLower);
    if(strcmp(confirmaLower, "si") > 0){
        return TRUE;
    }

    return FALSE;
}

void darDeBaja(eEmployee empleados[], int tam){
    int posicion, id;
    do{
        id = pedirIdPorPantalla();
        if(id == 0) return;
        posicion = findEmployeeById(empleados, tam, id);
    } while(posicion == -1);

    int confirma = confirmWithMessage("Confirmar la baja del empleado? Si o No?\n");
    if(confirma){
        empleados[posicion].isEmpty = TRUE;
        printf("El empleado se ha dado de baja correctamente\n");
    }
}



int chooseInformationToShow(){
    int opcion;
    showInformation();
    scanf("%d", &opcion);
    while(opcion < 1 || opcion > 5){
        printf("Opcion invalida. Reingrese opcion");
    }
    return opcion;
}


int chooseCamposModificar(){
    int opcion;
    printf("%d-NOMBRE\n%d-APELLIDO\n%d-SALARIO\n%d-SECTOR\n%d-VOLVER", NOMBRE, APELLIDO, SALARIO, SECTOR, VOLVER);
    scanf("%d", &opcion);
    while(opcion < 1 || opcion > 5){
        printf("Opcion invalida. Reingrese opcion");
    }
    return opcion;
}

void modificarNombreEmpleado(eEmployee empleados[], int posicion){
    printf("Ingrese el nombre del empleado:\n");
    char name[51];
    //fgets(name, 51, stdin);
    scanf("%s", name);
    if(confirmWithMessage("Confirmar la modificacion del nombre? Si o No?\n"))
        strcpy(empleados[posicion].name, name);
}


void modificarApellidoEmpleado(eEmployee empleados[], int posicion){
    printf("Ingrese el apellido del empleado:\n");
    char apellido[51];
    //fgets(name, 51, stdin);
    scanf("%s", apellido);
    if(confirmWithMessage("Confirmar la modificacion del nombre? Si o No?\n"))
        strcpy(empleados[posicion].lastName, apellido);
}

void modificarSalarioEmpleado(eEmployee* empleados, int posicion){
    printf("Ingrese el salario del empleado:\n");
    float salario;
    //fgets(name, 51, stdin);
    scanf("%f", &salario);
    if(confirmWithMessage("Confirmar la modificacion del nombre? Si o No?\n"))
        empleados[posicion].salary = salario;

}

void modificarSectorEmpleado(eEmployee* empleados, int posicion){
    printf("Ingrese el sector del empleado:\n");
    int sector;
    //fgets(name, 51, stdin);
    scanf("%d", &sector);
    if(confirmWithMessage("Confirmar la modificacion del nombre? Si o No?\n"))
        empleados[posicion].sector = sector;
}

void modificarEmpleado(eEmployee empleados[], int tam){
    int posicion, id;
    do{
        id = pedirIdPorPantalla();
        if(id == 0) return;
        posicion = findEmployeeById(empleados, tam, id);
    } while(posicion == -1);

    printf("Que desea modificar?\n");
    int opcion = chooseCamposModificar();
    switch(opcion)
    {
        case NOMBRE:
            modificarNombreEmpleado(empleados, posicion);
            break;
        case APELLIDO:
            modificarApellidoEmpleado(empleados, posicion);
            break;
        case SALARIO:
            modificarSalarioEmpleado(empleados, posicion);
            break;
        case SECTOR:
            modificarSectorEmpleado(empleados, posicion);
            break;
        case VOLVER:
            return;
        default:
            break;
    }
}



void informarDatosEmpleados(eEmployee empleados[], int tam){
    int opcion = chooseInformationToShow();
    float cant = 0;
    float promedio = 0;
    int cantidadEmpleadosSuperanSalarioPromedio = 0;
    switch(opcion)
    {
        case LISTA_EMPLEADOS:
            printAllEmployees(empleados, tam);
            break;
       case LISTA_ORDENADOS_APELLIDO:
            /*puts("Apellidos antes de ordenar");
            for(int i = 0; i < tam; i++){
                if(empleados[i].isEmpty == FALSE){
                    printf("Apellido: %s\n", empleados[i].lastName);
                }
            }*/
            ordenarPorApellido(empleados, tam);
            printAllEmployees(empleados, tam);
            /*puts("Apellidos luego de ordenar");
            for(int i = 0; i < tam; i++){
                 if(empleados[i].isEmpty == FALSE){
                    printf("Apellido: %s\n", empleados[i].lastName);
                }
            }*/
            break;
        case LISTA_ORDENADOS_SECTOR:
            ordenamientoPorSector(empleados, tam);
            printAllEmployees(empleados, tam);
            break;
        case TOTAL_PROMEDIO_EMPLEADOS_Y_CANTIDAD_SUPERAN_SALARIO_PROMEDIO:
            cant = totalSalaryEmployees(empleados, tam);
            promedio = cant/cantidadEmpleados(empleados, tam);
            printf("Total cantidad de salarios: %.2f y promedio de los salarios: %.2f\n", cant, promedio);
            for(int i = 0; i < tam; i++){
                if(empleados[i].isEmpty == FALSE && (empleados[i].salary > promedio)){
                        cantidadEmpleadosSuperanSalarioPromedio++;
                    }
                }
            printf("Cantidad de empleados que superan el salario promedio: %d\n\n", cantidadEmpleadosSuperanSalarioPromedio);
            break;
        default:
            break;
    }
}

int getPrimeraPosicionOcupada(eEmployee* empleados, int tam, int posicionActual)
{
    int posicion = posicionActual + 1;


    for(posicion ; posicion < tam; posicion++)
    {
        if(!empleados[posicion].isEmpty)
        {
            return posicion;
        }
    }

    return -1;
}

void ordenarPorApellido(eEmployee* empleados, int tam)
{
    eEmployee employeeAux;
    int posicion = 0;
    int i, j;



    for(i = 0; i < tam -1; i++){
        if(!empleados[i].isEmpty)
            posicion = getPrimeraPosicionOcupada(empleados, tam, i);
            if(posicion == -1){
                break;
            }

        // si la posicion es -1 no seguir, analizar que hacer
        for(j = 0; j < tam; j++){
            if(empleados[j].isEmpty)
                continue;
            if(strcmp(empleados[j].lastName, empleados[posicion].lastName) > 0){
                employeeAux= empleados[j];
                empleados[j] = empleados[posicion];
                empleados[posicion] = employeeAux;

            }
        }
    }
}

void ordenamientoPorSector(eEmployee* empleados, int tam)
{
    eEmployee employeeAux;
    int posicion = 0;
    int i, j;



    for(i = 0; i < tam -1; i++){
        if(!empleados[i].isEmpty)
            posicion = getPrimeraPosicionOcupada(empleados, tam, i);
            if(posicion == -1){
                break;
            }

        // si la posicion es -1 no seguir, analizar que hacer
        for(j = 0; j < tam; j++){
            if(empleados[j].isEmpty)
                continue;
            if(empleados[j].sector > empleados[posicion].sector){
                employeeAux= empleados[j];
                empleados[j] = empleados[posicion];
                empleados[posicion] = employeeAux;

            }
        }
    }
}
