#include<stdio.h>
void main()
{
	int x;
	int array[50];
	
	int cont=0;
	printf("ingrese el numero que desea convertir a binario\n");
	scanf("%d", &x);


	while(x!=0){

		array[cont]=x%2;

		x=x/2;
		
		cont=cont+1;
	}
	

	for(cont-- ; cont>=0; cont--)
	{
		printf("%d", array[cont]);
	}
}