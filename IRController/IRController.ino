#include <LiquidCrystal.h>
#include <IRremote.h>

const int RECV_PIN = 9;
IRrecv irrecv (RECV_PIN);
decode_results results;
bool a1 = false;

int senal;
const int rs = 13, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  irrecv.enableIRIn();
  //irrecv.blink13(true);
  lcd.clear();
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("WELCOME!");
  
    pinMode(7, INPUT);
    pinMode(8, OUTPUT); //Red
    pinMode(6, OUTPUT); //Blue
    pinMode(12, OUTPUT); //Yellow
    Serial.begin(9600); 
}

void loop() 
{
  
  
  if(irrecv.decode(&results))
  {
      unsigned int boton = results.value;
      Serial.print(boton);
  
  
    if(boton == 255 && a1 == false)
    {
      
     digitalWrite(7, HIGH); 
      a1 = true;
      boton = 0;
      delay(10);
    }
    
    if(boton == 255 && a1 == true) {
          
     digitalWrite(7, LOW); 
            a1 = false;
            boton = 0;
    }
      lcd.clear();
      lcd.setCursor(0,0);
        lcd.print("YOU PRESSED");
        lcd.setCursor(0,1);
    
       //0 
      if (boton == 12495 || boton == 39780)
      {
        lcd.print("BUTTON: 0");
        digitalWrite(8, LOW); 
        digitalWrite(6, LOW); 
        digitalWrite(12, LOW); 
      }
    
      // 1 - 3
    
      if (boton == 2295 || boton == 43350)
      {
        lcd.print("BUTTON: 1");
        digitalWrite(8, HIGH); 
      }
      
            
      if (boton == 34935 || boton == 39270)
      {
        lcd.print("BUTTON: 2");
        digitalWrite(6, HIGH); 
      }
    
                
      if (boton == 18615 || boton == 47430)
      {
       lcd.print("BUTTON: 3");
       digitalWrite(12, HIGH); 
      }
    
    
        
      // 4 - 6
    
      if (boton == 10455 || boton == 27540)
      {
        lcd.print("BUTTON: 4");
        digitalWrite(8, HIGH);
      }
    
        
      if (boton == 43095 || boton == 23460)
      {
        lcd.print("BUTTON: 5");
        digitalWrite(6, HIGH);
      }
    
        
      if (boton == 26775 || boton == 31620)
      {
        lcd.print("BUTTON: 6");
        digitalWrite(12, HIGH);
      }
    
            
      // 7 - 9
    
      if (boton == 6375 || boton == 27030)
      {
        lcd.print("BUTTON: 7");
        digitalWrite(8, HIGH);
      }
      
      if (boton == 39015 || boton == 22950)
      {
        lcd.print("BUTTON: 8");
        digitalWrite(6, HIGH);
      }
    
      if (boton == 22695 || boton == 31110)
      {
        lcd.print("BUTTON: 9");
        digitalWrite(12, HIGH);
      }
    
      irrecv.resume();
  }
  }
