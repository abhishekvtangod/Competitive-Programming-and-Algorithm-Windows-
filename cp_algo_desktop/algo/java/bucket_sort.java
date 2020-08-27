import java.util.*;

class bucket_sort{
    void sortArr(double[] arr,int n){
        ArrayList<Double> bkt[] = new ArrayList[n];
        for (int i = 0; i < n; i++)
            bkt[i] = new ArrayList<Double>();
        for(int i = 0;i <n ;i++){
            
            int idx =(int) arr[i] * n;
            bkt[idx].add(arr[i]);
        }
        for(int i = 0; i<n;i++){
            Collections.sort(bkt[i]);
        }
        int idx = 0;
        for(int i =0;i<n;i++){
            for(int j=0;j<bkt[i].size();j++){
                arr[idx++] = bkt[i].get(j);
            }
        }

    }
    
    public static  void main(String args[]){
        int n;

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of elements : ");
        n = sc.nextInt();
        double arr[] = new double[n+1];
        System.out.println("Enter all elements : ");
        bucket_sort obj = new bucket_sort();
    
        for(int i = 0;i<n;i++){
            arr[i] = sc.nextDouble();
        }
        obj.sortArr(arr,n);

        for(int i = 0;i<n;i++){
            System.out.print(arr[i]+" ");
        }
    
    }
}