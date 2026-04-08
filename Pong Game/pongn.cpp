#include<SFML/Graphics.hpp>
#include "bat.h"
#include "ball.cpp"
#include<sstream>
using namespace sf;
//#include<batn.cpp>
int main(){
   VideoMode vm(960, 540);
   RenderWindow window(vm, "PONG");
   
   Font font;
   font.loadFromFile("DS-DIGI.TTF");
   Text hud;
   hud.setFont(font);
   hud.setPosition(20, 20);
   hud.setCharacterSize(30);
   hud.setFillColor(Color::White);
   int score = 0;
   int lives = 3;
   
   
   bat bat(960/2, 540-20);
    ball ball(960/2,0);
   
   Clock clock;
   while(window.isOpen()){
      Event event;
      while(window.pollEvent(event)){
         if(event.type== event.Closed)
              window.close();
              }
      
     if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }
           
     if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            bat.moveLeft();
        }  
        
      else
        {
        bat.stopLeft();
        }
        
      if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            bat.moveRight();
        }  
        
        else
        {
        bat.stopRight();
        }     
        
                  
      std::stringstream ss;  
      ss<<"Score "<<score<<"  Lives " <<lives;
      hud.setString(ss.str());  
      
      Time dt = clock.restart();
      bat.update(dt);
      ball.update(dt);
      
      // Handle ball hitting sides
      
      if(ball.getPosition().left < 0 || ball.getPosition().left + ball.getPosition().width > window.getSize().x){
             ball.reboundSides();
             }
             
       // Handle ball hitting top      
     if(ball.getPosition().top < 0){
           ball.reboundBatOrTop();
           score++;
           } 
           
     // Handle ball hitting the bottom             
      if(ball.getPosition().top>window.getSize().y){
                 ball.reboundBottom();
                 lives--;
                           
          if(lives < 1){
          ss<<"Game Over";
          hud.setString(ss.str());
          score=0;
          lives=3;
        } 
      }
      
     // Has the ball hit the bat? 
      
    if(ball.getPosition().intersects(bat.getPosition())){
           ball.reboundBatOrTop();
           }
                        
           
      window.clear(Color::Black);
      window.draw(bat.getShape());
      window.draw(ball.getShape());
      window.draw(hud);
      window.display();
      }
      return 0;
      }     
