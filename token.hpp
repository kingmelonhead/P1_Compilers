#include <string>

enum tokenID {ID_Token, Num_Token, Ass_Token, Comp_Token, Greater_Token, Less_Token, Col_Token, Def_Token, Plu_Token, Min_Token, Mult_Token, Div_Token, 
                Perc_Token, Dot_Token, OParen_Token, CParen_Token, Com_Token, OCur_Token, CCur_Token, Semi_Token, OSqBra_Token, CSqBr_Token, Key_Token};

std::string tokenNames[] = {"Identifier", "Number", "Assignment Op (=)", "Comparison Op (==)", "Greater Than", "Less Than", "Colon", "Define Op (:=)", "Add", "Subtract", "Multiply", 
                            "Divide", "Percent", "Period", "Opening Parenthesis", "Closing Parenthesis", "Comma", "Opening Curley Brace", "Closing Curly Brace", "Semi-colon",
                            "Opening Square Brace", "Closing Square Brace", "Keyword"};

//if something is determined to be an identifier token, it will be checked to see if it matches any of the reserved keywords
//if the ID_Token does end up being a keyword then it gets marked as a Key_Token before being returned
std::string keywords[] = {"start", "stop", "loop", "while", "for", "label", "exit", "listen", "talk", "program", "if", "then", "assign", "declare", "jump", "else"};   
            
struct token { 
    tokenID token_type;
    std::string token_string; 
    int line_no;
    };