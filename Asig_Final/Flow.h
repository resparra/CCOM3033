#include <iostream>
#include <string>

using namespace std ;

#ifndef __FLOW_
#define __FLOW_
class Flow {
	private :
		string src_addr;        // Guardar Source Address
		string dst_addr;		// Guardar Destination Address
		int    src_port;		// Guardar Source Port
		int    dst_port;		// Guardar Destination Port
		int    octets;			// Guardar la cantidad de Octets
		int    packets;			// Guardar la cantidad de Packets
	
	public :
		Flow ();									// Default Constructor, todos los valores a 0
		Flow (string, string, int, int, int, int);  // Construtor donde se especifica cada uno de los Valores
		
		// Seters
		void setSrc_addr (string);   
		void setDst_addr (string);
		void setSrc_port (int);
		void setDst_port (int);
		void setOctets   (int);
		void setPackets  (int);
		
		// Geters
		string getSrc_addr   ();
		string getDst_addr   ();
		int    getSrc_port   ();
		int    getDst_port   ();
		int    getOctets     ();
		int    getPackets    ();
		
};
#endif