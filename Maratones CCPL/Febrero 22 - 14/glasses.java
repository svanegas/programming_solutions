/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.io.*;
import java.math.BigInteger;
import java.util.*;

/**
 *
 * @author Competidor
 */
public class glasses {

    private final int MAXN = 1005;
    public BigInteger [] fib = new BigInteger[MAXN];

    public void fibo() {
        fib[0] = new BigInteger("1");
        fib[1] = new BigInteger("2");
        for (int i = 2; i < MAXN; i++) {
            fib[i] = fib[i-2].add(fib[i-1]);
        }
    }
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        glasses g = new glasses();
        g.fibo();
        Scanner input = new Scanner(System.in);
        int x;
        while (input.hasNextInt()) {
            x = input.nextInt();
            System.out.println(g.fib[x]);
        }
    }

}
