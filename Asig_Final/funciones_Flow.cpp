#include "Flow.h"


Flow::Flow (){
	src_addr = "0";
    dst_addr = "0";
    src_port = 0 ;
	dst_port = 0 ;
	octets  = 0;
	packets = 0;
}
		
Flow::Flow (string x, string y, int j, int k, int l, int n){
	src_addr = x;
	dst_addr = y;
	src_port = j;
	dst_port = k;
	octets  = l;
	packets = n;

}
		
void Flow::setSrc_addr (string a){
	src_addr = a;
}
		
void Flow::setDst_addr (string b){
	dst_addr = b;
}
		
void Flow::setSrc_port (int a){
	src_port = a;
}
	
void Flow::setDst_port (int b){
	dst_port = b;
}
		
void Flow::setOctets   (int c){
	octets = c; 
}
		
void Flow::setPackets  (int d){
	packets = d;
}
		
string Flow::getSrc_addr  (){
	return src_addr; 
}

string Flow::getDst_addr  (){
	return dst_addr;
}
		
int    Flow::getSrc_port  (){
	return src_port;
}

int    Flow::getDst_port  (){
	return dst_port;
}

int    Flow::getOctets    (){
	return octets;
}
		
int    Flow::getPackets    (){
	return packets;
}