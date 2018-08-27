#include <Servo.h>   
#include <SerialCommand.h>
SerialCommand SCmd;   // The demo SerialCommand object
Servo servo[4][3];

//define servos' ports
const int servo_pin[4][3] = { {2, 3, 4}, {5, 6, 7}, {8, 9, 10}, {11, 12, 13} };
int pos = 0;
void setup()
{
  //initialize all servos
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      servo[i][j].attach(servo_pin[i][j]);
      delay(100);
    }
  }
  Serial.begin(9600);
   while(!Serial) {
    ; //Aguarda conexão da porta. Necessário apenas para placas com USB nativa (como o Arduino Leonardo)
   } //Fim do while

}


void loop() {
  // put your main code here, to run repeatedly:

  delay(1000);
  
 
  
  if (Serial.available()) { // Verificar se há caracteres disponíveis
    char caractere = Serial.read(); // Armazena caractere lido
    Serial.println(caractere);
    
  
    // in steps of 1 degree
      if(caractere == 'a'){
        Serial.println(caractere);
        for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
          servo[0][0].write(pos);
           delay(3);
        }
      }else if(caractere == 's'){
        Serial.println(caractere);
        for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
          servo[0][1].write(pos);
          delay(3);
        }
      }else if(caractere == 'd'){
        Serial.println(caractere);
        for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
          servo[0][2].write(pos);
          delay(3);
        }
      }
     
   
  }
  
  
}


void andar_frente(){
  for(pos = 0; pos <= 30; pos++){
    servo[0][0].write(pos);
  }
   for(pos = 0; pos <= 30; pos++){
    servo[0][1].write(pos);
  }
   for(pos = 0; pos <= 20; pos++){
    servo[0][2].write(pos);
  }
   for(pos = 30; pos >= 0; pos--){
    servo[0][0].write(pos);
  }
//-----------------/
for(pos = 0; pos <= 30; pos++){
    servo[2][0].write(pos);
  }
   for(pos = 0; pos <= 30; pos++){
    servo[2][1].write(pos);
  }
   for(pos = 20; pos >= 0; pos++){
    servo[2][2].write(pos);
  }
   for(pos = 30; pos >= 0; pos--){
    servo[2][0].write(pos);
  }
//--------------/
for(pos = 0; pos <= 30; pos++){
    servo[1][0].write(pos);
  }
   for(pos = 0; pos <= 30; pos++){
    servo[1][1].write(pos);
  }
   for(pos = 0; pos <= 20; pos--){
    servo[1][2].write(pos);
  }
   for(pos = 30; pos >= 0; pos--){
    servo[1][0].write(pos);
  }
//---------------------/
  for(pos = 0; pos <= 30; pos++){
    servo[3][0].write(pos);
  }
   for(pos = 0; pos <= 30; pos++){
    servo[3][1].write(pos);
  }
   for(pos = 20; pos >= 0; pos--){
    servo[3][2].write(pos);
  }
   for(pos = 30; pos >= 0; pos--){
    servo[3][0].write(pos);
  }

}

void girar(){
  
}

void iniciar(){
  for(pos = 0; pos <=45; pos++){
    servo[0][0].write(pos);
  }
  for(pos = 0; pos <= 135; pos++){
    servo[0][2].write(pos);
  }
//  ------------------------/
for(pos = 0; pos <=45; pos++){
    servo[1][0].write(pos);
  }
  for(pos = 0; pos <= 135; pos++){
    servo[1][2].write(pos);
  }
//  ------------------------/
for(pos = 0; pos <=45; pos++){
    servo[2][0].write(pos);
  }
  for(pos = 0; pos <= 135; pos++){
    servo[2][2].write(pos);
  }
//  ------------------------/
for(pos = 0; pos <=45; pos++){
    servo[3][0].write(pos);
  }
  for(pos = 0; pos <= 135; pos++){
    servo[3][2].write(pos);
  }
//  ------------------------/
}

