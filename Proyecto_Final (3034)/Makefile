# Makefile - R Arce
all: client

client: client.o ParsedFile.o SearchEngine.o
	c++ client.o ParsedFile.o SearchEngine.o -o client

client.o: client.cpp  SearchEngine.h
	c++ -c client.cpp

ParsedFile.o: ParsedFile.cpp ParsedFile.h 
	c++ -c ParsedFile.cpp

SearchEngine.o: SearchEngine.cpp SearchEngine.h
	c++ -c SearchEngine.cpp

clean: 
	rm -rf *.o

pack:
	tar cvzf engine.tgz client.cpp ParsedFile.h ParsedFile.cpp Makefile
