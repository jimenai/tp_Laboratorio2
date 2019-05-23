#include "ArrayEmployees.h"
#include "defines.h"
#include <stdio.h>
#include <stdlib.h>

int esNumerico(char numero[]){
    int i = 0;
    while(numero[i] != '\0'){
        if(numero[i] < '0' || numero[i]> '9'){
            return -1;
        }
        i++;
    }
    return 1;
}

int numeroFlotante(char numero[]){
    int i = 0;
    while(numero[i] != '\0'){
        if ((numero[i] < '0' || numero[i]> '9') && numero[i] != '.' ){
            return -1;
        }
        i++;
    }
    return 1;
}


int justString(char str[]){
    int i = 0;
    while(str[i] != '\0'){
        if((str[i] < 'a' || str[i] > 'z') && str[i] != ' ' && (str[i] < 'A' || str[i] > 'Z')){
            return -1;
        }
        i++;
    }
    return 1;
}


int esSoloLetrasMayusculas(char str[]){
    int i = 0;
    while(str[i] != '\0'){
        if(str[i] == ' ' || str[i]< 'a' || str[i]> 'z' ){
            return FALSE;
        }
        i++;
    }
    return TRUE;
}
/*
int esSoloLetrasMinusculas(char str[]){
    int i = 0;
    while(str[i] != '\0'){
        if(str[i] = ' ' || str[i]< 'A' || str[i]> 'Z'){
            return FALSE;
        }
        i++;
    }
    return TRUE;
}

int esSoloLetras(char str[]){
    if(esSoloLetrasMayusculas(str) && esSoloLetrasMinusculas(str)){
        return TRUE;
    }
    return FALSE;
}

int validaSoloLetras(char mensaje[], char input[]){
    char aux[51];
    getString(mensaje, aux);
    if(soloLetras(aux)){
        strcpy(input, aux);
        return 1;
    }

    return 0;
}

*/
