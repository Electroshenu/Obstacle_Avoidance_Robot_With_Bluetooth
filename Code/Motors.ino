int speed = 255; //change this value to increase or decrease the speed. (0-255)You will get better result by calibrating by yourself

void FRONT(){  
  M.motor(1, FORWARD, speed);
  M.motor(2, FORWARD, speed);
  M.motor(3, FORWARD, speed);
  M.motor(4, FORWARD, speed);
} 

void LEFT(){
  M.motor(1, BACKWARD, speed);
  M.motor(2, BACKWARD, speed);
  M.motor(3, FORWARD, speed);
  M.motor(4, FORWARD, speed);
}

void RIGHT(){
  M.motor(1, FORWARD, speed);
  M.motor(2, FORWARD, speed);
  M.motor(3, BACKWARD, speed);
  M.motor(4, BACKWARD, speed);
}

void BACK(){
  M.motor(1, BACKWARD, speed);
  M.motor(2, BACKWARD, speed);
  M.motor(3, BACKWARD, speed);
  M.motor(4, BACKWARD, speed);
}

void STOP(){
  M.motor(1, FORWARD, 0);
  M.motor(2, FORWARD, 0);
  M.motor(3, FORWARD, 0);
  M.motor(4, FORWARD, 0);
}