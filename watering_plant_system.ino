/*******************automatic plant watering system*******************/
/* Title:Automatic plant watering system 
 * Author: Laya Mathikshara
 * Date of creation: 14.05.2019
 * MCU: Arduino Uno
 * Sensors: water level depth detection sensor module
 * Actuator: Micro servo 9g sg90
 * Pinout: 
 *        Micro servo - 11(pwm)
 *        Water Level sensor - A2
 */
// Includes 
#include<Servo.h>

// Motor object
Servo motor;
 
void setup() 
{
  //attaching servo motor 
  motor.attach(11);
  
  //water level sensor 
  pinMode(A2,INPUT);
 
  //serial moniter begins
  Serial.begin(9600);
}

void loop()
{
  int reading=analogRead(A2);
  
  //The readings will be printed in the serial monoter
  Serial.println(reading);
  delay(1000);

  //If the reading in the sensor is less than 325 then the servo motor moves.
  if(reading<=325)
  {
    //Motion of Servo Motor.
    motor.write(0);
    delay(1000);
    motor.write(90); 
    delay(2000);
    motor.write(0)
  }
}

