#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include <stdbool.h>
#include "teamplus.h"
#define pgbut 0  //壱舛敗呪
#define pgrbut 79 
#define meetbut 0


void GotoXY(int x, int y)  //疎妊葵舛税
{
    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int GetKeyDown();  //徹逢舛税


void pinger(int pgX)  //謝亜喰 嬬車妊獣
{
    GotoXY(pgX, 12);
    printf("  けけけけしけけ      ");
    GotoXY(pgX, 13);
    printf("  けけけけしけけけけ  ");
    GotoXY(pgX, 14);
    printf("  けけけけし          ");
    GotoXY(pgX, 15);
    printf("  けけけし            ");

}

void pingerRight(int pgrX)  //謝亜喰 嬬車妊獣
{
    GotoXY(pgrX, 12);
    printf("     けけしけけけけ   ");
    GotoXY(pgrX, 13);
    printf(" けけけけしけけけけ   ");
    GotoXY(pgrX, 14);
    printf("         しけけけけ   ");
    GotoXY(pgrX, 15);
    printf("           しけけけ ");

}
void meeting(int meety)  //亀較嬬車妊獣
{
    GotoXY(20, meety);
    printf("けけけけけけけけけけけけけけけけけけけけけけけけけけけけけけ");
    GotoXY(20, meety + 1);
    printf("[            '                                             ]");
    GotoXY(20, meety + 2);
    printf(" )                              '                         ( ");
    GotoXY(20, meety + 3);
    printf("[                                                '         ]");
    GotoXY(20, meety + 4);
    printf("けけけけけけけけけけけけけけけけけけけけけけけけけけけけけけ");

}

bool isCollision(const int pgX, const int meety)  //中宜葵敗呪
{
    if (meety <= 14 && meety >= 12 && pgX > 3) //戚繕闇 幻膳獣
    {
        return true;
    }
    return false;
}
void firstwindow(void);
void gameover(void);
void gameclear(void);

void  stage5(void) //五昔敗呪
{

    bool uppg = false;  //舛岩雌殿
    bool isBottom = true;  //神岩雌殿
    const int gravity = 4;  //謝亜喰 崇送績 壱舛葵
    int score = 0;
    int i = 100;


    int pgX = pgbut;  //壱舛敗呪 企脊
    int pgrX = pgrbut;
    int meety = meetbut;

    int endTime = (unsigned)time(NULL);
    endTime += 10;
    while (true)  //鋼差庚
    {
        int startTime = (unsigned)time(NULL);
        GotoXY(80, 0);
        printf("%d段 \n", endTime - startTime);
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
                uppg = true;  //醗失鉢
                isBottom = false;  //搾醗失鉢
            }
            break;
        }
        if (uppg)  
        {
            pgX += gravity;    //舛岩戚檎 装亜
            pgrX -= gravity;
        }
        else
        {
            pgX -= gravity;  //神岩戚檎 姶社
            pgrX += gravity;
        }
        if (pgX <= pgbut)  // 謝亜喰戚x但聖 込嬢蟹檎
        {
            pgX = pgbut;  //謝亜喰 是帖壱舛
            isBottom = true;  //舛岩坦軒
        }
        if (pgrX >= pgrbut)  // 謝亜喰戚x但聖 込嬢蟹檎
        {
            pgrX = pgrbut;  //謝亜喰 是帖壱舛
        }
        if (pgX >= 4)  //謝亜喰戚 析舛 戚雌 角嬢哀形檎
        {
            uppg = false;  //神岩坦軒
        }
        meety += 2;  //亀較 2梢装亜
        if (meety >= 24)  //焼掘混拭 恭嬢走檎
        {
            system("cls");
            gameover();
            system("cls");
            firstwindow();
        }
        if (meety <= 11 && pgX > 3)  //亀較戚 謝亜喰拭 願奄穿拭 胡煽 喚軒檎 
        {
            system("cls");
            gameover();
            system("cls");
            firstwindow();
        }
        if (isCollision(pgX, meety))  //亀較戚 謝亜喰引 窒宜獣
        {
            meety = meetbut;  //亀較軒実
            score++; //繊呪装亜
        }
        if (score > 4)  //5腰失因獣
        {         
            gameclear();
            system("pause");
            system("cls");
            firstwindow();
            
        }
        if (score == 1)  //紗亀 装亜
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

        pinger(pgX); //謝亜喰聖 啄嬢虞
        meeting(meety);  //亀較聖 啄嬢虞
        pingerRight(pgrX);
        Sleep(i);  //渠傾戚
        system("cls");  //嬬車 適軒嬢
        GotoXY(40, 0);
        printf("Score : %d ", score); //繊呪 窒径
    }

    return;
}

