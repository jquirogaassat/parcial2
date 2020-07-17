#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<iostream>

/*Un taller de computación arma 4 modelos de equipos en 5 puntos del interior del pais,se tienen tres lotes de datos con la siguiente información:

el primero
-	número de modelo
-	costo
el segundo 
-	lugar de armado 
-	costo del flete

Si  el lugar de armado es el 4 se le aplica un descuento del 15% al costo por incentivo zona desfavorable
El precio de venta tendra un 150% de ganancia
El tercer lote de datos tiene la siguiente información
-	número de modelo
-	lugar de armado 
-	cantidad

	Se desea  saber:

a.	cantidad armada en cada lugar
b.	cantidad vendida de cada modelo
c.	total facturado por cada modelo
d.	porcentual que representa esa facturación sobre el total
e.	precio promedio
f.	cuál fue la ganancia de la empresa
g.	cuál fue el lugar de más produccián de equipos en total
h.	cuál equipo y adonde se fabricó menos
i.	imprimir el punto 2 y 3 ordenado descendentemente por total facturado

*/


void fsmenu();
void fscarga(float[],int [],int[],int[]);
void fscant(int[]);
void fsventas(int[]);
void fsfacturado(float[]);

int main() 
{
	char usuario [15];
	char contrasena[15];
	char user[15];
	char contra[15];
	int cont=0, u,p,bandera,opcion;
	strcpy(usuario,"jair");// 		usuario
	strcpy(contrasena,"1234");//		password
	float vecmod[5];
	int veclug [6];
	int vetcantidad[6]={0};
	int vecventas[5]={0};
	
	
	do
	{
		bandera=0;
		printf("Ingrese usuario :");
		fflush(stdin);
		gets(user);
		printf("Ingrese contraseña :");
		fflush(stdin);
		gets(contra);
		u=strcmp(usuario,user);
		p=strcmp(contrasena,contra);
		if(u!=0)
		{
			bandera=1;
		}
		if(p!=0)
		{
			bandera=1;
		}
		cont= cont+1;
				
	}while((bandera!=0)&&(cont<3));
	
		if (bandera!=0)
		{
			printf("Lo siento Ud ha introducido usuario o contraseña incorrecta.\n");
		}
		else
		{
			printf("Bienvenido, a continuacion se mostrara el menu de opciones \n");
			system("pause");
			fsmenu();//					ingreso al menu
			
			do
			{
				printf("\tIngrese la opcion que desea :\n");
				scanf("%d",&opcion);
			}while( opcion!=0);
			
			
			bandera=0;
			while(opcion!=4)
			{
				switch(opcion)
				{
					case 0:
						if(bandera==0)
						{
						fscarga(vecmod,veclug,vetcantidad,vecventas);
						bandera=1;	
						}else
						{
						printf("No es posible realizar la carga.\n");
						system("pause");	
						}						
					break;					
					case 1:
						if(bandera==1)
						{
						fscant(vetcantidad);
						}else
						{
							printf("Para poder acceder a este item, necesita realizar la carga. \n");
							system("pause");
						}					
					break;
					case 2:
						if(bandera==1)
						{
						fsventas(vecventas);	
						}else
						{
							printf("Para poder acceder a este item, necesita realizar la carga. \n");
							system("pause");	
						}						
					break;
					case 3:
						if(bandera==1)
						{
						fsfacturado(vecmod);	
						}else
						{
							printf("Para poder acceder a este item, necesita realizar la carga. \n");
							system("pause");	
						}
					break;
						
							
				}
				fsmenu();
				printf("Ingrese la opcion que desea :\n");
				scanf("%d",&opcion);
				
				
				
			}
			printf("Ud eligio salir. Hasta pronto!!! Gracias por operar con nosotros.");
			system("pause");
			
		}
	
	
}

void fsmenu()
{
	system("cls");
	printf("\t*******Bienvenido al sistema de gestion *******\n");
	printf("\tElija la opcion que desee : \n ");
	printf("\t0-- Carga de datos \n");
	printf("\t1-- Cantidad armada en cada lugar \n");
	printf("\t2-- Cantidad vendida de cada modelo \n");
	printf("\t3-- Total facturado \n");
	printf("\t4-- Salir del programa \n");
	
}


void fscarga(float vecmod[5],int veclug[6],int vetcantidad[6],int vecventas[5] )
{
	int nromodelo,lugarmado,cant =0;
	float costo,costof;
	
	int i, bandera=0;
	
	do{
		printf("Ingrese modelo, finaliza con n° modelo 0 \n");// pide 1ra vez
		scanf("%d",&nromodelo);
	}while(nromodelo>=5);
	
	while (nromodelo!=0)
	{
		
		printf("Ingrese cantidad \n");
		scanf("%d",&cant);
		printf("Ingrese costo \n");
		scanf("%f",&costo);
		vecmod[nromodelo]=vecmod[nromodelo]+costo;
		
		do{			
		printf("Ingrese lugar de armado \n");
		scanf("%d",&lugarmado);		
		 }while (lugarmado>=6);
		 
		printf("Ingrese costo del flete \n");
		scanf("%f",&costof);
		veclug[lugarmado]=veclug[lugarmado]+costof;
		fflush(stdin);
		vetcantidad [lugarmado]=vetcantidad[lugarmado]+cant;//termina info 1 modelo
		vecventas[nromodelo]=vecventas[nromodelo]+cant;
		bandera=1;
		
		do{
		printf("Ingrese modelo, finaliza con n° modelo 0 \n");// pide 1ra vez
		scanf("%d",&nromodelo);
		}while(nromodelo>=5);	
	//	printf("Ingrese modelo, finaliza con n° modelo 0 \n");
	//	scanf("%d",&nromodelo);
	}
	
	
	
}

void fscant(int vetcantidad[6])
{
	int f;
	for(f=1;f<=5;f++)
	{
		printf(" La cantidad armada en el lugar  %d, es de %d \n ",f,vetcantidad[f]);	 		
	}
	
	system("pause");
	
}

void fsventas(int vecventas[5])
{
	int f;
	for(f=1;f<=5;f++)
	{
		printf("La cantidad vendida del modelo %d, es de %d \n",f,vecventas[f]);
	}
	system("pause");
}

void fsfacturado (float vecmod[5])
{
	int f;
	for(f=1;f<=5;f++)
	{
		printf("El total facturado por modelo %d, es de %.2f \n",f,vecmod[f]);	
		
	}
	system("pause");
}


















