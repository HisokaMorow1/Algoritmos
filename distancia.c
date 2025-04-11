#include <stdio.h>
#include <string.h>

int min(int a, int b) ;
int min3(int a, int b, int c);
void editDistance(char A[], char B[]);

int main() 
{
    char A[] = "ALTRUISTIC";
    char B[] = "ALGORITHM";

    editDistance(A, B);

    return 0;
}

int min(int a, int b) 
{
    if (a < b) 
    {
        return a;
    } 
    else 
    {
        return b;
    }
}

int min3(int a, int b, int c) 
{
    return min(a, min(b, c));
}

void editDistance(char A[], char B[]) 
{
    int m = strlen(A);
    int n = strlen(B);
    int ED[m + 1][n + 1];
    char operations[m + 1][n + 1];

    for (int i = 0; i <= m; i++) 
    {
        ED[i][0] = i;
        operations[i][0] = 'D';
    }
    for (int j = 0; j <= n; j++) 
    {
        ED[0][j] = j;
        operations[0][j] = 'I'; 
    }
    operations[0][0] = ' ';

    for (int i = 1; i <= m; i++) 
    {
        for (int j = 1; j <= n; j++) 
        {
            if (A[i - 1] == B[j - 1]) 
            {
                ED[i][j] = ED[i - 1][j - 1];
                operations[i][j] = 'M'; 
            } 
            else 
            {
                int delete = ED[i - 1][j] + 1;
                int insert = ED[i][j - 1] + 1;
                int substitute = ED[i - 1][j - 1] + 1;

                ED[i][j] = min3(delete, insert, substitute);

                if (ED[i][j] == delete)
                    operations[i][j] = 'D'; 
                else if (ED[i][j] == insert)
                    operations[i][j] = 'I';
                else
                    operations[i][j] = 'S'; 
            }
        }
    }

    printf("tabla de distancia de edicion:\n");
    for (int i = 0; i <= m; i++) 
    {
        for (int j = 0; j <= n; j++) 
        {
            printf("%d ", ED[i][j]);
        }
        printf("\n");
    }

    printf("\noperaciones para transformar '%s' en '%s':\n", A, B);
    int i = m, j = n;
    while (i > 0 || j > 0) 
    {
        if (operations[i][j] == 'M') 
        {
            printf("mantener '%c'\n", A[i - 1]);
            i--;
            j--;
        } 
        else if (operations[i][j] == 'S') 
        {
            printf("sustituir '%c' por '%c'\n", A[i - 1], B[j - 1]);
            i--;
            j--;
        } 
        else if (operations[i][j] == 'D') 
        {
            printf("eliminar '%c'\n", A[i - 1]);
            i--;
        } 
        else if (operations[i][j] == 'I') 
        {
            printf("insertar '%c'\n", B[j - 1]);
            j--;
        }
    }

    printf("\ndistancia de edicion minima: %d\n", ED[m][n]);

    printf("operaciones:\n");
    for(int i=0; i <= m; i++) 
    {
        for(int j=0; j <= n; j++) 
        {
            printf("%c ", operations[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}