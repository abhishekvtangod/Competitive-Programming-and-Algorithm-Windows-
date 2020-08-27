//author: 1MS18CS006
import java.util.*;

class insertion_sort{
    void sortArr(int[] arr,int n){
        for(int i = 1;i<n;i++){
            int curr = arr[i];
            int j = i-1;
            for(j = i-1; j>=0 ;j--){
                if(arr[j] <= curr){
                    // arr[j+1] = curr;
                    break;
                }
                arr[j+1] = arr[j];
            }
            arr[j+1] = curr;
        }
    }
    
    public static  void main(String args[]){
        int n;

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of elements : ");
        n = sc.nextInt();
        int arr[] = new int[n+1];
        System.out.println("Enter all elements : ");
        insertion_sort obj = new insertion_sort();

        for(int i = 0;i<n;i++){
            arr[i] = sc.nextInt();
        }
        obj.sortArr(arr,n);

        for(int i = 0;i<n;i++){
            System.out.print(arr[i]+" ");
        }
    
    }
}