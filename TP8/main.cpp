#include <iostream>
#include "Point3D.hpp"

using namespace std;


template<typename T>
const T &getMinimum(const T &a, const T &b)
{
  return a < b ? a : b;
}

// Surcharge de la fonction template getMinimum

template<>
const char &getMinimum(const char &a, const char &b)
{
  return toupper(a) < toupper(b) ? a : b;
}

int main() {

  // Exercice 1 : Merci Patron !

  /* ---- 1 ---- */

  if (getMinimum<int>(79, 6)) {
    cout << "(INT) : Le premier terme est plus petit." << endl;
  }else{
    cout << "(INT) : Le second est plus petit." << endl;
  }

  if (getMinimum<float>(7.9f, 6.7f)) {
    cout << "(FLOAT) : Le premier terme est plus petit." << endl;
  }else{
    cout << "(FLOAT) : Le second est plus petit." << endl;
  }

  if (getMinimum<char>('a', 'z')) {
    cout << "(CHARS) : Le premier terme est plus petit." << endl;
  }else{
    cout << "(CHARS) : Le second est plus petit." << endl;
  }

  cout << endl << endl;

  /* ---- 2 ---- */

  if(getMinimum<float>(7.9f, 67)){
    cout<< "(FLOAT/INT + CAST) Le premier terme est plus petit." << endl;
  }

  cout << endl << endl;

  // Exercice 2 : Un Patron qui a la classe !

  Point3D<double> a(1,2,3);
  Point3D<double> b(a);






  return 0;
}
