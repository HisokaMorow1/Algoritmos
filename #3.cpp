r=0;
for(i=1;i<n;i++)
{
    for(j=1;j<=i;j++)
    {
            r++;
    }
}

c1*1
c2*(n-1)
c3*sumatoria(i=1 hasta n-1) sumatoria(j=1 hasta i) j
c4*sumatoria(i=1 hasta n-1) 

a) como es el comportamiento de este algoritmo?t(n)
b) cual es el orden de este algoritmo? O(t(n))

a) c1*1+c2*(n-1)+c3*sumatoria(i=1 hasta n-1) sumatoria(j=1 hasta i) j + c4*sumatoria(i=1 hasta n-1) = c1+c2*(n-1)+c3*sumatoria(i=1 hasta n-1) i(i+1)/2 + c4*n(n-1)/2 = c1+c2*(n-1)+c3*(n-1)n(n+1)/2 + c4*n(n-1)/2 = (c3/2)*n^3 + (c3/2+c4/2)*n^2 + (c2+c3/2+c4/2)*n + c1+c2
b) O(t(n)) = O(n^3)

