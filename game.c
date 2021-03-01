#include"game.h"
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] =' ';
		}
	}
}
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if(j<col-1)
			printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}

	}
}
void PlayerMove(char board[ROW][COL],int row,int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("玩家走:");
		scanf_s("%d %d", &x, &y);
		if (x >= 1 && x <= 3 && y >= 1 && y <= 3)
		{

			if (board[x-1][y-1] != ' ')
			{
				printf("坐标被占用，重新输入\n");
        	}
			else
			{
				board[x-1][y-1] = '*';
				break;
			}

		}
		else
		{
			printf("坐标非法，重新输入\n");
		}
	}
}
void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("电脑走\n");

	while (1)//死循环，直到坐标合法为止
	{
		int x = rand() % row;
		int y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}
int is_full(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i< row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}
char CheckWin(char board[ROW][COL], int row,int col)
{
	int i = 0;
	//三行
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}
	for(i=0;i<col;i++)
		//三列
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[0][i];
		}
	//对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
    }
	if (board[0][2] ==board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	//平局
	if (is_full(board,row,col)==1)
	{
		return 'q';
	}
	//游戏继续
	//前面没有赢，也没有平局就是继续
	return 'c';
}
