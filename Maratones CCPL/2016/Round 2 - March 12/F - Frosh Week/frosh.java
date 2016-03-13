import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class frosh {

    public static long countInversions(long nums[]) {
        int mid = nums.length / 2, k;
        long countLeft, countRight, countMerge;
        if (nums.length <= 1) return 0;
        long left[] = new long[mid];
        long right[] = new long[nums.length - mid];
        for (k = 0; k < mid; ++k) {
            left[k] = nums[k];
        }
        for (k = 0; k < nums.length - mid; ++k) {
            right[k] = nums[mid + k];
        }
        countLeft = countInversions(left);
        countRight = countInversions(right);
        long result[] = new long[nums.length];
        countMerge = mergeAndCount(left, right, result);
        for (k = 0; k < nums.length; ++k)
            nums[k] = result[k];
        return (countLeft + countRight + countMerge);
    }

    public static long mergeAndCount(long left[], long right[], long result[]) {
        int a = 0, b = 0, i, k = 0;
        long count = 0;
        while ((a < left.length) && (b < right.length)) {
            if (left[a] <= right[b])
                result[k] = left[a++];
            else {
                result[k] = right[b++];
                count += Long.valueOf(left.length - a);
            }
            k++;
        }
        if (a == left.length)
            for (i = b; i < right.length; ++i)
                result[k++] = right[i];
        else
            for (i = a; i < left.length; ++i)
                result[k++] = left[i];
        return count;
    }

    public static void main(String[] args) {
        int n;
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        boolean read = true;
        while (read) {
            try {
                String line = reader.readLine();
                StringTokenizer tokenizer = new StringTokenizer(line);
                n = Integer.valueOf(tokenizer.nextToken());
                long [] arr = new long[n];
                for (int i = 0; i < n; ++i) {
                    line = reader.readLine();
                    tokenizer = new StringTokenizer(line);
                    arr[i] = Long.valueOf(tokenizer.nextToken());
                }
                System.out.println(countInversions(arr));
            }
            catch (Exception e) {
                read = false;
            }
        }
    }
}
