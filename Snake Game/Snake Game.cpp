// Snake Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include <conio.h>


using namespace std;

const int width = 20;
const int height = 20;

int x, y, fruitx, fruity, score;

int tailX[100], tailY[100];
int nTail;

enum eDirection
{
    STOP = 0, LEFT, RIGHT, UP, DOWN
};

eDirection dir;

bool gameOver;

void SetUp()
{
    
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitx = rand() % width;
    fruity = rand() % height;
}

void Draw() 
{
    system("cls");

    for(int i = 0; i <= width; i++)
        cout << "#";
    cout << endl;


    for (int i = 0; i <= height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)

                cout << "#";
            if (i == y && j == x)
                cout << "O";
            else if (i == fruity && j == fruitx)
                cout << "F";
            else
            {
                bool print = false;
                for (int k = 0; k < nTail; k++)
                {
                    
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        cout << "o";
                        print = true;
                    }
            
                }
                if (!print)
                    cout << " ";
                
            }

            if (j == width - 1)
                cout << "#";

            
        }
        cout << endl;
    }


    for (int i = 0; i <= width; i++)
        cout << "#";
    cout << endl;
    cout << "Score: " << score << endl;
}

void Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
            case 'a':
            dir = LEFT;
             break;
            case 'd':
                dir = RIGHT;
             break;
            case 'w':
                dir = UP;
             break;
            case 's':
                dir = DOWN;
                break;

            case 'x':
                gameOver = true;
                   break;
        }
    }
}



void Logic()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;

    for (int i = 1; i < nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
        tailX[0] = x;
        tailY[0] = y;


    }

    switch (dir)
    {
    case STOP:
        break;
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
        gameOver = true;
    if (x == fruitx && y == fruity)
    {
        score += 10;
        fruitx = rand() % width;
        fruity = rand() % height;
        nTail++;
    }
}

int main()
{
    SetUp();
    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
    }
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
