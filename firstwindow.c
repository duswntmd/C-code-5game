#include <stdio.h>
#include <windows.h>
#include "teamplus.h"

void titleDraw();
void GotoXY(int, int);
int menuDraw();
void infoDraw();
void stage1draw(void);
void firstwindow(void) {

	mciSendString(TEXT("open \"gamemain.wav\" type mpegvideo alias gamemain"), NULL, 0, NULL); //��� ���� ����
	mciSendString(TEXT("play gamemain repeat"), NULL, 0, NULL); //������� �ݺ� ���

	while (1) {
		titleDraw();
		int menuCode = menuDraw();
		if (menuCode == 0) {
			mciSendString(TEXT("close gamemain"), NULL, 0, NULL); //��� ���� �ݱ�
			stage1draw();
			break;
		}
		else if (menuCode == 1) {
			infoDraw();
		}
		else if (menuCode == 2) {
			break;
		}
		system("cls");
	}


}
void infoDraw() {
	system("cls");
	int x = 24;
	int y = 12;
	GotoXY(x - 2, y);
	printf("                [ ���۹� ] \n\n");
	GotoXY(x, y + 1);
	printf("              �� ��: ����Ű \n");
	GotoXY(x, y + 2);
	printf("              ���� : z \n");
	GotoXY(x, y + 5);
	printf("              z�� ������ ����ȭ������ �̵��մϴ�. ");

	while (1) {
		int key = GetKeyDown();
		if (key == 5) {
			break;
		}
	}
}

void titleDraw() {
	printf("\n\n\n\n");
	printf("         #####    #####   #         #    #     #    \n");
	printf("         #    #   #       #        # #    #   #     \n");
	printf("         #####    #####   #       #####    ###      \n");
	printf("         #   #    #       #       #   #     #       \n");
	printf("         #    #   #####   ######  #   #     #       \n");

}
void GotoXY(int x, int y);
int menuDraw() {
	int x = 24;
	int y = 12;
	GotoXY(x - 2, y);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3); //�Ķ���
	printf("> �� �� �� ��");
	GotoXY(x, y + 1);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); //�Ķ���
	printf("Ű  ��   ��");
	GotoXY(x, y + 2);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); //�Ķ���
	printf("��       �� ");
	while (1) {
		int key = GetKeyDown();
		switch (key) {
		case 1: {
			if (y > 12) {
				GotoXY(x - 2, y); //y�� 12~14������ �̵�
				printf(" "); //���� ��ġ�����
				GotoXY(x - 2, --y); //���� �̵��� ��ġ�� �̵��Ͽ�
				printf(">");
			}
			break;
		}
		case 2: {
			if (y < 14) {
				GotoXY(x - 2, y);
				printf(" ");
				GotoXY(x - 2, ++y);
				printf(">");
			}
			break;
		}
		case 5: {
			return y - 12;

		}
		}

	}
	return 0;
}