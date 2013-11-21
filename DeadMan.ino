/*
ERGO DeadMan Code

*/
const int ledLiving = 0;//Grn proof of life led
const int ledDead = 1;// Red DEAD led
const int ledInterrupt = 3;// Wht Interrupt felt led
const int rlyPowerOff = 4;// High to release relay and reset the EtherMega
const int isrRefresh= 0;// Interrupt input.  HIGH shows life

volatile int count = 0;


void isrResponse()// Interrupt Service Routine (ISR)
{
	count = 0;// Reset the counter;
	digitalWrite (ledInterrupt, HIGH);


	delay(1000);
	digitalWrite (ledInterrupt, LOW);
}

void lampTest()
{
	digitalWrite (ledLiving, HIGH);// Turn ON all LEDS
	digitalWrite (ledDead, HIGH);
	digitalWrite (ledInterrupt, HIGH);
	delay(500);
	digitalWrite (ledLiving, LOW);// Shut off all LEDS
	digitalWrite (ledDead, LOW);
	digitalWrite (ledInterrupt, LOW);
	delay(500);
	digitalWrite (ledLiving, HIGH);// Turn on all LEDS
	digitalWrite (ledDead, HIGH);
	digitalWrite (ledInterrupt, HIGH);
	delay(500);
	digitalWrite (ledLiving, LOW);// Shut off all LEDS
	digitalWrite (ledDead, LOW);
	digitalWrite (ledInterrupt, LOW);
	delay(1000);
}

void setup ()
{
	pinMode(ledLiving,OUTPUT);//GRN LED Alive
	pinMode(ledDead,OUTPUT);//RED LED Dead
	pinMode(ledInterrupt,OUTPUT);//WHT LED Interrupt felt
	
	pinMode(rlyPowerOff,OUTPUT);//RELAY
	lampTest();
	
	attachInterrupt (0, isrResponse, HIGH);  // attach interrupt handler
	count = 0;
}

void loop ()
{

	if (count >60)
	{
		digitalWrite(rlyPowerOff,HIGH);//Dead Man drop relay
		digitalWrite(ledDead,HIGH);//Dead Man Turn on LED
		delay(5000);
		digitalWrite(rlyPowerOff,LOW);//Dead Man drop relay
		digitalWrite(ledDead,LOW);//Dead Man Turn off LED
		count = 0;
	}
	
	else
	{


		digitalWrite(rlyPowerOff
		,LOW);//Keep relay closed
	}
	digitalWrite(ledLiving,HIGH);  // Proof of life
	delay(500);
	digitalWrite(ledLiving,LOW);  // Proof of life
	delay(500);
	count ++;
}
