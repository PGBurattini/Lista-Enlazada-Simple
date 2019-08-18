//LISTA SIMPLEMENTE ENLAZADA

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <string.h>

using namespace std;

class NODO{
			public:
				NODO(char *); //CONSTRUCTOR DE NODO
				~NODO(); //SIRVE PARA CONTROLAR SI ESTÁ BIEN HECHO EL PROGRAMA
				char NOM[20];
				NODO * SIG;
		  };

NODO::NODO(char * S)
{
	strcpy (NOM, S);
}

NODO::~NODO()
{
	cout << "\n\n MATANDO A ... " << NOM ;
	getchar();
}

class LISTA{
			private:
				NODO * INICIO;
				void PONER_P(NODO *);
				void PONER_F(NODO *);
				void INSERT (NODO *);
				NODO * MINIMO();
				NODO * MAXIMO();
				NODO * BUSCAR(char *);
				void MATAR(NODO *);

			public:
				LISTA(); //CONSTRUCTOR PARA QUE "INICIO" TENGA ENLACE NULL.
				~LISTA(); //DESTRUCTOR PARA QUE NO QUEDEN LOS NODOS EN LA MEMORIA UNA VEZ TERMINADA LA FUNCION.
				void AGREGAR_P( char *);
				void AGREGAR_F( char *);
				void INSERTAR (char *);
				void MIRAR();
				void MIRARCP();
				void MENOR();
				void MAYOR();
				void ELIMINAR(char *);
				void SACAR(NODO *);
		   };

LISTA::LISTA()
{
	INICIO = NULL ;
}


LISTA::~LISTA()
{
	cout << "\n\n SE DEBEN LIBERAR (DESTRUIR) TODOS LOS NODOS ";
	cout << "\n\n ERA PARA USTEDES Y TODAVIA NO LA HICIERON!! ";
	getchar();
}

void LISTA::AGREGAR_P(char * S)
{
	NODO * P; //TENGO UN PUNTERO.
	P = new NODO(S); //TENGO UN NODO.

	PONER_P(P);

}

void LISTA::PONER_P (NODO * PN)
{

		PN->SIG = INICIO;
		INICIO = PN;
}


void LISTA::AGREGAR_F(char * S)
{
	NODO * P; //TENGO UN PUNTERO.
	P = new NODO(S); //TENGO UN NODO.

	PONER_F(P);

}

void LISTA::PONER_F(NODO * PN)
{
		NODO * P;
		P = INICIO;

		PN-> SIG = NULL;
		if ( ! INICIO ) //INICIO ES NULL
		{
			//LISTA VACIA
			INICIO = PN;
			return ;
		}

		//LISTA NO VACIA

		while ( P->SIG )
			{
				P = P->SIG;     //LEVA A P AL ULTIMO NODO.
			}

		P->SIG = PN;

}

void LISTA::MIRAR()
{
	NODO * P;
	cout << "\n\n\t\t	CONTENIDO DE LA LISTA	\n";
	P = INICIO;
		while (P) //MIENTRAS P NO SEA NULL
			{
				cout << "\n\t\t" << P->NOM;//MUESTRO
				P = P->SIG; //AVANZO
			}
	getchar();
}

void LISTA::MIRARCP()
{
	NODO * P;
	cout << "\n\n\t\t	CONTENIDO DE LA LISTA	\n";
	P = INICIO;
		while (P) //MIENTRAS P NO SEA NULL
			{
				printf("\n\t%15p\t%-15s%15p", P, P->NOM, P->SIG);//MUESTRO
				P = P->SIG; //AVANZO
			}
	getchar();
}


void LISTA::MENOR()
{
	if ( INICIO )

	cout << "\n\n\n MENOR	:	" << MINIMO()->NOM;
	getchar();

}

void LISTA::MAYOR()
{
	if ( INICIO )

	cout << "\n\n\n MAYOR	:	" << MAXIMO()->NOM;
	getchar();
}

NODO * LISTA::MINIMO()
{
	NODO * P, * PMIN;
	PMIN = P = INICIO; //TODOS A INICIO, O TODOS A NULL

	while (P)
		{
			if(strcmp( P->NOM , PMIN->NOM ) < 0)
				PMIN = P;

			P = P->SIG;
		}

		return PMIN;
}

NODO * LISTA::MAXIMO()
{
	NODO * P, * PMAX;
	PMAX = P = INICIO; //TODOS A INICIO, O TODOS A NULL

	while (P)
		{
			if(strcmp( P->NOM , PMAX->NOM ) > 0)
				PMAX = P;

			P = P->SIG;
		}

		return PMAX;
}

NODO * BUSCAR(char * S)
{
	NODO * P;
	P = INICIO; //TODOS A INICIO, O TODOS A NULL

	while (P)
		{
			if( !strcmp( P->NOM , S ) ) // si strcmp(P->NOM, S) == 0
				return P;

			P = P->SIG;
		}

		return NULL;
}

void LISTA::ELIMINAR(char * S)
{
	NODO * P;
	P = BUSCAR(S);

	if ( P )
		MATAR(P);

}

void LISTA::MATAR (NODO * PELIM)
{
	NODO * P;

	if ( ! INICIO || ! PELIM )
		return ;

	//ACECHAR
	if ( PELIM == INICIO ) //esta en la primer posicion
		{
			INICIO = PELIM->SIG; //SECUESTRO
			delete PELIM; //LIQUIDO
			return; //ESCAPO
		}

	//Si llegué acá, la victima no estaba en la primer posición.

	while ( P->SIG != PELIM && P )
		{
			P = P->SIG; //ACECHO
		}

	if ( P )
	{
		 //SECUESTRO
		P->SIG = P->SIG->SIG; //PELIM->SIG; sería otra forma, pero vemos ésta ya que en listas dobles se va a usar.
		delete PELIM; //LIQUIDO

	}


}

void SACAR(char *);


char * GENERANOM();

void LISTA::INSERT( NODO * PN)
{
	NODO * P, * ANT;
	P = INICIO;
	ANT = NULL;

	if(!INICIO)
	{
		/*LISTA VACIA*/
		PN->SIG = NULL; //ENLACE 1
		INICIO = PN; //ENLACE 2
		return;
	}

	/*LISTA NO VACIA*/

	while (P)
	{
		if (strcmp(P->NOM , PN->NOM) < 0)
			{
				/*BARRIDO*/
				ANT = P;
				P = P->SIG;
			}
		else
		{
			/*EUREKA*/
			if ( ANT )
			{

					//NODO INTERMEDIO

					PN -> SIG = P;	//ENLACE 3
					ANT->SIG = PN;  //ENLACE 4
					return;
			}

			//NUEVO PRIMER NODO
			PN->SIG = INICIO;	//ENLACE 5
			INICIO = PN;		//ENLACE 6
			return;


		} // ELSE

	} //WHILE

		//NUEVO ULTIMO NODO

	PN ->SIG = NULL;	//ENLACE 7
	ANT->SIG = PN;		//ENLACE 8
}

int main()
{

	LISTA L;
	char BUF[20];

		strcpy( BUF, GENERANOM());
		while (strcmp(BUF, "FIN"))
			{
				L.AGREGAR_F(BUF);
				strcpy(BUF, GENERANOM());
			}

			L.MIRAR();

			L.MIRARCP();
			L.MENOR();
			L.MAYOR();

			cout << "\n\n NOMBRE A ELIMINAR	:	";
			scanf ("%d", &BUF);

			L.ELIMINAR(BUF);
			L.BUSCAR(BUF);


	printf("\n\n\n FIN DEL PROGRAMA");
	return 0;
}

char * GENERANOM()
{
	static int I = 0;
	static char NOM[][20] = {
						"PEPE","LOLA","JOSE","ANASTASIA",
						"LUCRECIA","TOMAS","PEDRO","PATRICIO",
						"LEONEL","SOFIA","MARIA","BRIAN",
						"MANUEL","EMILIANO","FEDERICO","FIN"
					 };
	return NOM[I++];
}
