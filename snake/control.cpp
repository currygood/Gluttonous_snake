#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>
#include <ctype.h>
#include <random>

char key_down;
char rectang[50][50];
int snake_x[10], snake_y[10];
int n_snake=1;
int food_x , food_y;
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<int> distribution(2, 47);

void initialize();
void show();
void gameover();
void move_left();
void move_right();
void move_up();
void move_down();
void win();

int main()
{
	initialize();
	food_x = distribution(gen);
	food_y = distribution(gen);
	rectang[food_x][food_y] = '$';
	show();
	while (1)
	{
		if (snake_x[0] < 1 || snake_y[0] < 1 || snake_x[0] >48 || snake_y[0] >48)
		{
			gameover();
		}
		if (n_snake >= 10)
		{
			win();
		}
		key_down = _getch();
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
		show();
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
		putchar('\n');
	}
}

void move_left()
{
	int i;
	for (i = 1; i < n_snake; i++)
	{
		if (snake_y[0] - 1 == snake_y[i] && snake_x[0] == snake_x[i])
		{
			system("cls");
			printf("You can't eat yourself!");
			Sleep(5000);
			gameover();
		}
	}
	for (i = 0; i < n_snake; i++)
	{
		rectang[snake_x[i]][snake_y[i]] = ' ';
	}
	for (i = n_snake - 1; i > 0; i--)
	{
		snake_x[i] = snake_x[i - 1];
		snake_y[i] = snake_y[i - 1];
	}
	snake_y[0] -= 1;
	rectang[snake_x[0]][snake_y[0]] = '@';
	for (i = 1; i < n_snake; i++)
	{
		rectang[snake_x[i]][snake_y[i]] = '#';
	}
	if (food_x == snake_x[0] && food_y == snake_y[0])
	{
		snake_x[n_snake] = snake_x[n_snake - 1];
		snake_y[n_snake] = snake_y[n_snake - 1] + 1;
		rectang[snake_x[n_snake]][snake_y[n_snake]] = '#';
		n_snake += 1;
		food_x = distribution(gen);
		food_y = distribution(gen);
		rectang[food_x][food_y] = '$';
	}
}

void move_right()
{
	int i;
	for (i = 1; i < n_snake; i++)
	{
		if (snake_y[0] + 1 == snake_y[i] && snake_x[0] == snake_x[i])
		{
			system("cls");
			printf("You can't eat yourself!");
			Sleep(5000);
			gameover();
		}
	}
	for (i = 0; i < n_snake; i++)
	{
		rectang[snake_x[i]][snake_y[i]] = ' ';
	}
	for (i = n_snake - 1; i > 0; i--)
	{
		snake_x[i] = snake_x[i - 1];
		snake_y[i] = snake_y[i - 1];
	}
	snake_y[0] += 1;
	rectang[snake_x[0]][snake_y[0]] = '@';
	for (i = 1; i < n_snake; i++)
	{
		rectang[snake_x[i]][snake_y[i]] = '#';
	}
	if (food_x == snake_x[0] && food_y == snake_y[0])
	{
		snake_x[n_snake] = snake_x[n_snake - 1];
		snake_y[n_snake] = snake_y[n_snake - 1] - 1;
		rectang[snake_x[n_snake]][snake_y[n_snake]] = '#';
		n_snake += 1;
		food_x = distribution(gen);
		food_y = distribution(gen);
		rectang[food_x][food_y] = '$';
	}
}

void move_up()
{
	int i;
	for (i = 1; i < n_snake; i++)
	{
		if (snake_x[0] - 1 == snake_x[i] && snake_y[0] == snake_y[i])
		{
			system("cls");
			printf("You can't eat yourself!");
			Sleep(5000);
			gameover();
		}
	}
	for (i = 0; i < n_snake; i++)
	{
		rectang[snake_x[i]][snake_y[i]] = ' ';
	}
	for (i = n_snake - 1; i > 0; i--)
	{
		snake_x[i] = snake_x[i - 1];
		snake_y[i] = snake_y[i - 1];
	}
	snake_x[0] -= 1;
	rectang[snake_x[0]][snake_y[0]] = '@';
	for (i = 1; i < n_snake; i++)
	{
		rectang[snake_x[i]][snake_y[i]] = '#';
	}
	if (food_x == snake_x[0] && food_y == snake_y[0])
	{
		snake_x[n_snake] = snake_x[n_snake - 1] + 1;
		snake_y[n_snake] = snake_y[n_snake - 1];
		rectang[snake_x[n_snake]][snake_y[n_snake]] = '#';
		n_snake += 1;
		food_x = distribution(gen);
		food_y = distribution(gen);
		rectang[food_x][food_y] = '$';
	}
}

void move_down()
{
	int i;
	for (i = 1; i < n_snake; i++)
	{
		if (snake_x[0] + 1 == snake_x[i] && snake_y[0] == snake_y[i])
		{
			system("cls");
			printf("You can't eat yourself!");
			Sleep(5000);
			gameover();
		}
	}
	for (i = 0; i < n_snake; i++)
	{
		rectang[snake_x[i]][snake_y[i]] = ' ';
	}
	for (i = n_snake - 1; i > 0; i--)
	{
		snake_x[i] = snake_x[i - 1];
		snake_y[i] = snake_y[i - 1];
	}
	snake_x[0] += 1;
	rectang[snake_x[0]][snake_y[0]] = '@';
	for (i = 1; i < n_snake; i++)
	{
		rectang[snake_x[i]][snake_y[i]] = '#';
	}
	if (food_x == snake_x[0] && food_y == snake_y[0])
	{
		snake_x[n_snake] = snake_x[n_snake - 1] - 1;
		snake_y[n_snake] = snake_y[n_snake - 1];
		rectang[snake_x[n_snake]][snake_y[n_snake]] = '#';
		n_snake += 1;
		food_x = distribution(gen);
		food_y = distribution(gen);
		rectang[food_x][food_y] = '$';
	}
}

void initialize()
{
	int i, j;
	for (i = 0; i < 50; i++)
	{
		for (j = 0; j < 50; j++)
		{
			if (j == 0 || i == 0 || j == 49 || i == 49)
			{
				rectang[i][j] = '+';
			}
			else if (i == 1 && j == 1)
			{
				rectang[i][j] = '@';
			}
			else
			{
				rectang[i][j] = ' ';
			}
		}
	}
	//define snake head location;
	snake_x[0] = 1;
	snake_y[0] = 1;
}

void win()
{
	system("cls");
	printf("You win. Congration\n");
	exit(0);
}

void gameover()
{
	system("cls");
	printf("You loss. Game over\n");
	exit(0);
}