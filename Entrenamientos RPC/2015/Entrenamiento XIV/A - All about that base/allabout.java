
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author svanegas
 */
public class allabout {

  public static int count1(String text) {
    int count = 0;
    for (int i = 0; i < text.length(); ++i) {
      if (text.charAt(i) == '1') count++;
    }
    return count;
  }

  public static BigInteger calc(BigInteger x, BigInteger y, String op) {
    if (op.equals("+")) return x.add(y);
    else if (op.equals("-")) return x.subtract(y);
    else if (op.equals("*")) return x.multiply(y);
    else {
      if (y.compareTo(BigInteger.ZERO) == 0) return new BigInteger("9999999999999999999999");
      else {
        if (x.remainder(y).compareTo(BigInteger.ZERO) == 0) {
          return x.divide(y);
        }
        else return new BigInteger("9999999999999999999999");
      }
    }
  }

  public static BigInteger MAXI = new BigInteger("4294967295");

  public static boolean verify(BigInteger val) {
    if (val.compareTo(MAXI) == 1) return false;
    if (val.compareTo(BigInteger.ONE) == -1) return false;
    return true;
  }

  public static boolean go(BigInteger x, BigInteger y, BigInteger z, String op) {
    if (verify(x) && verify(y) && verify(z)) {
      BigInteger caca = calc(x, y, op);
      if (verify(caca) && caca.compareTo(z) == 0) {
        return true;
      }
    }
    return false;
  }

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int n = in.nextInt();
    for (int i = 0; i < n; ++i) {
      ArrayList <Integer> ans = new ArrayList<Integer>();
      String left, op, right, res;
      left = in.next(); op = in.next(); right = in.next();
      res = in.next(); res = in.next();
      if (count1(left) == left.length() && count1(right) == right.length() &&
          count1(res) == res.length()) {
        BigInteger x = new BigInteger("" + left.length());
        BigInteger y = new BigInteger("" + right.length());
        BigInteger z = new BigInteger("" + res.length());
        if (go(x, y, z, op)) ans.add(1);
      }
      for (int j = 2; j <= 36; ++j) {
        try {
          BigInteger x = new BigInteger(left, j);
          BigInteger y = new BigInteger(right, j);
          BigInteger z = new BigInteger(res, j);
          if (go(x, y, z, op)) ans.add(j);
        }
        catch (java.lang.NumberFormatException ex) {

        }
      }
      if (ans.isEmpty()) {
        System.out.println("invalid");
      }
      else {
        for (int k = 0; k < ans.size(); ++k) {
          int cur = ans.get(k);
          if (cur >= 10) {
            char x = 'a';
            x += (cur - 10);
            if (x > 'z') System.out.print(0);
            else System.out.print(x);
          }
          else System.out.print(cur);
        }
        System.out.println("");
      }
    }
  }
}
