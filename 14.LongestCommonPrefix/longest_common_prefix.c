char* longestCommonPrefix(char**strs, int strsSize) {
    if(strs == NULL || *strs == NULL)
        return "";
    
    int i = 0, minLen = (0x7fffffff), minId = 0, tmpLen = 0;
    for(; i < strsSize; i ++)
    {
    	tmpLen = strlen(strs[i]);

		if(tmpLen < minLen){
			minLen = tmpLen;
			minId = i;			
		}	
    }
    
    tmpLen = minLen;
    
    while(minLen)
    {
		for(i = 0; i < strsSize	; i ++){
			if(i == minId){
				continue;
			}
			
			if(strncmp(strs[i], strs[minId], tmpLen)){
				tmpLen --;
				break;
			}
		}
		
		if(!(tmpLen ^ minLen)){
			break;	
		}
		
		minLen --;
    }
    
    char *prefix = malloc(sizeof(char) * tmpLen + 1);
    memset(prefix, 0, sizeof(char) * tmpLen + 1);
    strncpy(prefix, strs[minId], tmpLen);
    
	return prefix;
}
