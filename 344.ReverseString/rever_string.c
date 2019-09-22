char* reverseString(char* rs)
{
    char *p = NULL, *q = NULL, *mid = NULL;
	char tmp = '\0';
	int i, len;
	len = strlen(rs);
	
	//printf("len=%d\n", len);
	char *s = malloc(len + 1);
	memset(s, 0, len+1);
	strncpy(s, rs, len);
	
	if (len <= 1)
		return rs;
		
	if (len % 2 == 0)
	{
		for(i = 0; i < len / 2; i ++)
		{
			tmp = s[i];
			s[i] = s[len - i - 1];
			s[len - i - 1] = tmp;
		}	
	}
	else
	{
		p = &s[0];
		mid = &s[(len / 2) + 1];//middle elem
		q = &s[len - 1];
		
		while(p != mid)
		{
			tmp = *p;
			*p = *q;
			*q = tmp;
			
			p ++;
			q --;
		}
	}
	
	return s;
}
