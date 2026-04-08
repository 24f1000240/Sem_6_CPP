#include "bat.h"
bat::bat(int st_x, int st_y){
   m_Position.x = st_x;
   m_Position.y= st_y;
   m_Shape.setSize(Vector2f(50, 5));
   m_Shape.setPosition(m_Position);
      }
   
   FloatRect bat::getPosition(){
         return m_Shape.getGlobalBounds();
         }
   RectangleShape bat::getShape(){
           return m_Shape;
           }
       
 void bat::moveLeft(){
         m_MovingLeft = true;
         }
 void bat::moveRight(){
             m_MovingRight = true;
        }
 void bat::stopLeft(){
       m_MovingLeft = false;
       } 
void bat::stopRight(){
    m_MovingRight = false;
    }

void bat::update(Time dt)
{	 if(m_MovingLeft)
		if(m_Position.x >0)
     		m_Position.x -= m_Speed * dt.asSeconds();
     
     if(m_MovingRight){
     	if(m_Position.x < 910)
     		m_Position.x += m_Speed * dt.asSeconds();
     }
     
     m_Shape.setPosition(m_Position);
     
}
