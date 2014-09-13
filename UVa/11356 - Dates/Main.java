import java.util.Calendar;
import java.util.Scanner;

public class Main {

    private Calendar cal = Calendar.getInstance();
    
    public void readDate(String date) {
        int i = 0;
        String year = "", month = "", day = "";
        while (date.charAt(i++) != '-') year += date.charAt(i-1);
        while (date.charAt(i++) != '-') month += date.charAt(i-1);
        while (i++ < date.length()) day += date.charAt(i-1);
        cal.set(Integer.parseInt(year), getMonth(month), Integer.parseInt(day));
    }
    
    public int getMonth(String month) {
        if (month.equals("January")) return 0;
        if (month.equals("February")) return 1;
        if (month.equals("March")) return 2;
        if (month.equals("April")) return 3;
        if (month.equals("May")) return 4;
        if (month.equals("June")) return 5;
        if (month.equals("July")) return 6;
        if (month.equals("August")) return 7;
        if (month.equals("September")) return 8;
        if (month.equals("October")) return 9;
        if (month.equals("November")) return 10;
        return 11;
    }
    
    public String getName(int month) {
        if (month == 0) return "January";
        if (month == 1) return "February";
        if (month == 2) return "March";
        if (month == 3) return "April";
        if (month == 4) return "May";
        if (month == 5) return "June";
        if (month == 6) return "July";
        if (month == 7) return "August";
        if (month == 8) return "September";
        if (month == 9) return "October";
        if (month == 10) return "November";
        return "December";
    }
    
    public void solve() {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        int z = 1;
        while (t-- > 0) {
            readDate(in.next());
            int add = in.nextInt();
            cal.add(Calendar.DAY_OF_YEAR, add);
            int year = cal.get(Calendar.YEAR);
            String month = getName(cal.get(Calendar.MONTH));
            String day = String.format("%02d", cal.get(Calendar.DAY_OF_MONTH));
            System.out.println("Case " + (z++) + ": " + year + "-" + month + "-"
                                + day);
        }   
    }
    
    public static void main(String[] args) {
        new Main().solve();
    }
}
