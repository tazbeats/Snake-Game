#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
bool gameOver;
const int width = 50;
const int height = 25;
int x, y, fruitA, fruitB, score;
int endA[100], endB[100];
int endc;
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirecton dir;
void Setup()
{
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitA = rand() % width;
    fruitB = rand() % height;
    score = 0;
}
void Draw()
{
    system("cls"); //system("clear");
    for (int i = 0; i < width + 2; i++)
        cout << "_";
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                cout << "|";
            if (i == y && j == x)
                cout << "0";
            else if (i == fruitB && j == fruitA)
                cout << "$";
            else
            {
                bool print = false;
                for (int k = 0; k < endc; k++)
                {
                    if (endA[k] == j && endB[k] == i)
                    {
                        cout << "0";
                        print = true;
                    }
                }
                if (!print)
                    cout << " ";
            }


            if (j == width - 1)
                cout << "|";
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)
        cout << "_";
    cout << endl;
    cout << "Score:" << score << endl;
}
void Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case '4':
            dir = LEFT;
            break;
        case '6':
            dir = RIGHT;
            break;
        case '8':
            dir = UP;
            break;
        case '2':
            dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            cout << "Game Over \n";
            cout << "press F to pay Respects\n";
            cout << "Better Luck Next Time : )\n";
            cout << "Project by Aaish Ahmed and Talha Zia  ";
            break;
        }
    }
}
void Logic()
{
    int prevX = endA[0];
    int prevY = endB[0];
    int prev2X, prev2Y;
    endA[0] = x;
    endB[0] = y;
    for (int i = 1; i < endc; i++)
    {
        prev2X = endA[i];
        prev2Y = endB[i];
        endA[i] = prevX;
        endB[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }
    if (x > width || x < 0 || y > height || y < 0)
    {
        gameOver = true;
        cout << "Game Over \n";
        cout << "press F to pay Respect\n";
        cout << "Better Luck Next Time : )\n";
        cout << "Project by Aaish Ahmed and Talha Zia  ";
    }
    //if (x > 50 || y > 25)
    //{
        //gameOver = true;
        //cout << "Game Over \n";
        //cout << "press F to pay Respect\n";
        //cout << "Better Luck Next Time : )\n";
       // cout << "Project by Aaish Ahmed and Talha Zia  ";
    //}
    if (x >= width) x = 0; else if (x < 0) x = width - 1;
    if (y >= height) y = 0; else if (y < 0) y = height - 1;

    for (int i = 0; i < endc; i++)
        if (endA[i] == x && endB[i] == y)
            gameOver = true;

    if (x == fruitA && y == fruitB)
    {
        score += 10;
        fruitA = rand() % width;
        fruitB = rand() % height;
        endc++;
    }
    }
int main()
{
    Setup();
    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
        Sleep(100); //sleep(100);
    }_getch();
    return 0;
}