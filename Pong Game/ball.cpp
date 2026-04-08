#include "ball.h"
ball::ball(float st_x, float st_y){
        m_Shape.setRadius(20);
 	m_Position.x =st_x;
 	m_Position.y= st_y;
 	m_Shape.setFillColor(Color::Green);
 	m_Shape.setPosition(m_Position);
 }
 CircleShape ball::getShape(){
 	return m_Shape;
 }
 
 FloatRect ball::getPosition(){
    return m_Shape.getGlobalBounds();
  }
  void ball::reboundSides(){
     m_DirectionX = -m_DirectionX;
     }
  
   void ball::reboundBatOrTop(){
        m_DirectionY = -m_DirectionY;
        }
  void ball::reboundBottom(){
         m_Position.y = 11;
         m_Position.x = 500;
         }
   void ball::update(Time dt){
     m_Position.y +=  m_DirectionY * m_Speed * dt.asSeconds();
     
     m_Position.x +=  m_DirectionX * m_Speed * dt.asSeconds();
     m_Shape.setPosition(m_Position);
     }
