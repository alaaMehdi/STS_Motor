int T;
void Control_s_b_s_Motor(boolean ON,boolean SENSE,int SPEED,/*[0..100]*/int Nb_Steps/*00 if=0*/){

    if(ON==false){

      digitalWrite(10,LOW);digitalWrite(11,LOW);digitalWrite(12,LOW);digitalWrite(13,LOW);
      return;
      
    }
    else{

      T=(100-SPEED)*10;
      
      if(SENSE==true){

        //Position 1
          digitalWrite(10,HIGH);digitalWrite(11,LOW);digitalWrite(12,LOW);digitalWrite(13,LOW);delay(T);
          
        //Position 2
          digitalWrite(10,LOW);digitalWrite(11,HIGH);digitalWrite(12,LOW);digitalWrite(13,LOW);delay(T);
          
        //Position 3
          digitalWrite(10,LOW);digitalWrite(11,LOW);digitalWrite(12,HIGH);digitalWrite(13,LOW);delay(T);
          
        //Position 4
          digitalWrite(10,LOW);digitalWrite(11,LOW);digitalWrite(12,LOW);digitalWrite(13,HIGH);delay(T);
        
      }
      else{

        //Position 1
          digitalWrite(10,HIGH);digitalWrite(11,LOW);digitalWrite(12,LOW);digitalWrite(13,LOW);delay(T);
          
        //Position 2
          digitalWrite(10,LOW);digitalWrite(11,HIGH);digitalWrite(12,LOW);digitalWrite(13,LOW);delay(T);
          
        //Position 3
          digitalWrite(10,LOW);digitalWrite(11,LOW);digitalWrite(12,HIGH);digitalWrite(13,LOW);delay(T);
          
        //Position 4
          digitalWrite(10,LOW);digitalWrite(11,LOW);digitalWrite(12,LOW);digitalWrite(13,HIGH);delay(T);
        
      }

      
    }

    


    


}

void setup() {
  
    pinMode(10,OUTPUT);
    pinMode(11,OUTPUT);
    pinMode(12,OUTPUT);
    pinMode(13,OUTPUT);
    
    
}

void loop() {

  Control_s_b_s_Motor(true,true,50,10);

}
