#include "file_templates.h"

std::string MARKDOWN_README = 
" Project Name: \n"
" Motivation: \n"
" Usage: \n";

std::string MISC_MAKEFILE = 
"all : main.o\n"
"\tg++-13 main.o\n"
"main.o : main.o\n"
"\tg++-13 -c main.cpp\n"
"clean : \n"
"\trm *.o \n";

std::string CPP_PROJECT = 
" /*\n"
"\tAuthor: Carlos Tapia\n"
"\tProject: \n"
" */\n"
"#include <iostream> \n\n"
"int main(int argc, char* argv[]){\n"
"\t std::cout << \"hello world\" << std::endl;\n"
"\treturn 0;\n"
"}\n"
"";

std::string TEXT_TEST = 
" TEST ";

