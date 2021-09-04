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
void gridMap::loadLevel(int nInRow)
{
	//Size of row (4x4 or 6x6 or 8x8)
    int nRepetion = (nInRow*nInRow) / 8; 
	//Create 2d array[][] with sizes = nInRow
	gArr = new Grid * [nInRow];
	for (int row = 0; row < nInRow; row++)
	{
		gArr[row] = new Grid[nInRow];
	}
	//Create freq array and set values to zeros (8 is default number of sprites in this game)
	int freq[8] = { 0 };
	//Check if total number of grids is divisble by 8 if not some grids might have extra repetions
	int rem = (nInRow * nInRow) % 8;
	if (rem != 0) {
		for (int i = rem / 2; i > 0; i--)
		{
			freq[rand() % 8] = -2;
		}
	}
	int rndNo = 0;
	srand(time(NULL)); //to truly generate random number
	// filling board with random numbers
	for (int row = 0; row < nInRow; row++) {
		for (int col = 0; col < nInRow; col++) {
			while (true) { //generate random number then see if it can be repeated or not
				rndNo = rand() % 8;
				if (freq[rndNo] < nRepetion) {
					//Assign its texture
					gArr[row][col].setSprite(row, col, rndNo, texture);
					//increment random number repetions
					freq[rndNo]++;
					break;
				}
			}
		}
	}
}

void gridMap::drawMatrix(int size, RenderWindow* window)
{
	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < size; col++)
		{
			//To do draw matrix
			window->draw(gArr[row][col].getSprite());
		}
	}
}