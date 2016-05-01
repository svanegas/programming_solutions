import java.math.BigInteger;
import java.util.Scanner;

public class dividing {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.hasNextLine()) {
            String a = in.nextLine();
            BigInteger b = new BigInteger(a, 16);
            if (b.mod(new BigInteger("17")) == BigInteger.ZERO) System.out.println("yes");
            else System.out.println("no");
        }
    }
    
}
