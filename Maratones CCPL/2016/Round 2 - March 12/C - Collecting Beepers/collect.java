import java.util.Scanner;

public class collect {

    public static int[][] distancias;
    public static Integer[][] dpTsp;
    public static int[] x;
    public static int[] y;

    public static int tsp(int current, int mask) {
        if (dpTsp[current][mask] != null) return dpTsp[current][mask];
        if (Integer.bitCount(mask) == 1) {
            return dpTsp[current][mask] = distancias[0][Integer.numberOfTrailingZeros(mask)];
        }
        int maskT = mask;
        int j = 0;
        int best = Integer.MAX_VALUE;
        int nextMask = mask & (~(1 << current));
        while (maskT != 0) {
            if ((maskT & 1) == 1 && j != current) {
                best = Math.min(best, distancias[current][j] + tsp(j, nextMask));
            }
            j++;
            maskT >>= 1;
        }
        return dpTsp[current][mask] = best;
    }

    public static int dist(int a, int b) {
        return Math.abs(x[a] - x[b]) + Math.abs(y[a] - y[b]);
    }

    public static void main(String[] args) {
        distancias = new int[12][];
        dpTsp = new Integer[12][];
        for (int i = 0; i < 12; ++i) {
            distancias[i] = new int[12];
            int k = (1 << 12) - 1;
            dpTsp[i] = new Integer[k];
        }
        x = new int[12];
        y = new int[12];
        int t;
        Scanner in = new Scanner(System.in);
        t = in.nextInt();
        while (t-- > 0) {
            int n, m, beepers;
            n = in.nextInt();
            m = in.nextInt();
            x[0] = in.nextInt();
            y[0] = in.nextInt();
            beepers = in.nextInt();
            int k = (1 << (beepers + 2)) - 1;
            for (int i = 0; i < beepers + 2; ++i) {
                for (int j = 0; j < k; ++j) {
                    dpTsp[i][j] = null;
                }
            }
            for (int i = 1; i <= beepers; ++i) {
                x[i] = in.nextInt();
                y[i] = in.nextInt();
                for (int j = 0; j <= i; ++j) {
                    distancias[j][i] = distancias[i][j] = dist(j, i);
                }
            }
            System.out.printf("The shortest path has length %d\n", tsp(0, ((1 << (beepers + 1)) - 1)));
        }
    }
}
