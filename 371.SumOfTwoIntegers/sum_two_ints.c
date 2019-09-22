int getSum(int a, int b) 
{
  int carry, add;
  do {
    add = a ^ b;
    carry = (a & b) << 1;
    a = add;
    b = carry;
  } while(carry != 0);
  return add;
}
