#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h> 
#include<Windows.h> 
#include<conio.h> 
#include<stdlib.h> 
#include<time.h> 
#include"teamplus.h"


#define GAMESTART 1 
#define LEVEL 2 
#define EXIT 3 
#define WIDTH 10 
#define HEIGHT 20 
#define Y 0 
#define X 1 
#define NULL 0 
#define WALL 1 
#define PLAYER 2     
#define STAR 3 
#define false 0 
#define true 1 

int player[2];
int level = 3;
int run = 1;
int score = 0;
void firstwindow(void);
void stage3draw(void);
void gameclear(void);
void Init(int map[][WIDTH])
{
    player[X] = WIDTH - 5;
    player[Y] = HEIGHT - 1;
}
void StarCreate(int map[HEIGHT][WIDTH])
{
    int lv, i, x;
    int starCount = 0; // ������ ���� ������ �����ϴ� ����
    while (starCount < 5) // ���� 5�� �̸��� ��� ��� ����
    {
        x = rand() % 8 + 1;
        if (map[0][x] != STAR) // �̹� ���� �ִ� ��ġ���� �������� ����
        {
            map[0][x] = STAR;
            starCount++; // �� ���� ����
        }
    }
}

void map_reset(int map[][WIDTH])
{
    int y, x;
    for (y = 0; y < HEIGHT; y++)
    {
        for (x = 0; x < WIDTH; x++)
        {
            map[y][0] = WALL;
            map[y][WIDTH - 1] = WALL;
        }
    }
    StarCreate(map);
}


void MapDraw(int map[][WIDTH])
{
    COORD pos = { 0, 0 };
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            if (player[Y] == y && player[X] == x)
                printf("��");
            else if (map[y][x] == WALL)
                printf("��");
            else if (map[y][x] == STAR)
                printf("��");
            else
                printf("  ");
        }
        printf("\n");
    }
    printf("\n Score : %d\n", score);
}

void Star_Update(int map[HEIGHT][WIDTH])
{
    for (int y = HEIGHT - 1; y >= 0; y--)
    {
        for (int x = 1; x < WIDTH - 1; x++)
        {
            if (map[y][x] == STAR)
            {
                map[y][x] = 0;
                if (y + 1 >= HEIGHT)
                {
                    map[HEIGHT - 1][1] = 0;
                    map[HEIGHT - 1][2] = 0;
                    map[HEIGHT - 1][3] = 0;
                    map[HEIGHT - 1][4] = 0;
                    map[HEIGHT - 1][5] = 0;
                    map[HEIGHT - 1][6] = 0;
                    map[HEIGHT - 1][7] = 0;
                    map[HEIGHT - 1][8] = 0;
                    StarCreate(map);
                    return;
                }
                else
                {
                    map[y + 1][x] = STAR;
                }
            }
        }
    }
}

int check_hit(int map[][WIDTH])
{
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            if (map[y][x] == STAR)
            {
                if (player[Y] == y && player[X] == x)
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}

void PlayerMove(int map[][WIDTH])
{
    int run = 1;
    int gameover1 = 0;

    system("cls"); // ���� ���� �� �� ���� ȭ���� ����
    MapDraw(map);

    while (run)
    {
        int key = GetKeyDown();

        switch (key)
        {
        case 3: // �������� �����̴� Ű
            if (map[player[Y]][player[X] - 1] != WALL)
            {
                map[player[Y]][player[X]] = 0;
                player[X]--;
            }
            break;

        case 4: // ���������� �����̴� Ű
            if (map[player[Y]][player[X] + 1] != WALL)
            {
                map[player[Y]][player[X]] = 0;
                player[X]++;
            }
            break;

        default:
            break;
        }

        if (map[player[Y]][player[X]] == STAR)
        {
            run = 0;
            gameover1 = 1;
            system("cls");
            gameover();
            system("cls");
            firstwindow();

        }
        else
        {
            map[player[Y]][player[X]] = PLAYER;
            score++;
        }

        Star_Update(map); // ���� ��ġ ������Ʈ

        if (score > 200)
        {
            run = 0;
            stage3draw();
            Sleep(2000); // 2�� ���
        }

        if (!gameover1)
        {
            COORD pos = { 0, 0 };
            HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleCursorPosition(output, pos);
            MapDraw(map); // ���� �ٽ� �׸�
        }
        Sleep(50); // ���� �̵� �ӵ� ����
    }

    score = 0; // ���� ���� �� ���� �ʱ�ȭ
}

void stage2(void)
{
    int map[HEIGHT][WIDTH] = { 0 };


    srand((unsigned)time(NULL));

    map_reset(map);
    Init(map);

    while (run)
    {
        Star_Update(map);
        MapDraw(map);
        PlayerMove(map);

        if (score > 200)
        {
            
            stage3draw();
        }
        Sleep(50);
    }
}
