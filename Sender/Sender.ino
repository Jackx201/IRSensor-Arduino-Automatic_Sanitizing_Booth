//Emisor 
#include <IRremote.h>
IRsend irsend;
int pinButton = 1;
int valor_button;

void setup() 
{
Serial.begin(9600);
pinMode(pinButton,INPUT);
}

void loop() 
{
  valor_button = digitalRead(pinButton);
  if(valor_button == HIGH)
  irsend.sendNEC(18223,32);
  Serial.println("enviado");
  delay(100);
  
}

//
