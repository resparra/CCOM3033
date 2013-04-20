//************************************************************************
//                                                                  
//   Estudiante: Rafael Esparra Rivera   Programacion CCOM 3033        
//   Num.Stu: 801 - 08- 1826             Segundo Semestre 2011-2012     
//   Asignación 6                        Dr. José Ortíz-Ubarri        
//   Archivo: Asigna6.cpp                Fecha: 10 de Abril de 2012
//                                                                   
//************************************************************************
//                                                      
//                Propósito : Patient Medical Diagnoses Log Sorter.
//                      Organizar por fecha los diagnosticos del paciente
//                                                                    
//************************************************************************

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int SIZE = 25;    // Constante para el tamano de los Arrays 

// Definicion de las Funciones

bool Load_File(string, ifstream &);                                 // Abrir el Archivo de Records
int Display(string[], int[], int[], int[], int[], ifstream &) ;     // Guardar en Memoria el Record del Paciente
void Sorting (int[], int[], int[], int[], string[], int);           // Organiza los records por fecha de mayor a menor
void swap (int &, int &);                                           // Swap de valores enteros
void str_swap(string &, string &);                                  // Swap de variables tipo string
bool Write (int[], int[], int[], int[], string[], int, string, string, string); // Escribir el record organizado a nuevo archivo


int main ()
{
    string name;            // Variable que guarda el Nombre del Paciente
    string last;            // Variable que guarda el Apellido del Paciente
    string record_num;      // Variable que guarda el Numero del Record del Paciente
    
    
    ifstream file;          // Archivo de donde se va a leer los Records
    bool File_Open;         // Verifica si el archivo abrio o no
    bool File_Save;         // Verifica si el archivo de escribio o no
    
    string Condition[SIZE]; // Array para la Condicion o Diagnostico
    int  Doc[SIZE];         // Array que guarda el ID del Doctor que atendio el Paciente 
    int  Year[SIZE];        // Array para el Ano  -|
    int  Month[SIZE];       // Array para el Mes   |- FECHA DEL RECORD
    int  Day[SIZE];         // Array para el dia  -|
    int  Rec_lines;         // Variable que guarda la Cantidad de records que se leyeron del Archivo
    char Repeat;            // Variable para repetir el programam
    
     
    
    do                      // Se ejecuta cuantas veces el usuario quiera
    {
        system("clear");
        cout << "\t * Welcome to the Patient Medical Diagnoses Log Sorter * " << endl << endl;
        cout << "Insert the Patient Name : ";
        cin >> name ;                           // INSERTAR EL NOMBRE DEL PACIENTE
        cout << "Insert the Patient Last : ";
        cin >> last ;                           // INSERTAR EL APELLIDO DEL PACIENTE
        cout << "Insert the Patient Record Number : ";
        cin >> record_num;                      // INSERTAR EL NUMERO DE RECORD DEL PACIENTE
        
        File_Open = Load_File(record_num, file);    //FUNCION QUE HABRE EL ARCHIVO DE DONDE SE VA A LEER EL RECORD
                while(File_Open == false)           //VERIFICA SI EL ARCHIVO ABRIO O NO
                    {
                        cout << "Insert the Patient Record Number : ";
                        cin >> record_num;          // PIDE QUE VUELVA A INGRASAR EL EL NUMERO DE RECORD
                        File_Open = Load_File(record_num, file);
                    }
    
        Rec_lines = Display(Condition, Doc, Year, Month, Day, file); // FUNCION QUE GUARDA EN MEMORIA Y CUENTA LOS RECORDS
        
        Sorting (Year, Month, Day, Doc, Condition, Rec_lines);       // ORGANIZA LOS RECORDS POR FECHA
        
        File_Save = Write (Year, Month, Day, Doc, Condition, Rec_lines, record_num, name, last); // GUARDAR EN NUEVO ARCHIVO
            if (File_Save == false)                             //Verificar si el Archivo abrio o no
                cout << "Error: Failed to write sorted file";
            else
                cout << endl << "Saved Succesfully" << endl;

        cout << endl;
                
        file.close();               // CERRAR EL ARCHIVO DE ENTRADA 
        cout << "Continue ? (Y/N) : ";   // PREGUNTAR AL USUARIO SI QUIERE CONTINUAR
        cin >> Repeat;
    
    }
    while (Repeat == 'Y' || Repeat == 'y');
    
    return 0;
}

bool Load_File(string filename, ifstream &inputfile)      // FUNCION QUE HABRE EL ARCHIVO DE ENTRADA
{
    
    string infile = filename + ".dat";    // le suma la extencion al numero de record
    cout << endl << "Looking for the patient record : " << infile << endl << endl ;
    inputfile.open(infile.c_str());        // Abrir archivo de entrada
    
    if (inputfile.fail())                  // Verificar si abrio 
            {
                cout << "ERROR: Record Does Not Exist" << endl;
                return false;              // Si no abrio decirle a Main que no
            }
                
    else
            return true;                   // Si abrio decirle a Main que si
    
    
}

int Display (string Con[], int Doct[], int year[], int mon[], int dia[], ifstream &inputfile)  // FUNCION GUARDA Y CUENTA
{
    int i =0;
        while(inputfile >> Con[i] >> Doct[i] >> dia[i] >> mon[i] >> year[i]){     // MIENTRAS SE LEA DEL ARCHIVO SUMA 1
            i++;
            if (i > SIZE)  // Si el archivo tiene mas campos que los arrays pare
                break;
            }
    return i;               // DEVUELVE LA CANTIDAD DE ARCHIVOS QUE SE LEYERON
}



void Sorting (int year[], int month[], int day[], int D[], string C[],  int size) // FUNCION QUE ORGANIZA POR FECHA
{
    bool SWP = true;
    
    while (SWP == true)                  // PRIMERO SE ORGANIZAN LOS A~OS
    {
        for(int i=0; i <(size-1); i++)
        {
            if(year[i] > year[i+1])           // VERIFICA SI EL A~O DE SU LADO ES MAYOS SI LO ES SE CAMBIAN
            {                                // TODOS LOS CAMPOS
                swap(year[i],year[i+1]);
                swap(month[i],month[i+1]);
                swap(day[i],day[i+1]);
                swap(D[i], D[i+1]);
                str_swap(C[i],C[i+1]);                
                SWP = true;                  // SI SE REALIZO UN SWAP SE REPITE EL CICLO
            }
            else
                SWP = false;                 // SI NO SE HACE UN SWAP SIGNIFICA QUE ESTA ORGANIZADO
        }
    }
    
    while (SWP == false)                      // SI EL A~O ES EL MISMO ENTONCES MIRAMOS EL MES
    {
        for (int j = 0; j< (size-1); j++) 
        {
            if(year[j] == year[j+1])
            {
                if (month[j] > month[j+1])    // SI EL MES ES MAS GRANDE QUE EL PROXIMO SE CAMBIAN
                {
                    swap(month[j],month[j+1]);
                    swap(day[j],day[j+1]);
                    swap(D[j], D[j+1]);
                    str_swap(C[j],C[j+1]);
                    SWP = false;              // SE REPITE MINTRAS SE HAGA UN SWAP
                }
                else
                    SWP = true;               // TERMINA EL CICLO CUANDO NO SE REALIZE NINGUN SWAP
            }
        }
    }
    
    while (SWP == true) 
    {
        cout << "entre " << endl;
        for (int k = 0; k< (size-1); k++) 
        {
            if(year[k] == year[k+1] && month[k] == month[k+1] && day[k] > day[k+1])
            {
                    swap(day[k],day[k+1]);
                    swap(D[k], D[k+1]);
                    str_swap(C[k],C[k+1]);
                    SWP = true;              // SE REPITE MINTRAS SE HAGA UN SWAP
            }
            else
                    SWP = false;               // TERMINA EL CICLO CUANDO NO SE REALIZE NINGUN SWAP
        }
    }
    
    cout << "Condition \tDoctor \t Year \t Month \t Day " << endl;    // DESPLEGAR LOS RECORDS YA ORGANIZADOS POR FECHAS
    for(int i=0; i < size; i++){
        cout << C[i] << "\t\t" << D[i] <<"\t " << year[i] <<"\t " << month[i] << "\t " << day[i] << endl;
    }

}

void swap (int &a, int &b)   // Swap para enteros
{
    int temp;       // Variable que guarda temporalmente el valos de a
    temp= a;
    a=b;            // se cambia a por b
    b=temp;         // se cambia b (guardada en temp) por a
}

void str_swap (string &a, string &b)  // Swap para Strings
{
    string temp;    // Variable que guarda temporalmente el valos de a
    temp = a;
    a=b;            // se cambia a por b
    b= temp;        // se cambia b (guardada en temp) por a
}

bool Write (int y[], int m[], int d[], int D[], string C[],  int s, string name, string n, string l) // FUNCION QUE GUARDA LOS RECORS ORDENADOS EN UN NUEVO ARCHIVO
{
    string sortfile = name + ".sorted";  // Se suma la extencion el numero de record
    ofstream outfile;                    // Variabe para el archivo de salida
    
    
    outfile.open(sortfile.c_str());      // SE ABRE EL ARCHIVO DE SALIDA
    
    if (outfile.fail())         // VERIFICAR SI ABRIO            
            return false;       // Decirle a main que no abrio
    
    outfile << "Name : " << n << endl;                                  //Escribir Nombre y apellido 
    outfile << "Last Name : " << l << endl << endl ;
    outfile << "Condition \tDoctor \t Year \t Month \t Day " << endl;
        for(int i=0; i < s; i++)
            {
            outfile << C[i] << "\t\t" << D[i] <<"\t " << y[i] <<"\t " << m[i] << "\t " << d[i] << endl;
            }                                                       // ESCRIBIR CADA CAMPO DEL RECORD EN EL ARCHIVO NUEVO 
    
        outfile.close();    // CERRAR EL ARCHIVO DE SALIDA
    return true;  // Decirle a main que se creo  y se guardo el archivo
}

