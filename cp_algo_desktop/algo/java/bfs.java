import java.util.*;

class bfs{
    ArrayList<Integer>[] adj;
    boolean[] visited;

    bfs(int n){
        
        adj = new ArrayList[n+1];
        visited = new boolean[n+1];
        for(int i =0;i<=n;i++){
            visited[i] = false;
            adj[i] = new ArrayList<Integer>();
        }

    }


    void bfsG(int s){
    
        LinkedList<Integer> que = new LinkedList<Integer>();
        visited[s] = true;
        que.add(s);

        while(que.size() != 0){
            s = que.poll();
            System.out.print(s + " ");

            for(int i = 0; i <adj[s].size();i++){

                int u = adj[s].get(i); 
                if (visited[u] == false) 
                { 
                    visited[u] = true; 
                    que.add(u);
                }
            } 
        }    
      
    }


    public static void main(String args[]){

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the total number of vertices : ");
        int n = sc.nextInt();


        bfs g1 = new bfs(n);

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
        g1.bfsG(2);
        System.out.println(" ");

    }
}