// ASM-C++.cpp : main project file.
#include "stdafx.h"
#include "conio.h"
#include <iostream>
using namespace System; 

int mul (int a, int b){
	int valor;
	_asm{
		mov eax,a
		mul b
		mov valor, eax
	}
	return valor;

}

int res (int a, int b){
	int valor;
	_asm{
		mov eax,a
		sub eax,b
		mov valor, eax
	}
	return valor;

}


int divi (int a, int b){
	int valor;
	_asm{
		mov eax,0000h// Registro extendido en ax
	    mov edx,0000h// Registro extendido en dx
		MOV EAX, a 
	    MOV EBX, b      
		DIV EBX
		MOV valor,EAX
	}
	return valor;

}

int suma (int a, int b){
	int valor;
	_asm{
		
		MOV EAX,a   
		ADD EAX,b
		MOV valor,EAX
	}
	return valor;

}



int main(array<System::String ^> ^args)
{

   int opci;
   int val1;
   int val2;
   int resul;
	

	do{
    std::cout<< "1-.Multiplicacion\n2-.Suma\n3-.Division\n4-.Resta\n5-.Salir\n";
	std::cin >> opci;
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
