#include "map.h"

//LoadTexture: load texture used for grides
void gridMap::loadTexture()
{
	//loadfromfile returns boolean value if file is avaliable or not
	if (!texture.loadFromFile("Assets/gridSprite.png")) {
		//Error message
		std::cout << "Couldnot find texture";
	}
}

//Constructor
gridMap::gridMap()
{
	//loading texture from assets
	loadTexture();
}

gridMap::~gridMap()
{
}

//LoadLevel: Creates Grids 2d array and assign sprites randomly on them
void gridMap::loadLevel()
{
	/*
		Todo function avaliable for more sizes
	*/
	int nInRow = 6; //Size of row (4x4 or 6x6)
	int nRepetion = (nInRow*nInRow) / 8; 
	//Create array
	gArr = new Grid * [nInRow];
	for (int row = 0; row < nInRow; row++)
	{
		gArr[row] = new Grid[nInRow];
	}
	//Create freq array and set values to zeros
	int freq[8] = { 0 };
	//Check 
	int rem = nInRow * nInRow % 8;
	if (rem != 0) {
		for (int i = rem / 2; i > 0; i--)
		{
			freq[rand() % 8] = -2;
		}
	}
	int rndNo = 0;
	srand(time(NULL)); //to truly generate random number
	int test[6][6];
	// filling board with random numbers
	for (int row = 0; row < nInRow; row++) {
		for (int col = 0; col < nInRow; col++) {
			rndNo = rand() % 8;	//generate random number from 0 to 7
			if (freq[rndNo] < nRepetion) { //if that random number isnt repeated more than aallowed repetions
				//Assign its texture
				gArr[row][col].setSprite(row,col,rndNo, texture);
				test[row][col] = rndNo;
				freq[rndNo]++;	//increment random number repetions
			}
			else //if that random number exceeds allowed repetions
			{
				while (true) { //generate random number then see if it can be repeated or not
					rndNo = rand() % 8;
					if (freq[rndNo] < nRepetion) {
						//Assign its texture
						gArr[row][col].setSprite(row, col, rndNo, texture);
						test[row][col] = rndNo;
						freq[rndNo]++; //increment random number repetions
						break;
					}
				}
			}
		}
	}
	for (int i = 0; i < 6; i++)
	{
		for (int k = 0; k < 6; k++) {
			std::cout << test[i][k] << " ";
		}
		std::cout << std::endl;
	}
}