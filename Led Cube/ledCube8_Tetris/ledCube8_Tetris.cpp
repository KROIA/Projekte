//==========================================LED CUBE TETRIS=================== 
// Autor: 									Alex Krieg
// Erstellt:								14.5.16
// Version 									1.0.0
// Kompatibel mit den versionen: 			ledCube9.h : 3.0.3 BUILD
// Funktionen:								*****






#include "ledCube8_Tetris.h"

ledCube8_Tetris::ledCube8_Tetris(byte pins[])
{
	
		 cube = new LedCube8;
		 but1P1 = new Button(pins[0],activeHigh);
		 but2P1 = new Button(pins[1],activeHigh);
		 but3P1 = new Button(pins[2],activeHigh);
		 but4P1 = new Button(pins[3],activeHigh);
		 but5P1 = new Button(pins[4],activeHigh);
		 but6P1 = new Button(pins[5],activeHigh);
		 
		 but1P2 = new Button(pins[6],activeHigh);
		 but2P2 = new Button(pins[7],activeHigh);
		 but3P2 = new Button(pins[8],activeHigh);
		 but4P2 = new Button(pins[9],activeHigh);
		 but5P2 = new Button(pins[10],activeHigh);
		 but6P2 = new Button(pins[11],activeHigh);
		 

		but1P1->init();
		but2P1->init();
		but3P1->init();
		but4P1->init();
		but5P1->init();
		but6P1->init();
		
		but1P2->init();
		but2P2->init();
		but3P2->init();
		but4P2->init();
		but5P2->init();
		but6P2->init();
		
		Wire.begin();
		cube->time(1);
		
		startTime 	= 0;
		time		= 0;
		shiftTime 	= 1000;
		activeObjectA = random(-1,8);
		score		= 0;
		cubeData = {
		0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0		
		};
		cubeTerain = {
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0
		};
		activeObjectShifted = cubeData;
		activeObjectShiftedX = activeObjectShifted;
		objects[0]  ={
			
		0,0,0,0,0,0,0,0,	
		0,0,0,0,0,0,0,0,	
		0,0,0,0,1,0,0,0,	
		0,0,0,0,1,0,0,0,	
		0,0,0,0,1,0,0,0,	
		0,0,0,0,1,0,0,0,	
		0,0,0,0,0,0,0,0,	
		0,0,0,0,0,0,0,0
		};
		objects[1]  ={
			
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,1,0,0,0,
			0,0,0,0,1,0,0,0,
			0,0,0,1,1,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0
		};
		objects[2]  ={
			
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,1,0,0,0,0,
			0,0,0,1,0,0,0,0,
			0,0,0,1,1,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0
		};
		objects[3]  ={
			
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,1,1,0,0,0,
			0,0,0,1,1,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0
		};
		objects[4]  ={
			
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,1,1,0,0,
			0,0,0,1,1,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0
		};
		objects[5]  ={
			
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,1,1,1,0,0,
			0,0,0,0,1,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0
		};
		objects[6]  ={
			
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,1,1,0,0,0,
			0,0,0,0,1,1,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0
		};
		
		activeObject = objects[0];
		shiftDownAmount = 0;
		shiftLeftAmount = 3;
		
}
ledCube8_Tetris::~ledCube8_Tetris()
{
	delete cube;
}



void ledCube8_Tetris::init()
{	
	
	
	
	
}

void ledCube8_Tetris::run()
{
	startTime = millis();
	init();
	bool test = false;
	while(true)
	{
		send();
		time = millis();
		if((time -startTime) > shiftTime)
		{
			Serial.println(score);
			activeObjectA = random(-1,8);
			startTime = time;
			shiftDownAmount++;
			if(activeObjectShifted.CA1  == 1 ||
	  activeObjectShifted.CB1  == 1 ||
	  activeObjectShifted.CC1  == 1 ||
	  activeObjectShifted.CD1  == 1 ||
	  activeObjectShifted.CE1  == 1 ||
	  activeObjectShifted.CF1  == 1 ||
	  activeObjectShifted.CG1  == 1 ||
	  activeObjectShifted.CH1  == 1 )
	  {
		  test = true;
	  }
	  else
	  {
		  test = false;
	  }
			activeObjectShifted = cube->getShiftCubeDown(1,true,activeObjectShifted);
			if(checkForCollision()|| test)
			{
				{
					 if(shiftDownAmount ==1 )
					 {
						 stop();
					 }
					 activeObjectShifted = cube->getShiftCubeUp(1,true,activeObjectShifted);
					 cubeTerain = cube->add(activeObjectShifted,cubeTerain);
					 shiftDownAmount = 0;
					 activeObject = objects[activeObjectA];
					 shiftLeftAmount = 3;
					 score++;
				 }
				 checkForDelete();
			}
			//activeObjectShifted = cube->getShiftCubeUp(1,true,activeObjectShifted);
			calculate();
		}
		//checkForDelete();
		but1P1->checkButton();
		but2P1->checkButton();
		but3P1->checkButton();
		but4P1->checkButton();
		but5P1->checkButton();
		but6P1->checkButton();
		
		but1P2->checkButton();
		but2P2->checkButton();
		but3P2->checkButton();
		but4P2->checkButton();
		but5P2->checkButton();
		but6P2->checkButton();
	}
}
void ledCube8_Tetris::stop()
{

		
	
	startTime = millis();
	while(true)
	{
		time = millis();
		if((time - startTime) > 5000)
		{
		startTime 	= 0;
		time		= 0;
		shiftTime 	= 1000;
		activeObjectA = random(-1,8);
		score		= 0;
		cubeData = {
		0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0		
		};
		cubeTerain = {
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0
		};
		activeObjectShifted = cubeData;
		activeObjectShiftedX = activeObjectShifted;
		shiftDownAmount = 0;
		shiftLeftAmount = 3;
		send();
		run();
		}
	}
}
void ledCube8_Tetris::calculate()
{
	
	if(shiftDownAmount < 3)
	{
		activeObjectShifted = cube->getShiftCubeUp(3-shiftDownAmount,false,activeObject);
	}
	else
	{
		activeObjectShifted = cube->getShiftCubeDown(shiftDownAmount-3,false,activeObject);
	}
	if(shiftLeftAmount < 3)
	{
		activeObjectShifted = cube->getShiftCubeRight(3-shiftLeftAmount,false,activeObjectShifted);
	}
	else
	{
		activeObjectShifted = cube->getShiftCubeLeft(shiftLeftAmount-3,false,activeObjectShifted);
	}
	cubeData = cube->add(cubeTerain,activeObjectShifted);
	//cubeData.CA8 = score;
	send();
}

bool ledCube8_Tetris::checkForCollision()
{
	
	if(
	 cubeTerain.CA1 && activeObjectShifted.CA1  == 1 ||
	 cubeTerain.CB1 && activeObjectShifted.CB1  == 1 ||
	 cubeTerain.CC1 && activeObjectShifted.CC1  == 1 ||
	 cubeTerain.CD1 && activeObjectShifted.CD1  == 1 ||
	 cubeTerain.CE1 && activeObjectShifted.CE1  == 1 ||
	 cubeTerain.CF1 && activeObjectShifted.CF1  == 1 ||
	 cubeTerain.CG1 && activeObjectShifted.CG1  == 1 ||
	 cubeTerain.CH1 && activeObjectShifted.CH1  == 1 ||
	 
	 cubeTerain.CA2 && activeObjectShifted.CA2  == 1 ||
	 cubeTerain.CB2 && activeObjectShifted.CB2  == 1 ||
	 cubeTerain.CC2 && activeObjectShifted.CC2  == 1 ||
	 cubeTerain.CD2 && activeObjectShifted.CD2  == 1 ||
	 cubeTerain.CE2 && activeObjectShifted.CE2  == 1 ||
	 cubeTerain.CF2 && activeObjectShifted.CF2  == 1 ||
	 cubeTerain.CG2 && activeObjectShifted.CG2  == 1 ||
	 cubeTerain.CH2 && activeObjectShifted.CH2  == 1 ||
	 
	 cubeTerain.CA3 && activeObjectShifted.CA3  == 1 ||
	 cubeTerain.CB3 && activeObjectShifted.CB3  == 1 ||
	 cubeTerain.CC3 && activeObjectShifted.CC3  == 1 ||
	 cubeTerain.CD3 && activeObjectShifted.CD3  == 1 ||
	 cubeTerain.CE3 && activeObjectShifted.CE3  == 1 ||
	 cubeTerain.CF3 && activeObjectShifted.CF3  == 1 ||
	 cubeTerain.CG3 && activeObjectShifted.CG3  == 1 ||
	 cubeTerain.CH3 && activeObjectShifted.CH3  == 1 ||
	 
	 cubeTerain.CA4 && activeObjectShifted.CA4  == 1 ||
	 cubeTerain.CB4 && activeObjectShifted.CB4  == 1 ||
	 cubeTerain.CC4 && activeObjectShifted.CC4  == 1 ||
	 cubeTerain.CD4 && activeObjectShifted.CD4  == 1 ||
	 cubeTerain.CE4 && activeObjectShifted.CE4  == 1 ||
	 cubeTerain.CF4 && activeObjectShifted.CF4  == 1 ||
	 cubeTerain.CG4 && activeObjectShifted.CG4  == 1 ||
	 cubeTerain.CH4 && activeObjectShifted.CH4  == 1 ||
	 
	 cubeTerain.CA5 && activeObjectShifted.CA5  == 1 ||
	 cubeTerain.CB5 && activeObjectShifted.CB5  == 1 ||
	 cubeTerain.CC5 && activeObjectShifted.CC5  == 1 ||
	 cubeTerain.CD5 && activeObjectShifted.CD5  == 1 ||
	 cubeTerain.CE5 && activeObjectShifted.CE5  == 1 ||
	 cubeTerain.CF5 && activeObjectShifted.CF5  == 1 ||
	 cubeTerain.CG5 && activeObjectShifted.CG5  == 1 ||
	 cubeTerain.CH5 && activeObjectShifted.CH5  == 1 ||
	 
	 cubeTerain.CA6 && activeObjectShifted.CA6  == 1 ||
	 cubeTerain.CB6 && activeObjectShifted.CB6  == 1 ||
	 cubeTerain.CC6 && activeObjectShifted.CC6  == 1 ||
	 cubeTerain.CD6 && activeObjectShifted.CD6  == 1 ||
	 cubeTerain.CE6 && activeObjectShifted.CE6  == 1 ||
	 cubeTerain.CF6 && activeObjectShifted.CF6  == 1 ||
	 cubeTerain.CG6 && activeObjectShifted.CG6  == 1 ||
	 cubeTerain.CH6 && activeObjectShifted.CH6  == 1 ||
	 
	 cubeTerain.CA7 && activeObjectShifted.CA7  == 1 ||
	 cubeTerain.CB7 && activeObjectShifted.CB7  == 1 ||
	 cubeTerain.CC7 && activeObjectShifted.CC7  == 1 ||
	 cubeTerain.CD7 && activeObjectShifted.CD7  == 1 ||
	 cubeTerain.CE7 && activeObjectShifted.CE7  == 1 ||
	 cubeTerain.CF7 && activeObjectShifted.CF7  == 1 ||
	 cubeTerain.CG7 && activeObjectShifted.CG7  == 1 ||
	 cubeTerain.CH7 && activeObjectShifted.CH7  == 1 ||
	 
	 cubeTerain.CA8 && activeObjectShifted.CA8  == 1 ||
	 cubeTerain.CB8 && activeObjectShifted.CB8  == 1 ||
	 cubeTerain.CC8 && activeObjectShifted.CC8  == 1 ||
	 cubeTerain.CD8 && activeObjectShifted.CD8  == 1 ||
	 cubeTerain.CE8 && activeObjectShifted.CE8  == 1 ||
	 cubeTerain.CF8 && activeObjectShifted.CF8  == 1 ||
	 cubeTerain.CG8 && activeObjectShifted.CG8  == 1 ||
	 cubeTerain.CH8 && activeObjectShifted.CH8  == 1 
	 
	  
	 )
	 {
		/* if(shiftDownAmount ==1 )
		 {
			 stop();
		 }*/
		 //activeObjectShifted = cube->getShiftCubeUp(1,true,activeObjectShifted);
		 //cubeTerain = cube->add(activeObjectShifted,cubeTerain);
		// shiftDownAmount = 0;
		 //activeObject = objects[1];
		 //shiftLeftAmount = 3;
		 return true;
	 }
	 else
	 {
		 return false;
	 }
	 /*if(
	 cubeTerain.CA1 == 1 &&
	 cubeTerain.CB1 == 1 &&
	 cubeTerain.CC1 == 1 &&
	 cubeTerain.CD1 == 1 &&
	 cubeTerain.CE1 == 1 &&
	 cubeTerain.CF1 == 1 &&
	 cubeTerain.CG1 == 1 &&
	 cubeTerain.CH1 == 1  
	 )
	 {
		 cubeTerain = cube->getShiftCubeDown(1,false,cubeTerain);
	 }*/
}                                                
void ledCube8_Tetris::checkForDelete()
{
	CUBEDATACUBE TERAIN = cubeTerain;
	CUBEDATACUBE SUBTRACTOR = {
		1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1
	};
	if(
	 cubeTerain.CA1 == 1 &&
	 cubeTerain.CB1 == 1 &&
	 cubeTerain.CC1 == 1 &&
	 cubeTerain.CD1 == 1 &&
	 cubeTerain.CE1 == 1 &&
	 cubeTerain.CF1 == 1 &&
	 cubeTerain.CG1 == 1 &&
	 cubeTerain.CH1 == 1  
	 )
	 {
		 TERAIN = cube->getShiftCubeDown(1,false,TERAIN);
	 }
	/* if(
	 cubeTerain.CA2 == 1 &&
	 cubeTerain.CB2 == 1 &&
	 cubeTerain.CC2 == 1 &&
	 cubeTerain.CD2 == 1 &&
	 cubeTerain.CE2 == 1 &&
	 cubeTerain.CF2 == 1 &&
	 cubeTerain.CG2 == 1 &&
	 cubeTerain.CH2 == 1  
	 )
	 {		
	    SUBTRACTOR = cube->getShiftCubeDown(6,false,SUBTRACTOR);
		TERAIN = cube->subtract(TERAIN,SUBTRACTOR);
		TERAIN = cube->getShiftCubeDown(1,false,TERAIN);
		TERAIN.CA1 = cubeTerain.CA1;
		TERAIN.CB1 = cubeTerain.CB1;
		TERAIN.CC1 = cubeTerain.CC1;
		TERAIN.CD1 = cubeTerain.CD1;
		TERAIN.CE1 = cubeTerain.CE1;
		TERAIN.CF1 = cubeTerain.CF1;
		TERAIN.CG1 = cubeTerain.CG1;
		TERAIN.CH1 = cubeTerain.CH1;
	 }
	 if(
	 cubeTerain.CA3 == 1 &&
	 cubeTerain.CB3 == 1 &&
	 cubeTerain.CC3 == 1 &&
	 cubeTerain.CD3 == 1 &&
	 cubeTerain.CE3 == 1 &&
	 cubeTerain.CF3 == 1 &&
	 cubeTerain.CG3 == 1 &&
	 cubeTerain.CH3 == 1  
	 )
	 {		
	    SUBTRACTOR = cube->getShiftCubeDown(5,false,SUBTRACTOR);
		TERAIN = cube->subtract(TERAIN,SUBTRACTOR);
		TERAIN = cube->getShiftCubeDown(1,false,TERAIN);
		TERAIN.CA1 = cubeTerain.CA1;
		TERAIN.CB1 = cubeTerain.CB1;
		TERAIN.CC1 = cubeTerain.CC1;
		TERAIN.CD1 = cubeTerain.CD1;
		TERAIN.CE1 = cubeTerain.CE1;
		TERAIN.CF1 = cubeTerain.CF1;
		TERAIN.CG1 = cubeTerain.CG1;
		TERAIN.CH1 = cubeTerain.CH1;
		
		TERAIN.CA2 = cubeTerain.CA2;
		TERAIN.CB2 = cubeTerain.CB2;
		TERAIN.CC2 = cubeTerain.CC2;
		TERAIN.CD2 = cubeTerain.CD2;
		TERAIN.CE2 = cubeTerain.CE2;
		TERAIN.CF2 = cubeTerain.CF2;
		TERAIN.CG2 = cubeTerain.CG2;
		TERAIN.CH2 = cubeTerain.CH2;
	 }
	 if(
	 cubeTerain.CA4 == 1 &&
	 cubeTerain.CB4 == 1 &&
	 cubeTerain.CC4 == 1 &&
	 cubeTerain.CD4 == 1 &&
	 cubeTerain.CE4 == 1 &&
	 cubeTerain.CF4 == 1 &&
	 cubeTerain.CG4 == 1 &&
	 cubeTerain.CH4 == 1  
	 )
	 {		
	    SUBTRACTOR = cube->getShiftCubeDown(4,false,SUBTRACTOR);
		TERAIN = cube->subtract(TERAIN,SUBTRACTOR);
		TERAIN = cube->getShiftCubeDown(1,false,TERAIN);
		TERAIN.CA1 = cubeTerain.CA1;
		TERAIN.CB1 = cubeTerain.CB1;
		TERAIN.CC1 = cubeTerain.CC1;
		TERAIN.CD1 = cubeTerain.CD1;
		TERAIN.CE1 = cubeTerain.CE1;
		TERAIN.CF1 = cubeTerain.CF1;
		TERAIN.CG1 = cubeTerain.CG1;
		TERAIN.CH1 = cubeTerain.CH1;
		
		TERAIN.CA2 = cubeTerain.CA2;
		TERAIN.CB2 = cubeTerain.CB2;
		TERAIN.CC2 = cubeTerain.CC2;
		TERAIN.CD2 = cubeTerain.CD2;
		TERAIN.CE2 = cubeTerain.CE2;
		TERAIN.CF2 = cubeTerain.CF2;
		TERAIN.CG2 = cubeTerain.CG2;
		TERAIN.CH2 = cubeTerain.CH2;
		
		TERAIN.CA3 = cubeTerain.CA3;
		TERAIN.CB3 = cubeTerain.CB3;
		TERAIN.CC3 = cubeTerain.CC3;
		TERAIN.CD3 = cubeTerain.CD3;
		TERAIN.CE3 = cubeTerain.CE3;
		TERAIN.CF3 = cubeTerain.CF3;
		TERAIN.CG3 = cubeTerain.CG3;
		TERAIN.CH3 = cubeTerain.CH3;
		
	 }
	if(
	 cubeTerain.CA5 == 1 &&
	 cubeTerain.CB5 == 1 &&
	 cubeTerain.CC5 == 1 &&
	 cubeTerain.CD5 == 1 &&
	 cubeTerain.CE5 == 1 &&
	 cubeTerain.CF5 == 1 &&
	 cubeTerain.CG5 == 1 &&
	 cubeTerain.CH5 == 1  
	 )
	 {		
	    SUBTRACTOR = cube->getShiftCubeDown(3,false,SUBTRACTOR);
		TERAIN = cube->subtract(TERAIN,SUBTRACTOR);
		TERAIN = cube->getShiftCubeDown(1,false,TERAIN);
		TERAIN.CA1 = cubeTerain.CA1;
		TERAIN.CB1 = cubeTerain.CB1;
		TERAIN.CC1 = cubeTerain.CC1;
		TERAIN.CD1 = cubeTerain.CD1;
		TERAIN.CE1 = cubeTerain.CE1;
		TERAIN.CF1 = cubeTerain.CF1;
		TERAIN.CG1 = cubeTerain.CG1;
		TERAIN.CH1 = cubeTerain.CH1;
		
		TERAIN.CA2 = cubeTerain.CA2;
		TERAIN.CB2 = cubeTerain.CB2;
		TERAIN.CC2 = cubeTerain.CC2;
		TERAIN.CD2 = cubeTerain.CD2;
		TERAIN.CE2 = cubeTerain.CE2;
		TERAIN.CF2 = cubeTerain.CF2;
		TERAIN.CG2 = cubeTerain.CG2;
		TERAIN.CH2 = cubeTerain.CH2;
		
		TERAIN.CA3 = cubeTerain.CA3;
		TERAIN.CB3 = cubeTerain.CB3;
		TERAIN.CC3 = cubeTerain.CC3;
		TERAIN.CD3 = cubeTerain.CD3;
		TERAIN.CE3 = cubeTerain.CE3;
		TERAIN.CF3 = cubeTerain.CF3;
		TERAIN.CG3 = cubeTerain.CG3;
		TERAIN.CH3 = cubeTerain.CH3;
		
		TERAIN.CA4 = cubeTerain.CA4;
		TERAIN.CB4 = cubeTerain.CB4;
		TERAIN.CC4 = cubeTerain.CC4;
		TERAIN.CD4 = cubeTerain.CD4;
		TERAIN.CE4 = cubeTerain.CE4;
		TERAIN.CF4 = cubeTerain.CF4;
		TERAIN.CG4 = cubeTerain.CG4;
		TERAIN.CH4 = cubeTerain.CH4;
	 }
	if(
	 cubeTerain.CA6 == 1 &&
	 cubeTerain.CB6 == 1 &&
	 cubeTerain.CC6 == 1 &&
	 cubeTerain.CD6 == 1 &&
	 cubeTerain.CE6 == 1 &&
	 cubeTerain.CF6 == 1 &&
	 cubeTerain.CG6 == 1 &&
	 cubeTerain.CH6 == 1  
	 )
	 {		
	    SUBTRACTOR = cube->getShiftCubeDown(2,false,SUBTRACTOR);
		TERAIN = cube->subtract(TERAIN,SUBTRACTOR);
		TERAIN = cube->getShiftCubeDown(1,false,TERAIN);
		TERAIN.CA1 = cubeTerain.CA1;
		TERAIN.CB1 = cubeTerain.CB1;
		TERAIN.CC1 = cubeTerain.CC1;
		TERAIN.CD1 = cubeTerain.CD1;
		TERAIN.CE1 = cubeTerain.CE1;
		TERAIN.CF1 = cubeTerain.CF1;
		TERAIN.CG1 = cubeTerain.CG1;
		TERAIN.CH1 = cubeTerain.CH1;
		
		TERAIN.CA2 = cubeTerain.CA2;
		TERAIN.CB2 = cubeTerain.CB2;
		TERAIN.CC2 = cubeTerain.CC2;
		TERAIN.CD2 = cubeTerain.CD2;
		TERAIN.CE2 = cubeTerain.CE2;
		TERAIN.CF2 = cubeTerain.CF2;
		TERAIN.CG2 = cubeTerain.CG2;
		TERAIN.CH2 = cubeTerain.CH2;
		
		TERAIN.CA3 = cubeTerain.CA3;
		TERAIN.CB3 = cubeTerain.CB3;
		TERAIN.CC3 = cubeTerain.CC3;
		TERAIN.CD3 = cubeTerain.CD3;
		TERAIN.CE3 = cubeTerain.CE3;
		TERAIN.CF3 = cubeTerain.CF3;
		TERAIN.CG3 = cubeTerain.CG3;
		TERAIN.CH3 = cubeTerain.CH3;
		
		TERAIN.CA4 = cubeTerain.CA4;
		TERAIN.CB4 = cubeTerain.CB4;
		TERAIN.CC4 = cubeTerain.CC4;
		TERAIN.CD4 = cubeTerain.CD4;
		TERAIN.CE4 = cubeTerain.CE4;
		TERAIN.CF4 = cubeTerain.CF4;
		TERAIN.CG4 = cubeTerain.CG4;
		TERAIN.CH4 = cubeTerain.CH4;
		
		TERAIN.CA5 = cubeTerain.CA5;
		TERAIN.CB5 = cubeTerain.CB5;
		TERAIN.CC5 = cubeTerain.CC5;
		TERAIN.CD5 = cubeTerain.CD5;
		TERAIN.CE5 = cubeTerain.CE5;
		TERAIN.CF5 = cubeTerain.CF5;
		TERAIN.CG5 = cubeTerain.CG5;
		TERAIN.CH5 = cubeTerain.CH5;
	 }
	if(
	 cubeTerain.CA7 == 1 &&
	 cubeTerain.CB7 == 1 &&
	 cubeTerain.CC7 == 1 &&
	 cubeTerain.CD7 == 1 &&
	 cubeTerain.CE7 == 1 &&
	 cubeTerain.CF7 == 1 &&
	 cubeTerain.CG7 == 1 &&
	 cubeTerain.CH7 == 1  
	 )
	 {		
	    SUBTRACTOR = cube->getShiftCubeDown(1,false,SUBTRACTOR);
		TERAIN = cube->subtract(TERAIN,SUBTRACTOR);
		TERAIN = cube->getShiftCubeDown(1,false,TERAIN);
		TERAIN.CA1 = cubeTerain.CA1;
		TERAIN.CB1 = cubeTerain.CB1;
		TERAIN.CC1 = cubeTerain.CC1;
		TERAIN.CD1 = cubeTerain.CD1;
		TERAIN.CE1 = cubeTerain.CE1;
		TERAIN.CF1 = cubeTerain.CF1;
		TERAIN.CG1 = cubeTerain.CG1;
		TERAIN.CH1 = cubeTerain.CH1;
		
		TERAIN.CA2 = cubeTerain.CA2;
		TERAIN.CB2 = cubeTerain.CB2;
		TERAIN.CC2 = cubeTerain.CC2;
		TERAIN.CD2 = cubeTerain.CD2;
		TERAIN.CE2 = cubeTerain.CE2;
		TERAIN.CF2 = cubeTerain.CF2;
		TERAIN.CG2 = cubeTerain.CG2;
		TERAIN.CH2 = cubeTerain.CH2;
		
		TERAIN.CA3 = cubeTerain.CA3;
		TERAIN.CB3 = cubeTerain.CB3;
		TERAIN.CC3 = cubeTerain.CC3;
		TERAIN.CD3 = cubeTerain.CD3;
		TERAIN.CE3 = cubeTerain.CE3;
		TERAIN.CF3 = cubeTerain.CF3;
		TERAIN.CG3 = cubeTerain.CG3;
		TERAIN.CH3 = cubeTerain.CH3;
		
		TERAIN.CA4 = cubeTerain.CA4;
		TERAIN.CB4 = cubeTerain.CB4;
		TERAIN.CC4 = cubeTerain.CC4;
		TERAIN.CD4 = cubeTerain.CD4;
		TERAIN.CE4 = cubeTerain.CE4;
		TERAIN.CF4 = cubeTerain.CF4;
		TERAIN.CG4 = cubeTerain.CG4;
		TERAIN.CH4 = cubeTerain.CH4;
		
		TERAIN.CA5 = cubeTerain.CA5;
		TERAIN.CB5 = cubeTerain.CB5;
		TERAIN.CC5 = cubeTerain.CC5;
		TERAIN.CD5 = cubeTerain.CD5;
		TERAIN.CE5 = cubeTerain.CE5;
		TERAIN.CF5 = cubeTerain.CF5;
		TERAIN.CG5 = cubeTerain.CG5;
		TERAIN.CH5 = cubeTerain.CH5;
		
		TERAIN.CA6 = cubeTerain.CA6;
		TERAIN.CB6 = cubeTerain.CB6;
		TERAIN.CC6 = cubeTerain.CC6;
		TERAIN.CD6 = cubeTerain.CD6;
		TERAIN.CE6 = cubeTerain.CE6;
		TERAIN.CF6 = cubeTerain.CF6;
		TERAIN.CG6 = cubeTerain.CG6;
		TERAIN.CH6 = cubeTerain.CH6;
	 }
	if(
	 cubeTerain.CA8 == 1 &&
	 cubeTerain.CB8 == 1 &&
	 cubeTerain.CC8 == 1 &&
	 cubeTerain.CD8 == 1 &&
	 cubeTerain.CE8 == 1 &&
	 cubeTerain.CF8 == 1 &&
	 cubeTerain.CG8 == 1 &&
	 cubeTerain.CH8 == 1  
	 )
	 {		
	  //  SUBTRACTOR = cube->getShiftCubeDown(1,false,SUBTRACTOR);
		TERAIN = cube->subtract(TERAIN,SUBTRACTOR);
		TERAIN = cube->getShiftCubeDown(1,false,TERAIN);
		TERAIN.CA1 = cubeTerain.CA1;
		TERAIN.CB1 = cubeTerain.CB1;
		TERAIN.CC1 = cubeTerain.CC1;
		TERAIN.CD1 = cubeTerain.CD1;
		TERAIN.CE1 = cubeTerain.CE1;
		TERAIN.CF1 = cubeTerain.CF1;
		TERAIN.CG1 = cubeTerain.CG1;
		TERAIN.CH1 = cubeTerain.CH1;
		
		TERAIN.CA2 = cubeTerain.CA2;
		TERAIN.CB2 = cubeTerain.CB2;
		TERAIN.CC2 = cubeTerain.CC2;
		TERAIN.CD2 = cubeTerain.CD2;
		TERAIN.CE2 = cubeTerain.CE2;
		TERAIN.CF2 = cubeTerain.CF2;
		TERAIN.CG2 = cubeTerain.CG2;
		TERAIN.CH2 = cubeTerain.CH2;
		
		TERAIN.CA3 = cubeTerain.CA3;
		TERAIN.CB3 = cubeTerain.CB3;
		TERAIN.CC3 = cubeTerain.CC3;
		TERAIN.CD3 = cubeTerain.CD3;
		TERAIN.CE3 = cubeTerain.CE3;
		TERAIN.CF3 = cubeTerain.CF3;
		TERAIN.CG3 = cubeTerain.CG3;
		TERAIN.CH3 = cubeTerain.CH3;
		
		TERAIN.CA4 = cubeTerain.CA4;
		TERAIN.CB4 = cubeTerain.CB4;
		TERAIN.CC4 = cubeTerain.CC4;
		TERAIN.CD4 = cubeTerain.CD4;
		TERAIN.CE4 = cubeTerain.CE4;
		TERAIN.CF4 = cubeTerain.CF4;
		TERAIN.CG4 = cubeTerain.CG4;
		TERAIN.CH4 = cubeTerain.CH4;
		
		TERAIN.CA5 = cubeTerain.CA5;
		TERAIN.CB5 = cubeTerain.CB5;
		TERAIN.CC5 = cubeTerain.CC5;
		TERAIN.CD5 = cubeTerain.CD5;
		TERAIN.CE5 = cubeTerain.CE5;
		TERAIN.CF5 = cubeTerain.CF5;
		TERAIN.CG5 = cubeTerain.CG5;
		TERAIN.CH5 = cubeTerain.CH5;
		
		TERAIN.CA6 = cubeTerain.CA6;
		TERAIN.CB6 = cubeTerain.CB6;
		TERAIN.CC6 = cubeTerain.CC6;
		TERAIN.CD6 = cubeTerain.CD6;
		TERAIN.CE6 = cubeTerain.CE6;
		TERAIN.CF6 = cubeTerain.CF6;
		TERAIN.CG6 = cubeTerain.CG6;
		TERAIN.CH6 = cubeTerain.CH6;
		
		TERAIN.CA7 = cubeTerain.CA7;
		TERAIN.CB7 = cubeTerain.CB7;
		TERAIN.CC7 = cubeTerain.CC7;
		TERAIN.CD7 = cubeTerain.CD7;
		TERAIN.CE7 = cubeTerain.CE7;
		TERAIN.CF7 = cubeTerain.CF7;
		TERAIN.CG7 = cubeTerain.CG7;
		TERAIN.CH7 = cubeTerain.CH7;
	 }*/


	 
	cubeTerain = TERAIN;
}

//===========================SEND===========================================
void ledCube8_Tetris::send()
{
	cube->drawCube(cubeData);
	/*int reference = 1;
	Wire.beginTransmission(1); // transmit to device #1
	
	
	Wire.write(reference);
	Wire.write(cubeData.CA1);        
	Wire.write(cubeData.CB1);
	Wire.write(cubeData.CC1);
	Wire.write(cubeData.CD1);
	Wire.write(cubeData.CE1);
	Wire.write(cubeData.CF1);
	Wire.write(cubeData.CG1);
	Wire.write(cubeData.CH1);
	           
	Wire.write(cubeData.CA2);        
	Wire.write(cubeData.CB2);
	Wire.write(cubeData.CC2);
	Wire.write(cubeData.CD2);
	Wire.write(cubeData.CE2);
	Wire.write(cubeData.CF2);
	Wire.write(cubeData.CG2);
	Wire.write(cubeData.CH2);
	Wire.endTransmission(); 
	reference++;
	Wire.beginTransmission(1);	 
	Wire.write(reference);
	Wire.write(cubeData.CA3);        
	Wire.write(cubeData.CB3);
	Wire.write(cubeData.CC3);
	Wire.write(cubeData.CD3);
	Wire.write(cubeData.CE3);
	Wire.write(cubeData.CF3);
	Wire.write(cubeData.CG3);
	Wire.write(cubeData.CH3);
	           
	Wire.write(cubeData.CA4);        
	Wire.write(cubeData.CB4);
	Wire.write(cubeData.CC4);
	Wire.write(cubeData.CD4);
	Wire.write(cubeData.CE4);
	Wire.write(cubeData.CF4);
	Wire.write(cubeData.CG4);
	Wire.write(cubeData.CH4);
	Wire.endTransmission(); 
	reference++;
	Wire.beginTransmission(1);	
	Wire.write(reference);	
	Wire.write(cubeData.CA5);        
	Wire.write(cubeData.CB5);
	Wire.write(cubeData.CC5);
	Wire.write(cubeData.CD5);
	Wire.write(cubeData.CE5);
	Wire.write(cubeData.CF5);
	Wire.write(cubeData.CG5);
	Wire.write(cubeData.CH5);
	           
	Wire.write(cubeData.CA6);        
	Wire.write(cubeData.CB6);
	Wire.write(cubeData.CC6);
	Wire.write(cubeData.CD6);
	Wire.write(cubeData.CE6);
	Wire.write(cubeData.CF6);
	Wire.write(cubeData.CG6);
	Wire.write(cubeData.CH6);
	Wire.endTransmission(); 
	reference++;
	Wire.beginTransmission(1);
	Wire.write(reference);	
	Wire.write(cubeData.CA7);        
	Wire.write(cubeData.CB7);
	Wire.write(cubeData.CC7);
	Wire.write(cubeData.CD7);
	Wire.write(cubeData.CE7);
	Wire.write(cubeData.CF7);
	Wire.write(cubeData.CG7);
	Wire.write(cubeData.CH7);
	           
	Wire.write(cubeData.CA8);        
	Wire.write(cubeData.CB8);
	Wire.write(cubeData.CC8);
	Wire.write(cubeData.CD8);
	Wire.write(cubeData.CE8);
	Wire.write(cubeData.CF8);
	Wire.write(cubeData.CG8);
	Wire.write(cubeData.CH8);
	Wire.endTransmission();*/    // stop transmitting
}
//===========================BUTTONS========================================
//===========================Player1========================================
void ledCube8_Tetris::button1Player1()
{
	
}
void ledCube8_Tetris::button2Player1()
{
	
}
void ledCube8_Tetris::button3Player1()
{   
activeObjectShifted = cube->getShiftCubeLeft(1,true,activeObjectShifted);
	if(checkForCollision())
	 {
		 activeObjectShifted = cube->getShiftCubeRight(1,true,activeObjectShifted);
		// cubeTerain = cube->add(activeObjectShifted,cubeTerain);
		 //shiftDownAmount = 0;
		 //activeObject = objects[1];
		 //shiftLeftAmount = 3;
	 }
	 else{
		 shiftLeftAmount++;
	 }
	
	calculate();
}
void ledCube8_Tetris::button4Player1()
{
	activeObjectShifted = cube->getShiftCubeRight(1,true,activeObjectShifted);
	if(checkForCollision())
	 {
		 activeObjectShifted = cube->getShiftCubeLeft(1,true,activeObjectShifted);
		// cubeTerain = cube->add(activeObjectShifted,cubeTerain);
		 //shiftDownAmount = 0;
		 //activeObject = objects[1];
		 //shiftLeftAmount = 3;
	 }
	 else{
		 shiftLeftAmount--;
	 }
	calculate();
}
void ledCube8_Tetris::button5Player1()
{
	activeObject = cube->getRotate(1,activeObject);
	calculate();
}
void ledCube8_Tetris::button6Player1()
{
	
}
//===============================Player2=====================================

void ledCube8_Tetris::button1Player2()
{
	
}
void ledCube8_Tetris::button2Player2()
{
	
}
void ledCube8_Tetris::button3Player2()
{
	
}
void ledCube8_Tetris::button4Player2()
{
	
}
void ledCube8_Tetris::button5Player2()
{

	
}
void ledCube8_Tetris::button6Player2()
{
	
}