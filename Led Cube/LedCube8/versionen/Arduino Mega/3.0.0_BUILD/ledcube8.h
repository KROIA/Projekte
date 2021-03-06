// Autor: 									Alex Krieg
// Erstellt:								3.5.16
// Version 									3.0.0 BUILD
// Kompatibel mit den versionen: 			*****
// Funktionen:								*****
// Hardware									Arduino Mega (2560)

/*
struct CUBEDATALAYER
struct CUBEDATACUBE

*/
#ifndef LEDCUBE8_H
#define LEDCUBE8_H
#include "Arduino.h"
	struct CUBEDATALAYER
{
  byte Layer;
  byte A; 
  byte B; 
  byte C; 
  byte D; 
  byte E; 
  byte F; 
  byte G; 
  byte H; 
};
	struct CUBEDATACUBE
{
  byte CA8; 
  byte CB8; 
  byte CC8; 
  byte CD8; 
  byte CE8; 
  byte CF8; 
  byte CG8; 
  byte CH8; 
  
  byte CA7; 
  byte CB7; 
  byte CC7; 
  byte CD7; 
  byte CE7; 
  byte CF7; 
  byte CG7; 
  byte CH7; 
  
  byte CA6; 
  byte CB6; 
  byte CC6; 
  byte CD6; 
  byte CE6; 
  byte CF6; 
  byte CG6; 
  byte CH6;
  
  
  byte CA5; 
  byte CB5; 
  byte CC5; 
  byte CD5; 
  byte CE5; 
  byte CF5; 
  byte CG5; 
  byte CH5; 
  
  byte CA4; 
  byte CB4; 
  byte CC4; 
  byte CD4; 
  byte CE4; 
  byte CF4; 
  byte CG4; 
  byte CH4; 
  
  byte CA3; 
  byte CB3; 
  byte CC3; 
  byte CD3; 
  byte CE3; 
  byte CF3; 
  byte CG3; 
  byte CH3; 
  
  byte CA2; 
  byte CB2; 
  byte CC2; 
  byte CD2; 
  byte CE2; 
  byte CF2; 
  byte CG2; 
  byte CH2; 
  
  byte CA1; 
  byte CB1; 
  byte CC1; 
  byte CD1; 
  byte CE1; 
  byte CF1; 
  byte CG1; 
  byte CH1; 
};
	struct POS
{
  int X;
  int Y;
  int Z;
};


class LedCube8
{
	public:
		 LedCube8(byte flipfloppin[],byte ledadress[],byte layeradresspin[]);
		 ~LedCube8();
	void init();
	void draw(struct CUBEDATALAYER data);
	void drawCube(struct CUBEDATACUBE data);

	
	void drawLayer(byte layer);
	void drawWall(byte wall);
	void drawWall90(byte wall);
	
	void shiftLayerRight    (int count,bool reload, struct CUBEDATALAYER data);
	void shiftLayerLeft    (int count,bool reload, struct CUBEDATALAYER data);
	void shiftLayerRight90  (int count,bool reload, struct CUBEDATALAYER data);
	void shiftLayerLeft90  (int count,bool reload, struct CUBEDATALAYER data);
	void shiftLayerDown (int count,bool reload, struct CUBEDATALAYER data);
	void shiftLayerUp 	(int count,bool reload, struct CUBEDATALAYER data);
	
	void shiftCubeRight		(int count,bool reload, struct CUBEDATACUBE data);
	void shiftCubeLeft		(int count,bool reload, struct CUBEDATACUBE data);
    void shiftCubeRight90	(int count,bool reload, struct CUBEDATACUBE data);
	void shiftCubeLeft90	(int count,bool reload, struct CUBEDATACUBE data);								
	void shiftCubeUp	(int count,bool reload, struct CUBEDATACUBE data);
	void shiftCubeDown	(int count,bool reload, struct CUBEDATACUBE data);
	
	void light(byte L);
	void rain(byte count,byte amount);
	void writeLayer(char text[],byte lenge,byte layer);
	
	void time(int t);
	void hackLight(bool status);
	
	private:
	
	byte countAddress();								//zählt "counter" um 1 hoch
	void setPin(byte pin, byte address);				//setzt pins bei den pins 2-9
	void saveToFlipFlop(byte address);					//setzt pins in Binär bei 10-13
	void setLayer(byte layer,int T,int multiplikator);	//setzt pins in Binär bei A0-A4
	
	byte *ledpin;
	byte *ledAddresspin;
	byte *layerpin;
	
	byte led;
	byte ledAddress;
	byte layerAddress;
	
	byte counter;
	byte helligkeit;
	unsigned long Time;
	unsigned long TimeMicro;
	
	
	bool hackLightStatus;
	unsigned long startMillis;
	unsigned long referenzMillis;
	unsigned long benotigtMillis;
	
};
#endif