void HC165(){//дописать защёлку на PL
	digitalWrite(clockPin,LOW);
	for (int i=5;i<9;i++){
		resByteArray[i]=shiftIn(dataPin, clockPin, LSBFIRST);
	}
}