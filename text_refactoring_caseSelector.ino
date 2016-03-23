//поток данных:
//	Get запрос в функцию резки до состояния комманды
//	от туда в Case selector из loop
//	и из него уже по функциям через кейсы

void textRefactoring(string request){
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
		break;
		case 2:
		bitrewrite(input);
		break;
		case 3:
		AllLow();
		break;
		case 4:
		AllHigh();
		break;
		case 5:
		Serial.println("information function callback");
		break;
		default:
		memory();
		break;
	}
}

void HC165(){
bitWrite(resByteArray[0], latchPin_165, 1);//защёлка вверх
bitWrite(resByteArray[0], clockinh_165, 1);//ингибитор вверх
HC595(0);
bitWrite(resByteArray[0], latchPin_165,0);//защёлка вниз
HC595(0);
for (int i=5;i<9;i++){
	resByteArray[i]=shiftIn(dataPort, clockPin, LSBFIRST);
}
  bitWrite(resByteArray[0], clockinh_165, 0);//ингибитор вниз
  HC595(0); 
  serv_mes= "hc165 ";
  for (int i=5;i<9;i++){
  	serv_mes= serv_mes+String(resByteArray[i]);
  }
  Send_to_server(serv_mes);
}

void HC595(int wif){
digitalWrite(latchPin_595, LOW);  // проталкиваем байт в регистр
for (int i=4; i<=0; i--){
	shiftOut(dataPin, clockPin, MSBFIRST, resByteArray[i]); 
}
digitalWrite(latchPin_595, HIGH);
if (wif ==1){
	serv_mes= "hc595 ";
	for (int i=4; i<=0; i--){
		serv_mes+String(resByteArray[i]);
	}
	Send_to_server(serv_mes); 
}
}

void clock_out(){
  if (clock_min<2){
    if (clock_sek==60){
      clock_sek=0 ; 
      clock_min++; 
      if (clock_min == 60){
        clock_min=0;
        clock_ch++;
        String clock_str = String(clock_ch);
        int val=clock_str.length();
        if (val<2){
          int n=0;
          resByteArray[clock_1]=clock_set[n]; 
          n=clock_str.toInt();
          resByteArray[clock_2]=clock_set[n];
        }
        else{
          int n=(clock_str.substring(1,1)).toInt();
          resByteArray[clock_1]=clock_set[n];
          n=(clock_str.substring(2,1)).toInt();
          resByteArray[clock_2]=clock_set[n];
        }   
      }
      String clock_str = String(clock_min);
      int val=clock_str.length();
      if (val<2){
        int n=0;
        resByteArray[clock_3]=clock_set[n]; 
        n=clock_str.toInt();
        resByteArray[clock_4]=clock_set[n];
      }
      else{
        int n=(clock_str.substring(1,1)).toInt();
        resByteArray[clock_3]=clock_set[n];
        n=(clock_str.substring(2,1)).toInt();
        resByteArray[clock_4]=clock_set[n];
      }   
    }  
    }else if(clock_min==2 && clock_ch==10){
     if (resByteArray[5] & trub == trub){
      bitWrite(resByteArray[other1], gud, 0);
      clock_min=59;
      clock_ch=9;
      }else{
        if(clock_sek<30){
          bitWrite(resByteArray[other1], gud, 1);
          }else{
            bitWrite(resByteArray[other1], gud, 0);
            bitWrite(resByteArray[other1], pump, 1);
          }
        }
      }
      clock_sek++;
      HC595(1); 
    }