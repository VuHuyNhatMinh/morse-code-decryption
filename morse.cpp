/*
    Author: Vu Huy Nhat Minh - 20191973
    This is the main function to execute the program.

    Github link for project: https://github.com/VuHuyNhatMinh/KTLT
    For more informations, please contact: nminhstickpk@gmail.com
*/

#include <iostream>
#include <fstream>
#include <string>
#include "Dictionary.h"
#include "ErrorChecking.h"
#include "Morse2String.h"
#include "String2Morse.h"

// #define DEBUG

using namespace std;

int main(int argc, char* argv[])
{
    /* 
        Check whether open file data or not 
    */
    if (!check_open(argv[1]))
    {
        return 1;
    }

    /*
        Check whether file result exsit or not 
        If does, overwrite or not
    */
    if (!check_exist_out(argv[2]))
    {
        return 1;
    }

    /*
        Open file data to perform decrypt
    */
    ifstream fdata;
    fdata.open(argv[1]);
    // An object string data to store all text in data file
    string data;    
    getline(fdata, data, '\0');
    fdata.close();
   
    /*
        Check the file type
    */
    // An object string res to store decryption data
    string res;;
    if (check_type(data))
    {
        // Check error in morse file
        check_morse(data);

        #ifdef DEBUG
            cout << "This is morse file" << endl;
        #endif

        // Decrypt to text file
        res = Decrypt(data);
    }
    else
    {
        // Check error in text file
        check_text(data);

        #ifdef DEBUG
            cout << "This is txt file" << endl;
        #endif

        // Decrypt to morse file
        res = Textmorse(data);
    }
    
    /*
        Open file result to write result
    */
    ofstream fresult;
    fresult.open(argv[2]);
    fresult << res;
    fresult.close(); 
}
