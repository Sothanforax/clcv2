/*
 * Copyright (C) 2021 M.T. Kano (mtkano3@gmail.org)
 *
 * This program is free software.  You can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation: either version 3 or
 * (at your option) any later version.
 */
#include <iostream>
#include <getopt.h>
#include <ncurses.h>
#include <string>
#include <cmath>
#include <random>
#include <regex>

int chartoint(char in){
		if(in == '*'){return 1;}
		else if(in == '/'){return 2;}
		else if(in == '+'){return 3;}
		else if(in == '-'){return 4;}
		else{return 0;}
}

void inttui(){
	int row, col;
	initscr();
	noecho();
	raw();
	getmaxyx(stdscr, row, col);
	wborder(stdscr,'|','|','-','-','*','*','*','*');
	mvprintw(row - 2, 4, "ncurses tui not fully implemented currently, how ever you got here press any key to exit");
	refresh();
	getch();
	endwin();
}

void intsimple(){
	//COme On dO THE MARIO, SWING your ARms fROM side to side, COME ON NOW lets DO the MARIO, its easy now just PROGRAM LIKE A LOBOTOMITE, JUUUst Like THAT!
	//Being serious for a second here though this was written with minimal sleep and will make my eyes bleed the next time I review my code, whenever that is.
	bool cnt = true;
	char cntyn;
	char opr;
	double prob[2] = {0,0};
	double res = 0.0;
	int i = 1;
	while(cnt == true){
		if(i < 2){
			std::cout << "Simple Prompt v0.1, Escape character is ^C" << std::endl << "Available operators: * / + -" << std::endl;
			i++;
		}
		std::cout << "#1>";
		std::cin >> prob[0];
		std::cout << "#2>";
		std::cin >> prob[1];
		std::cout << "opr>";
		std::cin >> opr;
		int opr2 = chartoint(opr);
		switch(opr2){
			case 1: res = prob[0] * prob[1];
				break;
			case 2: res = prob[0] / prob[1];	
				break;
			case 3: res = prob[0] + prob[1];	
				break;
			case 4: res = prob[0] - prob[1];	
				break;
			default: 
				std::cerr << "\nInvalid operator" << std::endl;
				break;
		}
		std::cout << "\nResult: " << res << std::endl;
		std::cout << "Exit Prompt? y to quit, any other character to enter another problem" << std::endl;
		std::cout << ">";
		std::cin >> cntyn;
		if(cntyn == 'y'){cnt = false;}
	}
}

int main(int argc, char *argv[]){
	int arguballs;
	//intsimple();
	inttui();


	//for reference when writing the getopt(_long) help struct??	
	/*std::cout << "Usage:\n";
	std::cout << "progname [options] 		Start an interactive prompt\n";
	std::cout << "progname [options] [expr]	Enter an expression to solve\n";
	std::cout << "\n	Proof of concept calculator with multiple input methods\n";
	std::cout << "\nOptions:\n";
	std::cout << "-i, --interactive		Start a ncurses based interactive tui\n";
	std::cout << "-s, --interactive-simple	Start a simple interactive prompt\n";
	std::cout << "-h, --help			Display this help\n";
	std::cout << "-v, --version			Display version\n" << std::endl;
	std::cout << "\nprogname version 0.1" << std::endl;
	std::cout << "\nやらないか" << std::endl;
	std::cout << "Invalid argument!\n progname -h or --help for more." <<std::endl;
	std::cout << "No argument(s) specified" << std::endl;*/

}
