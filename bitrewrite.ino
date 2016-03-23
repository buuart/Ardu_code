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