#include "Ultrasonic.h"
#include "Timer.h"

typedef enum Direction {
  FRONT,
  LEFT,
  RIGHT,
  BACK
} Direction;

Ultrasonic front(3, 4);
Ultrasonic right(A1, A2);
Ultrasonic left(A3, A4);
Timer customTime;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  customTime.every(100,loopAgain);
}

void loop() {
  customTime.update();
}

void loopAgain(){
  Direction direction = ultrasonicSensor();
  switch (direction){
    case FRONT:
      Serial.println("Front");
      break;
    case LEFT:
      Serial.println("left");
      break;
    case RIGHT:
     Serial.println("right");
      break;
    case BACK:
      Serial.println("back");
      break;
      
  }
}

Direction ultrasonicSensor() {
  // put your main code here, to run repeatedly:
  long frontMillsecon = front.timing();
  float frontDistance = front.convert(frontMillsecon, Ultrasonic::CM);
  //Serial.print("Front-->");
  //Serial.println(frontDistance);
  //left
  long leftMillsecon = left.timing();
  float leftDistance = front.convert(leftMillsecon, Ultrasonic::CM);
  //Serial.print("Left-->");
  //Serial.println(leftDistance);

  //right
  long rightMillsecon = right.timing();
  float rightDistance = right.convert(rightMillsecon, Ultrasonic::CM);
  //Serial.print("Right-->");
  //Serial.println(rightDistance);

  
  if (frontDistance > 50){
    return FRONT;
  }else if (leftDistance > 50){
    return LEFT;
  }else if(rightDistance > 50){
    return RIGHT;
  }else{
    return BACK;
  }
  
}
