import java.util.Calendar;
import java.util.Scanner;

public class Main {

  private Scanner in;
  private Calendar cal;

  public void go() {
    in = new Scanner(System.in);
    cal = Calendar.getInstance();
    int add, dd, mm, yy;
    add = in.nextInt();
    dd = in.nextInt();
    mm = in.nextInt();
    yy = in.nextInt();
    while (add != 0 || dd != 0 || mm != 0 || yy != 0) {
      cal.set(Calendar.DAY_OF_MONTH, dd);
      cal.set(Calendar.MONTH, mm - 1);
      cal.set(Calendar.YEAR, yy);
      cal.add(Calendar.DAY_OF_YEAR, add);
      System.out.println(cal.get(Calendar.DAY_OF_MONTH) + " " +
                         (cal.get(Calendar.MONTH) + 1) + " " +
                         cal.get(Calendar.YEAR));
      add = in.nextInt();
      dd = in.nextInt();
      mm = in.nextInt();
      yy = in.nextInt();
    }
  }

  public static void main(String [] args) {
    new Main().go();
  }

}
