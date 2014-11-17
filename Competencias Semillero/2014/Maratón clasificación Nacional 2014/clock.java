import java.util.Calendar;
import java.util.Scanner;

/**
 *
 * @author cl18311
 */
public class clock {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Calendar cal = Calendar.getInstance();
        Scanner in = new Scanner(System.in);
        while (in.hasNextInt()) {
            int h = in.nextInt();
            int m = in.nextInt();
            if (h == -1) break;
            cal.set(Calendar.HOUR_OF_DAY, h);
            cal.set(Calendar.MINUTE, m);
            cal.add(Calendar.MINUTE, -45);
            System.out.print(cal.get(Calendar.HOUR_OF_DAY));
            System.out.println(" " + cal.get(Calendar.MINUTE));
        }
    }
    
}
