#include<SFML/Graphics.hpp>
using namespace sf;
int main(){
VideoMode vm(1600, 900);
RenderWindow window(vm, "Timber");

Texture textureBackground;
textureBackground.loadFromFile("/home/iteradmin/9505/Timber_prereq/graphics/background.png");
Sprite spriteBackground;
spriteBackground.setTexture(textureBackground);
spriteBackground.setPosition(0,0);

while(window.isOpen()){
	if(Keyboard::isKeyPressed(Keyboard::Escape)){
		window.close();
	}
window.clear();
window.display();
}

return 0;
}

