// Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>


using namespace std;

bool isOver;

const int width = 20;
const int height = 20;
int x, y,fruitX,fruitY,score;
int tailX[100], tailY[100];
int nTail; //length of the tail

enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

void setup()
{
    //Initializing the positions of the snake and the fruit.
    isOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;

    fruitX = rand() % width;
    fruitY = rand() % height;

}
void draw()
{
    //Drawing the map 
    system("cls");
    for (int i = 0; i < width+2; i++)
    {
        cout << "#";
    }
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                cout << "#";
            if (i == y && j == x)
                cout << "O";
            else if (i == fruitY && fruitX == j)
                cout << "F";
            else 
            {
                bool printed = false;
                for (int k = 0; k < nTail; k++)
                {
                   
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        cout << "o";
                        printed = true;
                    }
                }
                if (!printed)
                    cout << " ";
             
            }
                

            if (j == width - 1)
                cout << "#";
        }
        cout << endl;
    }

    for (int i = 0; i < width+2; i++)
    {
        cout << "#";
    }
    cout << endl;

    cout << "Score " << score << endl;
    cout << "Position: " << x << y<< endl;

}

void input()
{
    /*
        Handling the input
    */
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
            isOver = true;
            break;
        default:
            break;
        }
    }

}
void logic() 
{
    /*
    Movement and collision checking
    */
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
  
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
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
        y --;
        break;
    case DOWN:
        y += 1;
        break;
    default:
        break;
    }

    for (int i = 0; i < nTail; i++)
    {
        if (tailX[i] == x && tailY[i] == y)
            isOver = true;
    }
    if (x > width || x < 0 || y > height || y < 0)
      //  isOver = true;
    if (x >= width) x = 0; else if(x<0) x = width - 1;
    if (y >= height) y = 0; else if(y<0) y = height - 1;
    if (x == fruitX && y == fruitY)
    {

        score += 5;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }


}
void gameLoop()
{
    isOver = false;
    setup();
    while (!isOver)
    {
        draw();
        input();
        logic();
    }
}
int main()
{
    
    gameLoop();
 
    
   
   // std::cout << "Hello World!\n";
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
