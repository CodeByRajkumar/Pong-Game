
#include<SFML/Graphics.hpp>
#include<sstream>
#include<iostream>

using namespace std;
using namespace sf;

class Ball{
	private:
		Vector2f m_Position;
		CircleShape m_Shape;
		float m_Speed = 1.0f;
		float m_DirectionX = 0.2f;
		float m_DirectionY = 0.2f;
	public:
		Ball(float startX, float startY);
		FloatRect getPosition();//used FloatRect : 4 value to be return
		CircleShape getShape();
		
		void reboundSides();
		void reboundBatOrTop();
		void reboundBottom();
		void update(Time dt);
};

Ball :: Ball(float startX,float startY){
	m_Position.x = startX;
	m_Position.y = startY;
	m_Shape.setRadius(10);
	m_Shape.setPosition(m_Position);
}
FloatRect Ball::getPosition(){
	return m_Shape.getGlobalBounds();
}
CircleShape Ball::getShape(){
	return m_Shape;
}
void Ball::reboundSides(){
	m_DirectionX = -m_DirectionX;
}
void Ball::reboundBatOrTop(){
	m_DirectionY=-m_DirectionY;
}
void Ball::reboundBottom(){
	m_Position.x=500;
	m_Position.y=0;
	//m_DirectionY = -m_DirectionY;
}

void Ball::update(Time dt){
	m_Position.x=m_Position.x + m_DirectionX * m_Speed + dt.asSeconds();
	m_Position.y=m_Position.y + m_DirectionY * m_Speed + dt.asSeconds();
	m_Shape.setPosition(m_Position);
}
