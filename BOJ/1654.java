import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int k = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());
        long[] line = new long[k];
        long max = -1;

        for (int i = 0; i < k; i++) {
            st = new StringTokenizer(br.readLine());
            line[i] = Integer.parseInt(st.nextToken());
            max = (max < line[i]) ? line[i] : max;
        }

        System.out.println(search(1, max, line, n));
    }

    static long search(long left, long right, long[] line, int n) {
        long len = line.length;
        long result = 0;

        while (left <= right) {
            int sum = 0;
            long mid = (left + right) / 2;
            for (int i = 0; i < len; i++)
                sum += line[i] / mid;

            if (sum < n)
                right = mid - 1;
            else {
                left = mid + 1;
                result = (result > mid) ? result : mid;
            }
        }

        return result;
    }
}