/*-- client.cpp ----------------------------------------------------------
  Authors: Roxana Gonzalez Burgos
           Rafael Esparra Rivera
------------------------------------------------------------------------------*/
#include "SearchEngine.h"
using namespace std;

int main(){
        system("clear");
	cout << "\n**********  Welcome to the Search Engine  **********\n\n"
	     << "\t\t8 888888888o.    8888\n"
	     << "\t\t8 8888    `88.      88\n"  
	     << "\t\t8 8888     `88    888 \n"    
	     << "\t\t8 8888     ,88   888888  \n"  
	     << "\t\t8 8888.   ,88'       \n"       
	     << "\t\t8 888888888P'     \n"           
	     << "\t\t8 8888`8b       \n"           
	     << "\t\t8 8888 `8b.    \n"         
	     << "\t\t8 8888   `8b.  \n"    
	     << "\t\t8 8888     `88.\n\n";
 	//Create the object
	SearchEngine S;
	// Set the directory to load the files
	S.setDir("./moviesdb");
	cout << "\t\t[Press Enter to Continue]\n\n";	
	cin.ignore();
	string search;
        // Search the key phrase that the user inputs
	while(search != "EXIT"){
		cout << "Enter a Word or phrase\nType 'EXIT' to stop\n"
		     << "Search:  ";
		getline(cin, search);
		if(search == "EXIT") break;
		S.searchKey(search);
		cout << "\t\t[Press Enter to Continue]\n\n";	
		cin.ignore();
		}
	return 0;
}
