#include <string>
#include <fstream>
#include "token.hpp"
#include <iostream>
void driver(std::string);
void print_file_error(std::string);
struct container {
    std::string filter = "";
    int line_no = -1;
    bool end_of_file = false;
};

container refresh_container(std::fstream);