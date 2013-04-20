#include <iostream>

using namespace std ;

#ifndef __RECTANGLE_
#define __RECTANGLE_
class Rectangle{

	private:
		// Variables privadas que contienen la informacion
		// del largo  el ancho del rectangulo
		int largo;
		int ancho;
	public:
		Rectangle() ;
		Rectangle(int, int) ;
		int getLargo ();
		int getAncho ();
		void setAncho(int);
		void setLargo(int);
		void printRectangle() ;
		
} ;
#endif