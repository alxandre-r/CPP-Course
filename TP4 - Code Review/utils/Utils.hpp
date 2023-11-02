#pragma once

#include <iostream>

//Clears terminal
void clear_screen();

//Symbol to integer converter
int stoi(char symbol);

//Symbol choosing function
void choose_symbol(int& symbol);

//Main menu display and logic
void main_menu(int& mode, int& mode2);

//End screen display and logic
void end_screen(int& symbol, int& winner);