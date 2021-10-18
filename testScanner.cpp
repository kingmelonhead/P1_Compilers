#include "testScanner.hpp"
#include <iostream>

std::string tokenNames[] = {"whitespace", "Identifier", "Number", "Assignment Op (=)", "Comparison Op (==)", "Greater Than", "Less Than", "Colon", "Define Op (:=)", "Add", "Subtract", "Multiply", 
                            "Divide", "Percent", "Period", "Opening Parenthesis", "Closing Parenthesis", "Comma", "Opening Curley Brace", "Closing Curly Brace", "Semi-colon",
                            "Opening Square Brace", "Closing Square Brace", "Keyword"};

void print_vector(std::vector<token> &v){
    //loop through vector
    for (int i = 0; i < v.size(); i++){
        //pull next element from vector
        token temp = v.at(i);
        //display token information to console
        std::cout << "('" << temp.token_string << "', line: " << temp.line_no << ", type: " << tokenNames[temp.token_type] << ")\n";
    }
}