// This is completely bare-bones C language. 

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
	9) random spawns for enemies (DONE)
	10) random spawns for semicolons(food) (DONE)
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


	// type declarations
	void welcome(void);
	void customGame(void);


	welcome();
	
	customGame();


	return (0);
}

void welcome(void)
{
	printf("\n========================\n");
	printf("Welcome to Agario!!");
	printf("\n=========================\n");
	printf("When you are asked to make a move, enter: w, a, s, or d.\n");
	printf("For moving: up(w), down(s), left(a), or right(d).\n");
	printf("Food will generate at random as you play.\n");
	printf("Your Goal: Eat as much stuff as possible!\n");
	printf("Let's begin... \n\n");
	printf("Setting Player and Generaing random Enemies.....\n\n\n");
}


void customGame(void)
{

	// Vars
	int ctr = 0;
	int numRounds, foodGen;


	// Prototype Declarations
	int setRounds(void);
	int setFoodGen(void);
	void setPlayer(void);
	void setEnemy(void);
	void displaySpace(void);
	void playerMove(void);
	void enemyMove(void);
	void setFood(int n);






	numRounds = setRounds();
	foodGen = setFoodGen();

	setPlayer();
	setEnemy();

	displaySpace();



	do {

	playerMove();
	displaySpace();

	setFood(foodGen);

	enemyMove();
	displaySpace();
	ctr++;

	} while (ctr != numRounds);	// ctr is amnt of rounds...




}

void easyGame(void)
{



}

void hardGame(void)
{




}

void insaneGame(void)
{




}



int setRounds(void)
{
	int rounds;

	printf("Please Chose how many rounds you would like to play  :   ");
	scanf("%i", &rounds);

	return (rounds);

}

int setFoodGen(void)
{
	int numF;

	printf("Who much food should spawn per round?   :   ");
	scanf("%i", &numF);

	return numF;

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
	gameSpace[6][6] = 'o';
}


void setFood(int n)
{

	int randomY(void);
	int randomX(void);


	// Whatever number is passed to n will decide how many bits of food will be made

	int i;
	int x, y;


	for (i = 0; i < n; i++)
	{
		y = randomY();
		x = randomX();

		// only set if space is not taken.
		if (gameSpace[y][x] == 'o' || gameSpace[y][x] == 'e')
		{
			//don't set
		}
		else
		{
			gameSpace[y][x] = 'f';
		}
	}
}

void setEnemy(void)
{
	// Set Enemy at random dimensions...

	// type decs
	int randomY(void);
	int randomX(void);
	// vars
	int x;
	int y;
	//




	y = randomY();
	x = randomX();

	gameSpace[y][x] = 'e';


}




void playerMove(void)
{


	// Type Dec
	int findCurrentY(void);
	int findCurrentX(void);
	int checkForFood(int y, int x);
	int checkForEnemies(int y, int x);
	int checkBoundryY(int y);
	int checkBoundryX(int x);
    int food, enemy;


	// local variablse
	int newY, newX;
	int returnY, returnX;
    char move;

	printf("\n============================================================\n");
	printf("Make a move!   :   ");
	scanf(" %c", &move);
	printf("============================================================\n");

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




	/*	Declare function here that checks newY and newX for enemies or food.	*/
	/*	This should always handle collision events	*/
	food = 	checkForFood(newY, newX);
	enemy =	checkForEnemies(newY, newX);

	if (food == 1)
	{

		// eat food
		// increment health
		printf("YUM!!!!\n");
	}
	if (enemy == 1)
	{

		// die
		// game over
		printf("\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
		printf("\n\n\nYOU LOSE!!!!!!!\n\n\n");
		printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");

		exit(1);
	}

	//newY = checkBoundryY(newY);	// doesn't work for some reason
	newX = checkBoundryX(newX);

	gameSpace[newY][newX] = 'o'; // Set New position...

	gameSpace[returnY][returnX] = '.'; // Reset Prev position....


}



void enemyMove(void)
{
	printf("\n============================================================\n");
	printf("Computer Player's Move!");
	printf("\n============================================================\n");
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
int randomY(void)
{
	time_t t;	// for random seed
	srand((unsigned) time(&t));	// sets random seed to time
	int y;

	y = rand() % 15;

	return (y);
}
int randomX(void)
{
	time_t t;	// for random seed
	srand((unsigned) time(&t));	// sets random seed to time
	int x;

	x= rand() % 15;

	return (x);
}





int checkForEnemies(int y, int x)
{

	int food = 1;	// true flag

	if (gameSpace[y][x] == 'e')
	{
		return (food);
		// eat food.. inc health
	}
	else
	{
		// don't return anything/ do anything
		return (0);
	}

}
int checkForFood(int y, int x)
{
	int enemy = 1;

	if (gameSpace[y][x] == 'f')
	{

		// die!!
		// if health < e
		return (enemy);
	}
	else
	{
		return (0);
	}

}


/*
int checkBoundryY(int y)	//passed values will be current y and x
{
	// if player is out of bounds, set player to opposite side of playSpace
	if (y < 0)
	{
		y = 14;

		return y;

	}
	else if (y < 14)
	{
		y = 0;

		return y;

	}
	else
		return y;

}
// DOESN'T WORK
*/

	// Now check TargetX
int checkBoundryX(int x)
{
	if (x < 0)
	{

		x = 14;

		return x;

	}
	else if (x > 14)
	{

		x = 0;

		return x;

	}
	else
		return x;


}



