/*
 * Practica 4.
 *
 * @file merge.cpp
 * @brief Practicas Estructuras de Datos y Algoritmos Practica 4
 * Curso 2016 - 2017
 *
 * (c) Departament d'Informatica.
 *     Universitat de Valencia
 *
 * @version 1.0
 * @author Javier Alonso y Lucas Nicolini
 * @date 11-11-2016
 *
 */

#include <iostream>
#include "VElement.h"

using namespace std;

void Mezcla(int,int,int);
void MezclaOrd(int,int);

int vector[] = {5,8,4,99,1,45,78,6,7,2,33,48,13};
int vector_aux[sizeof(vector)/2]; // vector auxiliar

int contador = 0;

void MezclaOrd(int izquierda, int derecha)
{

	int m;

	if(izquierda < derecha)
	{
		m = (izquierda + derecha) / 2;
		MezclaOrd(izquierda, m);
		MezclaOrd(m+1, derecha);
		Mezcla(izquierda, m, derecha);
	}
}

void Mezcla(int izquierda, int m, int derecha)

{

	int h,i,j,k;
	h = izquierda; // Puntero que recorre el 1º subvector
	i = izquierda; // Puntero que recorre el vector auxiliar
	j = m + 1;	// Puntero que recorre el 2º subvector
	vector_aux[derecha]; // vector auxiliar

	while((h <= m)&& (j <= derecha))
	{
		if(vector[h] <= vector[j])
		{
			vector_aux[i] = vector[h];
			h++;
		}
		else
		{
			vector_aux[i] = vector[j];
			j++;
		}
	
		i++;
	}
	
	contador++;
	
	//Si algún subv termina copiamos el otro subv directamente.
	if(h > m)
	{
		for(k = j; k <= derecha; k++)
		{
			vector_aux[i] = vector[k];
			i++;
		}
	}
	else 
	{
		for(k = h; k <= m; k++)
		{
			vector_aux[i] = vector[k];
			i++;
		}
	}
	
	// Copiamos el vector C en A.
	for(k = izquierda; k <= derecha; k++)
	vector[k] = vector_aux[k];

}


int main()
{

	int num = sizeof(vector) / sizeof(int);
	
	MezclaOrd(0, num - 1);
	
	for(int i=0; i < num; i++)
	cout << vector[i] << " ";
	
	cout << endl;

}
