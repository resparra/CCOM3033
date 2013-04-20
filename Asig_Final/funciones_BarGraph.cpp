#include "BarGraph.h";


BarGraph::BarGraph (){
	title = "0";
	data = new GData;
	data_size = 0;
}
		
		
BarGraph::BarGraph (GData* dt, int a){
	data = dt;
	data_size = a;
}
		

void BarGraph::DisplayGraph (){
		ColorRectangle Oc;
		ColorRectangle Pack;
		
		Oc.setAncho((data[0].value/50));
		Oc.setColor(42);
		Pack.setAncho((data[1].value/50));
		Pack.setColor(43);
		
		cout << " Octects   " ;
		Oc.printRectangle();
		
		cout << " Packets   " ;
		Pack.printRectangle();
		
}
		

void BarGraph::setTittle (string a){
	title = a;
}

void BarGraph::setGData (int x, int y){
	data = new GData[2];
	data[0].label = "Octects";
	data[0].value = x;
	data[1].label = "Packets";
	data[1].value = y;
}

void BarGraph::setData_size (int a){
	data_size = a;
}
		
string BarGraph::getTittle(){
	return title;
}


GData* BarGraph::getGData (){
	return data;
}

int BarGraph::getData_size(){
	return data_size;
}
		
BarGraph::~BarGraph (){
	delete []data;
}
 