r=0;
for(i=1;i<=n;i++)
{
    for(j=0;j<=n;j++)
    {
            r=r+1
    }
}

c1*1
c2*(n+1)
c3*n(n+2)
c4*n(n+1)

a) como es el comportamiento de este algoritmo?t(n)
b) cual es el orden de este algoritmo? O(t(n))

a) c1*1+c2(n+1)+c3*n(n+2)+c4*n(n+1) = (c3+c4)*n^2 + (c2+c3+c4)*n + c1+c2
b) O(t(n)) = O(n^2)
