import java.util.*;
class ListNode{
    int val;
    ListNode next;
    ListNode(){
        val=0;
        next=null;
    }
    ListNode(int x){
        val=x;
        next=null;
    }
}

public class Main {
public static ListNode  alternate_node(ListNode head){
ListNode temp=head;
List<Integer>st=new ArrayList<>();
while(temp!=null){
    st.add(temp.val);
    temp=temp.next;
}

ListNode ans=new ListNode();
ListNode a=ans;
for(int i=0;i<2;i++){
 
        ListNode newnode=new ListNode(st.get(i));
        ans.next=newnode;
        ans=ans.next;
    
}
for(int i=2;i<st.size();i++){
    int x=st.get(i)+st.get(i-2);
     ListNode newnode=new ListNode(x);
        ans.next=newnode;
        ans=ans.next;
}
return a.next;
}
    public static void main(String[] args) {
   ListNode head=new ListNode();
ListNode temp=head;
Scanner sc=new Scanner (System.in);

System.out.println("Enter number of nodes : ");
int n=sc.nextInt();
System.out.println("Enter the elements of the linked list : ");
for(int i=0;i<n;i++){
    int item=sc.nextInt();
    
    ListNode newnode=new ListNode(item);
    temp.next=newnode;
    temp=temp.next;
}
ListNode t=head.next;
System.out.println("The linked list is : ");
while(t!=null){
    System.out.println(t.val+" ");
    t=t.next;
}
System.out.println("\n");
ListNode alternate_linkedlist=alternate_node(head.next);
ListNode t1=alternate_linkedlist;
System.out.println("Enter the alternate LinkedList : ");
while(t1!=null){
    System.out.println(t1.val+" ");
    t1=t1.next;
}
  }
  
}
