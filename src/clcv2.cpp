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

void inttui(){
}

void intsimple(){
	bool cnt = true;
	char opr;
	double prob[1];
	double res;
	while(cnt == true){
		std::cout << "Simple Prompt v0.1, Escape character is ^C" << std::endl << "Available operators: * / + -" << std::endl;
		std::cout << ">";
		std::cin >> prob[0];
		std::cout << "\n>";
		std::cin >> opr;
		std::cout << "\n>";
		std::cin >> prob[1];
		switch(opr){
			case '*': res = prob[0] * prob[1];
				break;
			case '/': res = prob[0] / prob[1];	
				break;
			case '+': res = prob[0] + prob[1];	
				break;
			case '-': res = prob[0] - prob[1];	
				break;
			default: std::cout << "\nInvalid operator" << std::endl;
				break;
		}
		std::cout << "\nResult: " << res << std::endl;
		std::cout << "Exit Prompt? y/n" << std::endl;
		std::cout << ">";
		std::cin >> prob[3];
		if(prob[3] == 'n'){cnt = false;}
	}
}

int main(int argc, char *argv[]){
	int arguballs;


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
	*\std::cout << "No argument(s) specified" << std::endl;

}
