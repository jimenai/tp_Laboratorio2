#ifndef VALIDACIONES_H
    #define VALIDACIONES_H


    /**
    * \brief Valida que el string este compuesto por numeros
    * \param numero Numero ingresao por el usuario a ser validado
    * \return TRUE retorna si es valido, de lo contrario retorna FALSE
    *
    */
    int esNumerico(char numero[]);

    /**
    * \brief Valida que el string sea decimal
    * \param numero Numero ingresao por el usuario a ser validado
    * \return TRUE retorna si es valido, de lo contrario retorna FALSE
    *
    */
    int numeroFlotante(char numero[]);

    /**
    * \brief Valida que el string este compuesto por unicamente letras
    * \param str String ingresao por el usuario a ser validado
    * \return TRUE retorna si es valido, de lo contrario retorna FALSE
    *
    */
    int justString(char str[]);


#endif // VALIDACIONES_H
