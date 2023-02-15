#include<stdio.h>
#include <stdlib.h>
int comparaenteros(const void *p, const void *q);
void main(){
	int n;//cantidad de coordenadas NOTA PONER QUE SEA MAYOR A 0
	printf("Ingrese la cantidad de coordenadas que va a dar\n");
	scanf("%d", &n);
	int coordenadasX[n];
	int coordenadasY[n];
	int copiaX[n];
	int copiaY[n];
	//llenando los arreglos o bien pidiendo las coordenadas
	printf("Ingrese las coordenadas de esta forma (x y)\n");
	for(int i=0;i<n;i++){
	printf("coordenada numero [%d]", i+1);
	printf("\nIngrese la coordenada X: ");
	scanf("%d", &coordenadasX[i]); 
	printf("Ingrese la coordenada de Y: ");
	scanf("%d", &coordenadasY[i]);
	}
	system("pause");
	system("cls");
	//copiando los arreglos
	for(int i=0;i<n;i++){
		copiaX[i]=coordenadasX[i];
		copiaY[i]=coordenadasY[i];
	}


//mostrando las coordenadas
	for(int i=0;i<n;i++){
		printf("La coordenada (%d , %d)\n", coordenadasX[i], coordenadasY[i]);
	}
	//ordenando las copias para obtener el numero mas grande para asi poder hacer la matriz
	qsort(copiaX, n, sizeof(int), &comparaenteros);
	qsort(copiaY, n, sizeof(int), &comparaenteros);


	printf("\n");
	//printf("La mas grande de X es: %d", copiaX[0]);
	printf("\n");
	//printf("La mas grande de Y es: %d", copiaY[0]);
	int matriztotal;
	if(copiaX[0]>copiaY[0]){
		matriztotal=copiaX[0];
	}else{
		matriztotal=copiaY[0];
	}
	printf("\n");
	printf("la matriz total es [%d]*[%d] \n", matriztotal, matriztotal);


//llenando la matriz de ceros
	int matriz[matriztotal][matriztotal];
	for(int i=0;i<matriztotal;i++)
	{
	for(int j=0;j<matriztotal;j++)
	{
		matriz[i][j]=0;
	}
	
}

//agregando unos de las coordenadas
int p, q;
for(int i=0;i<n;i++){
	p=coordenadasX[i]-1;
	q=coordenadasY[i]-1;
	matriz[p][q]=1;
}


//mostrando la matriz
for(int i=0;i<matriztotal;i++)
{
	for(int j=0;j<matriztotal;j++)
	{
		printf("\t%d", matriz[i][j]);

	} 
	printf("\n");
	
}

//generando copia de la matriz para operar en esta
//agregando ceros 
	int copia_matriz[matriztotal][matriztotal];
	for(int i=0;i<matriztotal;i++)
	{
	for(int j=0;j<matriztotal;j++)
	{
		copia_matriz[i][j]=0;
	}
	
}

//agregando unos a las coordenadas
int p1, q1;
for(int i=0;i<n;i++){
	p1=coordenadasX[i]-1;
	q1=coordenadasY[i]-1;
	copia_matriz[p1][q1]=1;
}



//aplicamos el algoritmo de washall

for(int k=0;k<matriztotal;k++){
	for(int i=0;i<matriztotal;i++){
		for(int j=0;j<matriztotal;j++){
			//aqui va el algoritmo
			
			copia_matriz[i][j]=copia_matriz[i][j] || (copia_matriz[i][k] && copia_matriz[k][j]);
	
		}//fin for j
	}//fin for i
}//fin for k

printf("\nLa matriz despues de aplicar el algoritmo de warshall\n");
//mostrando nueva matriz
for(int i=0;i<matriztotal;i++)
{
	for(int j=0;j<matriztotal;j++)
	{
		printf("\t%d", copia_matriz[i][j]);

	}
	printf("\n");
	
}
//SABER SI ES TRANSITIVA O NO comparando posiciones
int x=1;
int contador=0;
int posicion1[matriztotal];
int posicion2[matriztotal];
for(int i=0;i<matriztotal;i++)
{
	for(int j=0;j<matriztotal;j++)
	{
		if(copia_matriz[i][j]==matriz[i][j]){
			x=x;
		}else{
			x=0;
			posicion1[contador]=i+1;
			posicion2[contador]=j+1;
			contador=contador+1;

		}
	}
	
	
}
//logica de transitividad

if(x==1){
	printf("\nLA RELACION SI ES TRANSITIVA");

}else{
	printf("\nLA RELACION NO ES TRANSITIVA\n");
	printf("<<<<CIERRE DE MATRIZ>>>>\n");
	for(int i=0; i<contador; i++){
		printf("(%d , %d)\t", posicion1[i], posicion2[i]);
	}for(int i=0;i<n;i++){
		printf("(%d , %d)\t", coordenadasX[i], coordenadasY[i]);
	}

}





}//fin main




//funcion para ordenar las posiciones para asi saber cual es el numero mas grande
int comparaenteros(const void *p, const void *q){
	int x, y;
	x=*(int *) p;
	y=*(int *) q;
	if (x>y)
		return -1;
	
	if(x==y)
		return 0;
	
	return 1;


	}