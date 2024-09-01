#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <graphics.h>
#include <Windows.h>
#include <ctype.h>
#include <random>

//头不能回头吃自己

char key_down;
char rectang[50][50];
int snake_x[10], snake_y[10];
int n_snake=1;
int food_x , food_y;
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<int> distribution(2, 48);

void initialize();
void show();
void gameover();
void move_left();
void move_right();
void move_up();
void move_down();
void snake_add();

int main()
{
	initialize();
	food_x = distribution(gen);
	food_y = distribution(gen);
	rectang[food_x][food_y] = '$';
	while (1)
	{
		if (n_snake >= 10)
		{
			gameover();
		}
		if (snake_x[0] < 1 || snake_y[0] < 1 || snake_x[0] >48 || snake_y[0] >48)
		{
			gameover();
		}
		show();
		key_down = _getch();
		if (food_x == snake_x[0] && food_y == snake_y[0])
		{
			snake_add();
			n_snake +=1;
			food_x = distribution(gen);
			food_y = distribution(gen);
			rectang[food_x][food_y] = '$';
		}
		switch (key_down)
		{
			case 27:
				gameover();
				break;

			case 'a':
				move_left();
				break;

			case 'w':
				move_up();
				break;

			case 'd':
				move_right();
				break;

			case 's':
				move_down();
				break;

			default:
				break;
		}
		system("cls");
	}
	return 0;
}

void show()
{
	int i, j;
	for (i = 0; i < 50; i++)
	{
		for (j = 0; j < 50; j++)
		{
			putchar(rectang[i][j]);
		}
		printf("\n");
	}
}

void move_left()
{
	if (snake_y[0] - 1 == snake_y[1])
	{
		system("cls");
		printf("You can't eat yourself!");
		Sleep(5000);
		gameover();
	}
	int i;
	if (n_snake == 1)
	{
		rectang[snake_x[0]][snake_y[0]] = ' ';
		snake_y[0] -= 1;
		rectang[snake_x[0]][snake_y[0]] = '@';
		return;
	}
	for (i = 0; i < n_snake; i++)
	{
		rectang[snake_x[i]][snake_y[i]] = ' ';
	}
	for (i = n_snake - 1; i >= 0; i--)
	{
		snake_x[i + 1] = snake_x[i];
		snake_y[i + 1] = snake_y[i];
	}
	snake_y[0] -= 1;
	for (i = 0; i < n_snake; i++)
	{
		if (i == 0)
		{
			rectang[snake_x[i]][snake_y[i]] = '@';
		}
		else
		{
			rectang[snake_x[i]][snake_y[i]] = '#';
		}
	}
}


void move_right()
{
	if (snake_y[0] + 1 == snake_y[1])
	{
		system("cls");
		printf("You can't eat yourself!");
		Sleep(5000);
		gameover();
	}
	int i;
	if (n_snake == 1)
	{
		rectang[snake_x[0]][snake_y[0]] = ' ';
		snake_y[0] += 1;
		rectang[snake_x[0]][snake_y[0]] = '@';
		return;
	}
	for (i = 0; i < n_snake; i++)
	{
		rectang[snake_x[i]][snake_y[i]] = ' ';
	}
	for (i = n_snake - 1; i >= 0; i--)
	{
		snake_x[i + 1] = snake_x[i];
		snake_y[i + 1] = snake_y[i];
	}
	snake_y[0] += 1;
	for (i = 0; i < n_snake; i++)
	{
		if (i == 0)
		{
			rectang[snake_x[i]][snake_y[i]] = '@';
		}
		else
		{
			rectang[snake_x[i]][snake_y[i]] = '#';
		}
	}
}


void move_up()
{
	if (snake_x[0] - 1 == snake_x[1])
	{
		system("cls");
		printf("You can't eat yourself!");
		Sleep(5000);
		gameover();
	}
	int i;
	if (n_snake == 1)
	{
		rectang[snake_x[0]][snake_y[0]] = ' ';
		snake_x[0] -= 1;
		rectang[snake_x[0]][snake_y[0]] = '@';
		return;
	}
	for (i = 0; i < n_snake; i++)
	{
		rectang[snake_x[i]][snake_y[i]] = ' ';
	}
	for (i = n_snake - 1; i >= 0; i--)
	{
		snake_x[i + 1] = snake_x[i];
		snake_y[i + 1] = snake_y[i];
	}
	snake_x[0] -= 1;
	for (i = 0; i < n_snake; i++)
	{
		if (i == 0)
		{
			rectang[snake_x[i]][snake_y[i]] = '@';
		}
		else
		{
			rectang[snake_x[i]][snake_y[i]] = '#';
		}
	}
}


void move_down()
{ 
	if (snake_x[0] + 1 == snake_x[1])
	{
		system("cls");
		printf("You can't eat yourself!");
		Sleep(5000);
		gameover();
	}
	int i;
	if (n_snake == 1)
	{
		rectang[snake_x[0]][snake_y[0]] = ' ';
		snake_x[0] += 1;
		rectang[snake_x[0]][snake_y[0]] = '@';
		return;
	}
	for (i = 0; i < n_snake; i++)
	{
		rectang[snake_x[i]][snake_y[i]] = ' ';
	}
	for (i = n_snake-1; i >= 0; i--)
	{
		snake_x[i+1] = snake_x[i];
		snake_y[i + 1] = snake_y[i];
	}
	snake_x[0] += 1;
	for (i = 0; i < n_snake; i++)
	{
		if (i == 0)
		{
			rectang[snake_x[i]][snake_y[i]] = '@';
		}
		else
		{
			rectang[snake_x[i]][snake_y[i]] = '#';
		}
	}
}

void snake_add()
{
	snake_x[n_snake] = snake_x[n_snake - 1];
	snake_y[n_snake] = snake_y[n_snake - 1] - 1;
	rectang[snake_x[n_snake]][snake_y[n_snake]] = '#';
}

void initialize()
{
	int i, j;
	for (i = 0; i < 50; i++)
	{
		for (j = 0; j < 50; j++)
		{
			if (j == 0 || i==0 || j==49 || i==49)
			{
				rectang[i][j] ='+';
			}
			else if (i==1 && j==1)
			{
				rectang[i][j] = '@';
			}
			else
			{
				rectang[i][j] =' ';
			}
		}
	}
	//define snake head location;
	snake_x[0] = 1;
	snake_y[0] = 1;
}

void gameover()
{
	initgraph(150, 150);
	TCHAR over[] = _T("GameOver!");
	outtextxy(0, 0, over);
	Sleep(5000);
	closegraph();
	exit(0);
}