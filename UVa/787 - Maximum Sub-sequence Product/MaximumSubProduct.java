/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

import java.math.BigInteger;
import java.util.Scanner;

/**
 *
 * @author Santiago
 */
public class Main {

    private final int MAXN = 105;
    private BigInteger [] arr = new BigInteger[MAXN];
    private BigInteger end = new BigInteger("-999999");
    private int n;

    public void run() {
        Scanner in = new Scanner(System.in);
        n = 0;
        while (in.hasNextBigInteger()) {
            BigInteger xi = in.nextBigInteger();
            if (xi.compareTo(end) == 0) {
                System.out.println(reventar());
                n = 0;
                continue;
            }
            arr[n] = xi;
            if (n > 0 && arr[n-1].compareTo(BigInteger.ZERO) != 0) {
                arr[n] = arr[n].multiply(arr[n-1]);
            }
            n++;
        }
    }

    public BigInteger reventar() {
        BigInteger ans = arr[0];
        for (int i = 0; i < n; i++) {
            if (arr[i].compareTo(BigInteger.ZERO) == 0) continue;
            for (int j = i; j < n; j++) {
                BigInteger res = arr[j];
                if (i > 0 && arr[i-1].compareTo(BigInteger.ZERO) != 0) {
                    res = res.divide(arr[i-1]);
                }
                if (res.compareTo(ans) == 1) {
                    ans = res;
                }
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        new Main().run();
    }
}
