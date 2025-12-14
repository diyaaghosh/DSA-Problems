import java.util.*;


public class Main {
 public static int solve(int a,int b,int c,int d){

Map<Integer,Integer>mpp=new HashMap<>();
mpp.put(a,mpp.getOrDefault(a,0)+1);
mpp.put(b,mpp.getOrDefault(b,0)+1);
mpp.put(c,mpp.getOrDefault(c,0)+1);
mpp.put(d,mpp.getOrDefault(d,0)+1);
int sum1=0;
int sum2=0;
for(Map.Entry<Integer,Integer>m : mpp.entrySet()){
   if(m.getValue()==1){
    sum1+=m.getKey();
   }
   else{
    sum2+=m.getKey();
   }
}
return sum1-sum2;
}
    public static void main(String[] args) {
     Scanner sc=new Scanner(System.in);
    System.out.println("Enter a,b,c,d : ");
    int a=sc.nextInt();
    int b=sc.nextInt();
    int c=sc.nextInt();
    int d=sc.nextInt();  
    int ans=solve(a,b,c,d);
    System.out.println("Distinct Duplicate sum "+ans);
  }
  
}
