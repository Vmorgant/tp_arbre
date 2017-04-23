#include <ab_animaux.h>

/*
 * Affichage 
 */


extern 
void ab_animaux_afficher( const ab_t * arbre , 
			  void (*fonction_affichage)(const void *)) 
{
<<<<<<< HEAD
  ab_afficher_bis( arbre->racine ,affichage,prefixe); 
=======
  /***********
   * A FAIRE *
   ***********/
 
  return ; 
>>>>>>> 531871622e69db7962683dac4cf52885a4f12b93
}

/*
 * Reconnaissance 
 */

<<<<<<< HEAD
void ab_animaux_reconnaitre( ab_t * arbre , 
			     err_t (*fonction_affectation)(void * , void *) ,
			     void (*fonction_affichage)(const void *),int reponse) 
{
    if(reponse==0){
        if(!noeud_feuille(arbre->racine)
            ab_afficher_bis( arbre->racine->droit ,affichage,prefixe); 
        else
    }
    else
        ab_afficher_bis( arbre->racine->gauche ,affichage,prefixe); 

=======
extern 
void ab_animaux_reconnaitre( ab_t * arbre , 
			     err_t (*fonction_affectation)(void * , void *) ,
			     void (*fonction_affichage)(const void *)) 
{
  /***********
   * A FAIRE *
   ***********/

  return ; 
>>>>>>> 531871622e69db7962683dac4cf52885a4f12b93
}
