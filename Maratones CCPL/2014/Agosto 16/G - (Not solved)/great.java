
import java.awt.Polygon;
import java.awt.geom.Area;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 *
 * @author Estudiante
 */
public class great {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        while (true) {
            try {
                String line = reader.readLine();
                StringTokenizer tokenizer = new StringTokenizer(line);
                int m, c;
                m = Integer.valueOf(tokenizer.nextToken());
                c = Integer.valueOf(tokenizer.nextToken());
                if (m == 0) break;
                int [] arrMx = new int [m];
                int [] arrMy = new int [m];
                int [] arrCx = new int [c];
                int [] arrCy = new int [c];
                for (int i = 0; i < m; i++) {
                    int x, y;
                    line = reader.readLine();
                    tokenizer = new StringTokenizer(line);
                    x = Integer.valueOf(tokenizer.nextToken());
                    y = Integer.valueOf(tokenizer.nextToken());
                    arrMx[i] = x;
                    arrMy[i] = y;
                }  
                for (int i = 0; i < c; i++) {
                    int x, y;
                    line = reader.readLine();
                    tokenizer = new StringTokenizer(line);
                    x = Integer.valueOf(tokenizer.nextToken());
                    y = Integer.valueOf(tokenizer.nextToken());
                    arrCx[i] = x;
                    arrCy[i] = y;
                }  
                Polygon polM = new Polygon(arrMx, arrMy, m);
                Polygon polC = new Polygon(arrCx, arrCy, c);
                Area aM = new Area(polM);
                Area aC = new Area(polC);
                aM.intersect(aC);
                if (aM.isEmpty()) {
                    System.out.println("Yes");
                }
                else {
                    System.out.println("No");
                }
            } catch (IOException ex) {
                System.err.println("Input error");
            }
        }
    }
    
}
