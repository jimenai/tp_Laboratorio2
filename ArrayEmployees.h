#ifndef ARRAY_EMPLOYEES_H
#define ARRAY_EMPLOYEES_H


typedef struct{
    int id;
    char name[21];
    char lastName[21];
    float salary;
    int sector;
    int isEmpty;
}eEmployee;

/**
* \brief Inicializa todos los empleados del array
* \param employees Array de la estructura empleados
* \param tam Tamanio del array de la estructura empleados
* \return No retorna nada porque es de tipo VOID
*
*/
void initEmployees(eEmployee employees[], int tam);

/**
* \brief Busca al empleado por el ID recorriendo todo el array de empleados
* \param employees Array de la estructura empleados
* \param tam Tamanio del array de la estructura empleados
* \param id Id del empleado a buscar en el array de estructura empleado
* \return index Retorna la posicion libre dentro del vector, si no lo encuentra retorna -1
*
*/
int findEmployeeById(eEmployee employees[], int tam, int id);

/**
* \brief Busca un espacio libre en el array empleado
* \param employees Array de la estructura empleados
* \param tam Tamanio del array de la estructura empleados
* \return index Retorna la posicion del empleado dentro del vector, si no encuentra retorna -1
*
*/
int findSpaceInEmployeeList(eEmployee employees[], int tam);

/**
* \brief Muestra a un empleado dado de alta
* \param employees Un solo elemento del array de la estructura empleados
* \return No retorna nada porque es de tipo VOID
*
*/
void printEmployee(eEmployee employee);

/**
* \brief Muestra a todos los empleados dado de alta
* \param employees Array de la estructura empleados
* \param tam Tamanio del array de la estructura empleados
* \return No retorna nada porque es de tipo VOID
*
*/
void printAllEmployees(eEmployee employees[], int tam);

/**
* \brief Calcula el total de los salarios de todos los  empleados dados de alta
* \param employees Array de la estructura empleados
* \param tam Tamanio del array de la estructura empleados
* \return totalSalario Retorna el total de todos los salarios
*
*/
float totalSalaryEmployees(eEmployee employees[], int tam);

/**
* \brief Muestra a todos los empleados dado de alta
* \param employees Array de la estructura empleados
* \param tam Tamanio del array de la estructura empleados
* \return cantidadEmpleados Retorna la cantidad total de empleados dados de alta
*
*/
int cantidadEmpleados(eEmployee employees[], int tam);

/**
* \brief Crea un id a cada empleado dado de alta
* \return id Retorna el id creado para el empleado
*
*/
int getIdForNewEmployee();

/**
* \brief Agrega al empleado dado de alta al array de la estructura de empleados
* \param employees Array de la estructura empleados
* \param tam Tamanio del array de la estructura empleados
* \param id Id del empleado dado de alta
* \param name Nombre del empleado dado de alta
* \param lastName Apellido del empleado dado de alta
* \param salary Salario del empleado dado de alta
* \param sector Sector del empleado dado de alta
* \return TRUE retorna si se pudo agregar el empleado, de lo contrario retorns FALSE
*
*/
int addEmployee(eEmployee employees[], int tam, int id, char name[], char lastName[], float salary, int sector);

/**
* \brief Da de alta al empleado verificando que no haya sido dado de alta anteriormente
* \param employees Array de la estructura empleados
* \param tam Tamanio del array de la estructura empleados
* \return No retorna nada porque es de tipo VOID
*
*/
void darDeAltaEmpleado(eEmployee employees[], int tam);

/**
* \brief Pide el ID del empleado por pantalla
* \return id Retorna el id pedido
*
*/
int pedirIdPorPantalla();

/**
* \brief Pide el sector del empleado por pantalla
* \return sector Retorna el sector pedido
*
*/
int pedirSector();

/**
* \brief Muestra un mensaje de confirmacion
* \return TRUE Retorna si la confirmacion es posistiva y retorna FALSE si es negativa
*
*/
int confirmWithMessage();

/**
* \brief Da de baja el empleado
* \param employees Array de la estructura empleados
* \param tam Tamanio del array de la estructura empleados
* \return No retorna nada porque es de tipo VOID
*
*/
void darDeBaja(eEmployee empleados[], int tam);

/**
* \brief Muestra un mensaje de confirmacion sobre la modificacion de los parametros del empleado
* \return TRUE Retorna si la confirmacion es posistiva y retorna FALSE si es negativa
*
*/
int confirmModifyEmployee();

/**
* \brief Ordena la lista de empleados dados de alta de manera descendente por sector
* \param employees Array de la estructura empleados
* \param tam Tamanio del array de la estructura empleados
* \return No retorna nada porque es de tipo VOID
*
*/
void ordenamientoPorSector(eEmployee* employees, int tam);

/**
* \brief Modifica el nombre del empleado dado de alta
* \param employees Array de la estructura empleados
* \param posicion Es la posicion dentro del empleado a modificar
* \return No retorna nada porque es de tipo VOID
*
*/
void modificarNombreEmpleado(eEmployee *employee, int posicion);

/**
* \brief Modifica el apellido del empleado dado de alta
* \param employees Array de la estructura empleados
* \param posicion Es la posicion dentro del empleado a modificar
* \return No retorna nada porque es de tipo VOID
*
*/
void modificarApellidoEmpleado(eEmployee* employee, int posicion);

/**
* \brief Modifica el sector del empleado dado de alta
* \param employees Array de la estructura empleados
* \param posicion Es la posicion dentro del empleado a modificar
* \return No retorna nada porque es de tipo VOID
*
*/
void modificarSectorEmpleado(eEmployee* employee, int posicion);

/**
* \brief Modifica el salario del empleado dado de alta
* \param employees Array de la estructura empleados
* \param posicion Es la posicion dentro del empleado a modificar
* \return No retorna nada porque es de tipo VOID
*
*/
void modificarSalarioEmpleado(eEmployee* employee, int posicion);

/**
* \brief Modifica el nombre del empleado dado de alta
* \param employees Array de la estructura empleados
* \param tam Tamanio del array de la estructura empleados
* \return No retorna nada porque es de tipo VOID
*
*/
void modificarEmpleado(eEmployee* empleados, int tam);

/**
* \brief Muestra un menu de informacion al usuario sobre que informes desea ver sobre los empleados dados de alta
* \param employees Array de la estructura empleados
* \param tam Tamanio del array de la estructura empleados
* \return No retorna nada porque es de tipo VOID
*
*/
void informarDatosEmpleados(eEmployee* empleados, int tam);

/**
* \brief Ordena alfabeticamente por apellido a los empleados dados de alta
* \param employees Array de la estructura empleados
* \param tam Tamanio del array de la estructura empleados
* \return No retorna nada porque es de tipo VOID
*
*/
void ordenaPorApellido(eEmployee* empleados, int tam);

/**
* \brief Obtiene la primera posicion ocupada desde la posicion actual en el array de empleados dados de alta
* \param employees Array de la estructura empleados
* \param tam Tamanio del array de la estructura empleados
* \param posicionActual Posicion dentro del array empleados dados de alta la cual sera utilizada para obtener la siguiente ocupada
* \return posicion Retorna la primera posicion ocupada luego de la posicion actual cargada, de lo contrario FALSE.
*
*/
int getPrimeraPosicionOcupada(eEmployee* empleados, int tam, int posicionActual);

#endif
