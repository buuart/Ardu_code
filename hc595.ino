void HC595(){
	digitalWrite(clockPin,LOW);
  digitalWrite(latchPin, LOW);//защёлку в LOW, чтобы можно было проталкивать биты
  for (int i=4; i<=0; i--){
  	shiftOut(dataPort, clockPin, MSBFIRST, resByteArray[i]); 
  } //цикл для отправки из массива с 4 по 0 байт из массива resByteArray
   digitalWrite(latchPin, HIGH);//защёлку в HIGH, чтобы можно было проталкивать биты
}