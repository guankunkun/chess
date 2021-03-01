#define _CRT_SECURE_NO_WARNNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3
#define COL 3
void InitBoard(char board[ROW][COL], int row, int col);
//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL], int row, int col);
//电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col);
char  CheckWin(char board[ROW][COL], int row, int col);
int is_full(char board[ROW][COL], int row, int col);
