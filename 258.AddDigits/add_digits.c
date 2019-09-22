int addDigits(int num) {
    int res = 0;
    res = (num - 1) % 9 + 1;
    return res;
}
