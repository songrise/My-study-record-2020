#ifndef TTT_H_
#define TTT_H_

#include <stdio.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <time.h>
#include <vector>
#include <algorithm>
#include <unistd.h>

/**************Macros***************/
#define WIDTH 60
#define BUFSIZE 256
#define CENTERED 1
#define LEFTALIGNED 0

// control color of console, just ignore them when reading source file.
#define CLOSE printf("\033[0m");
#define BLACK printf("\033[30m");
#define RED printf("\033[31m");
#define GREEN printf("\033[32m");
#define YELLOW printf("\033[33m");
#define BLUE printf("\033[34m");
#define WHITE printf("\033[37m");
#define WHITE_BC printf("\033[47m"); //Temporarily disabled, because may cause bug on certain system.
#define BOLD printf("\033[1m");
//set console color

/*************Function prototypes**************/
void welcome(void);
int get_command(void);
int select_mode(void);
// Color enable_color(void); //Temporarily disabled, because may cause bug on certain system.
void pve();
void pvp();
int roll_dice();
void piece(int chessID);
void draw_board(int *board);
bool get_action(int *board, int first);
void easy_comp_move(int *board, int first);
int next_step(int *board, int first);
int check_winner(int *board);
inline int Evaluate(int board[3][3]);
inline int dfs(const int &depth, const int &nowWho, int board[3][3]);
void hard_comp_move(int *board, int first);
void draw_line(char symbol, int width);                              //draw horizontal line
void draw_embraced(char symbol, const char *string, int option = 0); // print string embraced by given symbol
void msg_box(const char *string, char tb = '-', char lr = '|');      //print string inside a message box

#endif