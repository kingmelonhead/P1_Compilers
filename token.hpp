#include <string>
#include <vector>
#include <map>

enum tokenID {WHITESPACE, ID_Token, Num_Token, Ass_Token, Comp_Token, Greater_Token, Less_Token, Col_Token, Def_Token, Plu_Token, Min_Token, Mult_Token, Div_Token, 
                Perc_Token, Dot_Token, LParen_Token, RParen_Token, Com_Token, LCur_Token, RCur_Token, Semi_Token, LSqBra_Token, RSqBr_Token, Key_Token};

struct token { 
    tokenID token_type;
    std::string token_string; 
    int line_no;
    };

token gen_token(std::string, int, tokenID);

enum columns {low, up, num, dol, eq, gt, lt, col, plu, sub, mul, divi, perc, dot, lper, rper, com, lcur, rcur, sem, lsq, rsq, ws, end, junk};

std::string keywords[16] = {"start", "stop", "loop", "while", "for", "label", "exit", "listen", "talk", "program", "if", "then", "assign", "declare", "jump", "else"};   

std::string tokenNames[] = {"whitespace", "Identifier", "Number", "Assignment Op (=)", "Comparison Op (==)", "Greater Than", "Less Than", "Colon", "Define Op (:=)", "Add", "Subtract", "Multiply", 
                            "Divide", "Percent", "Period", "Opening Parenthesis", "Closing Parenthesis", "Comma", "Opening Curley Brace", "Closing Curly Brace", "Semi-colon",
                            "Opening Square Brace", "Closing Square Brace", "Keyword"};
                    
std::map <char, columns> m = {
    {'a',low}, {'b',low}, {'c',low}, {'d',low}, {'e',low}, {'f',low}, {'g',low}, {'h',low}, {'i',low}, {'j',low}, {'k',low}, {'l',low}, {'m',low},
    {'n',low}, {'o',low}, {'p',low}, {'q',low}, {'r',low}, {'s',low}, {'t',low}, {'u',low}, {'v',low}, {'w',low}, {'x',low}, {'y',low}, {'z',low},
    {'A', up}, {'B', up}, {'C', up}, {'D', up}, {'E', up}, {'F', up}, {'G', up}, {'H', up}, {'I', up}, {'J', up}, {'K', up}, {'L', up}, {'M', up}, 
    {'N', up}, {'O', up}, {'P', up}, {'Q', up}, {'R', up}, {'S', up}, {'T', up}, {'U', up}, {'V', up}, {'W', up}, {'X', up}, {'Y', up}, {'Z', up}, 
    {'0', num}, {'1', num}, {'2', num}, {'3', num}, {'4', num}, {'5', num}, {'6', num}, {'7', num}, {'8', num}, {'9', num}, 
    {'$', dol}, {'=', eq}, {'<', lt}, {'>', gt}, {':', col}, {'+', plu}, {'-', sub}, {'*', mul}, {'/', divi}, {'%', perc}, {'.', dot}, {'(', lper}, 
    {')', rper}, {',', com}, {'{', lcur}, {'}', rcur}, {';', sem}, {'[', lsq}, {']', rsq}, {' ', ws}
};

enum states {s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13, s14, s15, s16, s17, s18, s19, s20, s21, s22, s23};

void print_vector(std::vector<token> &);
int get_col(char, std::map<char, columns> &);            
