/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;

/* Name of the class has to be "Main" only if the class is public. */
class a
{
  public static void main (String[] args) throws java.lang.Exception
  {
    Scanner in = new Scanner(System.in);
    int z = 1;
    while (in.hasNextBigInteger()) {
      BigInteger v1, d1, v2, d2;
      v1 = in.nextBigInteger();
      d1 = in.nextBigInteger();
      v2 = in.nextBigInteger();
      d2 = in.nextBigInteger();
      if (v1.compareTo(BigInteger.ZERO) == 0) break;
      BigInteger num = d1.multiply(v2);
      num = num.add(v1.multiply(d2));
      BigInteger den = v1.multiply(v2.multiply(new BigInteger("2")));
      BigInteger by = num.gcd(den);
      num = num.divide(by);
      den = den.divide(by);
      System.out.print("Case #" + z + ": ");
      z++;
      BigInteger mcm = v1.multiply(v2);
      mcm = mcm.divide(v1.gcd(v2));
      BigInteger one = d1.multiply(mcm.divide(v1));
      BigInteger two = d2.multiply(mcm.divide(v2));
      if (one.compareTo(two) == -1) System.out.println("You owe me a beer!");
      else System.out.println("No beer for the captain.");
      System.out.print("Avg. arrival time: " + num);
      if (den.compareTo(BigInteger.ONE) == 1) System.out.print("/" + den);
      System.out.println("");
    }
  }
}
