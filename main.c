#include <stdio.h>
#include <gb/gb.h>
#include <gb/drawing.h>

#define V_OFF 25

UINT8 keyState, oldState;
UINT8 lineCounter;

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
void printKey();
void eventHandler();

int main() {
	lineCounter = 0;
	drawGameBoy();
	line(50,0,50,GRAPHICS_HEIGHT);
	while(1){
		eventHandler();
		if(keyState!=oldState){
			printKey();
			//line(50,0,50,GRAPHICS_HEIGHT);
			//drawGameBoy();
			drawButtons();
			oldState = keyState;
			if(lineCounter>=36){
				color(WHITE,WHITE,SOLID);
				box(0,0,49,GRAPHICS_HEIGHT,1);
			   	lineCounter = 0;
			}
		}
		keyState = 0;
	}
	return 0;
}

void drawGameBoy(){
	//Draw body
	color(DKGREY, BLACK, SOLID); 
	box(45+V_OFF,15,115+V_OFF,130,1);
	color(DKGREY, BLACK, SOLID); 
	box(45+V_OFF,15,115+V_OFF,130,1);
	//Draw screen frame
	color(BLACK, DKGREY, SOLID);
	box(50+V_OFF,25,110+V_OFF,65,1);
	//Draw LED
	circle(55+V_OFF,40,1,1);
	//Draw screen
	color(BLACK, LTGREY, SOLID);
	box(60+V_OFF,28,100+V_OFF,62,1);
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
	circle(105+V_OFF,93,5,1);
	setPressedColor();
	circle(105+V_OFF,93,5,0);
}

void drawB(){
	if(keyState&64) setPressedColor();
	else setButtonColor();	
	circle(92+V_OFF,97,5,1);
	setPressedColor();
	circle(92+V_OFF,97,5,0);
}

void drawUP(){
	if(keyState&32) setPressedColor();	
	else setButtonColor();	
	circle(58+V_OFF,88,3,1);
	setPressedColor();
	line(55+V_OFF,85,61+V_OFF,85);
	line(55+V_OFF,85,55+V_OFF,91);
	line(61+V_OFF,85,61+V_OFF,91);
}

void drawDOWN(){
	if(keyState&16) setPressedColor();	
	else setButtonColor();	
	circle(58+V_OFF,98,3,1);
	setPressedColor();
	line(55+V_OFF,101,61+V_OFF,101);
	line(55+V_OFF,95,55+V_OFF,101);
	line(61+V_OFF,95,61+V_OFF,101);
}

void drawLEFT(){
	if(keyState&8) setPressedColor();	
	else setButtonColor();	
	circle(53+V_OFF,93,3,1);
	setPressedColor();
	line(50+V_OFF,90,55+V_OFF,90);
	line(50+V_OFF,90,50+V_OFF,96);
	line(50+V_OFF,96,55+V_OFF,96);
}

void drawRIGHT(){
	if(keyState&4) setPressedColor();	
	else setButtonColor();	
	circle(63+V_OFF,93,3,1);
	setPressedColor();
	line(61+V_OFF,90,66+V_OFF,90);
	line(66+V_OFF,90,66+V_OFF,96);
	line(61+V_OFF,96,66+V_OFF,96);
}

void drawSTART(){
	if(keyState&2) setPressedColor();
	else setButtonColor();
	box(79+V_OFF,115,85+V_OFF,117,1);
}

void drawSELECT(){
	if(keyState&1) setPressedColor();
	else setButtonColor();
	box(70+V_OFF,115,76+V_OFF,117,1);
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

void printKey(){
	color(BLACK,WHITE,SOLID);
	gotogxy(0, lineCounter/2);
	if(keyState&1) gprintf("SELECT");
	else if(keyState&2) gprintf("START ");
	else if(keyState&4) gprintf("RIGHT ");
	else if(keyState&8) gprintf("LEFT  ");
	else if(keyState&16) gprintf("DOWN  ");
	else if(keyState&32) gprintf("UP    ");
	else if(keyState&64) gprintf("B     ");
	else if(keyState&128) gprintf("A     ");
	lineCounter++;
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
