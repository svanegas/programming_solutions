

import java.math.BigInteger;
import java.util.Scanner;

/**
 *
 * @author Estudiante
 */
public class ones {

    private BigInteger n;
    private BigInteger num;

    private void solve() {
        Scanner in = new Scanner(System.in);
        while (in.hasNext()) {
            int cont = 1;
            num = BigInteger.ONE;
            n = in.nextBigInteger();
            while (!num.mod(n).equals(BigInteger.ZERO)) {
                num = num.multiply(BigInteger.TEN);
                num = num.add(BigInteger.ONE);
                cont++;
            }
            System.out.println(cont);
        }
    }

    public static void main(String[] args) {
        new ones().solve();
    }

}
