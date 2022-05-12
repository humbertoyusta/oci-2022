def sum(x):
    return x * ( x + 1 ) // 2

n = int(input())
a = list(map(int,input().split()))

ans = 0

for i in range(1,n+1):
    v = [0]
    for j in range(n):
        if a[j] == i:
            v.append(j+1)
    v.append(n+1)
    
    ans += sum(n)
    for j in range(len(v)-1):
        ans -= sum(v[j+1]-v[j]-1)

print(ans)
