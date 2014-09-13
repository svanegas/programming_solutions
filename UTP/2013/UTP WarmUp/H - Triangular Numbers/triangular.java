
import java.math.BigInteger;
import java.util.Scanner;

/**
 *
 * @author Santiago
 */
public class Main{
    
    BigInteger cero = BigInteger.ZERO;

    public Main() {
        BigInteger n;
        Scanner in = new Scanner(System.in);
        n = in.nextBigInteger();
        while (n.compareTo(cero) == 1) {
            BigInteger sq = n.multiply(new BigInteger("8")).add(new BigInteger("1"));
            BigInteger root = sqrt(sq);
            if (root.multiply(root).compareTo(sq) == 0) System.out.println("YES");
            else System.out.println("NO");
            n = in.nextBigInteger();
        }
    }
    
    public BigInteger sqrt(BigInteger n) {
        final int bitLength = n.bitLength();
        BigInteger root = BigInteger.ONE.shiftLeft(bitLength / 2);
        while (!isSqrt(n, root)) {
            root = root.add(n.divide(root)).divide(new BigInteger("2"));
        }
        return root;
    }
    
    public boolean isSqrt(BigInteger n, BigInteger root) {
        final BigInteger lowerBound = root.pow(2);
        final BigInteger upperBound = root.add(BigInteger.ONE).pow(2);
        return lowerBound.compareTo(n) <= 0 && n.compareTo(upperBound) < 0;
    }
    
    public static void main(String[] args) {
        new Main();
    }
}
