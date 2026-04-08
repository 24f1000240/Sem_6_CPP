#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>
#include "bat.h"
#include "ball.h"

using namespace sf;

int main() {
    VideoMode vm(960, 540);
    RenderWindow window(vm, "Pong");

  
    Font font;
    font.loadFromFile("DS-DIGI.TTF");

    
    Text hud;
    hud.setFont(font);
    hud.setString("PRESS ENTER TO START!");
    hud.setCharacterSize(40);
    hud.setFillColor(Color::White);

    FloatRect textRect = hud.getLocalBounds();
    hud.setOrigin(textRect.left + textRect.width / 2.0f,
                   textRect.top + textRect.height / 2.0f);
    hud.setPosition(window.getSize().x / 2.0f,
                     window.getSize().y / 2.0f);

    
    SoundBuffer GV;
    GV.loadFromFile("gv.wav");
    Sound ov;
    ov.setBuffer(GV);

    int score = 0;
    int lives = 3;
    bool paused = true;

    
    bat bat((960 - 50) / 2, 540 - 30);
    ball ball(960 / 2, 0);

    std::stringstream ss;
    Clock clock;

   
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            window.close();
        }

      
        if (Keyboard::isKeyPressed(Keyboard::Return)) {
            paused = false;
        }

        if (!paused) {
          
            ss.str("");
            ss << "Score: " << score << "   Lives: " << lives;
            hud.setString(ss.str());

           
            if (Keyboard::isKeyPressed(Keyboard::Left)) {
                bat.moveLeft();
            } else {
                bat.stopLeft();
            }

            if (Keyboard::isKeyPressed(Keyboard::Right)) {
                bat.moveRight();
            } else {
                bat.stopRight();
            }

            
            Time dt = clock.restart();

            bat.update(dt);
            ball.update(dt);

            
            if (ball.getPosition().left < 0 ||
                ball.getPosition().left + ball.getPosition().width > window.getSize().x) {
                ball.reboundSides();
                ov.play();
            }

            if (ball.getPosition().top < 0) {
                ball.reboundBatOrTop();
                score++;
                ov.play();
            }

            if (ball.getPosition().top > window.getSize().y) {
                ball.reboundBottom();
                lives--;
                ov.play();
            }

            if (ball.getPosition().intersects(bat.getPosition())) {
                ball.reboundBatOrTop();
                ov.play();
            }

            
            if (lives <= 0) {
                paused = true;
                score = 0;
                lives = 3;
            }
        }

       
        window.clear(Color::Black);

        if (paused) {
            window.draw(hud);
        } else {
            window.draw(bat.getShape());
            window.draw(ball.getShape());
            window.draw(hud);
        }

        window.display();
    }

    return 0;
}
