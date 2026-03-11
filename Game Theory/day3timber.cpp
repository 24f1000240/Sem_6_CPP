#include<SFML/Graphics.hpp>
#include<iostream>
#include<sstream>
#include<cstring>
using namespace sf;

int main(){

VideoMode vm(1600, 900);
RenderWindow window(vm, "Timber");

Texture textureBackground;
textureBackground.loadFromFile("graphics/background.png");
Sprite spriteBackground;
spriteBackground.setTexture(textureBackground);
spriteBackground.setPosition(0,0);

Texture textureTree;
textureTree.loadFromFile("graphics/tree.png");
Sprite spriteTree;
spriteTree.setTexture(textureTree);
spriteTree.setPosition(500,0);
spriteTree.setScale(0.5f,2.0f);

Texture textureCloud;
textureCloud.loadFromFile("graphics/cloud.png");
Sprite spc1;
Sprite spc2;
Sprite spc3;
spc1.setTexture(textureCloud);
spc2.setTexture(textureCloud);
spc3.setTexture(textureCloud);
spc1.setPosition(150,35);
spc2.setPosition(680,20);
spc3.setPosition(1200,5);
spc1.setScale(0.5f,0.5f);
spc2.setScale(0.5f,0.5f);
spc3.setScale(0.5f,0.5f);

Texture textureBee;
textureBee.loadFromFile("graphics/bee.png");
Sprite spriteBee;
spriteBee.setTexture(textureBee);
spriteBee.setPosition(750,300);

float cloudSpeed1 = 20.0f;
float cloudSpeed2 = 15.0f;
float cloudSpeed3 = 10.0f;

bool beeActive=false;
float beeSpeed=0.0f;
bool paused = true;
Clock clock;
Time dt;

Text text;
Font font;
font.loadFromFile("fonts/KOMIKAP_.ttf");
text.setString("Press Enter to Start");
text.setFont(font);
text.setCharacterSize(60);
text.setFillColor(Color::Red);
text.setPosition(1600/2.0f,900/2.0f);

FloatRect textRect=text.getLocalBounds();
text.setOrigin(textRect.left+textRect.width/2.0f,textRect.top+textRect.height/2.0f);

Text score;
score.setString("SCORE: ");
score.setFont(font);
score.setCharacterSize(50);
score.setFillColor(Color::Red);
score.setPosition(5,5);
Event event;
int Score = 0;
//int currPos=spriteBee.getposition().x;
//currPos+=200/5000;

while(window.isOpen()){	
	dt = clock.restart();
	
	if(Keyboard::isKeyPressed(Keyboard::Return)){
		paused = false;
	}
	
	if(!paused){
	
		if(event.type == Event::KeyPressed){
			if(Keyboard::isKeyPressed(Keyboard::Space))
				Score+=1;
			std::stringstream ss;
			ss << "SCORE: " << Score;
			score.setString(ss.str());
		}
	
		if(!beeActive){
			srand((int)time(0));
			beeSpeed=(rand()%200)+200;
		
			srand((int)time(0)*10);
			float height = (rand()%500)+500;
			spriteBee.setPosition(1800,height);
			beeActive=true;
		}	
		else{
			spriteBee.setPosition(
			spriteBee.getPosition().x-(beeSpeed*dt.asSeconds()),
			spriteBee.getPosition().y);
		
			if(spriteBee.getPosition().x<-100)
				beeActive=false;
		}
	
		spc1.setPosition(
        	spc1.getPosition().x-(cloudSpeed1 * dt.asSeconds()),
        	spc1.getPosition().y);

	    	spc2.setPosition(
        	spc2.getPosition().x-(cloudSpeed2 * dt.asSeconds()),
        	spc2.getPosition().y);
	
    		spc3.setPosition(
        	spc3.getPosition().x-(cloudSpeed3 * dt.asSeconds()),
        	spc3.getPosition().y);

    		if(spc1.getPosition().x < -200)
        		spc1.setPosition(1600,35);
	
    		if(spc2.getPosition().x < -200)
        		spc2.setPosition(1600,20);
	
    		if(spc3.getPosition().x < -200)
        		spc3.setPosition(1600,5);
	}
	

	while (window.pollEvent(event)){
		if(event.type == event.Closed)
			window.close();
	}
	if(Keyboard::isKeyPressed(Keyboard::Escape)){
		window.close();
	}
	
window.clear();
window.draw(spriteBackground);
window.draw(spc1);
window.draw(spc2);
window.draw(spc3);
window.draw(spriteTree);
window.draw(spriteBee);
window.draw(score);
if(paused){
	window.draw(text);
}
window.display();
}

return 0;
}

