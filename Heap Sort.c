#include <stdio.h>

int num[10];

void CriaHeap(int *num, int i, int f)
{
	int aux = num[i];
	int j = i * 2 + 1;
	while (j <= f)
	{
		if (j < f)
		{
			if (num[j] < num[j + 1])
			{
				j = j + 1;
			}
		}
		if (aux < num[j])
		{
			num[i] = num[j];
			i = j;
			j = 2 * i + 1;
		}
		else {
			j = f + 1;
		}
	}
	num[i] = aux;
}

void heap(int *num, int n)
{
	int i, aux;
	for(i = (n - 1)/2; i >= 0; i--)
	{
		CriaHeap(num, i, n-1);
	}
	for(i= (n-1); i>=1; i--)
	{
		aux = num[0];
		num [0] = num[i];
		num [i] = aux;
		CriaHeap(num, 0, i-1);
	}
}


int main()
{
   int i, n;
   printf("Insira o tamanho do array: ");
   scanf("%d", &n);
   for (i=0;i<n;i++){
     printf("\nInsira o valor da posicao %d a ser ordenado : ", i+1);
     scanf("%d", &num[i]);
     getchar();
   }
   printf("\nLista antes da ordenacao: " );
   for (i=0;i<n; i++)
     printf("%d ", num[i]);
   
   
   heap(num, n);
   
   printf("\nLista apos ser ordenada: ");
     for (i=0; i<n; i++)
   	     printf("%d ", num[i]);
   
   
   
   return 0;

}

