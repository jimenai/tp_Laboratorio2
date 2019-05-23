void to_lower(char* strAConvertir, char* strConvertido){
    char letraLower;
    for(int i = 0; strAConvertir[i] != '\0'; i++){
        letraLower = tolower(strAConvertir[i]);
        strConvertido[i] = letraLower;
    }
}

void printTrueOrFalse(int trueOrFalse){
    if(trueOrFalse){
        printf("Verdadero\n");
    }
    else{
        printf("Falso\n");
    }
}
