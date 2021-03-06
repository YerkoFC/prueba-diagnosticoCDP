#include <iostream>
#include <ctype.h>

// Retorna true si contiene un numero y false si no
bool contieneNumeros(std::string cadena){
    // Si cadena no contiene nada
    if(cadena.length() == 0 || cadena == " "){
        return false;
    }else{
        // Bucle que recorre cadena para comprobar si contiene digitos
        for(int i=0; i < cadena.length(); i++){
            // Si posicion i de cadena es un digito, retorna true. Si no, continua
           if(isdigit(cadena[i])){
               return true;
           } else{
               continue;
           }
        }
        // Si no se encontraron digitos en la cadena, se retorna false
        return false;   
    }   
}
// Retorna un string completo en minuscula
std::string arrayALowerCase(std::string cadena){
    for(int i=0; i<cadena.length(); i++){
        cadena[i] = tolower(cadena[i]);
    }
    return cadena;
}
// Retorna true si la cadena contiene solamente las letras que esten dentro de los valores 122 y 97 segun codigo ascii
bool soloLetras(std::string cadena){
    for(int i=0; i<cadena.length(); i++){
        if( (int(cadena[i]) > 122) || (int(cadena[i]) < 97)){
            return false;
        }else{
            continue;
        }
    }
    return true;
}

// Funcion principal
int main(){
    // Se inicializa variable en la cual se almacenará la cadena ingresada por el usuario
    std::string cadena = "";
    // Se solicita ingresar un valor de tipo string por consola
L1: std::cin >> cadena;
    // Se evalúa si la cadena ingresa contiene digitos
    if(contieneNumeros(cadena)){
        std::cout << "la cadena no debe contener numeros. Ingrese nuevamente una: " << std::endl;
        // Si contiene algún digito, se transfiere el control del programa a la etiquera L1 
        goto L1;
    }else{
        // Se evalua si la cadena no contiene letras
        if(!soloLetras(arrayALowerCase(cadena))){
            std::cout << "la cadena solo debe contener letras. Ingrese nuevamente una: " << std::endl;
            // Si contiene algún caracter diferente de una letra, se transfiere el control del programa a la etiqueta L1 nuevamente
            goto L1;
        }else{
            // Se pasa cadena a minusculas
            cadena = arrayALowerCase(cadena);
            // Se inicializan variables par
            std::string aux0 = "", aux1 = "", resultado = "";
            // Se inicializa variable que almacenará el conteo del numero de repeticiones por letra
            // Su valor es 1 puesto que se asume que la primera letra de la cadena a lo menos está repetida una sola vez
            int contLetras = 1;
            // Bucle for que evaluara indice por indice 
            for(int i=0; i<cadena.length(); i++){
                // Siempre y cuando i sea menor que el largo de la cadena, se accede a la condicional
                if(i < cadena.length()){
                    // Se almacenan los valores de los dos primeros indices en aux0 y aux1 respectivamente
                    aux0 = cadena[i];
                    aux1 = cadena[i+1];
                    // Se evalúa si son iguales. Si lo son, se suma 1 al contLetras
                    if(aux0 == aux1){
                        contLetras++;
                    // Si no son iguales, se concatena la letra con su respectiva cantidad de repeticiones
                    }else{
                        // contLetras se pasa a tipo string para concatenar
                        resultado += cadena[i] + std::to_string(contLetras);
                        // Se vuelve a incializar contLetras en 1, puesto que se asume que la proxima letra tendrá a lo menos una repeticion
                        contLetras = 1;
                    }
                }
            }
            // Se imprime el resultado esperado por el usuario
            std::cout << resultado << std::endl;
        }     
    }
    return 0;
}