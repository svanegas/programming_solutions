import java.math.BigInteger;
import java.util.Scanner;

/**
 *
 * @author Santiago
 */
public class Main {
    
    BigInteger cero = BigInteger.ZERO;
    BigInteger uno = BigInteger.ONE;
    BigInteger dos = new BigInteger("2");
    
    public Main() {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        while (t > 0) {
            int n = 0, e = 0;
            BigInteger mayor = cero;
            for (int i = 0; i < t; i++) {
                BigInteger a, b;
                a = in.nextBigInteger();
                b = in.nextBigInteger();
                BigInteger res = modulo(a, b);
                if (res.compareTo(mayor) == 1) {
                    n = a.intValue();
                    e = b.intValue();
                    mayor = res;
                }
            }
            System.out.println(n + " " + e);
            t = in.nextInt();
        }
    }
    
    public BigInteger modulo(BigInteger a, BigInteger b) {
        BigInteger x = new BigInteger("1");
        BigInteger y = new BigInteger(String.valueOf(a));
        while (b.compareTo(cero) == 1) {
            if ((b.mod(dos)).compareTo(uno) == 0) {
                x = (x.multiply(y));
            }
            y = (y.multiply(y));
            b = b.divide(dos);
        }
        return x;
    }
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        new Main();
    }
}