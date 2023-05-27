#include <iostream>
#include <cstdlib>
#include <string.h>
#include <cstring>
#include <sstream>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <cstdio>
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
///----------------------------------------Menu principal------------------------------------------------///


void menuPrincipal(){
    int op = 0;
    cout << "1. Consultar la hora del sistema"<<endl;
    cout << "2. Calculadora"<<endl;
    cout << "3. Calcular el factorial"<<endl;
    cout << "4. Conversion de unidades"<<endl;
    cout << "5. Temperatura"<< endl;

    cin>> op;
    if (op == 1){
        hora();
    }
    if (op == 3){
        factorial();
    }
}

void menuCOnversiones(){
    int op = 0;
    cout<< "1. Decimal a Binario"<<endl;
    cout<< "2. Binario a Decimal"<<endl;
    if (op == 1){
        decimalBinario();
    }

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




void decimalToBinary_asm(int n) {
    __asm__ __volatile__(
            "pushl %%ebp\n"
            "movl %%esp, %%ebp\n"
            "subl $4, %%esp\n"
            "movl %0, %%eax\n"
            "movl $0, %%ebx\n"
            "movl $0, %%ecx\n"

            "convert_loop:\n"
            "cmpl $0, %%eax\n"
            "je loop_end\n"
            "movl $2, %%ebx\n"
            "xorl %%edx, %%edx\n"
            "divl %%ebx\n"
            "movl %%edx, (%%ecx)\n"
            "incl %%ecx\n"
            "jmp convert_loop\n"

            "loop_end:\n"
            "cmpl $0, %%ecx\n"
            "je print_zero\n"

            "print_loop:\n"
            "decl %%ecx\n"
            "movl (%%ecx), %%eax\n"
            "addl $48, %%eax\n"
            "pushl %%eax\n"
            "call putchar\n"
            "addl $4, %%esp\n"
            "cmpl $0, %%ecx\n"
            "jg print_loop\n"

            "print_zero:\n"
            "pushl $48\n"
            "call putchar\n"
            "addl $4, %%esp\n"

            "movl %%ebp, %%esp\n"
            "popl %%ebp\n"
            :
            : "g" (n)
            : "%eax", "%ebx", "%ecx", "%edx"
            );
}

void decimalBinario(){
    int num;
    std::cout << "Ingrese un número decimal: ";
    std::cin >> num;

    decimalToBinary_asm(num);
}

int main() {
    menuPrincipal();
    return 0 ;
}
