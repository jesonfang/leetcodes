bool isPowerOfThree(int n) {
    if (n <= 0)
        return false;
    
    while(0 == (n % 3)){
        n/=3;
    }    
    
    return (n == 1);
}
