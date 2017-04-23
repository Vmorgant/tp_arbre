#include <noeud.h>


/* Numero */

extern 
int noeud_numero_lire( const noeud_t * noeud ) 
{

  return(noeud->numero) ; 
}

extern 
err_t noeud_numero_ecrire( noeud_t * noeud , const int numero ) 
{
	noeud->numero=numero;
  return(OK) ; 
}

/* Etiquette */

extern 
void * noeud_etiquette_lire( const noeud_t * noeud ) 
{
  return(noeud->etiquette) ; 
}

extern 
err_t noeud_etiquette_ecrire( noeud_t * noeud , 
			      void * etiquette ,
			      err_t (*affecter)( void * e1 , void * e2 ) ) 
{
  
  return(affecter(noeud->etiquette,etiquette)) ; 
}

/* Sous arbre gauche */

extern 
noeud_t * noeud_sag_lire( const noeud_t * noeud ) 
{
  return(noeud->gauche);
}

extern 
err_t noeud_sag_ecrire( noeud_t * noeud ,  noeud_t * sous_arbre_gauche ) 
{
  noeud->gauche=sous_arbre_gauche;
  return(OK) ; 
}

/* Sous arbre droit */

extern 
noeud_t * noeud_sad_lire( const noeud_t * noeud ) 
{
  return(noeud->droit); 
}

extern 
err_t noeud_sad_ecrire( noeud_t * noeud ,  noeud_t * sous_arbre_droit ) 
{
  noeud->droit=sous_arbre_droit;
  return(OK) ; 
}

/*
 * Existance ?
 */

booleen_t
noeud_existe( const noeud_t * noeud )
{
  if(noeud==NULL)
  	  return(FAUX);
  return(VRAI) ; 
}

/* 
 * Feuille ?
 */
extern 
booleen_t noeud_feuille( const noeud_t * noeud )
{
  if(!noeud_existe(noeud_sag_lire(noeud)) && !noeud_existe(noeud_sad_lire(noeud)))
  	  return(VRAI);
  return(FAUX) ; 
}

/* 
 * Parents ?
 */

extern
booleen_t noeud_est_pere( const noeud_t * noeud_pere , 
			  const noeud_t * noeud_fils ) 
{
  if( (noeud_pere->gauche==noeud_fils) || (noeud_pere->droit==noeud_fils) )
  	  return(VRAI);
  return(FAUX) ; 
}

/* 
 * Creation
 */

extern 
noeud_t * noeud_creer( const int numero , 
		       void * etiquette , 
		       noeud_t * sous_arbre_gauche ,
		       noeud_t * sous_arbre_droit ,
		       err_t (*affecter)( void * e1 , void * e2 ) )
{
  noeud_t * noeud = NULL ; 
  noeud=malloc(sizeof(noeud_t));
  noeud->numero=numero;
  noeud->etiquette=NULL;
  affecter(&(noeud->etiquette),etiquette);
  noeud->gauche=sous_arbre_gauche;
  noeud->droit=sous_arbre_droit;
 
  return( noeud ) ;
}

/*
 * Destruction 
 */

extern 
err_t noeud_detruire( noeud_t ** noeud , 
		      err_t (*detruire)( void * e) ) 
{
  if(!(noeud_existe(*noeud)))
  	  return(OK);
  
  detruire(&(*noeud)->etiquette);
<<<<<<< HEAD
=======
 /* if(noeud_existe((*noeud)->gauche)){
  		  noeud_t *fg=noeud_sag_lire(*noeud);
  		  noeud_detruire(&fg,detruire(fg));
  }
  if(noeud_existe((*noeud)->droit)){
  		  noeud_t *fd=noeud_sad_lire(*noeud);
  		  noeud_detruire(&fd,detruire(fd)) ;
  }*/
>>>>>>> 531871622e69db7962683dac4cf52885a4f12b93
 
  return(OK) ; 
}

/*
 * Affichage 
 */

extern
void noeud_afficher_bis( const noeud_t * noeud ,
		     void (*afficher)(const void *),int profondeur) 
{
	int i;
  if(!noeud_existe(noeud))
  	  return;
  for(i=0;i<profondeur;i++){
  	 printf("  ");
  	 
  }
  afficher(noeud->etiquette);
  if(noeud->gauche !=NULL)
  	  noeud_afficher_bis(noeud->gauche,afficher,profondeur+1);
  if(noeud->droit !=NULL)
  	  noeud_afficher_bis(noeud->droit,afficher,profondeur+1);
}

void noeud_afficher( const noeud_t * noeud ,
		     void (*afficher)(const void *)) 
{
	noeud_afficher_bis(noeud,afficher,0);

}
/*
 * Sauvegarde dans un fichier 
 */

extern 
err_t noeud_fd_sauver( noeud_t * noeud  ,	                  /* Noeud a sauvegarder */
		       FILE * fd , 		                  /* Descripteur fichier  */
		       err_t (*sauver)( void * e, FILE *  desc) ) /* Fonction de sauvegarde d'un element */
{
  err_t noerr = OK ;

  if( ! noeud_existe( noeud ) ) 
    return(OK) ; 

  fprintf( fd , "%d " , noeud->numero ) ;
  noeud_t * fils_gauche  = noeud_sag_lire( noeud ) ;
  noeud_t * fils_droit   = noeud_sad_lire( noeud ) ;

  if( noeud_existe( fils_gauche ) )
    fprintf( fd , "%d " ,  noeud_numero_lire(fils_gauche) ) ; 
  else
    fprintf( fd , "-1 " ) ; 

  if( noeud_existe( fils_droit ) )
    fprintf( fd , "%d " ,  noeud_numero_lire(fils_droit) ) ; 
  else
    fprintf( fd , "-1 " ) ; 

  if( ( noerr = sauver( noeud->etiquette , fd ) ) )
    return(noerr) ; 

  return(OK) ; 
}

/*
 * Recherches d'un noeud dans un arbre 
 */


/* Sur le numero */

extern
booleen_t noeud_numero_rechercher( noeud_t ** result ,        /* Resultat: @ du noeud trouve */  
				   noeud_t * racine ,  /* Racine de l'arbre de recherche */
				   const int numero       )  /* Numero a rechercher dans l'arbre */
{
	if(racine->numero ==numero)
		result=&racine;
		return (VRAI);
	if(noeud_feuille(racine))
		return(FAUX) ; 
	else
		noeud_numero_rechercher(result,racine->gauche,numero);
		noeud_numero_rechercher(result,racine->droit,numero);
}


/* Sur l'etiquette */

extern
booleen_t noeud_rechercher( noeud_t ** result ,			 /* Resultat: @ du noeud trouve */  
			    noeud_t * racine  ,	         /* Racine de l'arbre de recherche */
			    void * etiquette     ,		 /* Valeur a rechercher dans l'arbre */
			    int (*comparer)(void * n1 , void * n2) ) /* Fonction de comparaison des etiquettes */
{
  if(racine->etiquette ==etiquette)
		result=&racine;
		return (VRAI);
	if(noeud_feuille(racine))
		return(FAUX) ; 
	else
		noeud_rechercher(result,racine->gauche,etiquette,comparer);
		noeud_rechercher(result,racine->droit,etiquette,comparer);
  return(FAUX) ; 
}
