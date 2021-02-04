// sort algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <string.h>
struct Noeud
{
   int valeur;
   Noeud* fils_droite;
   Noeud* fils_gauche;
};
Noeud* arbre = NULL;
void Placer(Noeud* noeud)
{
   Noeud* courant = arbre;
   Noeud* precedent = NULL;

   // Si l'arbre est vide, ça va très vite :
   if(arbre == NULL)
   {
      arbre = noeud;
      return;
   }

   // On se fraye un chemin jusqu'a une place vide
   while(courant)
   {
      precedent = courant;
      if(noeud->valeur < courant->valeur)
         courant = courant->fils_gauche;
      else
         courant = courant->fils_droite;
   }

   // Hop, on a trouvé une place libre, et
   // precedent pointe vers le parent de notre
   // noeud à replacer.
   if(noeud->valeur < precedent->valeur)
      precedent->fils_gauche = noeud;
   else
      precedent->fils_droite = noeud;
}

void Ajouter(int valeur)
{
   // Création de notre nouveau noeud en mémoire
   Noeud* nouveau = new Noeud;
   nouveau->valeur = valeur;
   nouveau->fils_droite = NULL;
   nouveau->fils_gauche = NULL;

   // Puis on laisse Placer() le mettre à la bonne place
   Placer(nouveau);
}

Noeud* Rechercher(int valeur)
{
   Noeud* courant = arbre;
   while(courant)
   {
      if(valeur == courant->valeur)
         return courant;
      else if(valeur < courant->valeur)
         courant = courant->fils_gauche;
      else
         courant = courant->fils_droite;
   }

   return NULL;
}

void Supprimer(Noeud* noeud)
{
   Noeud* droite = noeud->fils_droite;
   Noeud* gauche = noeud->fils_gauche;
   Noeud* courant = arbre;

   // Cas délicat : si on supprime la racine? V11
   if(noeud == arbre)
   {
      arbre = droite;
      if(gauche) Placer(gauche);
      delete noeud;
      return;
   }

   while(courant)
   {
      if(courant->fils_droite == noeud
         || courant->fils_gauche == noeud)
         break;

      if(noeud->valeur >= courant->valeur)
         courant = courant->fils_droite;
      else
         courant = courant->fils_gauche;
   }

   // Courant pointe maintenant vers le noeud précédent le 
   // noeud à supprimer.
   if(courant->fils_droite == noeud)
      courant->fils_droite = droite;
   else
      courant->fils_gauche = droite;

   // Et puis on replace l'autre fils du noeud disparu
   if(gauche) Placer(gauche);

   // Enfin, on libère l'objet noeud de ses obligations
   delete noeud;
}

void Afficher(Noeud* racine)
{
   if(racine->fils_gauche) Afficher(racine->fils_gauche);
   std::cout << racine->valeur << std::endl;
   if(racine->fils_droite) Afficher(racine->fils_droite);
}

int main(void)
{
   Ajouter(10);
   Ajouter(4);
   Ajouter(15);
   Ajouter(2);
   Ajouter(16);
   Ajouter(1);
   Ajouter(9);
   Ajouter(14);

   Afficher(arbre);

   Noeud* n = Rechercher(4);
   Supprimer(n);

   Afficher(arbre);

   return 0;
}