#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include <fstream>
#include <string>
using namespace std;
#define CANVAS_SKY_X 150
#define CANVAS_SKY_Y 20 
#define CANVAS_URBAN_X 130
#define CANVAS_URBAN_Y 10 
char canvas_sky[20][150];
char canvas_urban[10][130];

string getascii(string);
void night();
void morning();
//void init_night();
void init_sky();
void init_urban();
void print_sky();
void print_urban();
void moveObject();



#define SUN_HIEIGHT 15
#define SUN_WIDTH 40 
char sun[SUN_HIEIGHT][SUN_WIDTH] = {
"          .      '      .",
"    .      .     :     .      .",
"     '.        ______       .'",
"       '  _.-\"`      `\"-._ '",
"        .'                '.",
" `'--. /                    \\ .--'`",
"      /                      \\,",
"     ;                        ;",
"- -- |                        | -- -",
"     |                        |",
"     ;                        ;",
" .-'  \\                      /  '-."
};

#define TEXT_HEIGHT 8
#define TEXT_WIDTH 90 
char text[TEXT_HEIGHT][TEXT_WIDTH] = {
"  _   _                           _   _                __   __             ",
" | | | |                         | \\ | |               \\ \\ / /              ",
" | |_| | __ _ _ __  _ __  _   _  |  \\| | _____      __  \\ V /___  __ _ _ __ ",
" |  _  |/ _` | '_ \\| '_ \\| | | | | . ` |/ _ \\ \\ /\\ / /   \\ // _ \\/ _` | '__|",
" | | | | (_| | |_) | |_) | |_| | | |\\  |  __/\\ V  V /    | |  __/ (_| | |   ",
" \\_| |_/\\__,_| .__/| .__/ \\__, | \\_| \\_/\\___| \\_/\\_/     \\_/\\___|\\__,_|_|   ",
"             | |   | |     __/ |                                            ",
"             |_|   |_|    |___/                                             " 
};
