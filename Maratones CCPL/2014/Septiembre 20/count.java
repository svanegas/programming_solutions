import java.math.BigInteger;
import java.util.Scanner;

/**
 *
 * @author Santiago
 */
public class count {
    
    private static int n;
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.hasNextInt()) {
            n = in.nextInt();
            if (n == 0) break;
            BigInteger ans = BigInteger.ONE;
            for (int i = n + 2; i <= n * 2; i++) {
                ans = ans.multiply(new BigInteger(i + ""));
            }
            System.out.println(ans);
        }
    }
}
