//
//  AsignaFinal.cpp
//  
//
//  Created by Rafael Esparra Rivera on 5/15/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <string>
#include "NetInfo.h"
#include "BarGraph.h"
#include "Flow.h"
using namespace std;

int Menu ();

int main ()
{
    
    int Selection;                   // Selecion del Menu del Usuario
    int Total = 0;                   // Total de records leidos del archivo
    string filename ;
    Netinfo Network;
    
    
    Selection = Menu();                        // Desplegar opciones y Pedirle al usuario que elija una Opcion del Menu
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
            	Network.LoadFile();   				// Cargar Archivo
                break;
            case 2:
                Network.FindPort();        			// Desplegar Records con Port común especificado por el Usuario
		    	break;
            case 3:
				Network.SortAddressDest();     	 	// Organizar los Records por el Address Destination
                break;
            case 4:
                Network.DisplayNetworkInfo();		// Desplegar todos los Records
                break;
            case 5:
            	Network.DisplayNetworkSummary();    // Desplegar Resumen y Grafica
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


int Menu ()
{
    cout << "Network Monitoring Tool" << endl << endl;    //DESPLEGAR TODAS LAS OPCIONES
    cout << "1) Load Network File"             << endl;
    cout << "2) Search Port"                   << endl;
    cout << "3) Sort by Destination Address"   << endl;
    cout << "4) Display Netinfo"               << endl;
    cout << "5) Display Network Summary"       << endl;
    cout << "6) Exit Program"                  << endl; 
    
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

