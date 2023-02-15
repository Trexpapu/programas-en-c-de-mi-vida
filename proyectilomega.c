#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n, k;
	//leyendo n cantidad de coordenadas ya disparadas y k cantidad de coordenadas a las que quieres disparar
	scanf("%d %d", &n, &k);
	int dispx[n];//coordenada x ya disparada
	int dispy[n];//coordenada y ya disparada
	int nextdispx[k];//sig coor x disp
	int nextdispy[k];//sig coot y disp
	for(int i=0; i<n;i++){//lenando las coordenadas ya disparadas
		scanf("%d %d", &dispx[i], &dispy[i]);

	}
	for(int i=0; i<k;i++){//lenando las coordenadas por disparadar
		scanf("%d %d", &nextdispx[i], &nextdispy[i]);

	}
	int arreglo[k]; //arreglo del tamaño de las coordenadas ya disparadas para guardar las salidas
	//comparando coordenadas para buscar cual se repite
	for(int i=0;i<k;i++){
		int x=0;
		for(int j=0;j<n;j++){
			if(nextdispx[i] == dispx[j] && nextdispy[i]==dispy[j]){
				x=1;
				break;

			}
		}//fin for anidado
		//llenando la salida con comparaciones de la salida x
		if(x==1){
			arreglo[i]=0;
		}else{
			arreglo[i]=1;
		}
	}//fin ultimo for

	for(int i=0; i<k;i++){// imprimiendo salida
		printf("%d\n", arreglo[i]);

	}


	return 0;
}