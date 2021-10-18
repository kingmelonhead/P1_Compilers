#include "scanner.hpp"
#include "testScanner.hpp"
#include <iostream>

void print_arg_error();

int main(int argc, char *argv[]){

    std::vector<token> tokens;

    if (argc != 2) print_arg_error();
    else tokens = driver(argv[1]);
    print_vector(tokens);
    //then pass tokens to parser
    return 0;
}

void print_arg_error(){
    std::cout << "Error: There is either too many, or too few arguments.\n invoke program using './P1 filename'\n";
}