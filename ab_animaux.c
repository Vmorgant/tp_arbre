#include <ab_animaux.h>

/*
 * Affichage 
 */


extern 
void ab_animaux_afficher( const ab_t * arbre , 
			  void (*fonction_affichage)(const void *),ab_parcours_t parcours) 
{

  ab_afficher( arbre ,fonction_affichage,parcours); 
 
  return ; 
}

/*
 * Reconnaissance 
 */

void ab_animaux_reconnaitre( ab_t * arbre , 
			     err_t (*fonction_affectation)(void * , void *) ,
			     void (*fonction_affichage)(const void *),ab_parcours_t parcours) 
{

}
