#include <iostream>
#include <cstdlib>
#include <string.h>
#include <cstring>
#include <sstream>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <cstdio>
#include <map>
#include <list>
#include <fstream>
using namespace std;

/// Estas son las llamadas de todos los menus
void menuSuma();
void menuResta();
void menuMultiplicacion();
void menuDivision();
void menuPotencia();
void menuCalculadora();
void menuPrincipal();
void hora();
void factorial();
void decimalBinario();
void menuConverBinarias();
void ConversionLongitud(int,int,float);
void menuConvLongitud();
void menuConvMasas();
void menuConverUni();
void converMasas(int,int,float);
void converTemp(int,int,float);
void menuConvTemp();
void converMonedas(int ,int ,float );
void menuConvMonedas();
///----------------------------------------Menu principal------------------------------------------------///


void menuPrincipal(){
    while(true){
        int op = 0;
        cout << "1. Consultar la hora del sistema"<<endl;
        cout << "2. Calculadora"<<endl;
        cout << "3. Calcular el factorial"<<endl;
        cout << "4. Conversion de unidades"<<endl;
        cout << "5. Salir"<< endl;

        cin>> op;
        if (op == 1){
            hora();
        }
        if (op == 2){
            menuCalculadora();
        }
        if (op == 3){
            factorial();
        }
        if (op == 4){
            menuConverUni();
        }
        if (op == 5){
            break;
        }
    }


///----------------------------------------Menu Conversion de unidades------------------------------------------------///

}
void menuConverUni(){
    int op = 0;
    cout << "1. Sistemas numericos"<<endl;
    cout << "2. Longitud"<<endl;
    cout << "3. Masas"<<endl;
    cout << "4. Monedas"<<endl;
    cout << "5. Temperaturas"<< endl;
    cout << "6. Salir"<< endl;
    cin>> op;
    if (op == 1){
        menuConverBinarias();
    }
    if (op == 2){
        menuConvLongitud();
    }
    if (op == 3){
        menuConvMasas();
    }
    if (op == 4){
        menuConvMonedas();
    }
    if (op == 5){
        menuConvTemp();
    }


}


///----------------------------------------Menu conversiones de binarios------------------------------------------------///

void menuConverBinarias(){
    int op = 0;
    cout<< "1. Decimal a Binario"<<endl;
    cout<< "2. Binario a Decimal"<<endl;
    cin>> op;
    if (op == 1){
        decimalBinario();
    }
    if (op == 2){
        cout << "En proceso"<<endl;
    }

}


///----------------------------------------Menu conversiones de longitud------------------------------------------------///
void menuConvLongitud(){

    int select1;
    int select2;
    float valor;
    cout<< "1.Metros\n2.Kilometros\n3.Millas\n4.Pulgadas\n5.Pies"<<endl;
    cout<<"Ingrese la primera unidad"<<endl;
    cin>>select1;
    cout<< "1.Metros\n2.Kilometros\n3.Millas\n4.Pulgadas\n5.Pies"<<endl;
    cout<<"Ingrese la segunda unidad"<<endl;
    cin>>select2;
    cout<< "Ingrese el valor que quiere convertir"<<endl;
    cin>>valor;
    ConversionLongitud(select1,select2,valor);

}



///----------------------------------------Menu conversiones de masas------------------------------------------------///

void menuConvMasas(){

    int select1;
    int select2;
    float valor;
    cout<< "1.Gramos\n2.Kilogramos\n3.Libras"<<endl;
    cout<<"Ingrese la primera unidad"<<endl;
    cin>>select1;
    cout<< "1.Gramos\n2.Kilogramos\n3.Libras"<<endl;
    cout<<"Ingrese la segunda unidad"<<endl;
    cin>>select2;
    cout<< "Ingrese el valor que quiere convertir"<<endl;
    cin>>valor;
    converMasas(select1,select2,valor);

}

void menuConvTemp(){
    int select1;
    int select2;
    float valor;
    cout<< "1.Celsius\n2.Fahrenheit\n3.Kelvin"<<endl;
    cout<<"Ingrese la primera unidad"<<endl;
    cin>>select1;
    cout<< "1.Celsius\n2.Fahrenheit\n3.Kelvin"<<endl;
    cout<<"Ingrese la segunda unidad"<<endl;
    cin>>select2;
    cout<< "Ingrese el valor que quiere convertir"<<endl;
    cin>>valor;
    converTemp(select1,select2,valor);

}

void menuConvMonedas(){
    int select1;
    int select2;
    float valor;
    cout<< "1.Dolar\n2.Colones\n3.Euro"<<endl;
    cout<<"Ingrese la primera unidad"<<endl;
    cin>>select1;
    cout<< "1.Dolar\n2.Colones\n3.Euro"<<endl;
    cout<<"Ingrese la segunda unidad"<<endl;
    cin>>select2;
    cout<< "Ingrese el valor que quiere convertir"<<endl;
    cin>>valor;
    converMonedas(select1,select2,valor);

}


///----------------------------------------Operaciones Aritmeticas------------------------------------------------///

void menuCalculadora(){
    system("clear");
  char x = '0';
  cout << endl <<"------->> Operaciones aritmeticas <<-------" << endl;
  cout << endl <<"Opciones: ";
  cout << endl <<"1. SUMA";
  cout << endl <<"2. RESTA";
  cout << endl <<"3. MULTIPLICACION";
  cout << endl <<"4. DIVISION";  
  cout << endl <<"Opcion: ";
  cin >> x;


  if(x == '1'){
    menuSuma();
  }
  else if(x == '2'){
    menuResta();
  }

  else if(x == '3'){
    menuMultiplicacion();
  }

  else if(x == '4'){
    menuDivision();
  }
  else{
    menuCalculadora();
  }
}


void menuSuma(){
  char x = '1';

  while(x == '1'){
    system("clear");
    float num1, num2, suma;

    cout << endl <<"------->> Suma <<-------" << endl;

    cout << endl <<"Digite el primer numero: ";
    cin >> num1;

    cout << endl <<"Digite el Segundo numero: ";
    cin >> num2;

    /// Realiza la suma directamente en el ensambldor
    /// Suma el registro ax con el registro bx

    __asm__ ( "fld %1;"
              "fld %2;"
              "faddp;"
              "fstp %0;" : "=m" (suma) : "m" (num1), "m" (num2) ) ;

    cout << endl <<"El resultado de la Suma: "<< num1 <<" + "<< num2 << " = "  <<suma;

    cout << endl << endl <<"--> Presione una tecla para salir....";
    cin >> x;
  }
  menuCalculadora();
}


void menuResta(){
  char x = '1';

  while(x == '1'){
    system("clear");
    float num1, num2, resta;

    cout << endl <<"------->> Resta <<-------" << endl;

    cout << endl <<"Digite el primer numero: ";
    cin >> num1;

    cout << endl <<"Digite el Segundo numero: ";
    cin >> num2;

    /// Realiza la Resta directamente en el ensambldor
    /// Resta el registro ax con el registro bx

    __asm__ ( "fld %2;"
              "fld %1;"
              "fsubp;"
              "fstp %0;" : "=m" (resta) : "m" (num1), "m" (num2) ) ;

    cout << endl <<"El resultado de la Resta: "<< num1 <<" - "<< num2 << " = "  <<resta;

    cout << endl << endl <<"--> Presione una tecla para salir....";
    cin >> x;
  }
  menuCalculadora();
}


void menuMultiplicacion(){
  char x = '1';

  while(x == '1'){
    system("clear");
    float num1, num2, mul;

    cout << endl <<"------->> Multiplicacion <<-------" << endl;

    cout << endl <<"Digite el primer numero: ";
    cin >> num1;

    cout << endl <<"Digite el Segundo numero: ";
    cin >> num2;

    /// Realiza la multiplicacion directamente en el ensambldor
    /// Multiplica el registro ax con el registro bx

    __asm__ ( "fld %1;"
              "fld %2;"
              "fmulp;"
              "fstp %0;" : "=m" (mul) : "m" (num1), "m" (num2) ) ;

    cout << endl <<"El resultado de la Multiplicacion: "<< num1 <<" * "<< num2 << " = "  <<mul;

    cout << endl << endl <<"--> Presione una tecla para salir....";
    cin >> x;
  }
  menuCalculadora();
}


void menuDivision(){
  char x = '1';

  while(x == '1'){
    system("clear");
    float num1, num2, cociente;

    cout << endl <<"------->> Division <<-------";

    cout << endl <<"RECUERDE QUE NO FUNCIONA CON LOS NUMEROS RACIONALES"<<endl;

    cout << endl <<"Digite el primer numero: ";
    cin >> num1;

    cout << endl <<"Digite el Segundo numero: ";
    cin >> num2;

    /// Realiza la division en el ensamblador

    __asm__ ( "fld %2;"
              "fld %1;"
              "fdivp;"
              "fstp %0;" : "=m" (cociente) : "m" (num1), "m" (num2) ) ;

    cout << endl <<"El resultado de la division: "<< num1 <<" / "<< num2 << " = "  <<cociente;

    cout << endl << endl <<"--> Presione una tecla para salir....";
    cin >> x;
  }
  menuCalculadora();
}


///----------------------------------------HORA DEL SISTEMA------------------------------------------------///

void hora(){

    int hour, minute, second;

    __asm__ volatile (
            "movl $10, %%ebx\n"             // Función 10: sys_gettimeofday
            "xorl %%ecx, %%ecx\n"           // Puntero a estructura timeval en ecx
            "xorl %%edx, %%edx\n"           // Puntero a estructura timezone en edx
            "int $0x80\n"                   // Llamada al sistema

            "movl %%eax, %0\n"              // Almacenar el valor de retorno en hour
            "movl 0x4(%%ecx), %1\n"          // Almacenar tv_sec en minute
            "movl 0x8(%%ecx), %2\n"          // Almacenar tv_usec en second
            : "=r" (hour), "=r" (minute), "=r" (second)
            :
            : "%eax", "%ebx", "%ecx", "%edx"
            );

    std::cout << hour << ":" << minute << ":" << second << std::endl;

}
///----------------------------------------Factorial------------------------------------------------///

int factorial_asm(int n) {
    int result;
    __asm__ __volatile__(
            "movl $1, %%eax\n"
            "movl %1, %%ecx\n"
            "loop_start:\n"
            "imull %%ecx, %%eax\n"
            "decl %%ecx\n"
            "cmpl $1, %%ecx\n"
            "jg loop_start\n"
            : "=a" (result)
            : "c" (n)
            :
            );

    return result;
}

void factorial() {
    int num;
    std::cout << "Ingrese un número: ";
    std::cin >> num;

    int result = factorial_asm(num);

    std::cout << "El factorial de " << num << " es: " << result << std::endl;


}
///----------------------------------------Decimal a binario------------------------------------------------///
/***
void decimalToBinary_asm() {
    int decimal;
    std::cout << "Ingrese un número decimal: ";
    cin >> decimal;

    char binary[33];  // Buffer to store the binary result (32 bits + null terminator)

    __asm__(
            "mov %[decimal], %%eax\n\t"  // Move the decimal number to EAX

            "mov $32, %%ecx\n\t"         // Set the loop counter to 32

            "loop:\n\t"
            "xor %%edx, %%edx\n\t"       // Clear the EDX register
            "mov $2, %%ebx\n\t"          // Set the divisor to 2
            "div %%ebx\n\t"              // Divide EAX by 2 (quotient in EAX, remainder in EDX)

            "add $'0', %%dl\n\t"         // Convert the remainder to a character
            "dec %[binary]\n\t"          // Move back one position in the binary buffer
            "mov %%dl, (%[binary])\n\t"  // Store the character in the binary buffer

            "dec %%ecx\n\t"              // Decrement the loop counter
            "jnz loop\n\t"               // Jump to 'loop' if the loop counter is not zero

            : [binary] "=r" (binary)     // Output: binary buffer
    : [decimal] "r" (decimal)    // Input: decimal number
    : "eax", "ebx", "ecx", "edx", "memory"
    );

    std::cout << "El número en binario es: " << binary << std::endl;
}
***/

void decimalBinario(){
    int num;
    std::cout << "Ingrese un número decimal: ";
    std::cin >> num;


}

void ConversionLongitud(int select1,int select2,float cant){
    /**
     * Metros,Kilometros,millas,pulgadas,pies
     */

    float result = 0;
    std::map<int, std::map<int, float>> unidadesLongitud;
    //std::map<std::string, std::list<float>> unidadesLongitud;
    unidadesLongitud[1][2] = 0.001;
    unidadesLongitud[1][3] = 0.000621371;
    unidadesLongitud[1][4] = 39.3701;
    unidadesLongitud[1][5] = 3.28084;

    unidadesLongitud[2][1] = 1000;
    unidadesLongitud[2][3] = 0.621371;
    unidadesLongitud[2][4] = 39370.1;
    unidadesLongitud[2][5] = 3280.84;


    unidadesLongitud[3][1] = 1.60934;
    unidadesLongitud[3][2] = 1609.34;
    unidadesLongitud[3][4] = 63360;
    unidadesLongitud[3][5] = 5280;

    unidadesLongitud[4][1] = 0.0254;
    unidadesLongitud[4][2] = 0.0000254;
    unidadesLongitud[4][3] = 0.0000158;
    unidadesLongitud[4][5] = 0.0833333;


    unidadesLongitud[5][1] = 0.3048;
    unidadesLongitud[5][2] = 0.0003048;
    unidadesLongitud[5][3] = 0.000189394;
    unidadesLongitud[5][4] = 12.0;

    float num = unidadesLongitud.at(select1).at(select2);

    asm volatile (
            "fld %1;"
            "fmul %2;"
            "fstp %0;"
            : "=m" (result)
            : "m" (num), "m" (cant)
            : "st"
            );


    std::cout << "Resultado: " << result << std::endl;
}


///----------------------------------------Conversion de Masas------------------------------------------------///

//Gramos,Kilogramos,Libras
void converMasas(int select1,int select2,float valor){
    std::map<int, std::map<int, float>> unidadesPeso;
    float result = 0;
    unidadesPeso[1][3] = 0.00220462;
    unidadesPeso[1][2] = 0.001;
    unidadesPeso[2][1] = 1000;
    unidadesPeso[2][3] = 2.20462;
    unidadesPeso[3][1] = 453.592;
    unidadesPeso[3][2] = 0.453592;


    float num = unidadesPeso.at(select1).at(select2);

    asm volatile (
            "fld %1;"
            "fmul %2;"
            "fstp %0;"
            : "=m" (result)
            : "m" (num), "m" (valor)
            : "st"
            );


    std::cout << "Resultado: " << result << std::endl;
}

///----------------------------------------Conversion de Temperatura------------------------------------------------///

void converTemp(int select1,int select2,float valor){
    std::map<int, std::map<int, float>> unidadesTemperatura;
    float result = 0;
    unidadesTemperatura[1][2] = 33.8;
    unidadesTemperatura[1][3] = 274.15;
    unidadesTemperatura[2][1] = -17.2222;
    unidadesTemperatura[2][3] = 255.928;
    unidadesTemperatura[3][2] = -457.87;
    unidadesTemperatura[3][1] = -272.15;

    float num = unidadesTemperatura.at(select1).at(select2);
    if ((select1 ==3|| 3 == select2)){
        asm volatile (
                "fld %1;"
                "fadd %2;"
                "fstp %0;"
                : "=m" (result)
                : "m" (num), "m" (valor)
                : "st"
                );
        std::cout << "Resultado: " << result << std::endl;
    }
    else{
        float resultado2 = 0.0;
        float c = 1.8;
        float a = 32.0;
        asm volatile (
                "fld %1;"
                "fmul %2;"
                "fstp %0;"
                : "=m" (result)
                : "m" (c), "m" (valor)
                : "st"
                );
        asm volatile (
                "fld %1;"
                "fadd %2;"
                "fstp %0;"
                : "=m" (resultado2)
                : "m" (a), "m" (result)
                : "st"
                );

        std::cout << "Resultado: " << resultado2 << std::endl;
    }






}
void converMonedas(int select1,int select2,float valor){
    /***std::ifstream archivo("C:\\Users\\leine\\OneDrive\\Documentos\\GitHub\\ASM-Project\\cambioDivisa.txt"); // Reemplaza "archivo.txt" por la ruta y nombre de tu archivo de texto

    if (archivo.is_open()) {
        std::string linea;
        while (std::getline(archivo, linea)) {
            std::cout << linea << std::endl;
        }

        archivo.close();
    } else {
        std::cout << "No se pudo abrir el archivo." << std::endl;
    }***/
    std::map<int, std::map<int, float>> unidadesMonedas;
    float result = 0;
    unidadesMonedas[1][2] = 541.080374;
    unidadesMonedas[1][3] = 0.932079;
    unidadesMonedas[2][1] = 0.001848;
    unidadesMonedas[2][3] = 0.001721;
    unidadesMonedas[3][2] = 1.072871;
    unidadesMonedas[3][1] = 581.113078;

    float num = unidadesMonedas.at(select1).at(select2);

    asm volatile (
            "fld %1;"
            "fmul %2;"
            "fstp %0;"
            : "=m" (result)
            : "m" (num), "m" (valor)
            : "st"
            );


    std::cout << "Resultado: " << result << std::endl;
}


///----------------------------------------Main------------------------------------------------///



int main() {
    menuPrincipal();
    return 0 ;
}
