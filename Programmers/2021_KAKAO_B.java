import java.util.*;

class Solution {
    public String[] solution(String[] orders, int[] course) {
        String[] answer = {};
        ArrayList<String> tmpAnswer = new ArrayList<String>();
        HashMap<String, Integer> map = new HashMap<String, Integer>();

        for (String order : orders)
        {
            char[] tmpString = order.toCharArray();
            Arrays.sort(tmpString);
            order = new String(tmpString);
            
            select(order, "", 0, order.length(), map);
        }


        for (int sz : course) {
            int mx = 2;
            ArrayList<String> maxAnswer = new ArrayList<String>();

            for (String key : map.keySet()) {
                if (key.length() != sz)
                    continue;

                Integer value = map.get(key);

                if (mx < value) {
                    mx = value;
                    maxAnswer.clear();
                    maxAnswer.add(key);
                } else if (mx == value) {
                    maxAnswer.add(key);
                }
            }

            for (String str : maxAnswer)
                tmpAnswer.add(str);
        }

        answer = new String[tmpAnswer.size()];

        for (int i = 0; i < tmpAnswer.size(); i++)
            answer[i] = tmpAnswer.get(i);

        Arrays.sort(answer);

        return answer;
    }

    void select(String str, String comb, int idx, int len, HashMap<String, Integer> map) {

        if (comb.length() >= 2) {
            if (map.containsKey(comb))
                map.put(comb, map.get(comb) + 1);
            else
                map.put(comb, 1);
        }

        for (int i = idx; i < len; i++)
            select(str, comb + str.charAt(i), i + 1, len, map);
    }
}
