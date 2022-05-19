#include <iostream>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>

using namespace std;

const int N = 10;
int my_map[N][N] = { 0 };
char comp_map[N][N] = { 0 };
int x, y;


void  setup()
{
    srand(time(0));
    
    for (int i = 0; i < 4; i++)
    {
        x = rand() % N;
        y = rand() % N;
        comp_map[x][y] = 88;
    }

}

void draw()
{
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (my_map[j][i] == 0)
            {
                cout << "-";
            }
            else
            {
                cout << my_map[j][i];
            }
        }
        cout << endl;
    }
    cout << endl;

    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (comp_map[j][i] == 0)
            {
                cout << "-";
            }
            else
            {
                cout << comp_map[j][i];
            }
        }
        cout << endl;
    }
}

void logic()
{
   
    while (true)
    {
        cout << "Введіть координати ворожоко коробля по осі X" << endl;
        cin >> x;
        cout << "Введіть координати ворожоко коробля по осі Y" << endl;
        cin >> y;

        if (comp_map[x][y] == 88)
        {
            cout << "Ви попали." << endl;
            comp_map[x][y] = 0;

            
            bool detect = false;

            
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (comp_map[i][j] == 98)
                    {
                        detect = true;
                    }
                }
            }

            
            if (detect == false)
            {
                cout << "Ви перемогли!!" << endl;
                break;
            }
            
        }
        else
        {
            cout << "Ви не попали." << endl;
        }

    }
}

void input()
{

}

void main()
{
    setlocale(LC_ALL, "ukr");

    setup();
    draw();
    logic();
}