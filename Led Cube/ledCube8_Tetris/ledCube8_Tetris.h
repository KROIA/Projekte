//==========================================LED CUBE TETRIS=================== 
// Autor: 									Alex Krieg
// Erstellt:								14.5.16
// Version 									1.0.0
// Kompatibel mit den versionen: 			ledCube9.h : 3.0.3 BUILD
// Funktionen:								*****




#ifndef LEDCUBE8_TETRIS_H
#define LEDCUBE8_TETRIS_H

#include "ledcube8.h"
#include "button.h"
#include <Wire.h>


class ledCube8_Tetris
{
	public:
	ledCube8_Tetris(byte pins[]);
	~ledCube8_Tetris();
	
	void run();
	
	void button1Player1();
	void button2Player1();
	void button3Player1();
	void button4Player1();
	void button5Player1();
	void button6Player1();
	
	void button1Player2();
	void button2Player2();
	void button3Player2();
	void button4Player2();
	void button5Player2();
	void button6Player2();
	                  
	Button *but1P1;
	Button *but2P1;
	Button *but3P1;
	Button *but4P1;
	Button *but5P1;
	Button *but6P1;
	
	Button *but1P2;
	Button *but2P2;
	Button *but3P2;
	Button *but4P2;
	Button *but5P2;
	Button *but6P2;
	
	private:
	void init();
	void send();
	void calculate();
	bool checkForCollision();
	void checkForDelete();
	void stop();
	
	
	
	LedCube8* cube;
	
	int shiftDownAmount;
	int shiftLeftAmount;
	int activeObjectA;
	int score;
	
	unsigned long startTime;
	unsigned long time;
	unsigned long shiftTime;
	CUBEDATACUBE cubeData;
	CUBEDATACUBE objects[7];
	CUBEDATACUBE activeObject;
	CUBEDATACUBE cubeTerain;
	CUBEDATACUBE activeObjectShifted;
	CUBEDATACUBE activeObjectShiftedX;
	
};


#endif