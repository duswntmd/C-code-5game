#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
#include "teamplus.h"

#include <mmsystem.h> //playsound�� ����ϱ� ���ؼ�
#pragma comment(lib,"winmm.lib") //������ ���̺귯�� �ʿ���
#include "Digitalv.h"

typedef struct
{
    int x, y;

}POS;
void firstwindow(void);
void stage2draw(void);
void gameover(void);
void gotoxy(int x, int y, char* s)//��ü�� �̵�

{
    COORD Pos = { x * 2,y };

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

    printf("%s", s);// s�� �ʿ� ������ ����Ʈ��.

}

void draw_screen()  ///ó�� �� �׵θ� �׸���

{
    int i;

    system("cls");//ȭ�� ����

    gotoxy(0, 0, "��������������������������������");// �� �׵θ�

    for (i = 1; i < 20; i++)// ���� ������ �׵θ�

    {

        gotoxy(0, i, "��");

        gotoxy(30, i, "��");

    }

    gotoxy(0, 20, "��������������������������������\n");// �Ʒ��� �׵θ�

}
int GetKeyDown();// Ű �Լ� Ű���� �Է��ؼ� �����̰��ϱ�����

void move_snake(POS* snake, int len)///���� �����̴� �κ�

{
    static int dir = -1;

    if (_kbhit())///�Էºκ�

    {
        int key = GetKeyDown();// Ű �Լ� �θ���

        switch (key)//Ű�Լ��� �Է� Ű������ dir���� ���� ����

        {
        case 1: dir = 0; break;//��

        case 2: dir = 1; break;//�Ʒ�

        case 3: dir = 2; break;//����

        case 4: dir = 3; break;//������

        }

    }

    if (dir != -1)//Ű�Լ��� Ű�� �Է������� �����κп� ���� �ڵ�

    {

        int i;

        gotoxy(snake[len - 1].x, snake[len - 1].y, "  ");// ���� �������κ� �þ������ʰ��ϱ����� �ڵ�

        for (i = len - 1; i > 0; i--)
            snake[i] = snake[i - 1]; //������ �����κк��� ó���������� ��ĭ�� �̵���Ŵ �ٸ� ���⼭ �۷� ��Ÿ���� �ƴ�

        gotoxy(snake[1].x, snake[1].y, "��");//�����κ��� �����ϱ� �����ڵ�

    }


    switch (dir) //���� Ű������ ������ ����ġ������ ��ȯ�� ������ũ �Ӹ��κ� ��ġ ��ȯ

    {

    case 0: snake[0].y--;; break;//�� 

    case 1: snake[0].y++; break;//�Ʒ�

    case 2: snake[0].x--; break;//����

    case 3: snake[0].x++; break;//������

    }

    gotoxy(snake[0].x, snake[0].y, "��");//������ũ �Ӹ��κ�

}

int check_snake(POS* snake, int len)///���� �浹�ߴ��� Ȯ���ϴ� �κ�

{

    int i;

    if (snake[0].x == 0 || snake[0].y == 0 || snake[0].x == 30 || snake[0].y == 20)return 0;//������ũ�� ���� �ε������� 0��ȯ

    for (i = 1; i < len; i++)

    {

        if (snake[0].x == snake[i].x && snake[0].y == snake[i].y)return 0;//������ũ �Ӹ��� ������ �ε����� 0��ȯ

    }

    return 1;

}

void stage3(void)

{
    POS fall1[4], fall2[4], fall3[4], fall4[4];//��ֹ�
    POS snake[100], item, item2;//�������� ����, ������ ����
    int j, i, dir = -1, len = 5, score = 0;// len�� ���� ������������ �� �����, ���� ����
    int speed = 150; //���ǵ� ����
    double timec = 0;//�ð��� ���� ������ ���� ����**********************************
    clock_t start, end;//clock_t����*************************************8
    srand(time(NULL));//�Լ��� �������� �����Ҷ����� �������� �������

    mciSendString(TEXT("close gamemain"), NULL, 0, NULL); //��� ���� �ݱ�
    mciSendString(TEXT("open \"gaming.wav\" type mpegvideo alias gaming"), NULL, 0, NULL); //��� ���� ����
    mciSendString(TEXT("play gaming repeat"), NULL, 0, NULL); //������� �ݺ� ���

    draw_screen();// �ʻ���

    for (i = 0; i < len; i++)// ó�������ҋ��� ��ġ 

    {

        snake[i].x = 15 + i; //������ �� ��ġ

        snake[i].y = 10;

        gotoxy(snake[i].x, snake[i].y, "��");//ó�������Ҷ��� ��ġ�� ������ ǥ�� �Ӹ��� key�Լ��� ��Ÿ����

    }
    fall1[0].x = 3;// ó�� ������ֹ��� ��ġ
    fall1[0].y = 2;
    fall1[1].x = 4;
    fall1[1].y = 2;
    fall1[2].x = 3;
    fall1[2].y = 3;
    fall1[3].x = 4;
    fall1[3].y = 3;
    fall2[0].x = 3;
    fall2[0].y = 17;
    fall2[1].x = 4;
    fall2[1].y = 17;
    fall2[2].x = 3;
    fall2[2].y = 18;
    fall2[3].x = 4;
    fall2[3].y = 18;
    fall3[0].x = 26;
    fall3[0].y = 2;
    fall3[1].x = 27;
    fall3[1].y = 2;
    fall3[2].x = 26;
    fall3[2].y = 3;
    fall3[3].x = 27;
    fall3[3].y = 3;
    fall4[0].x = 26;
    fall4[0].y = 17;
    fall4[1].x = 27;
    fall4[1].y = 17;
    fall4[2].x = 26;
    fall4[2].y = 18;
    fall4[3].x = 27;
    fall4[3].y = 18;
respone:
    item.x = rand() % 28 + 1;// ������1�� ��ġ�� �������� ����

    item.y = rand() % 18 + 1;
respone1:
    item2.x = rand() % 28 + 1;//������2�� ��ġ�� �������� ����

    item2.y = rand() % 18 + 1;
    for (i = 0; i < 4; i++) {
        if (fall1[i].x == item.x && fall1[i].y == item.y)// ������1�� ������2�� ������ֹ��� �����Ǹ� �ٽ� goto������ �ٽ� ���ư��� ����
            goto respone;
        if (fall2[i].x == item.x && fall2[i].y == item.y)
            goto respone;
        if (fall3[i].x == item.x && fall3[i].y == item.y)
            goto respone;
        if (fall4[i].x == item.x && fall4[i].y == item.y)
            goto respone;
        if (fall1[i].x == item2.x && fall1[i].y == item2.y)
            goto respone1;
        if (fall2[i].x == item2.x && fall2[i].y == item2.y)
            goto respone1;
        if (fall3[i].x == item2.x && fall3[i].y == item2.y)
            goto respone1;
        if (fall4[i].x == item2.x && fall4[i].y == item2.y)
            goto respone1;
    }
    if (item.x == item2.x && item.y == item2.y)//������1�� ������2�� ��ġ�� �ٽ� ���ư��� ����
        goto respone1;
    gotoxy(1, 21, "Score : 0");// ó�� ���ھ� ��ġ ����






    while (1) {
        if (timec >= 30)//�����ð� ������ �ݺ��� Ż��*******************************
            break;
        if (check_snake(snake, len) == 0)//������ũ�� ���̳� �ʿ� �ε����� �ݺ��� Ż��

            break;

        if (snake[0].x == item.x && snake[0].y == item.y || snake[0].x == item2.x && snake[0].y == item2.y)///������ �Ծ��� ���

        {
            mciSendString(TEXT("open \"effect.wav\" type mpegvideo alias effect"), NULL, 0, NULL); //ȿ���� ����
            mciSendString(TEXT("play effect from 0 to 1000"), NULL, 0, NULL); //������� �ݺ� ���
            score += 10;//������ �ö�
            if (score == 40)//�������� ������ �ݺ��� Ż��
                stage4draw();
            if (snake[0].x == item.x && snake[0].y == item.y)// ������1�� �Ծ����� ���ǵ尡 ���۽��ǵ忡 ���� ������
                speed = 200;
            if (snake[0].x == item2.x && snake[0].y == item2.y)// ������2�� �Ծ����� ���ǵ尡 ���۽��ǵ忡 ���� ������
                speed = 90;
            gotoxy(item.x, item.y, "  ");//�������� �Ծ����� �������� ����̳����� ġ��� �ڵ�
            gotoxy(item2.x, item2.y, "  ");
            for (i = 0; i < 4; i++) {// �������� �Ծ����� ������ֹ��� ����̳��������� ġ��� �ڵ�
                gotoxy(fall1[i].x, fall1[i].y, "  ");
                gotoxy(fall2[i].x, fall2[i].y, "  ");
                gotoxy(fall3[i].x, fall3[i].y, "  ");
                gotoxy(fall4[i].x, fall4[i].y, "  ");
            }

        fall1:
            fall1[0].x = rand() % 28 + 1;// ù��° ������ֹ��� �����Լ��� ��ġ����

            fall1[0].y = rand() % 18 + 1;
            fall1[1].x = fall1[0].x + 1;// ù��° ������ֹ��� ��ġ�� �������� �簢�����θ���� ���� ��ġ����
            fall1[1].y = fall1[0].y;
            fall1[2].x = fall1[0].x;
            fall1[2].y = fall1[0].y + 1;
            fall1[3].x = fall1[0].x + 1;
            fall1[3].y = fall1[0].y + 1;
        fall2:
            fall2[0].x = rand() % 28 + 1;//���� ��������

            fall2[0].y = rand() % 18 + 1;
            fall2[1].x = fall2[0].x + 1;
            fall2[1].y = fall2[0].y;
            fall2[2].x = fall2[0].x;
            fall2[2].y = fall2[0].y + 1;
            fall2[3].x = fall2[0].x + 1;
            fall2[3].y = fall2[0].y + 1;
        fall3:
            fall3[0].x = rand() % 28 + 1;// ���� ��������

            fall3[0].y = rand() % 18 + 1;
            fall3[1].x = fall3[0].x + 1;
            fall3[1].y = fall3[0].y;
            fall3[2].x = fall3[0].x;
            fall3[2].y = fall3[0].y + 1;
            fall3[3].x = fall3[0].x + 1;
            fall3[3].y = fall3[0].y + 1;
        fall4:
            fall4[0].x = rand() % 28 + 1;//���� ��������

            fall4[0].y = rand() % 18 + 1;
            fall4[1].x = fall4[0].x + 1;
            fall4[1].y = fall4[0].y;
            fall4[2].x = fall4[0].x;
            fall4[2].y = fall4[0].y + 1;
            fall4[3].x = fall4[0].x + 1;
            fall4[3].y = fall4[0].y + 1;

            item.x = rand() % 28 + 1;// �������� ��ġ�� �������� ����

            item.y = rand() % 18 + 1;
        ask:
            item2.x = rand() % 28 + 1;

            item2.y = rand() % 18 + 1;
            if (item.x == item2.x && item.y == item2.y)// ������1,2�� ��ġ�� ������ �ٽ� ���ư��� ��ġ �缳��
                goto ask;
            for (i = 0; i < 4; i++) {// ������ ��ġ�� ������ֹ� ��ġ�� ������ ���ư��� �缳��
                if (fall1[i].x == item.x && fall1[i].y == item.y)
                    goto fall1;
                if (fall1[i].x == item2.x && fall1[i].y == item2.y)
                    goto fall1;
            }
            for (i = 0; i < 4; i++) {// ���� ��������
                if (fall2[i].x == item.x && fall2[i].y == item.y)
                    goto fall2;
                if (fall2[i].x == item2.x && fall2[i].y == item2.y)
                    goto fall2;
                if (fall3[i].x == item.x && fall3[i].y == item.y)
                    goto fall3;
                if (fall3[i].x == item2.x && fall3[i].y == item2.y)
                    goto fall3;
                if (fall4[i].x == item.x && fall4[i].y == item.y)
                    goto fall4;
                if (fall4[i].x == item2.x && fall4[i].y == item2.y)
                    goto fall4;
                if (snake[0].x == fall1[i].x && snake[0].y == fall1[i].y)// ������ֹ��� �����۸԰� �������� ��ġ�Ҷ� �Ӹ��κп� �����ȵǰ� �ϴ� �ڵ�
                    goto fall1;
                if (snake[0].x == fall2[i].x && snake[0].y == fall2[i].y)
                    goto fall2;
                if (snake[0].x == fall3[i].x && snake[0].y == fall3[i].y)
                    goto fall3;
                if (snake[0].x == fall4[i].x && snake[0].y == fall4[i].y)
                    goto fall4;
                if (snake[0].x + 1 == fall1[i].x && snake[0].y == fall1[i].y)// ������ֹ��� �����۸԰� �������� ��ġ�Ҷ� �Ӹ���ó�� �����ȵǰ� �ϴ� �ڵ�
                    goto fall1;
                if (snake[0].x + 1 == fall2[i].x && snake[0].y == fall2[i].y)
                    goto fall2;
                if (snake[0].x + 1 == fall3[i].x && snake[0].y == fall3[i].y)
                    goto fall3;
                if (snake[0].x + 1 == fall4[i].x && snake[0].y == fall4[i].y)
                    goto fall4;
                if (snake[0].x - 1 == fall1[i].x && snake[0].y == fall1[i].y)
                    goto fall1;
                if (snake[0].x - 1 == fall2[i].x && snake[0].y == fall2[i].y)
                    goto fall2;
                if (snake[0].x - 1 == fall3[i].x && snake[0].y == fall3[i].y)
                    goto fall3;
                if (snake[0].x - 1 == fall4[i].x && snake[0].y == fall4[i].y)
                    goto fall4;
                if (snake[0].x == fall1[i].x && snake[0].y + 1 == fall1[i].y)
                    goto fall1;
                if (snake[0].x == fall2[i].x && snake[0].y + 1 == fall2[i].y)
                    goto fall2;
                if (snake[0].x == fall3[i].x && snake[0].y + 1 == fall3[i].y)
                    goto fall3;
                if (snake[0].x == fall4[i].x && snake[0].y + 1 == fall4[i].y)
                    goto fall4;
                if (snake[0].x == fall1[i].x && snake[0].y - 1 == fall1[i].y)
                    goto fall1;
                if (snake[0].x == fall2[i].x && snake[0].y - 1 == fall2[i].y)
                    goto fall2;
                if (snake[0].x == fall3[i].x && snake[0].y - 1 == fall3[i].y)
                    goto fall3;
                if (snake[0].x == fall4[i].x && snake[0].y - 1 == fall4[i].y)
                    goto fall4;
            }

            gotoxy(1, 21, "Score : ");// ���ھ� ��ġ ����


            printf("%d", score);// ���� ����



            if (len < 100)// ������ �������� �̻� �ȳ����� �������� ��ĭ�������� �Ѿ�� len�Լ� ����

            {

                snake[len] = snake[len - 1];

                len++;

            }




        }

        if (snake[0].x == fall1[0].x && snake[0].y == fall1[0].y)// ������ũ�Ӹ��� ������ֹ��� �ε����� �ݺ��� Ż��
            break;
        if (snake[0].x == fall1[1].x && snake[0].y == fall1[1].y)
            break;
        if (snake[0].x == fall1[2].x && snake[0].y == fall1[2].y)
            break;
        if (snake[0].x == fall1[3].x && snake[0].y == fall1[3].y)
            break;

        if (snake[0].x == fall2[0].x && snake[0].y == fall2[0].y)
            break;
        if (snake[0].x == fall2[1].x && snake[0].y == fall2[1].y)
            break;
        if (snake[0].x == fall2[2].x && snake[0].y == fall2[2].y)
            break;
        if (snake[0].x == fall2[3].x && snake[0].y == fall2[3].y)
            break;

        if (snake[0].x == fall3[0].x && snake[0].y == fall3[0].y)
            break;
        if (snake[0].x == fall3[1].x && snake[0].y == fall3[1].y)
            break;
        if (snake[0].x == fall3[2].x && snake[0].y == fall3[2].y)
            break;
        if (snake[0].x == fall3[3].x && snake[0].y == fall3[3].y)
            break;
        if (snake[0].x == fall4[0].x && snake[0].y == fall4[0].y)
            break;
        if (snake[0].x == fall4[1].x && snake[0].y == fall4[1].y)
            break;
        if (snake[0].x == fall4[2].x && snake[0].y == fall4[2].y)
            break;
        if (snake[0].x == fall4[3].x && snake[0].y == fall4[3].y)
            break;
        start = clock();// �ð� ��°��� ����*************************************
        for (i = 0; i < 4; i++) {//������ֹ��� ��ġ������ ��缳��
            gotoxy(fall1[i].x, fall1[i].y, "��");
        }
        for (i = 0; i < 4; i++) {
            gotoxy(fall2[i].x, fall2[i].y, "��");
        }
        for (i = 0; i < 4; i++) {
            gotoxy(fall3[i].x, fall3[i].y, "��");
        }
        for (i = 0; i < 4; i++) {
            gotoxy(fall4[i].x, fall4[i].y, "��");
        }
        gotoxy(item.x, item.y, "��");//������ ��ġ������ ������
        gotoxy(item2.x, item2.y, "��");

        move_snake(snake, len);// ���� ������ �Լ� �ҷ�����

        Sleep(speed);// ���ǵ忡 ���� ���� ���� ������ �������� ������
        end = clock();// �ð� ��°��� ������ ���� ����*************************
        timec += (double)(end - start) / CLK_TCK; //�ð����� ���� ������ ���� ���Ͽ� ����*************************************************************
        gotoxy(7, 21, "�ð�: ");//************************************************
        printf("%d ", 30 - (int)timec);// �ð��پ��°� ����Ʈ**********************
    }

    for (i = 0; i < 4; i++) {//���� ��ֹ��� �ݺ��� Ż��� ���ӿ���
        if (snake[0].x == fall1[i].x && snake[0].y == fall1[i].y)
            system("cls");
            gameover();
            system("cls");
        firstwindow();
    }
    for (i = 0; i < 4; i++) {
        if (snake[0].x == fall2[i].x && snake[0].y == fall2[i].y)
            system("cls");
            gameover();
            system("cls");
        firstwindow();
    }
    for (i = 0; i < 4; i++) {
        if (snake[0].x == fall3[i].x && snake[0].y == fall3[i].y)
            system("cls");
            gameover();
            system("cls");
        firstwindow();
    }
    for (i = 0; i < 4; i++) {
        if (snake[0].x == fall4[i].x && snake[0].y == fall4[i].y)
            system("cls");
            gameover();
            system("cls");
        firstwindow();
    };
    if (score == 40) {//���ھ� ��Ƽ� �ݺ��� Ż��� ������������ ��ȯ

        stage4draw();
    }
    if (check_snake(snake, len) == 0) {//���̳� ���� �ε��� �ݺ��� Ż��� ���ӿ���
        system("cls");
        gameover();
        system("cls");
        firstwindow();

    }
    if (timec >= 30) {
        system("cls");
        gameover();
        system("cls");
        firstwindow();
    }//���� �ð� �Ѿ�� ���ӿ���******************************



}