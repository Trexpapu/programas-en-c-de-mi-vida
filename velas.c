#include<stdio.h>
void funcion(float velas, float residuo);
void main(){
	float x, y;
	printf("Bienvenido al juego de velas :)\n");
	printf("Ingrese la cantidad de velas que tiene\n");
	scanf("%f", &x);
	printf("\nAhora ingrese la cantidad de residuo de las velas para generar otra vela\n");
	scanf("%f", &y);
	funcion(x,y);
}

void funcion(float velas, float residuo){
	float residuototal=1/residuo; //residuo que se calcula a partir de la cantidad de velas que necesitamos para generar un residuo
	float cont=0; //contador de cuantas veces se suma una vela al total de velas
	float velastotales=velas; //velas totales al final
	float nuevasvelas=0;//las nuevas velas que se van generando
	while(nuevasvelas!=1){//bucle para cuando quede solamente una vela generada que eventualmente debería de pasar sino es así en ninún punto se rompe el while
		
	for(int i=1;i<=velas;i++){//bucle for para recorrer la cantidad de velas actual
		
		cont++;//sumamos al cont
		
		if(cont==residuo){//preguntamos si el contador es igual a la cantidad de velas que ocupamos si es asi entonces:
			
			velastotales++;//velastotales se suma uno
			cont=0; //contador vuelve a cero para repetir la pregunta correctamente
			nuevasvelas++;//agregamos una nueva vela que nacioooooo
		}
		if(i==velas && nuevasvelas==0){//condicional por si el primer if jamas ocurre es decir que jamás podra nacer otra vela por lo tanto ya es toda wey y rompemos
			nuevasvelas=1;
		}

			}//for
		velas=nuevasvelas;//al final del for igualamos las velas con las velas que nacieron para repetir el for correctamente
		if(nuevasvelas==1){//si solo nació una vela quiere decir que es el fin por lo tanto sumamos el residuo total
			velastotales=velastotales+residuototal;
		}else{//si esto no es verdad reiniciamos las velas que nacieron para ver cuantas volveran a nacer
			nuevasvelas=0;
		}
	}//while


	printf("Las velas totales fueron: %.1f\n", velastotales);
}