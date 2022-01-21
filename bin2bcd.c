
// most of the processors can make mathematical process like shifting and multipling
// divide process can take long time if compare with shifting and multipling
// in an ordinary bin to bcd convertion a lots of divide or subtraction process should be made
// the function below can made this with very fast and elegant way.

unsigned char bcd_digits[6];

// the fast 16bit binary to bcd function
void bin2bcd(unsigned int value) 
{ 
  unsigned int temp16 = value; unsigned char d0, d1, d2, d3, d4, q;

  d1 = ( temp16 >> 4 ) & 0x0F;
  d2 = ( temp16 >> 8 ) & 0x0F;
  d3 = ( temp16 >> 12) & 0x0F;

  d0 = 6*(d3 + d2+ d1) + ( temp16 & 0x0F );
  q = (d0 * 0xCD) >> 11;
  d0 = d0 - 10*q;

  d1 = q + 9*d3 + 5*d2 + d1;
  q = (d1 * 0xCD) >> 11;
  d1 = d1 - 10*q;

  d2 = q + 2*d2;
  q = (d2 * 0x1A) >> 8;
  d2 = d2 - 10*q;

  d3 = q + 4*d3;
  d4 = (d3 * 0x1A) >> 8;
  d3 = d3 - 10*d4;

  bcd_digits[4] = d0; // the least significant bcd
  bcd_digits[3] = d1;
  bcd_digits[2] = d2;
  bcd_digits[1] = d3;
  bcd_digits[0] = d4; // the most significant bcd
  // it can convert up to 16bit
  // this means output can be at most 5 binary coded digits (65535)
}
