#pragma once

#include <iostream>

//Clears terminal
void clear_screen();

//Symbol to integer converter
int stoi(char symbol);

//integer to symbol converter
char itos(int number);

//Verifies if the input is an integer included between two numbers
void verif_IsIntegerBetween(int& number, int number1, int number2);

//Verifies if the input is a letter included between two letters
void verif_IsLetterBetween(char& letter, char letter1, char letter2);

//Vérifies if the input is one of the two symbols, returns the symbol
char verif_IsSymbolRight(char& symbol);

//Symbol choosing function
void choose_symbol(int& symbol);

//Main menu display and logic
void main_menu(int& mode, int& mode2);

//End screen display and logic
void end_screen(int& symbol, int& winner);