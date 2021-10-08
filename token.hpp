#include <string>


//int FSA_Table[state_no][col_no] = {
//               a-z     A-Z      0-9     $     =       >      <      :     +       -      *      /      %      .      (      )      ,      {      }      ;      [     ]     WS     EOF   OTHER
///* s1  WS */ {   s2,   ERROR,    s3,     s2,    s4,    s6,    s7,    s8,   s10,   s11,   s12,   s13,   s14,   s15,   s16,   s17,   s18,   s19,   s20,   s21,   s22,   s23,    s1, FINAL, ERROR},
///* s2  ID */ {   s2,      s2,    s2,  FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, ERROR},
///* s3 NUM */ {FINAL,   FINAL,    s3,  FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, ERROR},
///* s4   = */ {FINAL,   FINAL, FINAL,  FINAL,    s5, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, ERROR},
///* s5  == */ {FINAL,   FINAL, FINAL,  FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, ERROR},
///* s6   > */ {FINAL,   FINAL, FINAL,  FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, ERROR},
///* s7   < */ {FINAL,   FINAL, FINAL,  FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, ERROR},
///* s8   : */ {FINAL,   FINAL, FINAL,  FINAL,    s9, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, ERROR},
///* s9  := */ {FINAL,   FINAL, FINAL,  FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, ERROR},
///* s10  + */ {FINAL,   FINAL, FINAL,  FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, ERROR},
///* s11  - */ {FINAL,   FINAL, FINAL,  FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, ERROR},
///* s12  * */ {FINAL,   FINAL, FINAL,  FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, ERROR},
///* s13  / */ {FINAL,   FINAL, FINAL,  FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, ERROR},
///* s14  % */ {FINAL,   FINAL, FINAL,  FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, ERROR},
///* s15  . */ {FINAL,   FINAL, FINAL,  FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, ERROR},
///* s16  ( */ {FINAL,   FINAL, FINAL,  FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, ERROR},
///* s17  ) */ {FINAL,   FINAL, FINAL,  FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, ERROR},
///* s18  , */ {FINAL,   FINAL, FINAL,  FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, ERROR},
///* s19  { */ {FINAL,   FINAL, FINAL,  FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, ERROR},
///* s20  } */ {FINAL,   FINAL, FINAL,  FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, ERROR},
///* s21  ; */ {FINAL,   FINAL, FINAL,  FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, ERROR},
///* s22  [ */ {FINAL,   FINAL, FINAL,  FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, ERROR},
///* s23  ] */ {FINAL,   FINAL, FINAL,  FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, ERROR},



enum tokenID {WHITESPACE, ID_Token, Num_Token, Ass_Token, Comp_Token, Greater_Token, Less_Token, Col_Token, Def_Token, Plu_Token, Min_Token, Mult_Token, Div_Token, 
                Perc_Token, Dot_Token, LParen_Token, RParen_Token, Com_Token, LCur_Token, RCur_Token, Semi_Token, LSqBra_Token, RSqBr_Token, Key_Token};

//enum states {s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13, s14, s15, s16, s17, s18, s19, s20, s21, s22, s23};

enum columns {low, up, num, dol, eq, gt, lt, col, plu, sub, mul, divi, perc, dot, lper, rper, com, lcur, rcur, sem, lsq, rsq, ws, end, junk};

std::string tokenNames[] = {"whitespace", "Identifier", "Number", "Assignment Op (=)", "Comparison Op (==)", "Greater Than", "Less Than", "Colon", "Define Op (:=)", "Add", "Subtract", "Multiply", 
                            "Divide", "Percent", "Period", "Opening Parenthesis", "Closing Parenthesis", "Comma", "Opening Curley Brace", "Closing Curly Brace", "Semi-colon",
                            "Opening Square Brace", "Closing Square Brace", "Keyword"};

//if something is determined to be an identifier token, it will be checked to see if it matches any of the reserved keywords
//if the ID_Token does end up being a keyword then it gets marked as a Key_Token before being returned
std::string keywords[16] = {"start", "stop", "loop", "while", "for", "label", "exit", "listen", "talk", "program", "if", "then", "assign", "declare", "jump", "else"};   
            
struct token { 
    tokenID token_type;
    std::string token_string; 
    int line_no;
    };