#include <math.h>

#include <ab.h>
#include <individu.h>

#define FICH_TEST "Fichiers/test_ab_individus.fich"

<<<<<<< HEAD

=======
>>>>>>> 531871622e69db7962683dac4cf52885a4f12b93
int
main(int argc , char * argv[] ) 
{
  err_t noerr = OK; 
  char nomprog[512] ;

  individu_t ** individus = NULL  ; 
  noeud_t ** noeuds = NULL ; 
  ab_t * arbre = NULL ; 

<<<<<<< HEAD
  float exp_n = 0 ;
=======
  float exp_n = 0 ; 
>>>>>>> 531871622e69db7962683dac4cf52885a4f12b93
  float N = 0 ; 

  int i ; 

  strcpy( nomprog , argv[0] ) ; 

  if( argc != 3 )
    {
      printf( "usage: %s 2<n> <parcours>\n" , nomprog ) ; 
      printf( "\t n: puissance de 2; n^2 - 1  representera le nombre d'elements de l'arbre\n" ) ; 
      printf( "\t <parcours>: type de parcours dans l'affichage de l'arbre\n" ) ; 
      printf( "\t            INF  --> Infixe \n" ) ; 
      printf( "\t            POST --> Postfixe \n" ) ; 
      printf( "\t            SYM  --> Symetrique \n" ) ; 
      exit(1) ;
    }

  exp_n = atof(argv[1]) ;
  N = powf( 2 , exp_n ) - 1 ; 

<<<<<<< HEAD
  ab_parcours_t parcours = UNK  ; 
  if( ! strcmp( argv[2] , "INF"  ) ) parcours = INFIXE ;
  if( ! strcmp( argv[2] , "POST" ) ) parcours = POSTFIXE ;
  if( ! strcmp( argv[2] , "PRE"  ) ) parcours = PREFIXE ;
=======

  ab_parcours_t parcours = UNK  ; 
  if( ! strcmp( argv[2] , "INF"  ) ) parcours = INFIXE ;
  if( ! strcmp( argv[2] , "POST" ) ) parcours = POSTFIXE ;
  if( ! strcmp( argv[2] , "SYM"  ) ) parcours = SYMETRIQUE ;
>>>>>>> 531871622e69db7962683dac4cf52885a4f12b93
  if( parcours == UNK ) 
    {
      printf( "Parametre <parcours> incorrect (%s)\n" , argv[2] ) ; 
      printf( "\t <parcours>: type de parcours dans l'affichage de l'arbre\n" ) ; 
      printf( "\t            INF  --> Infixe \n" ) ; 
      printf( "\t            POST --> Postfixe \n" ) ; 
<<<<<<< HEAD
      printf( "\t            PRE  --> Prefixe \n" ) ; 
=======
      printf( "\t            SYM  --> Symetrique \n" ) ; 
>>>>>>> 531871622e69db7962683dac4cf52885a4f12b93
      exit(1) ;
    }

  printf( "Debut du programme de test sur les objets de type arbre ab_t avec %d elements\n"  , (int)N ) ; 

  /* 
   * Creation variables de travail 
   */

  individus = malloc( sizeof(individu_t *) * N+1 )  ; 

  char prenom[128] ;
  char nom[128] ; 
  individus[0] = NULL ;
  for( i=1 ; i<N+1 ; i++ ) 
    {
      sprintf( nom , "nom_%d" , (int)N-i ) ;
      sprintf( prenom , "prenom_%d" , (int)N-i ) ;
      individus[i] = individu_creer( prenom , nom ) ; 
    }

  noeuds = malloc( sizeof(noeud_t *) * N+1 ) ; 
  noeuds[0] = NULL ; 
  for( i=1 ; i<N+1 ; i++ )
    {
      noeuds[i]= noeud_creer( i , individus[i] , NULL , NULL , individu_referencer_cb ) ; 
    }

  for( i=1 ; i<N+1 ; i++ )
    {
      if( 2*i <= N ) 
	{
	  noeud_sag_ecrire( noeuds[i] , noeuds[2*i] ) ; 
	  noeud_sad_ecrire( noeuds[i] , noeuds[(2*i)+1] ) ; 
	}
    }
  
  /* ----- */

 printf( "Test d'existance sur un ab_t inexistant\n" ) ;
 ( ab_existe(arbre) ? printf("-->KO\n") : printf ("-->OK\n") )  ;
<<<<<<< HEAD
 
=======

>>>>>>> 531871622e69db7962683dac4cf52885a4f12b93
 printf( "Test Creation d'un ab_t \n" ) ;
 if( ( arbre = ab_creer( individu_referencer_cb , individu_effacer_cb ) ) == NULL )
   { 
     printf("Debordement memoire\n") ;
     return(ERR_DEB_MEMOIRE) ; 
   } 
 printf( "Rattachement arbre a sa racine\n" ) ;
 if( N > 0 )
   {
     if( ( noerr = ab_racine_ecrire( arbre , noeuds[1] ) ) )
       { 
	 printf("Sortie avec code erreur = %d\n" , noerr ) ;
	 return(noerr) ; 
       }
   }

  printf( "Test affichage arbre\n" ) ;
<<<<<<< HEAD
  ab_afficher( arbre , individu_afficher_cb,parcours ) ; 
=======
  ab_afficher( arbre , individu_afficher_cb ) ; 
>>>>>>> 531871622e69db7962683dac4cf52885a4f12b93
  printf( "\n");

  printf( "Test d'existance sur un arbre ab_t existant\n" ) ;
  ( ab_existe(arbre) ? printf("-->OK\n") : printf ("-->KO\n") )  ;

  printf( "Test sauvegarde arbre ab_t\n" ) ; 
  if( ( noerr = ab_sauver( arbre , FICH_TEST , individu_sauver_cb ) ) )
    { 
      printf("Sortie avec code erreur = %d\n" , noerr ) ;
      return(noerr) ; 
    } 

  printf( "Test destruction arbre\n" ) ;
  if( ( noerr = ab_detruire( &arbre ) ) )
    { 
      printf("Sortie avec code erreur = %d\n" , noerr ) ;
      return(noerr) ; 
    }
  
<<<<<<< HEAD
/* printf( "Test chargement arbre\n" ) ;
=======
 printf( "Test chargement arbre\n" ) ;
>>>>>>> 531871622e69db7962683dac4cf52885a4f12b93
 if( ( noerr = ab_charger( &arbre  , FICH_TEST , 			
			   individu_copier_cb , individu_detruire_cb , 
			   individu_charger_cb ) ) )  
   { 
     printf("Sortie avec code erreur = %d\n" , noerr ) ;
     err_print(noerr) ;
     return(noerr) ; 
   }
<<<<<<< HEAD
*/
  printf( "Affichage arbre charge\n" ) ;
  ab_afficher( arbre , individu_afficher_cb, parcours  ) ; 
=======

  printf( "Affichage arbre charge\n" ) ;
  ab_afficher( arbre , individu_afficher_cb ) ; 
>>>>>>> 531871622e69db7962683dac4cf52885a4f12b93
  printf( "\n");

  /*
   * Destructions variables de travail 
   */
  
  for( i=1 ; i<N ; i++ ) 
    {
      individu_detruire( &individus[i] ) ; 
    }

  printf( "Fin du programme de test sur les objets de type arbre ab_t\n" ) ; 

  return(0) ; 
}