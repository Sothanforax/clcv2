/*
 * Copyright (C) 2021 M.T. Kano (mtkano3@gmail.org)
 *
 * This program is free software.  You can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation: either version 3 or
 * (at your option) any later version.
 */
#include <iostream>
#include <cstdio>
#include <getopt.h>
#include <ncurses.h>
#include <csignal>
#include <cstring>
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
	getmaxyx(stdscr, row, col);
	wborder(stdscr, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE, ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);
	mvprintw(row - 3, 2, "ncurses tui not fully implemented currently, how ever you got here press any key to exit");
	mvprintw(row - 2, 2, "columns %i rows %i", col, row);
	mvprintw(row - 4, 2, "Hello there!");
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
	int option_index = 0;

	static struct option long_options[] = {
		{"expression", required_argument, 0, 'e'},
		{"interactive", no_argument, 0, 'i'},
		{"interactive-simple", no_argument, 0, 's'},
		{"help", no_argument, 0, 'h'},
		{"usage", no_argument, 0, 'u'},
		{"version", no_argument, 0, 'v'},
		{0, 0, 0, 0}

	};
		arguballs = getopt_long(argc, argv, "e:ishuv", long_options, &option_index);

	switch(arguballs){
		case 0:
			std::cout << "test";
			break;
		case 'i':
			inttui();
			break;
		case 's':
			intsimple();
			break;
		case 'h':
			std::cout << "ephemera [options]\n";
			std::cout << "ephemera -e [expression]";
			std::cout << "\n	Cruddy proof of concept calculator with multiple input methods\n";
			std::cout << "\nOptions:\n";
			//std::cout << "-e --expression				Enter an expression straight into the terminal\n";
			std::cout << "-i --interactive			Start an ncurses based interactive tui\n";
			std::cout << "-s --interactive-simple			Start a simple interactive prompt\n";
			std::cout << "-h --help				Display this help\n";
			std::cout << "-v --version				Display version\n";
			break;
		case 'u':
			std::cout << "Usage: ephemera [ishuv]\n";
			break;
		case 'v':
			std::cout << "ephemera v0.2\n";
			break;
	}	
}
