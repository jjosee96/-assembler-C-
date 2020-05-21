// ASM-C++.cpp : main project file.
//Importacion de librerias necesarias
#include "stdafx.h"
#include "conio.h"
#include <iostream>
using namespace System; 
//Este programa se desarrollo en Microsoft Visual C++ 2010 Express, si se desea ejecutar este proyecto muy posiblemente se necesitará descargar dicho IDE. 
// Metodo para multiplicar
int mul (int a, int b){
	int valor;
	_asm{ //Palabra cable para abrir un bloque de codigo ensamblador 
		mov eax,a // Redirecciona el valor de a a ax
		mul b //Se realiza la multiplicación de b x a
		mov valor, eax // El resultado se almacena en la varible "valor".
	} // Cierre de cosigo ensamblador
	return valor; // Valor retornado por el metodo mul.

}
//Metodo para restar
int res (int a, int b){
	int valor;
	_asm{  //Palabra cable para abrir un bloque de codigo ensamblador 
		mov eax,a
		sub eax,b
		mov valor, eax
	}  // Cierre de cosigo ensamblador
	return valor;

}
//Metodo para dividir
int divi (int a, int b){
	int valor;
	_asm{  //Palabra cable para abrir un bloque de codigo ensamblador 
		mov eax,0000h // Registro extendido en ax
	    mov edx,0000h // Registro extendido en dx
		MOV EAX, a // Redirecciona el valor de "a" a AX
	    MOV EBX, b // Redirecciona el valor de "b" a BX   
		DIV EBX  // Se realiza la división 
		MOV valor,EAX // El resulta se almacena en AX (cociente) y se redirecciona a la variable "valor"
	}  // Cierre de cosigo ensamblador
	return valor;

}
//Metodo para sumar 
int suma (int a, int b){
	int valor;
	_asm{ //Palabra cable para abrir un bloque de codigo ensamblador 
		
		MOV EAX,a   //Redireccionamiento de "a" a AX
		ADD EAX,b  //Se realiza la suma de a + b
		MOV valor,EAX // Se redirecciona el resultado a la variable "valor"
	}  // Cierre de cosigo ensamblador
	return valor;

}
int main(array<System::String ^> ^args)
{
   int opci;
   int val1;
   int val2;
   int resul;
   std::cout<< "Jose Guadalupe Magana Diaz ISC ITSUR \n";
	do{
    std::cout<< "1-.Multiplicacion\n2-.Suma\n3-.Division\n4-.Resta\n5-.Salir\n";
	std::cin >> opci;
	/* Una vez que se tienen los bloques de codigo de ensamblador, simplemente se llaman los metodos
    de forma habitual y de igual forma se le pasan los parametros de cada metodo y se recibe el resultado.
	*/
	switch(opci){
		case 1:
			std::cout<< "****Multiplicacion****\n";
			std::cout<< "Ingresa tu primer valor\n";
			std::cin>>val1;
			std::cout<< "Ingresa tu segundo valor\n";
			std::cin>>val2;
			resul = mul(val1,val2);
			Console:: Write("El resultado es :" + resul+"\n");
			std::cout<< "Presione enter\n";
	        Console:: Read();
		break;
		case 2:
			std::cout<< "*****Suma*****\n";
		    std::cout<< "Ingresa el primer valor\n";
			std::cin>>val1;
			std::cout<< "Ingresa el segundo valor\n";
			std::cin>>val2;
	     	resul= suma(val1,val2);
			Console:: Write("El resultado es :" + resul+"\n"); 
			Console:: Read();
			break;
		case 3:
			std::cout<< "*****Division*****\n";
		    std::cout<< "Ingresa el dividendo\n";
			std::cin>>val1;
			std::cout<< "Ingresa el divisor\n";
			std::cin>>val2;
	     	resul= divi(val1,val2);
			Console:: Write("El resultado es :" + resul+"\n");
	        std::cout<< "Presione enter\n";
			Console:: Read();
			break;
		case 4:
			std::cout<< "*****Resta****\n";
			std::cout<< "Ingresa tu primer valor\n";
			std::cin>>val1;
			std::cout<< "Ingresa tu segundo valor\n";
			std::cin>>val2;
			resul = res(val1,val2);
			Console:: Write("El resultado es :" + resul+"\n");
			std::cout<< "Presione enter\n";
	        Console:: Read();
			break;
	}
	}while(opci!=5);
	std::cout<< "Presione enter";
	Console:: Read();
	return 0;
}
