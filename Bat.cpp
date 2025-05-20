
#include<SFML/Graphics.hpp>
#include<sstream>
#include<iostream>

using namespace std;
using namespace sf;

class Bat{
	private:
		Vector2f m_Position;
		RectangleShape m_Shape;
		float m_Speed = 1000.0f;
		bool m_MovingRight = false;
		bool m_MovingLeft = false;
	public:
		Bat(float startX, float startY);
		FloatRect getPosition();//used FloatRect : 4 value to be return
		RectangleShape getShape();
		
		void moveRight();
		void moveLeft();
		void stopRight();
		void stopLeft();
		void update(Time dt);
};
//method desc
Bat::Bat(float startX, float startY){
	m_Position.x = startX;
	m_Position.y = startY;
	m_Shape.setSize(sf::Vector2f(50,5));
	m_Shape.setPosition(m_Position);
}
FloatRect Bat::getPosition(){
	return m_Shape.getGlobalBounds();
}
RectangleShape Bat::getShape(){
	return m_Shape;
}
void  Bat::moveRight(){
	m_MovingRight=true;
}
void Bat::moveLeft(){
	m_MovingLeft=true;
}
void Bat::stopRight(){
	m_MovingRight=false;
}
void Bat::stopLeft(){
	m_MovingLeft=false;
}
void Bat::update(Time dt){
	if(m_MovingRight){
		m_Position.x += m_Speed*dt.asSeconds();
	}
	if(m_MovingLeft){
		m_Position.x -= m_Speed*dt.asSeconds();
	}
	
	m_Shape.setPosition(m_Position);
}

