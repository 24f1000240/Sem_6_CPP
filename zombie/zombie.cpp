#include "player.h" 
#include <SFML/Graphics.hpp>
using namespace sf;
int main(){
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;
    
    RenderWindow window(VideoMode(resolution.x, resolution.y),"Zombie Arena",Style::Fullscreen);
    View mainView(FloatRect(0, 0, resolution.x, resolution.y));
    
    Texture texturebg;
    texturebg.loadFromFile("graphics/background.png");
    Sprite spritebg;
    spritebg.setTexture(texturebg);
    spritebg.setPosition(-850,-250);
    
    player player;
    IntRect arena;
    arena.left = 0;
    arena.top = 0;
    arena.width = 500;
    arena.height = 500;
    
    int tileSize = 50;
    player.spawn(resolution, arena, tileSize);
    
    while (window.isOpen()){
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) 
                window.close();
        }
    if (Keyboard::isKeyPressed(Keyboard::Escape)) { 
            window.close(); 
        }
        
        mainView.setCenter(player.getCenter());
        window.clear();
        window.setView(mainView);
        window.draw(spritebg);
        window.draw(player.getSprite());
        window.display();
    }
    return 0;
}
