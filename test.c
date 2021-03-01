#include"game.h"
void game()
{
	char ret = 0;
	char board[ROW][COL];// 初始化为空格
	InitBoard(board,ROW,COL);
	DisplayBoard(board, ROW, COL);
	while (1)
	{

		//玩家走
		PlayerMove(board,ROW,COL);
		ret = CheckWin(board,ROW,COL);
		if (ret  != 'c')
		{
			break;
		}
		DisplayBoard(board,ROW,COL);
		//电脑走
		ComputerMove(board,ROW,COL);
		ret = CheckWin(board,ROW,COL);
		if (ret != 'c')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);
		//判断输赢 1：电脑赢-'#' 2：玩家赢-'*' 3：平局-'q' 4：继续呗-'c'
		
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else if (ret == 'q')
		printf("平局\n");
	DisplayBoard(board, ROW, COL);
	
}
void menu()
{
	printf("************\n");
	printf("****1.play**\n");
	printf("************\n");
	printf("************\n");
	printf("****0.exit **\n");
	printf("************\n");
}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请选择:");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，重新选择\n");
			break;
		}
	} while (input);




	return 0;
}