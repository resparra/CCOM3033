/*-- SearchEngine.h ------------------------------------------------------------
  Authors: Roxana Gonzalez Burgos
           Rafael Esparra Rivera
   This header file defines the data for the search engine
     Constructor
     Setters
	setDir    :	Set the directory
   	setFiles  :	Set the files vector
	setIndex  :	Set the index map
      Getters
   	getFiles  :	Returns files vector
	getIndex  :	Returns the index map
      Functions
   	StopWords : 	Store stop words from a .txt in a vector
   	FetchFiles:	Process the data
   	searchKey :	Outputs the three more relevant

------------------------------------------------------------------------------*/
#include "Timer.h"
#include <map>
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

#ifndef SEARCH_ENG
#define SEARCH_ENG

class SearchEngine
{ 

 private:
   /******** Data Members ********/
   
   string 			dir;	// File were are the .txt archives
   vector<string>               files;	// Store the files name from dir
   map<string, map<int, int> >  index;	// Store the results
   vector<string>               words;	// Store the stop words
 public:
   /******** Function Members ********/	
   //Constructor
   SearchEngine(): dir(""), files(), index(), words(){};

   /******** Setters ********/	
   //Setter of the Directory
   void           setDir     (string d) 	              {dir = d; FetchFiles(dir);} 
   // Setter of the files vector
   void           setFiles   (vector<string> f)               {files = f;} 
   // Setter of the index map
   void           setIndex   (map<string, map<int, int> >  i) {index = i;}

   /******** Getters ********/	
   // Returns the Index Map
   map<string, map<int, int> > getIndex() {return index;}
   // Returns the Files vector
   vector<string>              getFiles() {return files;}

   /******** Functions ********/
   // Load the Stop Words got from stop-words.txt
   vector<string> StopWords  (); 
   // Organize the data in a map
   void           FetchFiles (string);
   // Recieves a key, and outputs the three more relevant files 
   void           searchKey  (string);
};

#endif
