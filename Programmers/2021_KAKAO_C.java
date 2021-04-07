import java.util.*;

class Solution {
    HashMap<String, List<Integer>> group = new HashMap<>();

    public int[] solution(String[] info, String[] query) {
        int[] answer = {};
        ArrayList<Integer> tmpAnswer = new ArrayList<>();

        for (String str : info) {
            String[] parseStr = str.split(" ");
            makeGroup(parseStr, "", 0, parseStr.length);
        }

        for (String key : group.keySet()) {
            List<Integer> tmpList = group.get(key);
            Collections.sort(tmpList);
            group.put(key, tmpList);
        }

        for (String str : query) {
            str = str.replace(" and ", "");
            String[] token = str.split(" ");

            if (group.containsKey(token[0])) {
                int idx = lower_bound(group.get(token[0]), Integer.parseInt(token[1]));

                if (group.get(token[0]).get(idx) < Integer.parseInt(token[1]))
                    tmpAnswer.add(group.get(token[0]).size() - idx - 1);
                else
                    tmpAnswer.add(group.get(token[0]).size() - idx);
            } else
                tmpAnswer.add(0);
        }

        answer = new int[tmpAnswer.size()];

        for (int i = 0; i < tmpAnswer.size(); i++)
            answer[i] = tmpAnswer.get(i);

        return answer;
    }

    void makeGroup(String[] parseStr, String str, int idx, int len) {
        if (idx == len - 1) {
            int score = Integer.parseInt(parseStr[idx]);

            if (group.containsKey(str))
                group.get(str).add(score);
            else {
                List<Integer> tmpList = new ArrayList<Integer>(Arrays.asList(score));
                group.put(str, tmpList);
            }

            return;
        }

        makeGroup(parseStr, str + parseStr[idx], idx + 1, len);
        makeGroup(parseStr, str + "-", idx + 1, len);
    }

    int lower_bound(List<Integer> list, int num) {
        int left = 0, right = list.size(), mid = right;

        while (left < right) {
            mid = (left + right) / 2;

            if (list.get(mid) >= num)
                right = mid;
            else
                left = mid + 1;
        }

        return mid;
    }
}