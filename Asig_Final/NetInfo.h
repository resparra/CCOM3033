#include <iostream>
#include "Flow.h"

using namespace std ;

#ifndef __NETINFO_
#define __NETINFO_
class Netinfo {
	private :
		Flow*  flow_array;
		int    total_octets;
		int    total_packets;
		int    total_flows;
		int    max_flows;
		string filename;
		void  addPacket (string, string, int, int, int, int);
	
	public :
		Netinfo ();
		Netinfo (Flow*, int);
		
		void setFlow_array	  (Flow*);
		void setTotal_octets  ();
		void setTotal_packets ();
		void setTotal_flows   ();
		void setMax_flows     (int);
		void setFilename      (string);
		
		Flow*  getFlow_array   ();
		int    getTotal_octets ();
		int    getTotal_packets();
		int    getTotal_flows  ();
		int    getMax_flows    ();
		string getFilename     ();
		
	    void LoadFile 		 		();
		void FindPort 		 		();
		void SortAddressDest    	();
		void DisplayNetworkInfo 	();
		void DisplayNetworkSummary  ();
		
		~ Netinfo();
};

#endif