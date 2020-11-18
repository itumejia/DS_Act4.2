//Archivo de función toLetters

//Complejidad O(1)
//Función auxiliar de toLetters que le asigna una letra a un número del 1 al 26
char toLetter(int n){
    return "ZABCDEFGHIJKLMNOPQRSTUVWXYZ"[n];
}

//Complejidad O(1)
//Función que regresa código alfabético a partir de un número. Funciona con números de 1 al 702 (A - ZZ)
string toLetters(int n){
    //Si el número es menor a 26, simplemente se convierte a su letra correspondiente
    if(n<=26){
        return string(1,toLetter(n));
    }
    //Si es mayor a 26, y es múltiplo de 26:
    else if(n%26==0){
        return string(1,toLetter(n/26-1))+'Z';
    }
    //Si es mayor a 26 y no es múltiplo de 26:
    else{
        return string(1,toLetter(n/26))+toLetter(n%26);
    }
}

