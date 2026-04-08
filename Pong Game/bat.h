#include<SFML/Graphics.hpp>
using namespace sf;
class bat{
   private:
      Vector2f m_Position;
      RectangleShape m_Shape;
      float m_Speed = 600.0f;
      bool m_MovingLeft = false;
      bool m_MovingRight = false;
   public:
       bat(int st_x, int st_y);
       FloatRect getPosition();
       RectangleShape getShape();
       void moveLeft();
       void moveRight();
	void stopLeft();
	void stopRight();
	void update(Time dt);
	}; 
