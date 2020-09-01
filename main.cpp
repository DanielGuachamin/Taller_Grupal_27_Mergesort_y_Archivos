#include <iostream>
#include <fstream>

using namespace std;
const int MAX = 100;
void ingresar_datos(int arreglo[MAX], int t);
void imprimir(int arreglo[MAX], int t);
void dividir(int arreglo[MAX], int inicial, int final);
void fusionar(int arreglo[MAX], int pinicial, int pfinal, int medio);


int main() {
  ofstream Mergesort;
  Mergesort.open("mergesort", ios::out);
  if(Mergesort.is_open())
  {
    int Arreglo[MAX], tamanio, Ordenado[MAX], i;
    cout << "\nIngrese el tamanio del arreglo: ";
    cin >> tamanio;
    ingresar_datos(Arreglo, tamanio);
    cout << "\nArreglo original" << endl;
    imprimir(Arreglo, tamanio);
    Mergesort << "Arreglo original" << '\n' << "Elementos del arreglo: ";
    for(i = 0; i < tamanio; i++)
    {
      Mergesort << " | " << Arreglo[i] << " | ";
    } 
    cout << endl;
    dividir(Arreglo, 0, tamanio -1);
    cout << "\nArreglo ordenado" << endl;
    imprimir(Arreglo, tamanio);
    Mergesort << '\n' << "Arreglo ordenado" << '\n' << "Elementos del arreglo: ";
    for(i = 0; i < tamanio; i++)
    {
      Mergesort << " | " << Arreglo[i] << " | ";
    } 
  }
  else
  {
    cout << "\nEl archivo no abrio exitosamente" << endl;
  }
  Mergesort.close();
}
void ingresar_datos(int arreglo[MAX], int t)
{
  int i;
  srand(time(0));
  for(i = 0; i < t; i++)
  {
    arreglo[i] = 1+rand()%(50-1);
  }
}
void imprimir(int arreglo[MAX], int t)
{
  int i;
  cout << "\nElemento del arreglo: ";
  for(i = 0; i < t; i++)
  {
    cout << " | " << arreglo[i] << " | ";
  }
}
void dividir(int arreglo[MAX], int inicial, int final)
{
  int mitad;
  if (inicial < final)
  {
    mitad = (inicial + final)/2;

    dividir(arreglo, inicial, mitad);
    dividir(arreglo, mitad + 1, final);
    fusionar(arreglo, inicial, final , mitad);
  }
}
void fusionar(int arreglo[MAX], int pinicial, int pfinal, int medio)
{
  int i, j, k, temp[pfinal-pinicial + 1];
	i = pinicial;
	k = 0;
	j = medio + 1;
	while (i <= medio && j <= pfinal)
	{
		if (arreglo[i] < arreglo[j])
		{
			temp[k] = arreglo[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = arreglo[j];
			k++;
			j++;
		}
	}
	while (i <= medio)
	{
		temp[k] = arreglo[i];
		k++;
		i++;
	}

	while (j <= pfinal)
	{
		temp[k] = arreglo[j];
		k++;
		j++;
	}

	for (i = pinicial; i <= pfinal; i++)
	{
		arreglo[i] = temp[i-pinicial];
	}
}