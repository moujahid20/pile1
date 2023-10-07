#include <stdio.h>
#include <stdlib.h>


typedef struct elem
{
    int sommet;//sommet de le pile
    struct elem *suiv;//pointeur de l'element suivant
}ptpile;

///fonction pour aLLOUER une espace memoire
ptpile *allouer()
{
    ptpile *ptpl=(ptpile*)malloc(sizeof(ptpile));
    if(!ptpl)
    {
        printf("\n erreur!");
        exit(-1);
    }
    return ((ptpile*)ptpl);
}

///fonction pour creer une cellule
ptpile *creer_ptpile(int element)
{
    //alllouer l'espace memoire
    ptpile *ptpl=allouer();
    ptpl->suiv=NULL;
    ptpl->sommet=element;//initialiser le sommet
    return ((ptpile*)ptpl);
}

///pile vide
int estvide_tpile(ptpile *pile)
{
    return ((int)pile==NULL);
}

///fonction pour depiler la pile
ptpile *depiler_ptpile(ptpile *mapile)
{
    ptpile *supp;//pour l'element supprimer
    //tester si la pile est vide
   if(estvide_tpile(mapile))
       printf("\n pile est vide");
   else
   {
       //mettre la premier cellule dans l'element supp
       supp=mapile;
       //augmenter le sommet
       mapile=mapile->suiv;
       //supprimer l'element supp
       free(supp);
   }
   return ((ptpile*)mapile);
}

///fonction pour empiler la pile
ptpile *empiler(ptpile *PILE , int val)
{
    //creer une cellule
    ptpile *cellule;
    cellule=creer_ptpile(val);
     //tester si la pile est vide
    if(!PILE)
        //mettre la cellule dans la pile
        PILE=cellule;
    else
    {
        //mettre la cellule dans la pile
        cellule->suiv=PILE;
        PILE=cellule;
    }
    return ((ptpile*)PILE);
}

///fonction pour vider la pile
ptpile *raz_ptpile(ptpile *pl)
{
    //boucle pour supp toutes les element de la pile
    while(!estvide_tpile(pl)) pl=depiler_ptpile(pl);
    return ((ptpile*)pl);
}

///ffonction pour afficher les element de la pile
int afficher_tpile(ptpile *pile)
{
    //allouer l'espace memoire pour la 2eme pile
    ptpile *pile2=allouer();
    //tester si la pile est vide
    if(estvide_tpile(pile))
    {
        printf("\n pile est vide ");
        return((int)0);
    }
    //
    while(!estvide_tpile(pile))
    {
        //empiler le sommet de la 1ere pile dans la 2eme pile
        pile2=empiler(pile2,pile->sommet);
        //afficher le sommet de la 1ere pile
        printf("\t\t %d",pile->sommet);
        //depiler la 1ere pile
        pile=depiler_ptpile(pile);

    }
    while(!estvide_tpile(pile2))
    {
        //empiler le sommet de la 2eme pile dans la 1ere pile
        pile=empiler(pile,pile2->sommet);
        //depiler la 2eme pile
        pile2=depiler_ptpile(pile2);
    }
    printf("\n");
    return((int)1);

}


int main()
{
    ptpile *mapile=NULL;
    mapile=empiler(mapile,1);
    mapile=empiler(mapile,2);
    mapile=empiler(mapile,1);
    mapile=empiler(mapile,1);
    mapile=empiler(mapile,1);
    if(afficher_tpile(mapile));
    mapile=empiler(mapile,10);
    if(afficher_tpile(mapile));
    mapile=depiler_ptpile(mapile);
    mapile=empiler(mapile,11);
    mapile=empiler(mapile,12);
    if(afficher_tpile(mapile));
    mapile=depiler_ptpile(mapile);
    if(afficher_tpile(mapile));




}
