/*Nguoi viet: Nguyen Dinh Quoc Dai  20191724 */
#ifndef _DICTIONARY_H
#define _DICTIONARY_H

#include<iostream>
using namespace std;

//define data structure.
struct Data
{
    char letter ;
    string morseCode ;
};


//  initialize data for data structure. letters are saved with index value according to their ascii value in decimal.
Data dictionary[128] = { {'\0', ""}, 
                                {'\0', ""}, {'\0', ""}, {'\0', ""}, {'\0', ""}, {'\0', ""}, {'\0', ""}, {'\0', ""}, {'\0', ""}, {'\0', ""}, {'\n', "\n"},
                                {'\0', ""}, {'\0', ""}, {'\0', ""}, {'\0', ""}, {'\0', ""}, {'\0', ""}, {'\0', ""}, {'\0', ""}, {'\0', ""}, {'\0', ""}, 
                                {'\0', ""}, {'\0', ""}, {'\0', ""}, {'\0', ""}, {'\0', ""}, {'\0', ""}, {'\0', ""}, {'\0', ""}, {'\0', ""}, {'\0', ""}, 
                                {'\0', ""}, {'\0', ""}, {'\0', ""}, {'\0', ""},  {'#', "........"}, {'\0', ""}, {'\0', ""}, {'\0', ""}, {'\0', ""}, {'\0', ""}, 
                                {'\0', ""}, {'*', ""}, {'\0', ""}, {',', "--..--"}, {'-', "-....-"}, {'.', ".-.-.-"}, {'\0', ""}, {'0', "-----"}, {'1', ".----"}, {'2', "..---"}, 
                                {'3', "...--"}, {'4', "....-"}, {'5', "....."}, {'6', "-...."}, {'7', "--..."}, {'8', "---.."}, {'9', "----."}, {':', "---..."}, {'\0', ""}, {'\0', ""}, 
                                {'\0', ""}, {'\0', ""}, {'?', "..--.."}, {'\0', ""}, {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."}, {'F', "..-."}, 
                                {'G', "--."}, {'H', "...."}, {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."}, {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."}, 
                                {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"}, {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"}, {'Y', "-.--"}, {'Z', "--.."}, 
                                {'\0', ""}, {'\0', ""}, {'\0', ""}, {'\0', ""}, {'\0', ""}, {'\0', ""}, {'a', ".-"}, {'b', "-..."}, {'c', "-.-."}, {'d', "-.."}, 
                                {'e', "."}, {'f', "..-."}, {'g', "--."}, {'h', "...."}, {'i', ".."}, {'j', ".---"}, {'k', "-.-"}, {'l', ".-.."}, {'m', "--"}, {'n', "-."}, 
                                {'o', "---"}, {'p', ".--."}, {'q', "--.-"}, {'r', ".-."}, {'s', "..."}, {'t', "-"}, {'u', "..-"}, {'v', "...-"}, {'w', ".--"}, {'x', "-..-"}, 
                                {'y', "-.--"}, {'z', "--.."}, {'\0', ""}, {'\0', ""}, {'\0', ""}, {'\0', ""}, {'\0', ""} }; 

//function for accessing dictionary

//input: A char; output: Morsecode
string Char2Morse(char input){
    // access Morse code with a character
    if (dictionary[(int)input].morseCode == "")
    {
        return "";
    }
    return dictionary[(int)input].morseCode;
}

//input: A string of MORSE code; output: single character of char type.
char Morse2Char(string input){
    // search for a match with the Morse input in the dictionary. Exclude capital letters.
    for (int i = 0; i <= 64; i++)
    {
        if (input == dictionary[i].morseCode)
        {
            return dictionary[i].letter;
        }
    }
    for (int i = 97; i <= 128; i++)
    {
        if (input == dictionary[i].morseCode)
        {
            return dictionary[i].letter;
        }
    }
    return dictionary[42].letter; // return '*' if there's no match.
}

#endif
