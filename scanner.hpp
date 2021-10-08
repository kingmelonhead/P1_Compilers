#include <string>
#include <fstream>

#define MAX_ID_LEN 8

struct container {
    std::string filter = "";
    int line_no = -1;
    bool end_of_file = false;
};

container refresh_filter(std::fstream &, int &);
void driver(std::string);
void print_file_error(std::string);
bool all_ws(std::string);
bool is_keyword(std::string);
void remove_comments(std::string &);
void early_exit();