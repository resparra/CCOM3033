#include "ColorRectangle.h"

	

ColorRectangle::ColorRectangle(){
	r.setAncho(1) ;
	r.setLargo(1) ;
	color = BG_BLACK ;
}

ColorRectangle::ColorRectangle(int a, int b){
        if(a < 1|| b < 1){
                cout << "Error Line rectangle sides can't be <=2" <<endl;
                exit(0) ;
        }
        r.setAncho(a) ;
        r.setLargo(b) ;
        color = BG_BLACK ;
}

//***********************************************
//	Constructor that initializes the colors
//***********************************************

ColorRectangle::ColorRectangle(int a, int l , int c)
{
	r.setAncho(a);
	r.setLargo(l);
	color = c ;
}

void ColorRectangle::setAncho(int a){
	if(a >= 1)
		r.setAncho(a) ;
}

void ColorRectangle::setLargo(int l){
	if(l >=1)
		r.setLargo(l) ;
}

void ColorRectangle::setColor(int c){
	if(color >= 40 && color <= 47)
		color = c ;
}

int ColorRectangle::getColor(){
	return color ;
}

int ColorRectangle::getAncho(){
        return r.getAncho() ;
}

int ColorRectangle::getLargo(){
        return r.getLargo() ;
}


ColorRectangle::ColorRectangle(ColorRectangle &cr){
	r.setAncho(cr.r.getAncho()) ;
	r.setLargo(cr.getLargo()) ;
	color = cr.color ;
}

void ColorRectangle::printRectangle(){

	printf("%c[%d;%d;%dm", 0x1B, BRIGHT,RED,color);
	for(int i = 0; i < r.getLargo(); i++){
		for(int j = 0 ; j < r.getAncho()*2.5; j++){
			cout << " ";
		}
		cout <<endl ;
	}
	printf("%c[%dm", 0x1B, 0);

}

ColorRectangle & ColorRectangle::operator=(ColorRectangle &cr){
	
	color = cr.color ;
        r.setAncho(cr.r.getAncho()) ;
        r.setLargo(cr.r.getLargo()) ;
	
	return *this ;	
}
