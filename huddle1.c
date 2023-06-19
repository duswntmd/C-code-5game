#include<stdio.h>
#include<windows.h>
#include<stdbool.h>
#include<conio.h>
#include<time.h>
#include "teamplus.h"
//#include <mmsystem.h>

//#pragma comment(lib,"winmm.lib")
#define HUMAN_BOTTOM_X 7
#define HUMAN_BOTTOM_Y 12
#define TREE_BOTTOM_Y 14
#define TREE_BOTTOM_X 57

#define wallbut_Y 12
#define wallbut_X 0

#define exitdoor_X 45


//�ܼ� â�� ũ��� ������ �����ϴ� �Լ�
void SetConsoleView()
{
    system("mode con:cols=100 lines=25");
    system("title Google Dinosaurs. By LHS.");
}

//Ŀ���� ��ġ�� x, y�� �̵��ϴ� �Լ�
void GotoXy(int x, int y)
{
    COORD Pos;
    Pos.X = 2 * x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void firstwindow(void);
void stage4draw(void);
void gameover(void);

void DrawHuman(int humanX, int humanY, bool isJumping)
{
    GotoXy(humanX, humanY);
    printf("  @  \n");
    GotoXy(humanX, humanY + 1);
    printf("@ @ @\n");
    if (isJumping) {
        GotoXy(humanX, humanY + 2);
        printf("  @  \n");
        GotoXy(humanX, humanY + 3);
        printf("@   @\n");
    }
    else if (humanX % 2 == 0) {
        GotoXy(humanX, humanY + 2);
        printf("  @ @\n");
        GotoXy(humanX, humanY + 3);
        printf("@    \n");
    }
    else if (humanX % 2 == 1) {
        GotoXy(humanX, humanY + 2);
        printf("@ @  \n");
        GotoXy(humanX, humanY + 3);
        printf("    @\n");
    }


}


//������ �׸��� �Լ�
void DrawTree(int treeX)
{
    GotoXy(treeX, TREE_BOTTOM_Y);
    printf("$$$");
    GotoXy(treeX, TREE_BOTTOM_Y + 1);
    printf(" $ ");
}

void wall(int wallX, int wally)  //�ֿܼ� ��ǥ��
{
    GotoXy(wallX, wally);
    printf("��");
    GotoXy(wallX, wally + 1);
    printf("�� ��");
    GotoXy(wallX, wally + 2);
    printf("�� �� ��");
    GotoXy(wallX, wally + 3);
    printf("�� ��");
    GotoXy(wallX, wally + 4);
    printf("��");

}

//(v2.0) �浹 ������ ���ӿ��� �׷���
void DrawClear() {
    system("cls");
    int x = 18;
    int y = 8;
    GotoXy(x, y);
    printf("===========================");
    GotoXy(x, y + 1);
    printf("======G A M E C L E A R======");
    GotoXy(x, y + 2);
    printf("===========================");
}

void DrawGameOver()
{
    system("cls");
    int x = 18;
    int y = 8;
    GotoXy(x, y);
    printf("===========================");
    GotoXy(x, y + 1);
    printf("======G A M E O V E R======");
    GotoXy(x, y + 2);
    printf("===========================");

    //PlaySound(TEXT("fall.wav"), 0, SND_ASYNC | SND_LOOP);

    printf("\n\n\n\n\n\n\n\n\n");
    system("pause");
}
void Draw_exit(int exitX) {
    GotoXy(exitX, 10);
    printf(" @@");
    GotoXy(exitX, 11);
    printf("@  @");
    GotoXy(exitX, 12);
    printf("@  @");
    GotoXy(exitX, 13);
    printf("@  @");
    GotoXy(exitX, 14);
    printf("@  @");
    GotoXy(exitX, 15);
    printf(" @@");
}

//(v2.0) �浹������ true, �ƴϸ� false
bool isCollisionn(const int treeX, const int humanX, const int humanY)
{
    //Ʈ���� X�� human�� ��ü�ʿ� ������,
    //human�� ���̰� ������� �ʴٸ� �浹�� ó��
    
    if (treeX <= humanX + 3 && treeX >= humanX + 1 &&
        humanY > 9)
    {
        return true;
    }
    return false;
}
//void stage5(void);
void stage1(void)
{
    SetConsoleView();

    bool isMove = false;
    //const int gravity = 1;     //�� �ӵ� �����Լ�
    int wally = wallbut_Y;
    double wallX = wallbut_X;
    int exitX = exitdoor_X;

    while (true)        //(v2.0) ���� ����
    {
        mciSendString(TEXT("open \"gaming.wav\" type mpegvideo alias gaming"), NULL, 0, NULL); //��� ���� ����
        mciSendString(TEXT("play gaming repeat"), NULL, 0, NULL); //������� �ݺ� ���
        //���� ���۽� �ʱ�ȭ
        bool isJumping = false;
        bool isBottom = true;
        const int gravity = 3;

        int humanX = HUMAN_BOTTOM_X;
        int humanY = HUMAN_BOTTOM_Y;
        int treeX = TREE_BOTTOM_X;

        int endTime = (unsigned)time(NULL);
        endTime += 10;
        //PlaySound(TEXT("test.wav"), 0, SND_ASYNC | SND_LOOP);
        while (true)    //�� �ǿ� ���� ����
        {
            int startTime = (unsigned)time(NULL);
            GotoXy(80, 0);
            printf("%d�� \n", endTime - startTime);
            Sleep(1);
            if (endTime - startTime == 0) {
                gameover();
                
                firstwindow();
            }
            
            // �浹üũ Ʈ���� x���� human�� y������ �Ǵ�
            if (isCollisionn(treeX, humanX, humanY)) {
                system("cls");
                gameover();
                system("cls");
                firstwindow();
            }

            int key = GetKeyDown();

            switch (key)
            {
            case 4: //������ ==������
                humanX += 1;
                break;
            case 3: //����
                humanX -= 1;
                break;
            case 1: //���� =����
                if (isBottom) {
                    isJumping = true;
                    isBottom = false;
                    mciSendString(TEXT("open \"Jumping.wav\" type mpegvideo alias Jumping"), NULL, 0, NULL); //ȿ���� ����
                    mciSendString(TEXT("play jumping from 0 to 1000"), NULL, 0, NULL); //������� �ݺ� ���
                }
                break;
            }
            //�������̶�� Y�� ����, ������ �������� Y�� ����.
            if (isJumping)
            {
                humanY -= gravity;
            }
            else
            {
                humanY += gravity;
            }

            //Y�� ����ؼ� �����ϴ°� �������� �ٴ��� ����.
            if (humanY >= HUMAN_BOTTOM_Y)
            {
                humanY = HUMAN_BOTTOM_Y;
                isBottom = true;
            }

            //������ �������� (x����) �������ϰ�
            //������ ��ġ�� ���� �����ΰ��� �ٽ� ������ ������ ��ȯ.
            treeX -= 2;
            if (treeX <= 0)
            {
                treeX = TREE_BOTTOM_X;
            }

            //������ ������ ������ ������ ���� ��Ȳ.
            if (humanY <= 7)
            {
                isJumping = false;
            }

            wallX += 0.4;//���̵��ӵ�
            if (wallX + 3 >= humanX) {

                wallX = wallbut_X;
                system("cls");
                gameover();
                system("cls");
                firstwindow();

            }
            if (exitX == humanX) {

                stage2draw();
            }

            DrawHuman(humanX, humanY, isJumping);    //draw human
            DrawTree(treeX);        //draw Tree
            wall(wallX, wally);
            Draw_exit(exitX);


            Sleep(60);
            system("cls");    //clear
        }
        DrawGameOver();
    }

    return;
}