import java.util.*;


public class Main {

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
    System.out.println("Enter the String : ");
String s=sc.nextLine();

int n=s.length();
int ans=0;
for(int i=0;i<n;i++){
    if(s.charAt(i)=='A'){
    ans+=1;
    }
    else if(s.charAt(i)=='B'){
        ans+=10;
    }
    else if(s.charAt(i)=='C'){
        ans+=100;
    }
    else if(s.charAt(i)=='D'){
        ans+=1000;
    }
    else if(s.charAt(i)=='E'){
        ans+=10000;
    }
    else if(s.charAt(i)=='F'){
        ans+=100000;
    }
    else{
        ans+=1000000;
    }
}
System.out.println("Result : "+ans);
}
  
}
