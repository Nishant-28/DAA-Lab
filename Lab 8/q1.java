import java.util.*;

class Graph {
    private int V;
    private List<Integer>[] adj;
    
    public Graph(int V) {
        this.V = V;
        adj = new ArrayList[V];
        for (int i = 0; i < V; i++) {
            adj[i] = new ArrayList<>();
        }
    }
    
    public void addEdge(int u, int v) {
        adj[u].add(v);
        adj[v].add(u); // Because it's an undirected graph
    }
    
    public int[] bfs(int start) {
        boolean[] visited = new boolean[V];
        int[] distance = new int[V];
        Arrays.fill(distance, -1);
        
        Queue<Integer> queue = new LinkedList<>();
        visited[start] = true;
        distance[start] = 0;
        queue.add(start);
        
        while (!queue.isEmpty()) {
            int u = queue.poll();
            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    distance[v] = distance[u] + 2; // Edge weight is 2 units
                    queue.add(v);
                }
            }
        }
        
        return distance;
    }
}

public class q1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        
        Graph graph = new Graph(n);
        
        for (int i = 0; i < m; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            graph.addEdge(u - 1, v - 1);
        }
        
        int startNode = scanner.nextInt() - 1;
        scanner.close();
        
        int[] distances = graph.bfs(startNode);
        
        // Print BFS Traversal
        System.out.print("BFS Traversal: ");
        for (int i = 0; i < n; i++) {
            System.out.print((i + 1) + " ");
        }
        System.out.println();
        
        // Print Distance Array
        System.out.print("Distance [");
        for (int i = 0; i < n; i++) {
            System.out.print(distances[i]);
            if (i < n - 1) {
                System.out.print(" ");
            }
        }
        System.out.println("]");
    }
}

