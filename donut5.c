#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include <stdbool.h>
#include "teamplus.h"
#define pgbut 0  //�����Լ�
#define pgrbut 79 
#define meetbut 0


void GotoXY(int x, int y)  //��ǥ������
{
    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int GetKeyDown();  //Ű������


void pinger(int pgX)  //�հ��� �ܼ�ǥ��
{
    GotoXY(pgX, 12);
    printf("  ��������������      ");
    GotoXY(pgX, 13);
    printf("  ������������������  ");
    GotoXY(pgX, 14);
    printf("  ����������          ");
    GotoXY(pgX, 15);
    printf("  ��������            ");

}

void pingerRight(int pgrX)  //�հ��� �ܼ�ǥ��
{
    GotoXY(pgrX, 12);
    printf("     ��������������   ");
    GotoXY(pgrX, 13);
    printf(" ������������������   ");
    GotoXY(pgrX, 14);
    printf("         ����������   ");
    GotoXY(pgrX, 15);
    printf("           �������� ");

}
void meeting(int meety)  //�����ܼ�ǥ��
{
    GotoXY(20, meety);
    printf("������������������������������������������������������������");
    GotoXY(20, meety + 1);
    printf("[            '                                             ]");
    GotoXY(20, meety + 2);
    printf(" )                              '                         ( ");
    GotoXY(20, meety + 3);
    printf("[                                                '         ]");
    GotoXY(20, meety + 4);
    printf("������������������������������������������������������������");

}

bool isCollision(const int pgX, const int meety)  //�浹���Լ�
{
    if (meety <= 14 && meety >= 12 && pgX > 3) //������ ������
    {
        return true;
    }
    return false;
}
void firstwindow(void);
void gameover(void);
void gameclear(void);

void  stage5(void) //�����Լ�
{

    bool uppg = false;  //�������
    bool isBottom = true;  //�������
    const int gravity = 4;  //�հ��� ������ ������
    int score = 0;
    int i = 100;


    int pgX = pgbut;  //�����Լ� ����
    int pgrX = pgrbut;
    int meety = meetbut;

    int endTime = (unsigned)time(NULL);
    endTime += 10;
    while (true)  //�ݺ���
    {
        int startTime = (unsigned)time(NULL);
        GotoXY(80, 0);
        printf("%d�� \n", endTime - startTime);
        Sleep(1);
        if (endTime - startTime == 0) {
            gameover();

            firstwindow();
        }
        int key = GetKeyDown();
        switch (key)
        {
        case 5:
            if (isBottom)
            {
                uppg = true;  //Ȱ��ȭ
                isBottom = false;  //��Ȱ��ȭ
            }
            break;
        }
        if (uppg)  
        {
            pgX += gravity;    //�����̸� ����
            pgrX -= gravity;
        }
        else
        {
            pgX -= gravity;  //�����̸� ����
            pgrX += gravity;
        }
        if (pgX <= pgbut)  // �հ�����xâ�� �����
        {
            pgX = pgbut;  //�հ��� ��ġ����
            isBottom = true;  //����ó��
        }
        if (pgrX >= pgrbut)  // �հ�����xâ�� �����
        {
            pgrX = pgrbut;  //�հ��� ��ġ����
        }
        if (pgX >= 4)  //�հ����� ���� �̻� �Ѿ����
        {
            uppg = false;  //����ó��
        }
        meety += 2;  //���� 2������
        if (meety >= 24)  //�Ʒ����� ��������
        {
            system("cls");
            gameover();
            system("cls");
            firstwindow();
        }
        if (meety <= 11 && pgX > 3)  //������ �հ����� ������� ���� ������ 
        {
            system("cls");
            gameover();
            system("cls");
            firstwindow();
        }
        if (isCollision(pgX, meety))  //������ �հ����� �⵹��
        {
            meety = meetbut;  //���Ӹ���
            score++; //��������
        }
        if (score > 4)  //5��������
        {         
            gameclear();
            system("pause");
            system("cls");
            firstwindow();
            
        }
        if (score == 1)  //�ӵ� ����
        {
            i = 350;
        }
        if (score == 2)
        {
            i = 50;
        }
        if (score == 3)
        {
            i = 250;
        }
        if (score == 4)
        {
            i = 100;
        }

        pinger(pgX); //�հ����� ����
        meeting(meety);  //������ ����
        pingerRight(pgrX);
        Sleep(i);  //������
        system("cls");  //�ܼ� Ŭ����
        GotoXY(40, 0);
        printf("Score : %d ", score); //���� ���
    }

    return;
}

