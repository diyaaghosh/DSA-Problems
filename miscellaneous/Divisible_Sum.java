import java.util.*;

public class Main {
  public static boolean valid(List<Integer>arr,int val){
    int n=arr.size();
    int flag=1;
    for(int i=0;i<n;i++){
   if(val%arr.get(i)==0){ 
    flag=0;
    return false;
   }
    
    }
    if(flag==1)return true;
    return false;
}
    public static void main(String[] args) {
   
     Scanner sc=new Scanner(System.in);
   System.out.println("Enter dimension : ");
    int n=sc.nextInt();
    List<Integer>arr=new ArrayList<>();
   System.out.println("Enter the elements of the array : ");
    for(int i=0;i<n;i++){
        int item=sc.nextInt();
        
        arr.add(item);
    }
    int k=sc.nextInt();
    int sum=0;
   System.out.println("Enter K : ");
    
    int i=k;
    int j=1;
    while(i>0){
    if(valid(arr,j)){
       System.out.println(j);
        sum+=j;
        i--;
    }
    j++;
    }
   System.out.println("\nSum : "+sum);

  }
  
}
