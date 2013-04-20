//*********************************************************************
//                                                                  
//   Estudiante: Rafael Esparra Rivera   Programacion CCOM 3033        
//   Num.Stu: 801 - 08- 1826             Segundo Semestre 2011-2012     
//   Asignación 7                        Dr. José Ortíz-Ubarri        
//   Archivo: asigna05.cpp               Fecha: 25 de marzo de 2012
//                                                                   
//*********************************************************************
//                                                      
//                Propósito : NETWORK MONITORING TOOL (Struct Pointer)   
//                                                                    
//*********************************************************************

#include <iostream>
#include <string>
#include <fstream>

using namespace std;


struct Network {
    string S_Address  ;      
    string D_Address  ;      
    int    S_Port     ;      
    int    D_Port     ;         
    int    Port_Octect;      
    int    Packet     ;
};


int         Menu       (void);                        // Funcion para despelgar y escojer opcion del Menu
int         Count      (string &);                    // Cargar el Archivo
void        Load       (string &, Network*);
void        Display    (Network*, int, string);      // Desplegar todos los records del Archivo
void        Summary    (Network*, int, string);      // Guardar un Resumen del Archivo
void        FilterIP   (Network*, int, string);      // Buscar record de un IP especifico
void        FilterPort (Network*, int, string);      // Buscar record de un Puerto especifico


int main ()
{
    
    int Selection;                   // Selecion del Menu del Usuario
    int Total = 0;                   // Total de records leidos del archivo
    string filename;                 // Nombre del archivo que se le pide al usuario
    Network *net = NULL;
    
    
    Selection = Menu ();                        // Desplegar opciones y Pedirle al usuario que elija una Opcion del Menu
    while (Selection != 1 && Selection != 6)    // Verificar que se escoja primero la opcion 1. para cargar el archivo
    {
        system("clear");
        cout << "Error: * MUST LOAD NETWORK FILE FIRST *" << endl << endl;
        Selection = Menu();
    }
    
    while (Selection !=6)   // Deacuerdo a la selecion del Usuario se llama la funcion Correspondiente
    {
        switch(Selection) 
        {
            case 1:
                Total = Count (filename);     // Contar Archivo
                net = new Network[Total];
                Load (filename, net);         //Cargar Archivo
                break;
            case 2:
                Display(net, Total, filename);        // Desplegar todos los Records
		    	break;
            case 3:
				Summary (net, Total, filename);       // Desplegar y guardar un resumen
                break;
            case 4:
                FilterIP (net, Total, filename);      // Buscar record de IP Especifico
                break;
            case 5:
                FilterPort (net, Total, filename);    // Buscar record de PORT Especifico
                break;
        }
    
    // PAUSAR EL PROGRAMA PARA QUE EL USUARIO PUEDA VER LOS RESULTADOS
        cout << endl << "Press Any Key To Continue ..." << endl;    
        
        cin.get() ;
        cin.ignore();
        cout << endl; 
        
        system("clear");     	
        Selection = Menu(); 
    }
    
    return 0;
}



int Menu (void)
{
    cout << "Network Monitoring Tool" << endl << endl;    //DESPLEGAR TODAS LAS OPCIONES
    cout << "1) Load Network File"      << endl;
    cout << "2) Display Network File"   << endl;
    cout << "3) Network Summary"        << endl;
    cout << "4) Filter by IP Address"   << endl;
    cout << "5) Filter by Network Port" << endl;
    cout << "6) Exit Program"           << endl; 
    
    int Opcion;
    cout << endl << "Enter a Opcion from Menu => " ;      // Pedir al usuario que escoja una opcion
    cin >> Opcion;
    while (Opcion < 1 || Opcion > 6)                      // VERIFICAR QUE EL USUARIO ENTRE UNA OPCION VALIDA
    {
        cout << "Invalid, Enter a valid Opcion: ";
        cin >> Opcion;
    }
    return Opcion;    // DEVOLVER LA SELECION
}


int Count (string &filename )  // ABRIR EL ARCHIVO
{
    ifstream inputFile;                 // Variable para colocar el nombre del archivo
    int i=0;                            // Acumular cuantos records se leen del archivo
    string a, b ;
    int c, d , e , f;
    
    while(!inputFile.is_open())         // Verificar si el Archivo abrio
    {
        cout << "Enter filename: ";
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
    
    
    inputFile.close();                  // CERRAR EL ARCHIVO
    return i;                           // DEVOLVER CUANTOS RECORDS SE LEYERON
    
}


void Load (string &filename, Network* S){
    ifstream inFile;
    inFile.open(filename.c_str()); 
    int k = 0;
    
    while(inFile >> S[k].S_Address >> S[k].D_Address >> S[k].S_Port >> S[k].D_Port >> S[k].Port_Octect >> S[k].Packet)
    { 
        k++;  
    }    
    
}


void Display (Network* N , int Length, string filename) // DESPLEGAR TODOS LOS RECORDS
{
    cout << "Network File:  " << filename << endl;
    cout << "Source Address\t Destination Address \tSource Port \tDestination Port \tPort Octects \tPackets" <<endl ;
	
    
    for(int i = 0; i < Length; i++)   // DESPLEGAR CADA UNO DE LOS RECORDS HASTA EL ULTIMO QUE ESTA EN LA POSICION (lenght-1)
    {
        cout << N[i].S_Address << "   "<< N[i].D_Address << "    " << N[i].S_Port << "    " << N[i].D_Port << "    " << N[i].Port_Octect << "    " << N[i].Packet << endl;
    }
    
	
}

void Summary (Network* Net, int Length, string filename)   // DESPLEGAR Y GUARDAR UN RESUMEN EN OTRO ARCHIVO

{
    float oc_total = 0;   // Acumulador de Octetos
    float pa_total = 0;   // Acumulador de Packetes
    
    for(int i = 0; i < Length; i++)  // Suma todos los Octetos y Los Packetes
    {
        oc_total += Net[i].Port_Octect; 
        pa_total += Net[i].Packet;
    }
    
    // DESPLEGAR LOS RESULTADOS
    cout << "\n\nNetwork File:  " << filename << endl;
    cout << "Summary of the network file data: " << filename << endl;
    cout << "Octets:\t\t" << oc_total << endl;
    cout << "Packets:\t"<< pa_total << endl;
    cout << "Octets Avg:\t" << oc_total/Length << endl;
    cout << "Packets Avg:\t" << pa_total/Length << endl;
    
    
    string Name;                                    // Nombre del archivo Original 
    int largo = filename.size();                    // Largo del Nombre original
    
    for (int i=0 ; i < (largo-4)  ; i++)            // Solo tomar el nombre sin la extencion
        Name += filename[i];
    string summaryFile = Name + ".summary.net" ;    // Sumarle .summary.net al nombre orriginal para tener el nombre el archivo de salida
    
    ofstream outFile;
    
    outFile.open(summaryFile.c_str());              // ABRIR ARCHIVO DE SALIDA
    
    // ESCRIBIR EN EL ARCHIVO DE SALIDA
    outFile << "Network File:  " << filename                     << endl;
    outFile << "Summary of the network file data: " << filename  << endl; 
    outFile << "Octets:\t\t" << oc_total                         << endl;
    outFile << "Packets:\t"<< pa_total                           << endl;
    outFile << "Octets Avg:\t" << oc_total/Length                << endl;
    outFile << "Packets Avg:\t" << pa_total/Length               << endl;
    
    outFile.close();  // CERRAR ARCHIVO DE SALIDA
    
    cout << endl << "Summary Saved in file: " << summaryFile << endl;  // Informarle al Usuario que se guardo todo
    
    return;
    
}

void FilterIP (Network* K, int Length, string filename) // BUSQUEDA POR IP

{ 
    string IP;
    cout << "Insert IP Address: ";    // PEDIRLE AL USUARIO EL NUMERO DE IP
    
    cin >> IP;
    
    cout << "Source Address\t Destination Address \t\tSource Port \t\tDestination Port \t\tPort Octects \t\tPackets" <<endl ;
    
    for(int i = 0; i < Length; i++)  //BUSCAR EN CADA UNO DE LOS RECORDS DONDE APARECE EL IP ESPECIFICADO POR EL USUARIO
    {             
        if( (IP == K[i].S_Address) || (IP == K[i].D_Address) )
        {
            cout << K[i].S_Address << "   "<< K[i].D_Address << "      " << K[i].S_Port << "      " << K[i].D_Port << "      " << K[i].Port_Octect << "     " << K[i].Packet << endl; //DESPLEGAR
        }
    }
    return;
}



void FilterPort (Network* Red, int Length, string filename) // BUSQUEDA POR PORT
{
    int Port;
    cout << "Insert Port Number: ";   // PEDIRLE AL USUARIO EL NUMERO DE PORT 
    
    cin >> Port;
    
    cout << "Source Address\t Destination Address \t\tSource Port \t\tDestination Port \t\tPort Octects \t\tPackets" <<endl ; 
    
    for(int i = 0; i < Length; i++)   //BUSCAR EN CADA UNO DE LOS RECORDS DONDE APARECE EL PORT ESPECIFICADO POR EL USUARIO
    {             
        if( (Port == Red[i].S_Port) || (Port == Red[i].D_Port))
        {
            cout << Red[i].S_Address << "   "<< Red[i].D_Address << "     " << Red[i].S_Port << "    " << Red[i].D_Port << "    " << Red[i].Port_Octect << "    " << Red[i].Packet << endl;
        }
    }
    
    return;
}
