#include<SFML/Graphics.hpp>
#include"bat.h"
#include"ball.h"
#include<sstream>
#include<SFML/Audio.hpp>
using namespace sf;

int main(){
   VideoMode vm(960, 540);
   RenderWindow window(vm, "PONG");
   
   Font font;
   font.loadFromFile("DS-DIGI.TTF");
   
   Text hud1;
   hud1.setFont(font);
    hud1.setString("PRESS ENTER TO START!!!");
   hud1.setCharacterSize(40);
	  
    hud1.setFillColor(Color::White);
   FloatRect textRect = hud1.getLocalBounds();
   hud1.setPosition((window.getSize().x - textRect.width) / 2.f, (window.getSize().y - textRect.height) / 2.f);
	
   //hud.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + 	textRect.height / 2.0f);  
  
   
   
   SoundBuffer GV;
   GV.loadFromFile("gv.wav");
   Sound ov;
  ov.setBuffer(GV);
   
   Text hud;
   
   hud.setFont(font);
   hud.setPosition(20, 20);
   hud.setCharacterSize(30);
   hud.setFillColor(Color::White);
   
       
   
   
   int score = 0;
   int lives = 3;
   
   
   bool paused = true;  
   
   bat bat(960/2, 540-20);
    ball ball(960/2,0);
   std::stringstream ss; 
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
        
        
      if(Keyboard::isKeyPressed(Keyboard::Return)){
            paused = false;
          }  
       
           
            
     if(!paused){  
        ss.str(" "); 
        ss<<"Score "<<score<<"  Lives " <<lives;
         hud.setString(ss.str());        
           
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
        
                  
      
      Time dt = clock.restart();
      bat.update(dt);
      ball.update(dt);
      
      if(ball.getPosition().left < 0 || ball.getPosition().left + ball.getPosition().width > window.getSize().x){
             ball.reboundSides();
             }
             
     if(ball.getPosition().top < 0){
           ball.reboundBatOrTop();
           score++;
           }        
      if(ball.getPosition().top>window.getSize().y){
                 ball.reboundBottom();
                 lives--;
                           
          if(lives < 1){
             paused = true;
             
             
          hud1.setString("Game Over!!!");
          ov.play();
          
	ss.str(" ");
          hud.setString(ss.str());
          score=0;
          lives=3;
        } 
      }
      
    if(ball.getPosition().intersects(bat.getPosition())){
           ball.reboundBatOrTop();
           }
                        
    }//Endif!paused       
      window.clear(Color::Black);
      window.draw(bat.getShape());
      window.draw(ball.getShape());
      window.draw(hud);
      if(paused){
      window.draw(hud1);
      }
      window.display();
      }
      return 0;
      }     
