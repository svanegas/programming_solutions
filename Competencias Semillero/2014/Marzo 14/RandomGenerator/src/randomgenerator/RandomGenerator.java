/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package randomgenerator;

import java.util.ArrayList;

/**
 *
 * @author Santiago
 */
public class RandomGenerator {

    final int MAXN = 100;
    final int MAXX = 100000;
    final int SIZE = 20000005;
    final int K = 170;
    boolean [] array = new boolean [SIZE];
    long random;
    ArrayList<Long> generados = new ArrayList<Long>();
    
    public RandomGenerator() {
        System.out.println(MAXN + " " + K);
        random = (long)((Math.random() * ((MAXX * 2) + 1)) - MAXX);
        array[(int)(random + MAXX)] = true;
        System.out.print(random);
        generados.add(random);
        for (int i = 1; i < MAXN; i++) {
            random = (long)((Math.random() * ((MAXX * 2) + 1)) - MAXX);
            if (!array[(int)(random + MAXX)]) {
                System.out.print(" " + random);
                array[(int)(random + MAXX)] = true;
                if (generados.size() <= K) generados.add(random);
            }
            else i--;
        }
        System.out.println("");
        int i;
        for (i = K - 1; i >= 0; i--) System.out.println(generados.get(i));
    }
    
    public static void main(String[] args) {
        new RandomGenerator();
    }
}
