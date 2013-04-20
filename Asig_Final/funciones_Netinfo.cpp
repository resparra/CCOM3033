#include <iostream>
#include <string>
#include <fstream>
#include "NetInfo.h"
#include "BarGraph.h"



Netinfo::Netinfo (){
	flow_array = NULL;
	total_octets = 0;
	total_packets = 0;
	total_flows = 0;
	max_flows = 0;
	filename = "0";

}

Netinfo::Netinfo (Flow* Array_flows, int a){
	flow_array = Array_flows;
	total_flows = a;
}
		
void Netinfo::setFlow_array	   (Flow* ptr){
		flow_array = ptr;
}

void Netinfo::setTotal_octets (){
	
	for(int i = 0; i < total_flows; i++){
        total_octets += flow_array[i].getOctets(); 
    	}
}


void Netinfo::setTotal_packets () {
	for(int i = 0; i < total_flows; i++){ 
        total_packets += flow_array[i].getPackets();
    }
}


void Netinfo::setTotal_flows   (){
	ifstream inputFile;                 // Variable para colocar el nombre del archivo
    int i=0;							// Acumular cuantos records se leen del archivo                            
    string a, b ;
    int c, d , e , f;
    inputFile.open(filename.c_str());
    
    while(inputFile >> a >> b >> c >> d >> e >> f)  // LEER RECORDS DEL ARCHIVO
    { 
        i++;  
    }
	
	total_flows = i;
	
}

void Netinfo::setMax_flows  (int a){
	max_flows = a;
}


void Netinfo::setFilename      (string file){
	filename = file;
}
		
Flow*  Netinfo::getFlow_array   (){
	return flow_array;
}


int    Netinfo::getTotal_octets (){
	return total_octets;
	}
	
int    Netinfo::getTotal_packets(){
	return total_packets;
	}
	
int    Netinfo::getTotal_flows  (){
	return total_flows;
	}
int    Netinfo::getMax_flows    (){
	return max_flows;
	}
string Netinfo::getFilename     (){
	return filename;
	}
		
		
		
void Netinfo::LoadFile (){
	
	cout << "Enter Filename: ";
	cin >> filename ;
	ifstream inputFile;                 // Variable para colocar el nombre del archivo
    int i=0;							// Acumular cuantos records se leen del archivo
    int k=0 ;                           
    string a, b ;
    int c, d , e , f;
    inputFile.open(filename.c_str());
    
    while(!inputFile.is_open())         // Verificar si el Archivo abrio
    {
        cout << "Enter Filename: ";
        cin >> filename;
        inputFile.open(filename.c_str());
        
        while (!inputFile.is_open())
        {
            cout << "Error: enter file name again :  ";   // Si no abrio volver a pedir que entre el nombre del archivo
            cin >> filename;
            inputFile.open(filename.c_str());              // Intentar abrir el archivo otra vez
            
        }
    }
    
    
    
    while(inputFile >> a >> b >> c >> d >> e >> f)  // LEER RECORDS DEL ARCHIVO
    { 
        i++;  
    }
    
    inputFile.close();
    inputFile.open(filename.c_str());
    
	total_flows = i;
	max_flows = (i+5);
	
	cout << total_flows << " Records Loaded";
	
	flow_array = new Flow[max_flows];
	
	while(inputFile >> a >> b >> c >> d >> e >> f)
    { 
    	flow_array[k].setSrc_addr (a);
		flow_array[k].setDst_addr (b);
		flow_array[k].setSrc_port (c);
		flow_array[k].setDst_port (d);
		flow_array[k].setOctets   (e);
		flow_array[k].setPackets  (f);

        k++;  
    }    

}




void Netinfo::FindPort 	(){

	int port;
	cout << "Insert Port Number: ";   // PEDIRLE AL USUARIO EL NUMERO DE PORT 
    
    cin >> port;
    
    cout << "Source Address\t Destination Address \t Source Port \t Destination Port \t Port Octects \t Packets" <<endl ; 
    
    for(int i = 0; i < total_flows; i++)   //BUSCAR EN CADA UNO DE LOS RECORDS DONDE APARECE EL PORT ESPECIFICADO POR EL USUARIO
    {             
        if( (port == flow_array[i].getSrc_port()) || (port == flow_array[i].getDst_port()))
        {
            cout << flow_array[i].getSrc_addr() 	<< "    ";
			cout << flow_array[i].getDst_addr ()	<< "    ";
			cout << flow_array[i].getSrc_port ()	<< "    ";
			cout << flow_array[i].getDst_port () 	<< "    ";
			cout << flow_array[i].getOctets   () 	<< "    ";
			cout << flow_array[i].getPackets  () 	<< "    ";
			cout << endl;
        }
    }
}


void Netinfo::SortAddressDest    (){

string temp_str;
int temp;

bool SWP = true;
    
    while (SWP == true)                  // PRIMERO SE ORGANIZAN LOS A~OS
    {
        for(int i=0; i < (total_flows - 1) ; i++)
        {   
            if((flow_array[i].getDst_addr()) > (flow_array[i+1].getDst_addr()))   
            {                                // TODOS LOS CAMPOS
            	temp_str = flow_array[i].getSrc_addr();
				flow_array[i].setSrc_addr(flow_array[i+1].getSrc_addr());    
				flow_array[i+1].setSrc_addr(temp_str); 
            	
            	temp_str = flow_array[i].getDst_addr();
				flow_array[i].setDst_addr (flow_array[i+1].getDst_addr());    
				flow_array[i+1].setDst_addr(temp_str);
				
				temp = flow_array[i].getSrc_port();
				flow_array[i].setSrc_port(flow_array[i+1].getSrc_port());    
				flow_array[i+1].setSrc_port(temp);
				
				temp = flow_array[i].getDst_port();
				flow_array[i].setDst_port(flow_array[i+1].getDst_port());    
				flow_array[i+1].setDst_port(temp);
				
				temp = flow_array[i].getOctets();
				flow_array[i].setOctets(flow_array[i+1].getOctets());    
				flow_array[i+1].setOctets(temp);
				
				temp = flow_array[i].getPackets();
				flow_array[i].setPackets(flow_array[i+1].getPackets());    
				flow_array[i+1].setPackets(temp);
            	
            	SWP = true;                  // SI SE REALIZO UN SWAP SE REPITE EL CICLO
            }
            else
                SWP = false;                 // SI NO SE HACE UN SWAP SIGNIFICA QUE ESTA ORGANIZADO
        }
    }

}
void Netinfo::DisplayNetworkInfo (){

	cout << "Network File:  " << filename << endl;
    cout << "Source Address\t Destination Address \tSource Port \tDestination Port \tPort Octects \tPackets" <<endl ;

	for (int i=0 ; i < total_flows ; i++){
		cout << flow_array[i].getSrc_addr() 	<< "    ";
		cout << flow_array[i].getDst_addr () 	<< "    ";
		cout << flow_array[i].getSrc_port () 	<< "    ";
		cout << flow_array[i].getDst_port () 	<< "    ";
		cout << flow_array[i].getOctets   () 	<< "    ";
		cout << flow_array[i].getPackets  () 	<< "    ";
		cout << endl;
       }

}
void Netinfo::DisplayNetworkSummary  (){
	
    
    for(int i = 0; i < total_flows; i++)  // Suma todos los Octetos y Los Packetes
    {
        total_octets += flow_array[i].getOctets(); 
        total_packets += flow_array[i].getPackets();
    }
    
    // DESPLEGAR LOS RESULTADOS
    cout << "\n\nNetwork File:  " << filename << endl;
    cout << "Octets:\t\t" << total_octets << endl;
    cout << "Packets:\t"<< total_packets << endl;
    
    //PONER LAS FUNCIONES DE LAS GRAFICAS CON LAS CLASES DE LOS CUADRADOS ****************
	BarGraph Net_Graph;
	
	Net_Graph.setTittle(filename);
	Net_Graph.setGData(total_octets, total_packets);
	Net_Graph.DisplayGraph();

}

void Netinfo::addPacket (string a, string b, int c, int d, int e, int f){
		Flow *ptr;
		if ((total_flows+1) > max_flows){
			ptr = new Flow[max_flows + 10];
			
			for (int i=0 ; i < max_flows ; i++ ){
				ptr[i].setSrc_addr (flow_array[i].getSrc_addr ());
				ptr[i].setDst_addr (flow_array[i].getDst_addr ());
				ptr[i].setSrc_port (flow_array[i].getSrc_port ());
				ptr[i].setDst_port (flow_array[i].getDst_port ());
				ptr[i].setOctets   (flow_array[i].getOctets   ());
				ptr[i].setPackets  (flow_array[i].getPackets  ());
			}
			flow_array[total_flows +1].setSrc_addr (a);
			flow_array[total_flows +1].setDst_addr (b);
			flow_array[total_flows +1].setSrc_port (c);
			flow_array[total_flows +1].setDst_port (d);
			flow_array[total_flows +1].setOctets   (e);
			flow_array[total_flows +1].setPackets  (f);
		}
		else 
		{
			flow_array[total_flows +1].setSrc_addr (a);
			flow_array[total_flows +1].setDst_addr (b);
			flow_array[total_flows +1].setSrc_port (c);
			flow_array[total_flows +1].setDst_port (d);
			flow_array[total_flows +1].setOctets   (e);
			flow_array[total_flows +1].setPackets  (f);

		}
	}
		
Netinfo::~Netinfo(){
	delete [] flow_array ;
}