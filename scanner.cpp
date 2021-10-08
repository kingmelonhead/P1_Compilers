#include "scanner.hpp"
#include "token.hpp"
#include <iostream>
#include <vector>

const int state_no = 23;
const int col_no = 25;
const int ERROR = -1;
const int FINAL = 100;

bool open_comment = false;

std::fstream in_file;

int FSA_Table[state_no][col_no] = {
//               a-z     A-Z      0-9     $     =       >      <      :     +       -      *      /      %      .      (      )      ,      {      }      ;      [     ]     WS     EOF   OTHER
/* s1  WS */ {   s2,   ERROR,    s3,     s2,    s4,    s6,    s7,    s8,   s10,   s11,   s12,   s13,   s14,   s15,   s16,   s17,   s18,   s19,   s20,   s21,   s22,   s23,    s1, FINAL, ERROR},
/* s2  ID */ {   s2,      s2,    s2,  FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, ERROR},
/* s3 NUM */ {FINAL,   FINAL,    s3,  FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, ERROR},
/* s4   = */ {FINAL,   FINAL, FINAL,  FINAL,    s5, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, ERROR},
/* s5  == */ {FINAL,   FINAL, FINAL,  FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, ERROR},
/* s6   > */ {FINAL,   FINAL, FINAL,  FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, ERROR},
/* s7   < */ {FINAL,   FINAL, FINAL,  FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, ERROR},
/* s8   : */ {FINAL,   FINAL, FINAL,  FINAL,    s9, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, ERROR},
/* s9  := */ {FINAL,   FINAL, FINAL,  FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, ERROR},
/* s10  + */ {FINAL,   FINAL, FINAL,  FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, ERROR},
/* s11  - */ {FINAL,   FINAL, FINAL,  FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, ERROR},
/* s12  * */ {FINAL,   FINAL, FINAL,  FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, ERROR},
/* s13  / */ {FINAL,   FINAL, FINAL,  FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, ERROR},
/* s14  % */ {FINAL,   FINAL, FINAL,  FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, ERROR},
/* s15  . */ {FINAL,   FINAL, FINAL,  FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, ERROR},
/* s16  ( */ {FINAL,   FINAL, FINAL,  FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, ERROR},
/* s17  ) */ {FINAL,   FINAL, FINAL,  FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, ERROR},
/* s18  , */ {FINAL,   FINAL, FINAL,  FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, ERROR},
/* s19  { */ {FINAL,   FINAL, FINAL,  FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, ERROR},
/* s20  } */ {FINAL,   FINAL, FINAL,  FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, ERROR},
/* s21  ; */ {FINAL,   FINAL, FINAL,  FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, ERROR},
/* s22  [ */ {FINAL,   FINAL, FINAL,  FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, ERROR},
/* s23  ] */ {FINAL,   FINAL, FINAL,  FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, ERROR},
};



void driver(std::string filename){

    std::vector<token> tokens;
    std::string temp_string = "";
    token temp_token;
    tokenID kind;
    container filter_data;
    int filter_len, state, look_ahead, current_column, line_no = 1;

    //attempt to open file
    in_file.open(filename, std::fstream::in);

    //if file cant open, then it doesnt exist
    if(!in_file.is_open()) {
        in_file.close();
        print_file_error(filename);
    }

    while (!filter_data.end_of_file){

        filter_data = refresh_filter(in_file, line_no);
        filter_len = filter_data.filter.length();

        if (!filter_data.end_of_file) { 
            //in here, each filter will be broken into individual tokens and stored in a vector
            state = s1;
            kind = tokenID(s1);
            //iterate over the filter
            for (int i = 0; i <= filter_len - 2; i++){
                //all logic for tokenization goes in here
                current_column = get_col(filter_data.filter[i], m);
                look_ahead = FSA_Table[state][current_column];
                kind = tokenID(state);
                if (look_ahead == ERROR){
                    std::cout << "ERROR token cannot start with uppercase letter, exiting program...\n";
                    early_exit();
                }

                if (look_ahead != s1 && current_column != ws) temp_string += filter_data.filter[i];
                
                if (look_ahead == FINAL || temp_string.length() == MAX_ID_LEN){
                    if (is_keyword(temp_string)) kind = Key_Token;
                    temp_token = gen_token(temp_string, line_no, kind);
                    tokens.emplace_back(temp_token);
                    temp_string = "";
                    state = s1;
                }
                else state = look_ahead;
            }
            if (temp_string != ""){
                //if there is characters in the working token then turn it to a token
                kind = tokenID(state);
                if (is_keyword(temp_string)) kind = Key_Token;
                temp_token = gen_token(temp_string, line_no, kind);
                tokens.emplace_back(temp_token);
                temp_string = "";
            }
        }
    }
    //here end of file is reached
    print_vector(tokens);
    in_file.close();
}

token gen_token(std::string text, int line_no, tokenID kind){
    token temp;
    temp.line_no = line_no;
    temp.token_string = text;
    temp.token_type = kind;
    return temp;
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

void early_exit() {
    if (in_file.is_open()) in_file.close();
    exit (0);
}

int get_col(char c, std::map<char, columns> &m){
    auto temp = m.find(c);
    if (temp == m.end()){
        //std::cout << "ERROR: " << c << " is not a valid symbol\nProgram exiting...\n";
        early_exit();
    }
    else {
        //std::cout << "col for " << c << " is " << temp->second << std::endl;
        return temp->second;
    }
    return -1;
}

void print_vector(std::vector<token> &v){
    token temp;
    for (int i = 0; i < v.size(); i++){
        temp = v.at(i);
        std::cout << "('" << temp.token_string << "', line: " << temp.line_no << ", type: " << tokenNames[temp.token_type] << ")\n";
    }
}

bool is_keyword(std::string text){
    for (int i = 0; i < 16; i++){
        if (text == keywords[i]) return true;
    }
    return false;
}