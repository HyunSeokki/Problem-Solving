import java.util.*;

class Solution {
    public int solution(int n, int s, int a, int b, int[][] fares) {
        int answer = 0x7fffffff;
        PriorityQueue<Struct> pq = new PriorityQueue<>(new Comparator<Struct>() {
            @Override
            public int compare(Struct o1, Struct o2) {
                return o1.cost - o2.cost;
            }
        });

        List<Struct> l[] = new ArrayList[n + 1];
        int[][] dist = new int[n + 1][n + 1];
        int[] tmpNode = {s, a, b};

        for (int i = 0; i <= n; i++) {
            l[i] = new ArrayList<>();
            for (int j = 0; j <= n; j++)
                dist[i][j] = 0x7fffffff;
        }

        for (int[] x : fares) {
            l[x[0]].add(new Struct(x[1], x[2]));
            l[x[1]].add(new Struct(x[0], x[2]));
        }

        for (int i : tmpNode) {
            dist[i][i] = 0;
            pq.add(new Struct(i, 0));

            while (!pq.isEmpty()) {
                int node = pq.peek().node;
                int cost = pq.peek().cost;
                pq.poll();

                for (Struct x : l[node]) {
                    if (dist[i][node] + x.cost < dist[i][x.node]) {
                        dist[i][x.node] = dist[i][node] + x.cost;
                        dist[x.node][i] = dist[i][x.node];

                        pq.add(new Struct(x.node, x.cost));
                    }
                }
            }
        }


        for (int i = 1; i <= n; i++) {
            if(dist[i][a] == 0x7fffffff || dist[i][b] == 0x7fffffff)
                continue;
            
            if (answer > dist[s][i] + dist[i][a] + dist[i][b])
                answer = dist[s][i] + dist[i][a] + dist[i][b];
        }

        return answer;
    }
}

class Struct {
    int node;
    int cost;

    Struct(int node, int cost) {
        this.node = node;
        this.cost = cost;
    }
}