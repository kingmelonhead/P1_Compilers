#include "scanner.hpp"
int main(int argc, char *argv[]){

    if (argc != 2) print_arg_error();
    else driver(argv[1]);

    return 0;
}

void print_arg_error(){
    std::cout << "Error: There is either too many, or too few arguments.\n invoke program using './P1 filename'\n";
}