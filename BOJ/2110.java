import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());
        int[] house = new int[n];
        int max = -1;
        int min = 0x7fffffff;

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            house[i] = Integer.parseInt(st.nextToken());
            max = (max < house[i]) ? house[i] : max;
            min = (min > house[i]) ? house[i] : min;
        }

        Arrays.sort(house);
        System.out.println(search(1, max - min, house, c));
    }

    static int search(int left, int right, int[] house, int n) {
        int mid = (left + right) / 2;
        int result = 0;

        while (left <= right) {
            mid = (left + right) / 2;
            if (check(mid, house, n)) {
                left = mid + 1;
                result = (mid > result) ? mid : result;
            } else
                right = mid - 1;
        }
        return result;
    }

    static boolean check(int mid, int[] house, int c) {
        int cnt = 1;
        int num = house[0];
        int len = house.length;

        for (int i = 1; i < len; i++) {
            if (house[i] - num >= mid) {
                cnt++;
                num = house[i];
            }
        }

        if (cnt >= c)
            return true;
        else
            return false;
    }
}