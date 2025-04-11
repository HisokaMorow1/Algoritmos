#include <stdio.h>

void knapsack(int W, int n, int w[], int b[]);
int max(int a, int b);

int main() 
{
    int W = 11; 
    int n = 5;  
    int w[] = {1, 2, 5, 6, 7}; 
    int b[] = {1, 6, 18, 22, 28}; 

    knapsack(W, n, w, b);

    return 0;
}

int max(int a, int b) 
{
    if (a > b) 
    {
        return a;
    } 
    else 
    {
        return b;
    }
}

void knapsack(int W, int n, int w[], int b[]) 
{
    int B[n + 1][W + 1];

    for (int p = 0; p <= W; p++) 
    {
        B[0][p] = 0;
    }

    for (int k = 1; k <= n; k++) 
    {
        for (int p = 0; p <= W; p++) 
        {
            if (w[k - 1] <= p) 
            {
                B[k][p] = max(B[k - 1][p], B[k - 1][p - w[k - 1]] + b[k - 1]);
            } 
            else 
            {
                B[k][p] = B[k - 1][p];
            }
        }
    }

    printf("tabla de resultados:\n");
    for (int k = 0; k <= n; k++) 
    {
        for (int p = 0; p <= W; p++) 
        {
            printf("%d ", B[k][p]);
        }
        printf("\n");
    }

    printf("objetos seleccionados en orden inverso:\n");
    int p = W;
    int selected[n]; 
    int count = 0;  

    for (int k = n; k > 0; k--) 
    {
        if (B[k][p] != B[k - 1][p]) 
        {
            selected[count++] = k; 
            p -= w[k - 1];
        }
    }

    printf("objetos seleccionados en orden correcto:\n");
    int totalWeight = 0; 
    for (int i = count - 1; i >= 0; i--) 
    {
        int obj = selected[i];
        printf("objeto %d (valor: %d, peso: %d)\n", obj, b[obj - 1], w[obj - 1]);
        totalWeight += w[obj - 1]; 
    }

    printf("peso total: %d\n", totalWeight); 
    printf("valor maximo: %d\n", B[n][W]);

}

/*
O(n * W)

n = número de objetos
W = capacidad de la mochila
w[] = pesos de los objetos
b[] = beneficios de los objetos
B[][] = tabla de resultados
B[k][p] = valor máximo que se puede obtener con los primeros k objetos y capacidad p
B[k][p] = tiene n+1 filas y W+1 columnas

bucle externo que itera en n
for (int k = 1; k <= n; k++)

bucle interno que itera sobre la mochila y va de 0 hasta W
for (int p = 0; p <= W; p++)

cada celca B[k][p] se calcula de la siguiente manera:
B[k][p] = max(B[k - 1][p], B[k - 1][p - w[k - 1]] + b[k - 1]);

por lo tanto el numero total de cada iteracion es de n * W
el tiempo de ejecución es O(n * W) y el espacio de ejecución es O(n * W)

*/