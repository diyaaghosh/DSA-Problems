s=input("Enter the string : ")
ans=0
for ch in s:
    if ch=='A':
        ans+=1
    elif ch=='B':
        ans+=10
    elif ch=='C':
        ans+=100
    elif ch=='D':
        ans+=1000
    elif ch=='E':
        ans+=10000
    elif ch=='F':
        ans+=100000
    else:
        ans+=100000

print(ans)     
