#include"game.h"
void game()
{
	char ret = 0;
	char board[ROW][COL];// ��ʼ��Ϊ�ո�
	InitBoard(board,ROW,COL);
	DisplayBoard(board, ROW, COL);
	while (1)
	{

		//�����
		PlayerMove(board,ROW,COL);
		ret = CheckWin(board,ROW,COL);
		if (ret  != 'c')
		{
			break;
		}
		DisplayBoard(board,ROW,COL);
		//������
		ComputerMove(board,ROW,COL);
		ret = CheckWin(board,ROW,COL);
		if (ret != 'c')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);
		//�ж���Ӯ 1������Ӯ-'#' 2�����Ӯ-'*' 3��ƽ��-'q' 4��������-'c'
		
	}
	if (ret == '*')
	{
		printf("���Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else if (ret == 'q')
		printf("ƽ��\n");
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
		printf("��ѡ��:");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ���������ѡ��\n");
			break;
		}
	} while (input);




	return 0;
}