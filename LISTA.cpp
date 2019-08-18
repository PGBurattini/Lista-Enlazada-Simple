/*   LISTA SIMPLEMENTE ENLAZADA   */

#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std ;


class NODO {
		public :
			NODO(char *);
			~NODO() ;
			char NOM[20] ;
			NODO * SIG ;
};


NODO::NODO(char * S)
{
		strcpy ( NOM , S );
}

NODO::~NODO()
{
		cout << "\n\n   MATANDO A ... " << NOM ;
		getchar();	
}


class LISTA {
		private :
			NODO * INICIO ;
			void PONER_P(NODO *);
			void PONER_F(NODO *);
			void INSERT(NODO *);
			NODO * MINIMO() ;
			NODO * MAXIMO() ;
			NODO * BUSCAR(char *);
			void MATAR(NODO *);
			void SACAR(NODO *);
		public :
			LISTA() ;
			~LISTA();
			void AGREGAR_P(char *);
			void AGREGAR_F(char *);
			void INSERTAR(char *);
			void MIRAR();
			void MIRARCP();
			void RARIM();
			void MENOR() ;
			void MAYOR() ;
			void ELIMINAR(char *);
			void ORDENAR1();
			void ORDENAR2();
};

LISTA::LISTA()
{
		INICIO = NULL ;
}


LISTA::~LISTA()
{
		cout << "\n\n SE DEBEN LIBERAR (DESTRUIR) TODOS LOS NODOS " ;
		cout << "\n\n ERA PARA USTEDES Y TODAVIA NO LA HICIERON !!! " ;
		getchar();
}

void LISTA::AGREGAR_P(char * S)
{
		NODO * P ;
		P = new NODO(S) ;
	
		PONER_P(P) ;	
}

void LISTA::PONER_P ( NODO * PN)
{
		PN->SIG = INICIO ;
		INICIO = PN ;	
}

void LISTA::AGREGAR_F(char * S)
{
		NODO * P ;
		P = new NODO(S) ;
	
		PONER_F(P) ;	
}

void LISTA::PONER_F ( NODO * PN)
{
		NODO * P ;
		P = INICIO ;
	
		PN->SIG = NULL ;
		if ( ! INICIO ) {
				/*  LISTA VACIA  */
				INICIO = PN ;
				return ;			
		}
		/*  LISTA NO VACIA  */
		while ( P->SIG)
				P = P->SIG ; 		/*  LLEVAR P HASTA EL ULTIMO NODO  */
		P->SIG = PN ;
}

void LISTA::INSERTAR(char * S)
{
		NODO * P ;
		P = new NODO(S) ;
	
		INSERT(P) ;	
}

void LISTA::INSERT ( NODO * PN)
{
		NODO * P , * ANT ;
		P = INICIO ;
		ANT = NULL ;
		
		if ( !INICIO ) {
				/*  LISTA VACIA  */
				PN->SIG = NULL ;   						/* 1 */
				INICIO = PN ; 							/* 2 */
				return ;			
		}
		/*  LISTA NO VACIA  */
		while ( P ) {
			 	if ( strcmp(P->NOM , PN->NOM) < 0 ) {
			 			/*  BARRIDO  */
			 			ANT = P ;
			 			P = P->SIG ;
			 	}
			 	else  {
			 			/*  EUREKA  */
			 			if ( ANT ) {
			 					/*  NODO INTERMEDIO  */
			 					PN->SIG = P ; 				/* 3 */
			 					ANT->SIG = PN ; 			/* 4 */
			 					return ;			 					
			 			}
			 			/*  NUEVO PRIMER NODO  */
			 			PN->SIG = INICIO ;					/* 5 */
			 			INICIO = PN ;						/* 6 */
			 			return ;
			 	} /* else */
		} /* while */
		/*  NUEVO ULTIMO NODO  */	
		PN->SIG = NULL ;  									/* 7 */
		ANT->SIG = PN ; 									/* 8 */
}


void LISTA::MIRAR()
{
		NODO * P ;
		cout << "\n\n\t\t CONTENIDO DE LA LISTA\n";
		P = INICIO ;
		while ( P ) {
				cout << "\n\n\t\t " << P->NOM ;
				P = P->SIG ;        /* avanzo al siguiente nodo  */			
		}
		getchar();
}

void LISTA::MIRARCP()
{
		NODO * P ;
		cout << "\n\n\t\t CONTENIDO DE LA LISTA\n";
		P = INICIO ;
		while ( P ) {
				printf("\n\n\t\t%15p\t%-15s%15p" , P , P->NOM ,P->SIG ) ;
				P = P->SIG ;        /* avanzo al siguiente nodo  */			
		}
		getchar();
}


void LISTA::RARIM()
{
		
		cout << "\n\n\t\t CONTENIDO INVERSO DE LA LISTA\n";
		
		getchar();
}

void LISTA::MENOR()
{
		if ( INICIO )
				cout << "\n\n\n   MENOR   :   " << MINIMO()->NOM ;
		getchar();	
}

void LISTA::MAYOR()
{
		if ( INICIO )
				cout << "\n\n\n   MAYOR   :   " << MAXIMO()->NOM ;
		getchar();	
}

NODO * LISTA::MINIMO()
{
		NODO * P , * PMIN ;
		PMIN = P = INICIO ;
		while ( P ) {
				if ( strcmp(P->NOM,PMIN->NOM) < 0 )
						PMIN = P ;
				P = P->SIG ;			
		}
		return PMIN ;	
}

NODO * LISTA::MAXIMO()
{
		NODO * P , * PMAX ;
		PMAX = P = INICIO ;
		while ( P ) {
				if ( strcmp(P->NOM,PMAX->NOM) > 0 )
						PMAX = P ;
				P = P->SIG ;			
		}
		return PMAX ;	
}

NODO * LISTA::BUSCAR(char * S)
{
		NODO * P ;
		P = INICIO ;
		while ( P ) {
				if ( !strcmp(P->NOM,S) )
						return P ;
				P = P->SIG ;			
		}
		return NULL ;	
}

void LISTA::ELIMINAR(char * S)
{
		NODO * P ;
		P = BUSCAR(S) ;
	
		if ( P )
				MATAR(P) ;
}

void LISTA::MATAR(NODO * PELIM)
{
		NODO * P ;
		if ( !INICIO || !PELIM )
					return ;
		if ( PELIM == INICIO ) {
				INICIO = PELIM->SIG ;
				delete PELIM ;
				return ;
		}
		
		P = INICIO ;
		while ( P->SIG != PELIM && P )
				P = P->SIG ;
		if ( P ) {
				/*  P->SIG = PELIM->SIG ;  */	
				P->SIG = P->SIG->SIG ;
				delete PELIM ;			
		}	
}


void LISTA::SACAR(NODO * PELIM)
{
		NODO * P ;
		if ( !INICIO || !PELIM )
					return ;
		if ( PELIM == INICIO ) {
				INICIO = PELIM->SIG ;
				return ;
		}
		
		P = INICIO ;
		while ( P->SIG != PELIM && P )
				P = P->SIG ;
		if ( P ) 
				P->SIG = P->SIG->SIG ;
}

void LISTA::ORDENAR1()
{
		NODO * P ;
		NODO * AUXINI ;
		AUXINI = NULL ;
		
		while ( INICIO ) {
				P = MAXIMO() ;
				SACAR(P) ;
				P->SIG = AUXINI ;
				AUXINI = P ;		
		}
		INICIO = AUXINI ;
}

void LISTA::ORDENAR2()
{
		NODO * P ;
		LISTA AUXL ;
		
		while ( INICIO ) {
				P = INICIO ;
				SACAR(P) ;
				AUXL.INSERT(P) ;			
		}
		INICIO = AUXL.INICIO ;	
		AUXL.INICIO = NULL ;
}



char * GENERANOM() ;

int main( )
{  
		LISTA L ;
		char BUF[20] ;
				
		strcpy ( BUF , GENERANOM() ) ;
		while ( strcmp(BUF,"FIN") ) {
				L.AGREGAR_F(BUF) ;			
				strcpy ( BUF , GENERANOM() ) ;			
		}
		
		L.MIRAR() ;
		
//		cout << "\n\n  NOMBRE A ELIMINAR   :   ";
//		cin >> BUF ;
		
//		L.ELIMINAR(BUF) ;

		L.ORDENAR2() ;
		
		L.MIRAR() ;
								
		printf("\n\n   FIN DEL PROGRAMA  \n\n" );	
		return 0 ;
}

char * GENERANOM()
{
		static int I = 0 ;
		static char NOM[][20] = {"FEDERICO","ANA","LAURA","CAROLINA",
						  "JUAN","PEDRO","ANDRES","PEPE",
						  "LOLA","FELIPE","PACO","LUIS",
						  "CARLOS","LORENA","EDUARDO","MELISA",
						  "MARINA","FIN"};
		return NOM[I++];
}
	
	
	
	





