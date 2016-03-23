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