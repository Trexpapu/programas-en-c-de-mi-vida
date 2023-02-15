#include<stdio.h>
struct alumno
{	
	char nombre[50];
	 int promedio;
	 int edad;

	
}k[3];
void main()
{
int i;
for(i=0;i<3;i++)
{
	printf("ingrese el nombre del alumno\n");
	fflush(stdin);
	gets(k[i].nombre);
	printf("ingrese el promedio del alumno\n");
	scanf("%d", &k[i].promedio);
	printf("ingrese la edad del alumno\n");
	scanf("%d", &k[i].edad);

}

//k1=a k2=b k3=c
if(k[0].promedio>k[1].promedio && k[0].promedio>k[2].promedio)
{
printf("\n el mayor promedio es de\n %s", k[0].nombre);
printf("\n  \n promedio del alumno %d  \n", k[0].promedio);
	printf("\n  \n edad del alumno %d\n", k[0].edad);
}

if(k[1].promedio>k[0].promedio && k[1].promedio>k[2].promedio)
{
	printf(" \n el mayor promedio es de \n %s", k[1].nombre);
	printf("\n  \n promedio del alumno %d \n", k[1].promedio);
	printf("\n  \n edad del alumno %d \n", k[1].edad);
}

if(k[2].promedio>k[0].promedio && k[2].promedio>k[1].promedio)
{
	printf("\n el mayor promedio es de \n %s", k[2].nombre);
	printf("\n  \n promedio del alumno %d \n", k[2].promedio);
	printf("\n \n edad del alumno %d \n", k[2].edad);
}
}