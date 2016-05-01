import java.math.BigInteger;
import java.util.Scanner;

public class advanced {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.hasNextBigInteger()) {
            BigInteger a = in.nextBigInteger();
            if (a.compareTo(BigInteger.ZERO) == 0) break;
            a = a.multiply(a.add(BigInteger.ONE)).divide(new BigInteger("2"));
            a = a.multiply(a);
            System.out.println(a.mod(new BigInteger("10000000000")));
        }
    }
}
