// this is dumb.. but im gonna try to make an agario clone...
// This is completely bare-bones C language. This is a pretty pointless project... but I felt
// -- that i needed something a little more 'fun' to get used to C syntax.
// I acknowledge that i would probably never build any actual games with c.

// will write gameboard with periods ......... and a 0 for the player
// o for small player.
// O is health > 100.
// will get scanf input. W A S D to move player
// should write game board with multi dimensional array

// Y = row
// X = column



/*	Next Steps:

	1) players should be able to eat eachother
	2) 2 player mode?
	3) difficulty selects amnt of computer players
	4) player can collect semicolons to increase health
	5) if health > enemy eat enemy on collision
	6) bigger game board.
	7) once health hits a certain level, o becomes O
	7) player can split into multiple o's once we reach big O
	8) those little o's can still eat
	9) random spawns for enemies
	10) random spawns for semicolons(food)
	11) maybe something like (1) = player with health 1 and (50) = player with 50 health
		-- would work better for a player model. would need to use pointers and strings...
	12) break functions down a little.
	13) different levels

	*/




		/*			GLOBAL VARIABLES		*/
	char gameSpace[16][16] = {
	//    0   1   2   3   4   5   6   7   8   9   10  11  12  13  14
		{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},	// 0
		{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},	// 1
		{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},	// 2
		{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},	// 3
		{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},	// 4
		{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},	// 5
		{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},	// 6
		{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},	// 7
		{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},	// 8
		{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},	// 9
		{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},	// 10
		{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},	// 11
		{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},	// 12
		{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},	// 13
		{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'}	// 14

		};

#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main (void)
{


	int ctr = 1;

	// type declarations
	void welcome(void);
	void setPlayer(void);
	void setEnemy(void);
	void displaySpace(void);
	void playerMove(void);
	void enemyMove(void);
	void setFood(int n);

	welcome();

	setPlayer();
	setEnemy();

	displaySpace();



	do {
	playerMove();
	displaySpace();


	enemyMove();
	displaySpace();
	ctr++;

	} while (ctr != 10);	// ctr is amnt of rounds...



	return (0);
}

void welcome(void)
{

	printf("Welcome to Agario!!");
	printf("When you are asked to make a move, enter: w, a, s, or d.\n");
	printf("For moving: up(w), down(s), left(a), or right(d).\n");
	printf("Let's begin... \n\n");
	printf("Setting Player and Generaing random Enemies.....\n\n\n");
}

void displaySpace(void)
{
	int y, x;

	for (y = 0; y < 16; y++ )
	{
		printf("\n");
		for (x = 0; x < 16; x++ )
			printf("%4c", gameSpace[y][x]);
	}

	printf("\n\n");
}

void setPlayer(void)
{
	// Player always starts in middle...
	gameSpace[4][4] = 'o';
}


void setFood(int n)
{
	
	// Whatever number is passed to n will decide how many bits of food will be made
	
	time_t t;	// for random seed
	srand((unsigned) time(&t));	// sets random seed to time

	int i;
	int x = 0, y = 0;
	
	
	for (i = 0; i < n; i++)
	{

		x = rand() % 15;
		y = rand() % 15;


	gameSpace[x][y] = 'f';

	}
}

void setEnemy(void)
{
	// Set Enemy at random dimensions...
   	time_t t;	// for random seed
	srand((unsigned) time(&t));	// sets random seed to time

	int x;
	int y;

	y = rand() % 15;	// rand num btwn 1 - 10
	x = rand() % 15;

	gameSpace[y][x] = 'e';


}




void playerMove(void)
{


	// Type Dec
	int findCurrentY(void);
	int findCurrentX(void);

	// local variablse
	int newY, newX;
	int returnY, returnX;
    char move;

	printf("\nMake a move!   :   ");
	scanf(" %c", &move);

	// wont actually work.... need seperate funcions maybe

	returnY = findCurrentY();		// function to find where player currently is..  returns row(x) + column(y)
	returnX = findCurrentX();


	if (move == 'w')
	{
		newY = returnY - 1;
		newX = returnX;
		// move up
	}
	else if (move == 'a')
	{
		newY = returnY;
		newX = returnX - 1;
		// move left
	}
	else if (move == 's')
	{
		newY = returnY + 1;
		newX = returnX;
		// move down
	}
	else if (move == 'd')
	{

		newY = returnY;
		newX = returnX + 1;
		// move right
	}

	gameSpace[newY][newX] = 'o'; // Set New position...
	gameSpace[returnY][returnX] = '.'; // Reset Prev position....


}



void enemyMove(void)
{
	printf("Computer Player's Move!");
	// Type Decs
	int findCurrentY(void);
	int findCurrentX(void);
	int findEnemyY(void);
	int findEnemyX(void);

	// local vars
	int playerY, playerX;
	int enemyY, enemyX;
	int difY, difX;
    int tempY, tempX;


	// will move toward player
	playerY = findCurrentY();
	playerX = findCurrentX();

	enemyY = findEnemyY();
	enemyX = findEnemyX();

	tempY = enemyY;
	tempX = enemyX;

	difY = enemyY - playerY;	// set difference
	difX = enemyX - playerX;







	// make decisions based on the difference

	if (difY == 0)
	{
		// do nothing
	}
	else if (difY > 0)	// positive
	{
		enemyY--;		// move down
	}
	else				// negative
	{
		enemyY++;		// move up
	}






	if (difX == 0)
	{
		// do nothing
	}
	else if (difX > 0) // positive
	{
		enemyX--;		// left
	}
	else			   // negative
	{
		enemyX++;  		// right
	}




	//set new position on board
	gameSpace[enemyY][enemyX] = 'e';	// set new pos for enemy
	gameSpace[tempY][tempX] = '.'; 		// reset old pos



}

int findCurrentY(void)
{

	// need to loop through the multi dimen arrray, and if we find a o. stop loop there, and return the dimensions of the space.
	int x, y;
	int resultY;

	for ( y = 0; y < 16; y++ )
	{
		for ( x = 0; x < 16; x++)
		{
			if (gameSpace[y][x] == 'o')
			{
				resultY = y;
			}
		}
	}

	return (resultY);		// returns the dimensions it found

}

int findCurrentX(void)
{

	// need to loop through the multi dimen arrray, and if we find a o. stop loop there, and return the dimensions of the space.
	int x, y;
	int resultX;

	for ( y = 0; y < 16; y++ )
	{
		for ( x = 0; x < 16; x++)
		{
			if (gameSpace[y][x] == 'o')
			{
				resultX = x;
			}
		}
	}

	return (resultX);		// returns the dimensions it found

}
int findEnemyY(void)
{

	// need to loop through the multi dimen arrray, and if we find a o. stop loop there, and return the dimensions of the space.
	int x, y;
	int resultY;

	for ( y = 0; y < 16; y++ )
	{
		for ( x = 0; x < 16; x++)
		{
			if (gameSpace[y][x] == 'e')
			{
				resultY = y;
			}
		}
	}

	return (resultY);		// returns the dimensions it found

}


int findEnemyX(void)
{

	// need to loop through the multi dimen arrray, and if we find a o. stop loop there, and return the dimensions of the space.
	int x, y;
	int resultX;

	for ( y = 0; y < 16; y++ )
	{
		for ( x = 0; x < 16; x++)
		{
			if (gameSpace[y][x] == 'e')
			{
				resultX = x;
			}
		}
	}

	return (resultX);		// returns the dimensions it found

}
