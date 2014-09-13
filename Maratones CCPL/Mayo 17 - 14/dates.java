import java.util.Calendar;
import java.util.Date;
import java.util.Scanner;

public class dates {

	private Calendar cal;
	private Scanner in = new Scanner(System.in);
	private int iniYear;
	private int iniMonth;
	private int iniDay;
	private int t;
	private int k;

	public void solve() {
		/*cal = Calendar.getInstance();
		cal.set(1984, 9, 12);
		System.out.println(cal.get(Calendar.YEAR));
		System.out.println(cal.get(Calendar.MONTH));
		System.out.println(cal.get(Calendar.DAY_OF_MONTH));
		cal.add(Calendar.DAY_OF_YEAR, 318);
		System.out.println(cal.get(Calendar.YEAR));
		System.out.println(cal.get(Calendar.MONTH));
		System.out.println(cal.get(Calendar.DAY_OF_MONTH));*/
		t = in.nextInt();
		//System.out.println("t: " + t);
		for (int i = 1; i <= t; i++) {
			leerFecha();
			//System.out.println("Ano" + iniYear + " Mes: " + iniMonth + " Day:" + iniDay);
			k = in.nextInt();
			//System.out.println("k:" + k);
			cal = Calendar.getInstance();
			cal.set(iniYear, iniMonth, iniDay);
			/*System.out.println(cal.get(Calendar.YEAR));
			System.out.println(cal.get(Calendar.MONTH));
			System.out.println(cal.get(Calendar.DAY_OF_MONTH));*/
			cal.add(Calendar.DAY_OF_YEAR, k);
			/*System.out.println(cal.get(Calendar.YEAR));
			System.out.println(cal.get(Calendar.MONTH));
			System.out.println(cal.get(Calendar.DAY_OF_MONTH));*/
			String rAno = String.valueOf(cal.get(Calendar.YEAR));
			String rMes = intToMonth(cal.get(Calendar.MONTH));
			int rIntDia = cal.get(Calendar.DAY_OF_MONTH);
			String rDia;
			if (rIntDia < 10) rDia = "0";
			else rDia = "";
			rDia += String.valueOf(rIntDia);
			System.out.println("Case " + i + ": " + rAno + "-" + rMes + "-" + rDia);
		}

	}

	public void leerFecha() {
	    String s;
	    s = in.next();
	    String tmpYear, tmpMes, tmpDay;
	    tmpYear = tmpMes = tmpDay = "";
	    int i;
	    for (i = 0; s.charAt(i) != '-'; i++) tmpYear += s.charAt(i);
	    i++;
	    for (i = i; s.charAt(i) != '-'; i++) tmpMes += s.charAt(i);
	    i++;
	    for (i = i; i < s.length(); i++) tmpDay += s.charAt(i);
	    iniYear = Integer.parseInt(tmpYear);
	    iniMonth = monthToInt(tmpMes);
	    iniDay = Integer.parseInt(tmpDay);
	}

	public int monthToInt(String month) {
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
		if (month.equals("December")) return 11;
		return 0;
	}

	public String intToMonth (int m) {
		if (m == 0) return "January";
		if (m == 1) return "February";
		if (m == 2) return "March";
		if (m == 3) return "April";
		if (m == 4) return "May";
		if (m == 5) return "June";
		if (m == 6) return "July";
		if (m == 7) return "August";
		if (m == 8) return "September";
		if (m == 9) return "October";
		if (m == 10) return "November";
		if (m == 11) return "December";
		return "Nega";
	}

	public static void main(String args[]) {
		new dates().solve();
	}
}
