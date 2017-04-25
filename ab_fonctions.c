#include <ab_fonctions.h>

/*
 * Affichage des ancetres d'un noeud
 */

extern
void ab_ancetres_afficher( const ab_t * arbre , 
			   noeud_t * noeud ,
			   void (*afficher)(const void *) )
{

	noeud_t * pere=NULL;

  if( (pere=ab_pere_rechercher( arbre , noeud ))==NULL)
	{
		return;
	}
	else
	{
		afficher(pere->etiquette);
		printf("\n");
		ab_ancetres_afficher( arbre, pere, afficher);
	}

}
