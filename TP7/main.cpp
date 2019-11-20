#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <string>
#include <algorithm>
#include <random>


using namespace std;

int main() {

  /* Exercice 1 : Le conteneur vector et ses fonctions de base. */

  vector<int> v;

  if (v.empty() == true)
    cout << "Le vecteur est vide." << endl;
  else
    cout << "IL Y A QUELQUE CHOSE DANS TON VECTEUR." << endl;

  cout << "Ton vecteur a une taille de " << v.size() << endl;

  // La capacité : taille intermédiaire qu'il alloue => evite réallouer et recopie du tableau
  cout << "La capacité du vecteur est de " << v.capacity() << " ." << endl;
  cout << "Ton vecteur peut contenir au max " << v.max_size() << " entier(s)." << endl;

  const size_t sizeVec = 20;
  for (size_t i = 0; i < sizeVec; i++) {
    v.push_back(rand()%100);
  }

  cout << "Ton vecteur a une taille de " << v.size() << endl;
  cout << "La capacité du vecteur est de " << v.capacity() << " ." << endl;

  // Possible de #include <algorithm> réduire la capacité alloué avec la fonction suivante
  v.shrink_to_fit();
  cout << "La capacité du vecteur est de " << v.capacity() << " ." << endl;


  // Parcourir le vecteur et afficher ses valeurs avec un itérateur
  cout << "Le vecteur v contient les valeurs suivants : ";
  for (auto i: v) {
    cout << i << ", ";
  }

  cout << endl << endl << endl << "Exercice 2 : " << endl << endl;

  /* Exercice 2 */

  vector<string> v1;
  v1.push_back("Test");
  vector<string> v2;
  v2.push_back("Swap");

  v1.swap(v2);

  cout << "TEST : " << v1[0] << endl;
  cout << "SWAP : " << v2[0] << endl;


  cout << endl << endl << endl << "Exercice 3 : " << endl << endl;

  vector<int> vecInt(20);

  // cout << vecInt.size();

  // Pour générer aléatoirement des nombres autre que rand

/*
  random_device rd;
  set19937 gen(rd());
  uniform_int_distribution<int> dis(0,20);
*/

  for (size_t i = 0; i < vecInt.size(); i++) {
    vecInt[i] = (rand()%21);
  }

  for (auto i: vecInt) {
    cout << i << ", ";
  }

  cout << endl;


  sort(vecInt.begin(), vecInt.end());

  cout << "Après avoir trié : " << endl;

  for (auto i: vecInt) {
    cout << i << ", ";
  }

  cout << endl;

  // Permet de compter le nombre de fois qu'un nombre apparait

  cout << "Le nombre 7 apparait " <<
  count(vecInt.begin(), vecInt.end(), 7) << " fois" << endl;

  /* Exercice 4 */
  cout << endl << endl << endl << "Exercice 4 : " << endl << endl;

  deque<int> myqueue(5);

  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<int> dis(0,30);
  for (size_t i = 0; i < myqueue.size(); i++) {
    myqueue[i]= dis(gen);
  }

  /* Fonction Lambda = pour afficher les valeurs
  for_each(myqueue.begin(), myqueue.end(), [](const int val){cout << val << " ";});
  */
  for (size_t i = 0; i < myqueue.size(); i++) {
    cout << myqueue[i] << " ";
  }

  cout << endl;


  // Retire le dernier terme mais en rajoute un au début
  for (size_t i = 0; i < 5; i++) {
    myqueue.push_front(dis(gen));
    myqueue.pop_back();

    for (size_t i = 0; i < myqueue.size(); i++) {
      cout << myqueue[i] << " ";
    }

    cout << endl;
  }

  /* Exercice 5 */
  cout << endl << endl << endl << "Exercice 5 : " << endl << endl;

 list<string> l_philo;
 list<string> l_math;
 list<string>::iterator it;

 list<string> l_all;

 l_philo.push_back("Platon");
 l_philo.push_back("Aristote");
 l_philo.push_back("Descartes");
 l_philo.push_back("Kant");

 l_math.push_back("Gauss");
 l_math.push_back("Laplace");
 l_math.push_back("Poincaré");
 l_math.push_back("Descartes");


 cout << "La liste des philosophes contient :";
 for (it=l_philo.begin(); it!=l_philo.end(); ++it)
    cout << ' ' << *it;
 cout << '\n';
 l_philo.sort();
 cout << "La liste des philosophes contient : (après tri)";

 for (it=l_philo.begin(); it!=l_philo.end(); ++it)
    cout << ' ' << *it;
 cout << '\n';


 cout << "La liste des matheux contient :";
 for (it=l_math.begin(); it!=l_math.end(); ++it)
    cout << ' ' << *it;
 cout << '\n';
 l_math.sort();
 cout << "La liste des matheux contient : (après tri)";

 for (it=l_math.begin(); it!=l_math.end(); ++it)
    cout << ' ' << *it;
 cout << '\n';

 // fusionner deux listes

merge(
  l_philo.begin(), l_philo.end(),
  l_math.begin(), l_math.end(), back_inserter(l_all) );

 for (it=l_all.begin(); it!=l_all.end(); ++it)
    cout << ' ' << *it;
 cout << '\n';

  return 0;
}
