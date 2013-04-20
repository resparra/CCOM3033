#include "Rectangle.h"

Rectangle::Rectangle(){
	largo = 1 ;
	ancho = 1 ;
}
	
Rectangle::Rectangle(int a, int l){
	if(a < 1 || l < 1){
		cout << "Rectangle can't have sides <= 1" <<endl ;
		exit(0) ;
	}
	largo = l ;
	ancho = a ;
}

int Rectangle::getLargo(){
	return largo ;
}

int Rectangle::getAncho(){
	return ancho ;
}

void Rectangle::setAncho(int a){
	ancho = a ;
}

void Rectangle::setLargo(int l){
	largo = l ;
}

void Rectangle::printRectangle(){

	for(int i = 0; i < largo; i++){
		for(int j = 0; j < ancho; j++)
			cout << "#" ;
		cout <<endl ;
	}

}
