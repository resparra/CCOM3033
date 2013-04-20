#include <iostream>
#include "Rectangle.h"

using namespace std ;

#ifndef __COLORRECTANGLE_
#define __COLORRECTANGLE_

#define BRIGHT 1
#define RED 31
#define BG_BLACK 40

class ColorRectangle{
	private:
		Rectangle r ;
		int color ;
		
	public:
		ColorRectangle();
		ColorRectangle(int, int);
		ColorRectangle (int, int, int);
		ColorRectangle(ColorRectangle &) ;
		void setAncho(int) ;
		void setLargo(int) ;
		void setColor(int) ;
		int getColor() ;
		int getLargo() ;
		int getAncho() ;
		void printRectangle() ;
		ColorRectangle &  operator=(ColorRectangle &) ;
		ColorRectangle operator+(ColorRectangle & ) ;
		
} ;
#endif