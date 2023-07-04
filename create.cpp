#include <_ctype.h>
#include <iostream>
#include <fstream>
#include <string>

#include "file_templates.h"

// Filesystem is c++17
#include <filesystem>
namespace fs  = std::filesystem;


std::string create_file(std::string filename, std::string template_string);


int main (int argc, char *argv[]) {
  // getting the name of the project
  if (argc < 2){
    std::cout << "Usage: create [ProjectName] \n";
    exit(1);
  }
  std::string projectName = argv[1];

  if (!isupper(projectName[0])){
    projectName[0] = toupper(projectName[0]);
  }

  char ans;
  std::cout << "Do you want to create " << projectName << " project ? [y/n]" << std::endl;
  std::cin >> ans;
  if (ans == 'n') {
    std::cout << "Aborted" << std::endl;
    exit(1);
  }

  // make the directory; 
  fs::create_directory(projectName);

  auto path = fs::current_path() += ("/" + projectName);
  fs::current_path(path);

  create_file("MakeFile", MISC_MAKEFILE);
  create_file("testFile.txt", TEXT_TEST);
  create_file("main.cpp", CPP_PROJECT);
  create_file("README.md", MARKDOWN_README);
  
  return 0;
}

std::string create_file(std::string filename, std::string template_string){
  std::fstream file {filename, file.out};

  if (!file.is_open()) return 0;

  std::cout << "creating " << filename << std::endl;
  file << template_string;

  file.close();
  return filename;
}

