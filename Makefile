
all : create.o file_templates.o 
	g++-13 -o create create.o file_templates.o

create.o : create.cpp
	g++-13 -c create.cpp 

file_templates.o : file_templates.cpp
	g++-13 -c file_templates.cpp

clean :
	rm *.o

