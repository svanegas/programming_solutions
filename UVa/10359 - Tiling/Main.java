import java.math.BigInteger;
import java.util.Scanner;


public class Main {

    private final int n = 255;
    private BigInteger [] dp = new BigInteger[n];
    
    public void solve() {
        Scanner in = new Scanner(System.in);
        build();
        while (in.hasNext()) {
            int x = in.nextInt();
            System.out.println(dp[x]);
        }
    }
    
    public void build() {
        dp[0] = dp[1] = BigInteger.ONE;
        dp[2] = new BigInteger("3");
        dp[3] = new BigInteger("5");
        for (int i = 4; i <= 252; i++) {
            dp[i] = dp[i-2].multiply(new BigInteger("2"));
            dp[i] = dp[i].add(dp[i-1]);
        }
    }
    
    public static void main(String[] args) {
        new Main().solve();
    }
}
