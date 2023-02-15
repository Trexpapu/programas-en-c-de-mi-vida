#include<stdio.h>
#include<stdlib.h>
int comparaenteros(const void *p, const void *q); //funcion quicksort

int main(){
	int n[3];//arreglo de 3 espacios
	int z=0;//contador para recorrer el arreglo
	int salida[1000];//array donde guardaremos la salida
	int cont=0;//contador para saber si entro al for si se mantiene en cero dara la salida NINGUNA
	for(int i=0;i<3;i++){//leyendo los tres numeros
		scanf("%d", &n[i]);
	}
	qsort(n, 3, sizeof(int), &comparaenteros);//pasando parametros a quicksort para ordenar los numeros

	for(int i=n[0]+1;i<=n[1]-1;i++){//i empieza desde el valor de la posicion 0 del array, +1 al valor para tomar el que le sigue, recorre hasta el valor de la posicion 1, -1 para tomar el valor de antes
	//de esta forma solo tendremos los intermedios de cada numero 
		salida[z]=i;//guardamos i en la salida
		z++;//recorremos el arreglo
		cont++;//vemos si entro al for alguna vez
	}
	for(int i=n[1]+1;i<=n[2]-1;i++){//funcion igual que el for anterior pero ahora con los valores de la posicion 1 hasta la posicion 2
		salida[z]=i;
		z++;
		cont++;
	}

	if(cont==0){//vemos si alguna vez entro a alguno de los for
		printf("NINGUNA");
	}else{//si es mas de cero si entro al for por lo tanto imprimimos
	for(int i=0;i<z;i++){
		printf("%d ", salida[i]);
	}
		}

	return 0;
}

int comparaenteros(const void *p, const void *q){
	int x, y;
	x=*(int *) p;
	y=*(int *) q;
	if (x<y)
		return -1;
	
	if(x==y)
		return 0;
	
	return 1;


	}