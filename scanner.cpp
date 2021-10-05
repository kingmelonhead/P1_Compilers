#include "scanner.hpp"

/*
pseudocode for the scanner, just to keep a mental picture of where this is going:

string getNextFilter(parameters: file stream object){

    - if a line is comment, go to next line
    - scan the line for comments, remove part of line that has comments
    - if the whole line is comments skip to next line
    - if the whole line is white space
    - once there is a valid string then return it
}

driver function - this will be called from the main.cpp (parameters: file name as string)  {

    -string var: filter

    -attempt to open the file, if file does not exist then error and close program

    -call the getNextFilter to get a line to scan 

    
}

*/

const int state_no = 23;
const int col_no = 29;
const int ERROR = -1;
const int FINAL = 100;

enum states {s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13, s14, s15, s16, s17, s18, s19, s20, s21, s22, s23};

int FSA_Table[state_no][col_no] = {
//       a-z   A-Z  0-9   _     $   =    >   <   :   +    -    *    /    %    .    (     )   ,    {    }    ;    [    ]   WS    !      #       ^      &    EOF
/* s1 */ {s2, ERROR, s3, ERROR, s2, s4, s6, s7, s8, s10, s11, s12, s13, s14, s15, s16, s17, s18, s19, s20, s21, s22, s23, s1, ERROR, ERROR, ERROR, ERROR, FINAL},
/* s2 */
/* s3 */
/* s4 */
/* s5 */
/* s6 */
/* s7 */
/* s8 */
/* s9 */
/* s10 */
/* s11 */
/* s12 */
/* s13 */
/* s14 */
/* s15 */
/* s16 */
/* s17 */
/* s18 */
/* s19 */
/* s20 */
/* s21 */
/* s22 */
/* s23 */
};