int dataPin =34;
int clockPin=35;
int latchPin=22;
int dataPort =23;
String string = "";
byte resByteArray[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};//с 0 по 4 shiftOut c 5 по 8 ShiftIn
String stringVar;
void setup() {
	Serial.begin(9600);
	Serial.println("We ready to transmition");
}
void loop() {
  Serial.setTimeout(2000); // таймаут
  string = Serial.readStringUntil(33);// символ окончания строки "/"
  textRefactoring(string);
}
void memory() {
	for (int i = 0; i < (sizeof(resByteArray)); i++) {
		Serial.println(String (resByteArray[i], BIN));
	}
}
void ByteWrite(String input) {//запись в массив
  //Serial.print("length "); //слово длина
  int inputlen = input.length();
  for (int i = 0; i < inputlen / 3; i++) {
  	String post = input.substring(i * 3, ((i * 3) + 3));
    //Serial.println(post);
    byte intvar = post.toInt(); //две строки для преобразования
    resByteArray[i] = intvar;//
}
}
void bitrewrite(String input){
	int len  = input.length();
	for (int i = 0; i < len / 3; i++) {
		String post = input.substring(i * 3, ((i * 3) + 3));
		int x = (post.substring(0, 1)).toInt();
		int y = (post.substring(1, 2)).toInt();
		int val = (post.substring(2, 3)).toInt();
		bitWrite(resByteArray[x],y,val);
	}
}
void HC595(){
	digitalWrite(clockPin,LOW);
  digitalWrite(latchPin, LOW);//защёлку в LOW, чтобы можно было проталкивать биты
  for (int i=4; i<=0; i--){
  	shiftOut(dataPort, clockPin, MSBFIRST, resByteArray[i]); 
  } //цикл для отправки из массива с 4 по 0 байт из массива resByteArray
   digitalWrite(latchPin, HIGH);//защёлку в HIGH, чтобы можно было проталкивать биты
}
void AllHigh(){
	for (int i=0;i<5;i++){
		resByteArray[i]=255;
	}
}
void AllLow(){
	int chngd=0;
	for (int i=0;i<5;i++){
		resByteArray[i]=0;
	}
}
void HC165(){//дописать защёлку на PL
	digitalWrite(clockPin,LOW);
	for (int i=5;i<9;i++){
		resByteArray[i]=shiftIn(dataPin, clockPin, LSBFIRST);
	}
}

void textRefactoring(String request){
	String newResultat;
	int i = request.indexOf(' ');
	int o = request.lastIndexOf(' ');
	newResultat = request.substring(i+2, o);
	caseSelector(newResultat);
}

void caseSelector(String message){
	int selector=message.substring(0,1).toInt();
	int messageLength = message.length();
	String input = message.substring(1, messageLength + 1);
	switch (selector) {
		case 1:
		ByteWrite(input);
		memory();
		break;
		case 2:
		bitrewrite(input);
		memory();
		break;
		case 3:
		AllLow();
		memory();
		break;
		case 4:
		AllHigh();
		memory();
		break;
		case 5:
		Serial.println("information function callback");
		Serial.println("1 is for byte");
		Serial.println("2 is for bits");
		Serial.println("3 is for clear AllLow");
		Serial.println("4 is for clear AllHigh");
		break;
		default:
		break;
	}
}
void hourChange(int hr, int minu){
int hrD = hr / 10;
int hr0 = hr % 10;
int miD = minu/10;
int mi0 = minu % 10;
resByteArray[1]=clock_set[hrD];
resByteArray[2]=clock_set[hr0];
resByteArray[3]=clock_set[miD];
resByteArray[4]=clock_set[mi0];
}
