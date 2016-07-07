void replaceSpace(char *str, int length) {	
	int i = 0, j = 0,cnt=0;
	char *s = new char[length*3+5];
	while (str[i] != '\0'){
		if (str[i] == ' '){
			s[j++] = '%'; s[j++] = '2'; s[j++] = '0';
		}
		else{
			s[j++] = str[i];
		}
		++i;
	}
	s[j] = '\0';
	i = 0;
	for (; s[i] != '\0'; ++i)
		str[i] = s[i];
	str[i] = '\0';
	delete[]s;
}