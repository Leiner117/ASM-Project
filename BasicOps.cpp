#include <iostream>
#include <cstdlib>
#include <string.h>
#include <cstring>
#include <sstream>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

/// Estas son las llamadas de todos los menus
void menuSuma();
void menuResta();
void menuMultiplicacion();
void menuDivision();
void menuPotencia();
void menuCalculadora();
void menuPrincipal();

///----------------------------------------Menu principal------------------------------------------------///


void menuPrincipal(){
    menuCalculadora();
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


int main() {
    menuPrincipal();
    return 0 ;
}
