#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>


#define MAX_ID_LEN 8

void driver(std::string);
void print_file_error(std::string);

struct container {
    std::string filter = "";
    int line_no = -1;
    bool end_of_file = false;
};

container refresh_filter(std::fstream &, int &);

bool all_ws(std::string);

void remove_comments(std::string &);

void early_exit();

int get_col(char);


bool is_keyword(std::string);