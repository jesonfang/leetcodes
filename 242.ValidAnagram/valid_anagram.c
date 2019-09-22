int cmp( const void *a , const void *b )   
{   
    return *(char *)a - *(char *)b;   
}  

bool isAnagram(char* s, char* t) {
    char buff[128] = {0};
    char buff_new[128] = {0};
    
    if(s == NULL || t == NULL)
        return false;
    
    if (strlen(s) != strlen(t))
        return false;
    
    qsort(s, strlen(s), sizeof(char), cmp);
    qsort(t, strlen(t), sizeof(char), cmp);
    
    if (strcmp(s, t))
    {
        return false;
    }
    else
    { 
        return true;
    }
}
