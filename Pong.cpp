
#include<SFML/Graphics.hpp>
#include<sstream>
#include<iostream>
#include "Bat.cpp"
#include "Ball.cpp"


using namespace std;
using namespace sf;
int main(){

	//-------------------------Set UP -----------------------------------------
	VideoMode vm(1920,1080);
	
	RenderWindow window(vm,"Pong Game !!!",Style::Fullscreen);
	int score=0;
	int lives = 3;
	
	Font font;
	font.loadFromFile("./fonts/KOMIKAP_.ttf");
	Text hud;
	hud.setFont(font);
	hud.setCharacterSize(75);
	hud.setFillColor(Color::White);
	hud.setPosition(20,20);
	
	//
	float X = window.getSize().x;
	float Y = window.getSize().y;
	
	Bat bat(X/2,Y-20);//Bat bat(1920/2,1080-20);//------Bat initialization-------
	Ball ball(X/2,0);//Ball bat(1920/2,1080-20);//------Ball initialization-------
	
	bool touchButtom = false;
	
	Clock clock;
	
	
	//----------------------Main Game Loop---------------------------------------
	while(window.isOpen()){
	
		Event event;
		
		while(window.pollEvent(event)){
			if(event.type==Event::Closed){
				window.close();
			}
		}
		//---------------------------------------Player info-----------------------------------------------
		if(Keyboard::isKeyPressed(Keyboard::Escape)){
			window.close();
		}
		//-------------Handel Right Key pressed and released------------------
		if(Keyboard::isKeyPressed(Keyboard::Right)){
			bat.moveRight();
		}else{
			bat.stopRight();
		}
		
		//-------------Handel Left Key pressed and released-------------------
		
		if(Keyboard::isKeyPressed(Keyboard::Left)){
			bat.moveLeft();
		}else{
			bat.stopLeft();
		}
		//------------------------------------------UPDATE----------------------------------------------------
		
		Time dt = clock.restart();
		//---------Bat and Ball Update--------
		bat.update(dt);
		ball.update(dt);
		
		//------------update Score--------------
		std::stringstream ss;
		ss<<"Score:"<<score<<"  Lives:"<<lives;		
		hud.setString(ss.str());
		
		//-----------------------Handle Ball hitting--------------------------
		//------------Handle Ball hitting sides-----
		if(ball.getPosition().left<0 || (ball.getPosition().left + ball.getPosition().width)>X){
			ball.reboundSides();
		}
		//------------Handle Ball hitting bottom-----
		if(ball.getPosition().top > Y){
			
			ball.reboundBottom();
			lives = lives -1;
			touchButtom = true;
			if(lives<1){
				score=0;
				lives=3;
			}
		}
		//------------Handle Ball hitting top-----
		if(ball.getPosition().top < 0){
			ball.reboundBatOrTop();
			if(!touchButtom){
				score=score+1;
			}else{
				touchButtom = false;
			}
		}
		//
		if(ball.getPosition().intersects(bat.getPosition())){
			ball.reboundBatOrTop();
		}
		//-------------------------------------------WINDOW----------------------------------------------------
		window.clear();
		window.draw(hud);
		window.draw(bat.getShape());
		window.draw(ball.getShape());
		window.display();
		
	}
	
	return 0;

}
//  g++ Pong.cpp -o Pong -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio
//  ./Pong
