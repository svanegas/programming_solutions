import java.util.Scanner;

public class Main {

    private java.math.BigInteger diez = java.math.BigInteger.TEN;
    private java.math.BigInteger cero = java.math.BigInteger.ZERO;
    
    public void f() {
        Scanner in = new Scanner(System.in);
        java.math.BigInteger num = in.nextBigInteger();
        while (num.compareTo(cero) != 0) {
            System.out.println(toDecimal(num));
            num = in.nextBigInteger();
        }
    }
    
    public int toDecimal(java.math.BigInteger n) {
        int ans = 0;
        int mult = 1;
        while (n.compareTo(cero) == 1) {
            ans += (n.mod(diez)).multiply(new java.math.BigInteger(String.valueOf(mult))).intValue();
            mult *= 2;
            n = n.divide(diez);
        }
        return ans;
    }
    
    public static void main(String[] args) {
        new Main().f();
    }
}
