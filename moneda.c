#include <stdio.h>
#include <stdlib.h>

void cambio(int coin[],int n,int c);

int main()
{
    int coin[] = {1,4,6};
    int n = sizeof(coin)/sizeof(coin[0]);
    int amount = 8;
    cambio(coin,n,amount);
}

void cambio(int coin[],int n,int c)
{
    int a[c+1];
    int usarcoin[c+1];
    int b = 99999;

    for(int i = 0; i <= c; i++)
    {
        a[i] = 99999;
        usarcoin[i] = -1;
    }
    a[0] = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = coin[i]; j <= c; j++)
        {
            if(a[j] > a[j-coin[i]] + 1)
            {
                a[j] = a[j-coin[i]] + 1;
                usarcoin[j] = i;
            }
        }
    }

    if(a[c] == 99999)
    {
        printf("no es posible obtener cambio para %d con las monedas entregadas\n", c);
    }
    else
    {
        printf("cambio para %d es %d monedas\n", c, a[c]);
        printf("monedas usadas:\n");
        int j = c;
        while(j > 0)
        {
            printf("%d", coin[usarcoin[j]]);
            j = j - coin[usarcoin[j]];
            if(j > 0)
            {
                printf(", ");
            }
        }
        printf("\n");
    }
    
}