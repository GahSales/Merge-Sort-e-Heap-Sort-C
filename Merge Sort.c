#include <stdio.h>

int num[10];

int merge(int num[],int b,int m,int e) {
     int temp1[10],temp2[10]; 

     int n1,n2,i,j,k;
     n1=m-b+1;
     n2=e-m;

     for(i=0; i<n1; i++)
     temp1[i]=num[b+i];
     for(j=0; j<n2; j++)
     temp2[j]=num[m+j+1];

     temp1[i]=9999; 
     temp2[j]=9999;

     i=0;
     j=0;
     for(k=b; k<=e; k++) { 
     if(temp1[i]<=temp2[j])
         num[k]=temp1[i++];
     else
         num[k]=temp2[j++];
}
     return 0;
}


int sort(int num[], int beg, int end) {
	int mid;
	
	if(beg < end) {
		 mid = (beg + end)/2;
		 sort(num, beg, mid);
		 sort(num,mid+1,end);
		 merge(num, beg, mid, end);
	}
	
	return 0;
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
   
   
   sort(num,0,n-1);
   
   printf("\nLista apos ser ordenada: ");
     for (i=0; i<n; i++)
   	     printf("%d ", num[i]);
   
   
   
   return 0;

}




