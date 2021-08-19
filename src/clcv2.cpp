/*
 * Copyright (C) 2021 M.T. Kano (mtkano3@gmail.org)
 *
 * This program is free software.  You can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation: either version 3 or
 * (at your option) any later version.
 */
#include <iostream>
#include <unistd.h>
#include <getopt.h>
#include <ncurses.h>
#include <string>
#include <cmath>
#include <random>
#include <regex>

void inttui(){
}

void intsimple(){
}

int main(int argc, char *argv[]){
	std::string arg = argv[1];
if(argc > 1){
	if(arg == "--interactive" || "-i"){inttui();}

	if(arg == "--interactive-simple" || "-s"){intsimple();}

	if(arg == "--help" || "-h"){
		std::cout << "\nUsage:\n";
		std::cout << "	progname [options] 		Start an interactive prompt\n";
		std::cout << "	progname [options] [expr]	Enter an expression to solve\n";
		std::cout << "\n	Proof of concept calculator with multiple input methods\n";
		std::cout << "\nOptions:\n";
		std::cout << "	-i, --interactive		Start a ncurses based interactive tui\n";
		std::cout << "	-s, --interactive-simple	Start a simple interactive prompt\n";
		std::cout << "	-h, --help			Display this help\n";
		std::cout << "	-v, --version			Display version\n" << std::endl;}

	if(arg == "--version" || "-v"){std::cout << "\nprogname version 0.1" << std::endl;}

	if(arg == "--yaranaika" || "-y"){std::cout << "\nやらないか" << std::endl;}

	else{
		std::cout << "Invalid argument!\n progname -h or --help for more." <<std::endl;
	}
}
else{
	std::cout << "No argument(s) specified" << std::endl;
}

}
