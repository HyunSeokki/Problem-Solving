class Solution {
    public int maxArea(int[] height) {
        int ret = 0;
        int sz = height.length;
        int l = 0, r = sz - 1;

        while (l < r) {
            ret = Math.max((r - l) * Math.min(height[l], height[r]), ret);

            if (height[l] < height[r])
                l++;

            else if (height[l] > height[r])
                r--;
            
            else {
                int cnt = 1;
                while (true) {
                    if (height[l + cnt] < height[r - cnt]) {
                        l++;
                        break;
                    }
                    else if (height[l + cnt] > height[r - cnt]) {
                        r--;
                        break;
                    }

                    if (l + cnt >= r - cnt) {
                        l++;
                        break;
                    }

                    cnt++;
                }
            }
        }

        return ret;
    }
}