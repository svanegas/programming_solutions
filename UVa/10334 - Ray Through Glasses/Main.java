
import java.math.BigInteger;
import java.util.Scanner;

/**
 *
 * @author Santiago
 */
public class Main {
    
    private final int MAXN = 1005;
    private BigInteger [] fib = new BigInteger[MAXN];
    
    public void solve() {
        fib[0] = BigInteger.ONE;
        fib[1] = new BigInteger("2");
        fib[2] = new BigInteger("3");
        for (int i = 3; i < MAXN; i++) fib[i] = fib[i-1].add(fib[i-2]);
        Scanner in = new Scanner(System.in);
        while (in.hasNextInt()) {
            int x = in.nextInt();
            System.out.println(fib[x]);
        }
    }
    
    public static void main(String[] args) {
        new Main().solve();
    }
}
