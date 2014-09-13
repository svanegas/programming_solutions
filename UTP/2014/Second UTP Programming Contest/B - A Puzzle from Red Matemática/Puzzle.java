
import java.math.BigInteger;
import java.util.Scanner;

/**
 *
 * @author Santiago
 */
public class Puzzle {

    private Scanner in = new Scanner(System.in);
    
    public void solve() {
        String digit;
        int times;
        while (in.hasNext()) {
            digit = in.next();
            times = in.nextInt();
            if (digit.equals("0")) break;
            String num = "";
            for (int i = 0; i < times; i++) {
                num += digit;
            }
            BigInteger bNum = new BigInteger(num);
            bNum = bNum.multiply(bNum);
            String sNum = bNum.toString();
            int ans = 0;
            for (int i = 0; i < sNum.length(); i++) {
                ans += Character.getNumericValue(sNum.charAt(i));
            }
            System.out.println(ans);
        }
    }
    
    public static void main(String[] args) {
        System.out.println("TLE");
        //new Puzzle().solve();
    }
}
