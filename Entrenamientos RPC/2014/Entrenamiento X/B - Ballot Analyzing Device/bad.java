
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

/**
 *
 * @author Santiago
 */
public class bad implements Comparable<bad> {

    public int id;
    public int votes;
    public String name;
    
    public bad(int id, String name) {
        this.id = id;
        this.name = name;
        this.votes = 0;
    }
   
    @Override
    public int compareTo(bad than) {
        if (votes < than.votes) return -1;
        else if (votes == than.votes) {
            return id > than.id ? -1 : 1;
        }
        else return 1;
    }
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n, m;
        n = in.nextInt();
        m = in.nextInt();
        ArrayList <bad> cand = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            String name;
            name = in.next();
            cand.add(new bad(i, name));
        }
        String vote;
        int invalid = 0;
        for (int i = 0; i < m; ++i) {
            vote = in.next();
            int selected = -1;
            for (int j = 0; j < n; ++j) {
                if (vote.charAt(j) == 'X') {
                    if (selected != -1) {
                        selected = -1;
                        break;
                    }
                    else selected = j;
                }
            }
            if (selected == -1) invalid++;
            else cand.get(selected).votes++;
        }
        Collections.sort(cand);
        for (int i = n - 1; i >= 0; --i) {
            System.out.println(String.format("%s %.2f%%", cand.get(i).name, 100. * cand.get(i).votes / m));
        }
        System.out.println(String.format("Invalid %.2f%%", 100. * invalid / m));
    } 
}
