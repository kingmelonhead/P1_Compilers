#include "scanner.hpp"
#include "token.hpp"

const int state_no = 23;
const int col_no = 24;
const int ERROR = -1;
const int FINAL = 100;

bool open_comment = false;

enum states {s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13, s14, s15, s16, s17, s18, s19, s20, s21, s22, s23};

int FSA_Table[state_no][col_no] = {
//          a-z     A-Z      0-9     $     =       >      <      :     +       -      *      /      %      .      (      )      ,      {      }      ;      [     ]     WS     EOF
/* s1 */ {   s2,   ERROR,    s3,     s2,    s4,    s6,    s7,    s8,   s10,   s11,   s12,   s13,   s14,   s15,   s16,   s17,   s18,   s19,   s20,   s21,   s22,   s23,    s1, FINAL},
/* s2 */ {   s2,      s2,    s2,  FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL},
/* s3 */ {FINAL,   FINAL,    s3,  FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL},
/* s4 */ {FINAL,   FINAL, FINAL,  FINAL,    s5, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL},
/* s5 */ {FINAL,   FINAL, FINAL,  FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL},
/* s6 */ {FINAL,   FINAL, FINAL,  FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL},
/* s7 */ {FINAL,   FINAL, FINAL,  FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL},
/* s8 */ {FINAL,   FINAL, FINAL,  FINAL,    s9, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL},
/* s9 */ {FINAL,   FINAL, FINAL,  FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL},
/* s10 */{FINAL,   FINAL, FINAL,  FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL},
/* s11 */{FINAL,   FINAL, FINAL,  FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL},
/* s12 */{FINAL,   FINAL, FINAL,  FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL},
/* s13 */{FINAL,   FINAL, FINAL,  FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL},
/* s14 */{FINAL,   FINAL, FINAL,  FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL},
/* s15 */{FINAL,   FINAL, FINAL,  FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL},
/* s16 */{FINAL,   FINAL, FINAL,  FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL},
/* s17 */{FINAL,   FINAL, FINAL,  FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL},
/* s18 */{FINAL,   FINAL, FINAL,  FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL},
/* s19 */{FINAL,   FINAL, FINAL,  FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL},
/* s20 */{FINAL,   FINAL, FINAL,  FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL},
/* s21 */{FINAL,   FINAL, FINAL,  FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL},
/* s22 */{FINAL,   FINAL, FINAL,  FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL},
/* s23 */{FINAL,   FINAL, FINAL,  FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL},
};

void driver(std::string filename){

    int line_no = 1;

    container filter_data;

    //attempt to open file
    std::fstream in_file;
    in_file.open(filename, std::fstream::in);

    //if file cant open, then it doesnt exist
    if(!in_file.is_open()) {
        in_file.close();
        print_file_error(filename);
    }

    //if code makes it here then the file opened properly

    while (!filter_data.end_of_file){
        filter_data = refresh_filter(in_file, line_no);
        if (filter_data.line_no != -1) std::cout << "Filter: " << filter_data.filter << " line no: " << filter_data.line_no << std::endl;
    }
    in_file.close();
}

void print_file_error(std::string filename){
    std::cout << "Error: The provided file " << filename << " does not exist in the current directory.\nExiting Program...\n";
    exit(0);
}

container refresh_filter(std::fstream &infile, int &line_no){

    container temp;

    while (1){
        
        if (std::getline(infile, temp.filter)){     // gets line if not EOF

            temp.line_no = line_no; 
            line_no++; 

            remove_comments(temp.filter);           // attempt to remove comments

            if (!all_ws(temp.filter)) break;        // if filter is not empty after removing comments then filter is good           
        }
        else {                                      // end of file is reached
            temp.end_of_file = true;
            break;
        }
    }
    return temp;
}

bool all_ws(std::string text){
    //function that determines if a string is all white space

    int len = text.length();
    if (len == 0) return true;
    for (int i = 0; i < len ; i++) if (text[i] != ' ') return false;
    return true;
}

void remove_comments(std::string &text){
    // function to remove comments from the filter, will recursively call itself after removing comments
    // this is to ensure full removal of comments even if there are multiple comments embeded on a single line

    int len = text.length();
    int open_com = -10, close_com = -10;

    if (all_ws(text)) return;

    if (!open_comment){                                 // if there is not currently open comments
        for (int i = 0; i <= len - 2; i++){             // iterate through string
            if (text[i] == '&' && text[i+1] == '&'){    // && detected
                if (i != open_com + 1){                 // && detected is new
                    if (open_com > -10){                // if open comment has been detected already
                        close_com = i+1;
                        text.erase(open_com, (close_com - open_com) + 1); 
                        remove_comments(text);
                        return;
                    }
                    else open_com = i;                  // open coment is made
                }
            }
        }  
        //code reaches here if it gets through the whole loop without a completed embeded comment
        if (open_com > -1){                             // comment started this line but not closed
            text.erase(open_com, (len - open_com)); 
            open_comment = true;
            return;
        }
    }
    else {                                               // there is an open comment already
        if (len == 1) {                                  // if there is only one character then its impossible to close the comment on this line
            text = ""; 
            return;
        }
        for (int i = 0; i <= len - 2; i++){
            if (text[i] == '&' && text[i+1] == '&'){
                text.erase(0, i + 2);
                open_comment = false;
                remove_comments(text);
                return;
            }
        }
        //if code gets all the way through that loop without hiting a close symbol and there is an open comment then just delete the ehole thing
        text = "";
    }
}