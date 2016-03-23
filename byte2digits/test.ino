int ports[7]={2,3,4,5,6,7,8};
byte byteDigit[10]={191,134,218,207,230,237,253,135,255,239};
char segm[7]={'a','b','c','d','e','f','g'};
void setup()
{
	for(int i=0; i<8; i++){
	    pinMode(ports[i], OUTPUT);
	}
Serial.begin(9600);
}//end setup
void loop()
{
for(int i=0; i<10; i++){
    Serial.println(i);
    Byte2digits(i);
    delay(1000);
}
}//end loop
void Byte2digits(int digit){
//clear pins
for(int i=0; i<7; i++){
    digitalWrite(ports[i],LOW);
}
for(int i=0; i<7; i++){
    if(bitRead(byteDigit[digit],i)==1){
        digitalWrite(ports[i], HIGH);
        Serial.print(segm[i]);
        Serial.print("=");
        Serial.println("1");
    } else {
    	Serial.print(segm[i]);
        Serial.print("=");
        Serial.println("0");
    }
}
}//end Byte2digits