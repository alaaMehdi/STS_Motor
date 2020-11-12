#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int rs=0;
int T;
void Control_s_b_s_Motor(boolean ON,boolean SENSE,int SPEED,/*[0..100]*/int Nb_Steps/*00 if=0*/){

    if(ON==false){

      digitalWrite(0,LOW);digitalWrite(1,LOW);digitalWrite(6,LOW);digitalWrite(7,LOW); 
      return;
      
    }
    else{
    
      T=(100-SPEED)*10;
      
      if(SENSE==true){

        //Position 1
          digitalWrite(0,HIGH);digitalWrite(1,LOW);digitalWrite(6,LOW);digitalWrite(7,LOW);delay(T);
          
        //Position 2
          digitalWrite(0,LOW);digitalWrite(1,HIGH);digitalWrite(6,LOW);digitalWrite(7,LOW);delay(T);
          
        //Position 3
          digitalWrite(0,LOW);digitalWrite(1,LOW);digitalWrite(6,HIGH);digitalWrite(7,LOW);delay(T);
          
        //Position 4
          digitalWrite(0,LOW);digitalWrite(1,LOW);digitalWrite(6,LOW);digitalWrite(7,HIGH);delay(T);
        rs++;
      }
      else{

        //Position 1
          digitalWrite(7,HIGH);digitalWrite(6,LOW);digitalWrite(1,LOW);digitalWrite(0,LOW);delay(T);
          
        //Position 2
          digitalWrite(7,LOW);digitalWrite(6,HIGH);digitalWrite(1,LOW);digitalWrite(0,LOW);delay(T);
          
        //Position 3
          digitalWrite(7,LOW);digitalWrite(6,LOW);digitalWrite(1,HIGH);digitalWrite(0,LOW);delay(T);
          
        //Position 4
          digitalWrite(7,LOW);digitalWrite(6,LOW);digitalWrite(1,LOW);digitalWrite(0,HIGH);delay(T);
       rs++; 
      }

      
    }

    


    

}

void setup() {
  
    pinMode(0,OUTPUT);
    pinMode(1,OUTPUT);
    pinMode(6,OUTPUT);
    pinMode(7,OUTPUT);
    lcd.begin(16, 2);
    // Print a message to the LCD.
    lcd.print("Les nbr des pas: ");
    
}

void loop() {

  Control_s_b_s_Motor(true,true,40,1);
  lcd.setCursor(0,1);
  lcd.println(rs);
  lcd.display();
}
