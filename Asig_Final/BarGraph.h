#include <iostream>
#include <string>
#include "ColorRectangle.h"
#include "Rectangle.h"

using namespace std ;

#ifndef __BARGRAPH_
#define __BARGRAPH_

struct GData {
	int    value ;
	string label;
};

class BarGraph {
	private:
		string title;
		GData* data;
		int    data_size;
		
	public :
		BarGraph ();
		BarGraph (GData* , int );
		
		void DisplayGraph ();
		
		void setTittle    (string);
		void setGData     (int, int);
		void setData_size (int);
		
		string getTittle    ();
		GData* getGData     ();
		int    getData_size ();
		
		~BarGraph (); 
};
#endif