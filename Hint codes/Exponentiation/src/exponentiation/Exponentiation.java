
package exponentiation;

import java.math.BigInteger;
import java.util.Scanner;
/**
 *
 * @author Santiago
 */
public class Exponentiation {

    private BigInteger res;
    
    public Exponentiation() {
        Scanner in = new Scanner(System.in);
        int n;
        n = in.nextInt();
        while (n != 0) {
            res = new BigInteger("0");
            String ans = "";
            for (int i = 0; i < n; i++) {
                BigInteger b = in.nextBigInteger();
                int e = in.nextInt();
                BigInteger op = potencia(b, e);
                if (res.compareTo(op) == -1) {
                    res = op;
                    ans = b + " " + e;
                }
            }
            System.out.println(ans);
            n = in.nextInt();
        }
    }
    
    public BigInteger potencia(BigInteger a, int n) {
        return a.pow(n);
    }

    public static void main(String[] args) {
        new Exponentiation();
    }
}
