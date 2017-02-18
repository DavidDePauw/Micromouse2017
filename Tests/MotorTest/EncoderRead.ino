void encoderLeftR () {
  Serial.print("Left Encoder Reverse: ");
  Serial.println(analogRead(EncLeft_r));
  
}

void encoderRightR () {
  Serial.print("Right Encoder Reverse: ");
  Serial.println(analogRead(EncRight_r));
}

void encoderLeftF (){
  Serial.print("Left Encoder Forward: ");
  Serial.println(analogRead(EncLeft_f));
}

void encoderRightF () {
  Serial.print("Right encoder Forward: ");
  Serial.println(analogRead(EncRight_f));
}

