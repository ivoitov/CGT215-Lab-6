//Written by Ivan Voitov on October 4th, 2022
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
int main() {
	//Referencing the 2 images that we'll need for the final product
	string background = "images1/backgrounds/alebrije.png";
	string foreground = "images1/characters/yoda.png";
	Texture backgroundTex;
	//If the load doesn't work tell the user and exit the program
	if (!backgroundTex.loadFromFile(background)) {
		cout << "Couldn't Load Image" << endl;
		exit(1);
	}
	Texture foregroundTex;
	if (!foregroundTex.loadFromFile(foreground)) {
		cout << "Couldn't Load Image" << endl;
		exit(1);
	}
	//Setting the background image and getting the dimensions in the vector Vector2u
	Image backgroundImage;
	backgroundImage = backgroundTex.copyToImage();
	Image foregroundImage;
	foregroundImage = foregroundTex.copyToImage();
	Vector2u sz = backgroundImage.getSize();

	//Color check for the green in the greenscreen
	Color greenCheck(32, 214, 23, 255);

	//Replacement double for loop
	for (int y = 0; y < sz.y; y++) {
		
		for (int x = 0; x < sz.x; x++) {
			
			//Getting the pixel in the given location of the yoda image
			Color picYodaGreen = foregroundImage.getPixel(x, y);
			
			//Getting the pixel in the given location of the bacground image
			Color replacementPixel = backgroundImage.getPixel(x, y);
			
			//Check for whether or not the pixel in that spot is equivalent to the pixel that we defined earlier as our Green Check and if it is replace it with the background pixel
			if (greenCheck == picYodaGreen) {
				foregroundImage.setPixel(x, y, replacementPixel);
			}

		}

	}
	//Image display (making sure to set the RenderWindow to the right dimensions)
	RenderWindow window(VideoMode(1024, 771), "Yoda is Lost.");
	Sprite sprite1;
	Texture tex1;
	tex1.loadFromImage(foregroundImage);
	sprite1.setTexture(tex1);
	window.clear();
	window.draw(sprite1);
	window.display();
	while (true);
}