/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.math.BigInteger;
import java.util.Scanner;

/**
 *
 * @author svanegas
 */
public class catalan {

  private BigInteger [] fact = new BigInteger[10005];
  private Scanner in = new Scanner(System.in);
  
  private BigInteger sn(int n) {
    BigInteger num = fact[2 * n];
    BigInteger den = fact[n].multiply(fact[n + 1]);
    return num.divide(den);
  }
  
  public void go() {
    fact[0] = BigInteger.ONE;
    fact[1] = BigInteger.ONE;
    for (int i = 2; i <= 10002; ++i) {
      fact[i] = fact[i-1].multiply(new BigInteger("" + i));
    }
    int x = in.nextInt();
    System.out.println(sn(x + 1));
  }
  
  public static void main(String[] args) {
    new catalan().go();
  }
}
