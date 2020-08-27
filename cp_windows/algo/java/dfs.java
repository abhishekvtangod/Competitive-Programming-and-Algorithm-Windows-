import java.util.*;

class dfs{
    private ArrayList<Integer>[] adj;
    private boolean[] visited;


    dfs(int n){
        
        adj = new ArrayList[n+1];
        visited = new boolean[n+1];
        for(int i =0;i<=n;i++){
            visited[i] = false;
            adj[i] = new ArrayList<Integer>();
        }

    }


    void dfsG(int s){
        if(visited[s]){
            return;
        }
        visited[s] = true;
        System.out.print(s+" ");
        for(int i =0; i <adj[s].size();i++){
            dfsG(adj[s].get(i));
        }
    }

    public static void main(String args[]){

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the total number of vertices : ");
        int n = sc.nextInt();


        dfs g1 = new dfs(n);

        System.out.println("Enter total number of edges : ");
        int edges = sc.nextInt();
        System.out.println("Enter all edges : ");
        for(int i =1;i<=edges ; i++){
            int u,v;
            u = sc.nextInt();
            v = sc.nextInt();                       
            g1.adj[u].add(v);
            g1.adj[v].add(u);
        }
        g1.dfsG(1);
        System.out.println(" ");


    }
}