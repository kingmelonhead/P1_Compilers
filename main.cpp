#include "scanner.hpp"
#include "testScanner.hpp"
#include <iostream>

void print_arg_error();

int main(int argc, char *argv[]){

    std::string filename = "";

    std::vector<token> tokens;

    if (argc == 1) tokens = driver(filename, KEYBOARD);
    else if (argc == 2) tokens = driver(argv[1], SOURCE_FILE);
    else print_arg_error();
    print_vector(tokens);
    //then pass tokens to parser
    return 0;
}

void print_arg_error(){
    std::cout << "Error: There is either too many, or too few arguments.\n invoke program using './P1 filename'\n";
    exit(0);
}