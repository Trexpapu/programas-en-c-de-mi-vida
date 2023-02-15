//algoritmo de floyd washall
#include <stdio.h>
#include<stdlib.h>
#define INF 999//valor infinito, cuando no hay conexion entre los vertices 
//matematicamente podemos usar infinito pero en la computadora no, por lo que ponemos un numero grande





void main(){


	int vertices;//variable donde guardaremos la cantidad de vertices
	printf("Bienvenido al algoritmo de floyd washall\n");
	printf("Ingrese la cantidad de vertices que tiene su grafo\n");
	scanf("%d", &vertices);
	int matriz[vertices][vertices];//declaramos la matriz de distancias
	printf("Ahora ingrese las distancias en la matriz\n");
	printf("Donde quiera agregar un infinito introduzca un [-1]\n");//añadimos esto para saber donde habrá infinitos
	for(int i=0;i<vertices;i++){//llenamos la matriz de valores con ciclo anidado
		for(int j=0;j<vertices;j++){
			printf("Ingrese el valor de la posicion [%d][%d]: ", i, j);
			scanf("%d", &matriz[i][j]);//leemos el valor en dicha posicion
		}
	}//fin for anidado para pedir valores




for(int i=0;i<vertices;i++){//verificamos donde haya -1 para cambiarlo por infinito
		for(int j=0;j<vertices;j++){
			if(matriz[i][j]==-1){
				matriz[i][j]=INF;
			}
			
		}
		
	}
system("pause");
system("cls");


//mostrano la matriz
for(int i=0;i<vertices;i++){
		for(int j=0;j<vertices;j++){
			if(matriz[i][j]==INF)//condicional para imprimir infinito en lugar de 999
				printf("\tINF");
			else{
			printf("\t%d", matriz[i][j]);
			}
		}
		printf("\n");
	}


//------------------Aqui vamos a aplicar el algoritmo de FLOYD WARHSALL-------------------------//


int aux, aux2; //variables auxiliares para buscar el numero menor

for(int k=0;k<vertices;k++){
	for(int i=0;i<vertices;i++){
		for(int j=0;j<vertices;j++){
			aux=matriz[i][j];//guardamos la posicion donde intersecta o actual 
			aux2=(matriz[i][k] + matriz[k][j]);//sumamos las posiciones espejo de la matriz
			if(aux<aux2){//comparamos cual es el menor numero y el menor será la nueva posicion actual o de interseccion
				matriz[i][j]=aux;
			}else{
				matriz[i][j]=aux2;
			}



		}
	}
}



printf("\n");
printf("\n");
printf("Matriz despues de aplicar algoritmo de washall\n");

//mostrano la matriz despues del algoritmo 
for(int i=0;i<vertices;i++){
		for(int j=0;j<vertices;j++){
			if(matriz[i][j]==INF)//condicional para imprimir infinito en lugar de 999
				printf("\tINF");
			else{
			printf("\t%d", matriz[i][j]);
			}
		}
		printf("\n");
	}

//ver el costo del recorrido

int p, q, final;//p es la fila o punto inicial, q la columna o punto final, final es donde se guardara el valor de la posicion en la matriz
printf("Ingrese de que vertice a que vertice desea calcular la distancia ejemplo vertice inicial [0] a vertice de llegada o final[2]\n");
scanf("%d %d", &p, &q);

for(int i=0;i<vertices;i++){
		for(int j=0;j<vertices;j++){
			if(matriz[p][q]==matriz[i][j]){//aqui buscamos cual es el punto inicial y guardamos su costo en final
				final=matriz[i][j];
			}
		}
		
	}


	printf("El costo minimo del recorrido del punto [%d] al punto [%d] es ============ %d\n", p, q, final);



}//fin main


