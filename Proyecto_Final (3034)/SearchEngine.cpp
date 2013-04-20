/*-- SearchEngine.cpp ----------------------------------------------------------
  Authors: Roxana Gonzalez Burgos
           Rafael Esparra Rivera
------------------------------------------------------------------------------*/
#include "SearchEngine.h"
#include "ParsedFile.h"

using namespace std;

vector<string> SearchEngine::StopWords(){
/*------------------------------------------------------------------------
   Store the stop words in a vector

   Precondition:  The vector words is empty
   Postcondition: Stop words are returnes into words vector.
 ------------------------------------------------------------------------*/
    ifstream       inFile;
    string         tmp;
    vector<string> words;
    inFile.open("stopwords.txt");	// Open the stop words file
    while (inFile >> tmp){
       words.push_back(tmp);		// Load into the words vector all the 
    }					// stop words
    inFile.close();			// Close the file
    return words;
}
void SearchEngine::FetchFiles (string dir){
/*------------------------------------------------------------------------
   The data gained from the directory is being processed.

   Precondition: Recieves the directory that contains the .txt archives.
                 
   Postcondition:From each archive it's created a vector, which contains all the
                 words contained in that archive. Then a map is created, 
                 excluding the stop words and removing the punctuation marks.
 ------------------------------------------------------------------------*/
    vector<string> files  = vector<string>();
    vector<string> words = StopWords();
    map<string, map<int, int> > index;	
    Timer timer;			
    cout << "Fetching files ..." << endl;
    
    timer.start();			// Starts the timer
    getdir(dir,files);			// Get all the files from the directory
    timer.stop();			// Stops the timer
    setFiles(files);
    cout << "Reading Files ...";
    timer.start();			// Starts the timer
    for (unsigned int i = 0; i < files.size();i++){
        if(i == files.size()/2) cout << "50%...";
        if (files[i].c_str()[0]!='.') {
       	    vector<string> t;
            string tmp = dir+"/" + files[i];
            ParsedFile P(tmp);
            t = P.readAndTokenize();	// The content of each files is loaded 
					// into a vector
            for (int j= 0; j < t.size(); j++){
		string tmp(t[j]);
		string::iterator st;
		st=tmp.end()-1;
		// Remove the punctuation marks
  		if(!isalpha(*st)) tmp = tmp.substr(0, tmp.size()-1); 
		vector<string>::iterator it;
		// Remove the stop words
		for (it = words.begin() ; it!= words.end(); ++it) 
  			if(tmp == *it) tmp = " ";
		// Load content to the index map
		if(tmp!=" ")index[tmp][i] = index[tmp][i] + 1;
		}    
        }
    }
    timer.stop(); 			//Stops the timer
    cout << "100%" << endl <<"Done in : " << timer.getSeconds() << endl;
    cout << endl << "Press enter to Search in Movie Data Base ...";
    setIndex(index);
}

struct inv_index {
// Structure to store the data gained from the key phrase
    int filenum; // Stores the file number
    int count;	 // Stores the times it's being founded a word
     };
bool sortResults (inv_index i, inv_index j) { return (i.count>j.count); }

void SearchEngine::searchKey (string key){
/*------------------------------------------------------------------------
   Outputs the three most relevant files, given a key phrase for the search.

   Precondition: Recieves the key phrase for the search.
   Postcondition: Outputs the most relevant files.
 ------------------------------------------------------------------------*/
    vector<string> search;
    vector<string> Nsearch;
    vector<inv_index> results;
    map<string, map<int, int> > index = getIndex();
    vector<string> files = getFiles();
    search = tokenize(key, " ");
    // Make shure that the key words exists in the map, and if they are,  
    // they are store into a new vector
    for(int i=0; i<search.size(); i++){
        if (index.find(search[i]) == index.end()) 
		cout << "Error: Word '"<< search[i]<<"' Not Found" << endl;
	else Nsearch.push_back(search[i]);
    }
    // If there is data in the new vector then do the search
    if(!Nsearch.empty()){
        // For each file, look for the words gained
	for (int a = 0; a < files.size(); a++){
		inv_index temp;
        	temp.count = 0;
	   	for(int i=0; i<Nsearch.size(); i++){
			// If the words are founded in the map, then add them 
			// to the counter
            		if(index[Nsearch[i]].find(a) == index[Nsearch[i]].end()){}
            		else {temp.filenum = a;
			      temp.count += index[Nsearch[i]][a];
            	}
	}
	// Store the results in a vector
	results.push_back(temp);
     }
 	// Sort all the data gained
        sort (results.begin(), results.end(), sortResults);
	// Output the results
        for (int m=0; m < 3; m++){
       	        cout << m+1 << ": " 
	    	<< files[results[m].filenum] 
	     	<< " " << results[m].count 
	     	<< endl;
    	}
    }  
    
}
    

