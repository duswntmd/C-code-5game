#include<stdio.h>
#include<windows.h>

#include <mmsystem.h> //playsound�� ����ϱ� ���ؼ�
#pragma comment(lib,"winmm.lib") //������ ���̺귯�� �ʿ���
#include "Digitalv.h"

void GotoXY(int x, int y);
void stage1(void);
void stage2(void);
void stage3(void);
void stage4(void);
void stage5(void);
void stage1draw(void)
{
    int x = 25;
    system("cls");
    GotoXY(x, 8);
    printf("  ###   #####     #       #####    #####     #####");
    GotoXY(x, 9);
    printf(" #        #      # #     #         #           #   ");
    GotoXY(x, 10);
    printf("  ###     #     # # #    #   ###   #####       #   ");
    GotoXY(x, 11);
    printf("     #    #    #     #   #     #   #           #   ");
    GotoXY(x, 12);
    printf("  ###     #    #     #    #### #   #####     ##### ");
    GotoXY(x, 14);
    printf("     ���ѱ� : ��ֹ��� ���� �������� �����Ͻÿ�." );
    Sleep(3000);
    stage1();
}
void stage2draw(void)
{
    int x = 25;
    system("cls");
    GotoXY(x, 8);
    printf("  ###   #####     #       #####    #####     #####");
    GotoXY(x, 9);
    printf(" #        #      # #     #         #          # # ");
    GotoXY(x, 10);
    printf("  ###     #     # # #    #   ###   #####      # # ");
    GotoXY(x, 11);
    printf("     #    #    #     #   #     #   #          # # ");
    GotoXY(x, 12);
    printf("  ###     #    #     #    #### #   #####     #####");
    GotoXY(x, 14);
    printf("    �� ���ϱ� : ��ǥ���� 200������ ��� �����ÿ�"  );
    Sleep(1000);
    stage2();
}
void stage3draw(void)
{
    int x = 25;
    system("cls");
    GotoXY(x, 8);
    printf("  ###   #####     #       #####    #####     #######");
    GotoXY(x, 9);
    printf(" #        #      # #     #         #          # # #");
    GotoXY(x, 10);
    printf("  ###     #     # # #    #   ###   #####      # # #");
    GotoXY(x, 11);
    printf("     #    #    #     #   #     #   #          # # #");
    GotoXY(x, 12);
    printf("  ###     #    #     #    #### #   #####     #######");
    GotoXY(x, 14);
    printf(" �����̰��� : ������(4��)�� ȹ���Ͽ� Ŭ���� �Ͻÿ�"  );
    Sleep(1000);
    stage3();
}
void stage4draw(void)
{
    int x = 15;
    system("cls");
    GotoXY(x, 8);
    printf("  ###   #####     #       #####    #####     #####   #        #");
    GotoXY(x, 9);
    printf(" #        #      # #     #         #           #      #      #");
    GotoXY(x, 10);
    printf("  ###     #     # # #    #   ###   #####       #       #    #");
    GotoXY(x, 11);
    printf("     #    #    #     #   #     #   #           #        #  #");
    GotoXY(x, 12);
    printf("  ###     #    #     #    #### #   #####     #####       ##");
    GotoXY(x, 14);
    printf("     ��Ʈ���� : �ټ��� �ϼ��� Ŭ�����Ͻÿ�                   ");
    Sleep(1000);
    stage4();
}
void stage5draw(void)
{
    int x = 25;
    system("cls");
    GotoXY(x, 8);
    printf("  ###   #####     #       #####    #####    #        #");
    GotoXY(x, 9);
    printf(" #        #      # #     #         #         #      #");
    GotoXY(x, 10);
    printf("  ###     #     # # #    #   ###   #####      #    #");
    GotoXY(x, 11);
    printf("     #    #    #     #   #     #   #           #  #");
    GotoXY(x, 12);
    printf("  ###     #    #     #    #### #   #####        ##");
    GotoXY(x, 14);
    printf("     ���Ӱ��� : Ÿ�̹�(5��) ���߾� Ŭ����            ");
    Sleep(1000);
    stage5();
}

void gameclear(void) {

    int x = 15;
    system("cls");
    GotoXY(x, 8);
    printf("  #####      #      #     #   #####    #####   #        #####      #      #####    ");
    GotoXY(x, 9);
    printf(" #          # #     ##   ##   #       #        #        #         # #     #    #   ");
    GotoXY(x, 10);
    printf(" #   ###   # # #    # # # #   #####   #        #        #####    # # #    #####    ");
    GotoXY(x, 11);
    printf(" #     #  #     #   #  #  #   #       #        #        #       #     #   #    #   ");
    GotoXY(x, 12);
    printf("  #### #  #     #   #     #   #####    #####   ######   #####   #     #   #     #  ");
    GotoXY(x, 14);
    mciSendString(TEXT("close gaming"), NULL, 0, NULL); //��� ���� �ݱ�
    mciSendString(TEXT("open \"gameclear.wav\" type mpegvideo alias gameclear"), NULL, 0, NULL); //��� ���� ����
    mciSendString(TEXT("play gameclear repeat"), NULL, 0, NULL); //������� �ݺ� ���

    Sleep(3000);
    mciSendString(TEXT("close gameclear"), NULL, 0, NULL); //��� ���� �ݱ�
    mciSendString(TEXT("open \"gamemain.wav\" type mpegvideo alias gamemain"), NULL, 0, NULL); //��� ���� ����
    mciSendString(TEXT("play gamemain repeat"), NULL, 0, NULL); //������� �ݺ� ���
    
}

void gameover(void) {

    int x = 25;
    system("cls");
    GotoXY(x, 8);
    printf(" #####       #      #     #   #####    #####    #     #   #####   #####   ");
    GotoXY(x, 9);
    printf("#           # #     ##   ##   #       #     #   #     #   #       #    #  ");
    GotoXY(x, 10);
    printf("#   ###    # # #    # # # #   #####   #     #    #   #    #####   #####   ");
    GotoXY(x, 11);
    printf("#     #   #     #   #  #  #   #       #     #     # #     #       #    #  ");
    GotoXY(x, 12);
    printf(" #### #   #     #   #     #   #####    #####       #      #####   #     # ");
    GotoXY(x, 14);


    mciSendString(TEXT("close gaming"), NULL, 0, NULL); //��� ���� �ݱ�
    mciSendString(TEXT("open \"byebyeSound.wav\" type mpegvideo alias byebyeSound"), NULL, 0, NULL); //��� ���� ����
    mciSendString(TEXT("play byebyeSound"), NULL, 0, NULL); //������� �ݺ� ���
    Sleep(2000);
    mciSendString(TEXT("close byebyeSound"), NULL, 0, NULL); //��� ���� �ݱ�

}
