// Adivinar número aleatorio

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main () {

int num, dato, contador=0;

srand(time(NULL)); // genera numero aleatorio
dato= 1+rand()%(100);

do
{

    cout<<"Introduzca un número: "; cin>>num;

    if (num>dato) {
     cout<<"\nDigite un número menor\n";}

    if (num<dato) {
    cout << "\nDigite un número mayor\n";}

    contador++;

} while (num != dato);

cout<<"\nFelicidades, has adivinado el número\n";
cout << "Numero de intentos: "<<contador<<endl;

return 0;
}

