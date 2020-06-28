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
void fscarga(int [],int []);
void fscant(int []);
int main() 
{
	char usuario [15];
	char contrasena[15];
	char user[15];
	char contra[15];
	int cont=0, u,p,bandera,opcion;
	strcpy(usuario,"jair");
	strcpy(contrasena,"1234");
	int vecmod[5];
	int veccant[6];
	int veclug [6];
	
	
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
			fsmenu();
			
			do
			{
				printf("Ingrese la opcion que desea :\n");
				scanf("%d",&opcion);
			}while( (opcion<0)||(opcion>9));
			bandera=0;
			while(opcion!=9)
			{
				switch(opcion)
				{
					case 0:
						if(bandera==0)
						{
							printf("Ingrese los datos \n");
							fscarga(vecmod,veclug);
							bandera =1;
						}
						else
						{
							printf("Ud ya realizo la carga \n");	
						}
					break;
					
					case 1:
						if(bandera==1)
						{
							printf("");
						}
					break;
						
							
				}
			}
			
		}
	
	
}

void fsmenu()
{
	system("cls");
	printf("Elija la opcion que desee : \n ");
	printf("0-- Carga de datos \n");
	printf("1-- Cantidad armada en cada lugar \n");
	printf("2-- Cantidad vendida de cada modelo \n");
	printf("3-- Total facturado \n");
	printf("9-- Salir del programa \n");
	
}


void fscarga(int vecmod[5],int veclug[6] )
{
	int nromodelo,lugarmado;
	float costo,costof;
	vecmod[5];
	int i, bandera=0;
	while (bandera==0)
	{
		printf("Ingrese modelo \n");
		scanf("%d",&nromodelo);
		printf("Ingrese costo \n");
		scanf("%f",&costo);
		vecmod[nromodelo]=vecmod[nromodelo]+costo;
		printf("Ingrese lugar de armado \n");
		scanf("%d",&lugarmado);
		printf("Ingrese costo del flete \n");
		scanf("%f",&costof);
		veclug[lugarmado]=veclug[lugarmado]+costof;
		
		bandera=1;		
	}
	
	
	
}

void fscant(int veccant[])
{
	
}





















