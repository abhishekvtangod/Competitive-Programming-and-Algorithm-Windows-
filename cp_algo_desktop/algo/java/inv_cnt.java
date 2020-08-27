import java.util.*;

class inv_cnt{
    private static int cnt = 0;

    void merge(int arr[],int l,int r){
        int mid  = l+(r-l)/2;
        int i = l;
        int j = mid + 1;
        int temp[] = new int[r-l+1];
        int idx = 0;
        while(i <=mid && j <= r){
            if(arr[i] <= arr[j]){
                temp[idx++] = arr[i++]; 
            }
            else{
                cnt+= (mid - i + 1) ;
                temp[idx++] = arr[j++];
            }
        }

        // 1 8 9 | 3 4 5
        // 1 3

        while(i<=mid){
            temp[idx++] = arr[i++]; 
        }
        while(j<=r){
            temp[idx++] = arr[j++]; 
        }
        idx = 0;
        // int Tidx = 0;
        // System.out.println(l+" "+r+"-"+(r-l+1));
        for(int k =l;k<=r;k++){
            arr[k] = temp[idx++];
            // System.out.print(arr[k]+" ");
            // System.out.print(temp[Tidx++]+" ");
        }
        // System.out.println();

    }


    void mergeSortArr(int[] arr,int l,int r){

        if(r<=l){
            return;
        }
        // System.out.println(l+" "+r);
        int mid = l + (r-l)/2;
        mergeSortArr(arr,l,mid);
        mergeSortArr(arr,mid+1,r);
        merge(arr,l,r);
    }
    
    public static  void main(String args[]){
        int n;

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of elements : ");
        n = sc.nextInt();
        int arr[] = new int[n+1];
        System.out.println("Enter all elements : ");
        inv_cnt obj = new inv_cnt();

        for(int i = 0;i<n;i++){
            arr[i] = sc.nextInt();
        }
        obj.mergeSortArr(arr,0,n-1);

        System.out.println("Total number of inversions in the arrray : " + cnt);

        // for(int i = 0;i<n;i++){
        //     System.out.print(arr[i]+" ");
        // }
    
    }
}