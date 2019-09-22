char findTheDifference(char* s, char* t) {
    if (s == NULL || t == NULL)
        return '\0';
    
    int a[128] = {0};
    int b[128] = {0};

    int i = 0; 
    
    for (; i < strlen(s); i ++)
    {
        a[*(s+i)] += 1;
    }
    
    for(i = 0; i < strlen(t); i ++)
    {
        b[*(t+i)] += 1;
    }
    
    for (i = 96; i < 123; i ++)
    {
        if (a[i] != b[i])
        {
              break;  
        }
    }
    
    return (i);
}

char findTheDifference1(char* s, char* t) {
    if (s == NULL || t == NULL)
        return '\0';
    
    int a[256] = {0};
    int b[256] = {0};

    int i = 0; 
    
    for (; i < strlen(s); i ++)
    {
        a[*(s+i)] += 1;
    }
    
    for(i = 0; i < strlen(t); i ++)
    {
        b[*(t+i)] += 1;
    }
    
    for (i = 96; i < 256; i ++)
    {
        printf("a=[%d]=%d, b[%d]=%d\n", i , a[i], i , b[i]);
        
        if (a[i] != b[i])
        {
              break;  
        }
    }
    
    return (i);
}

