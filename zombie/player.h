#include<SFML/Graphics.hpp>
using namespace sf;
class player{
   private:
	Vector2f m_Position;
	Sprite m_sprite;
	Texture m_Texture;
	Vector2f m_Resolution;
	IntRect m_Arena;
	int m_Tilesize;
   public:
	player();
	FloatRect getPosition();
	Vector2f getCenter();
	Sprite getSprite();
	void spawn(Vector2f resolution,IntRect arena,int tilesize);
};
