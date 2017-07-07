#include <stdio.h>
#include <gb/gb.h>
#include <gb/drawing.h>

UINT8 keyState, oldState;

void setButtonColor();
void setPressedColor();
void drawGameBoy();
void drawButtons();
void drawA();
void drawB();
void drawUP();
void drawDOWN();
void drawLEFT();
void drawRIGHT();
void drawSELECT();
void drawSTART();
void eventHandler();

int main() {
	drawGameBoy();
	while(1){
		eventHandler();
		if(keyState!=oldState){
			drawButtons();
			oldState = keyState;
		}
		keyState = 0;
	}
	return 0;
}

void drawGameBoy(){
	//Draw body
	color(DKGREY, BLACK, SOLID); 
	box(45,15,115,130,1);
	color(DKGREY, BLACK, SOLID); 
	box(45,15,115,130,1);
	//Draw screen frame
	color(BLACK, DKGREY, SOLID);
	box(50,25,110,65,1);
	//Draw LED
	circle(55,40,1,1);
	//Draw screen
	color(BLACK, LTGREY, SOLID);
	box(60,28,100,62,1);
	//Draw buttons
	drawButtons();
}

void setButtonColor(){
	color(DKGREY,LTGREY,SOLID);
}

void setPressedColor(){
	color(LTGREY,LTGREY,SOLID);
}

void drawA(){
	if(keyState&128) setPressedColor();	
	else setButtonColor();
	circle(105,93,5,1);
	setPressedColor();
	circle(105,93,5,0);
}

void drawB(){
	if(keyState&64) setPressedColor();	
	else setButtonColor();	
	circle(92,97,5,1);
	setPressedColor();
	circle(92,97,5,0);
}

void drawUP(){
	if(keyState&32) setPressedColor();	
	else setButtonColor();	
	circle(58,88,3,1);
	setPressedColor();
	line(55,85,61,85);
	line(55,85,55,91);
	line(61,85,61,91);
}

void drawDOWN(){
	if(keyState&16) setPressedColor();	
	else setButtonColor();	
	circle(58,98,3,1);
	setPressedColor();
	line(55,101,61,101);
	line(55,95,55,101);
	line(61,95,61,101);
}

void drawLEFT(){
	if(keyState&8) setPressedColor();	
	else setButtonColor();	
	circle(53,93,3,1);
	setPressedColor();
	line(50,90,55,90);
	line(50,90,50,96);
	line(50,96,55,96);
}

void drawRIGHT(){
	if(keyState&4) setPressedColor();	
	else setButtonColor();	
	circle(63,93,3,1);
	setPressedColor();
	line(61,90,66,90);
	line(66,90,66,96);
	line(61,96,66,96);
}

void drawSTART(){
	if(keyState&2) setPressedColor();
	else setButtonColor();
	circle(80,116,1,1);
	circle(82,116,1,1);
	circle(84,116,1,1);
	setPressedColor();
	box(79,115,85,117,0);
}

void drawSELECT(){
	if(keyState&1) setPressedColor();
	else setButtonColor();
	circle(71,116,1,1);
	circle(73,116,1,1);
	circle(75,116,1,1);
	setPressedColor();
	box(70,115,76,117,0);
}

void drawButtons(){
	drawA();
	drawB();
	drawUP();
	drawDOWN();
	drawLEFT();
	drawRIGHT();
	drawSTART();
	drawSELECT();
}

void eventHandler(){
	keyState|=(joypad()==J_A); keyState<<=1;
	keyState|=(joypad()==J_B); keyState<<=1;
	keyState|=(joypad()==J_UP); keyState<<=1;
	keyState|=(joypad()==J_DOWN); keyState<<=1;
	keyState|=(joypad()==J_LEFT); keyState<<=1;
	keyState|=(joypad()==J_RIGHT); keyState<<=1;
	keyState|=(joypad()==J_START); keyState<<=1;
	keyState|=(joypad()==J_SELECT);
}
