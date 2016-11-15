#include<vector>
#include<iostream>
#include <fstream>
#include"VElement.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

void MezclaOrd (vector<VElement>& , vector<VElement>&, int , int );
void Mezclar(vector<VElement> &, vector<VElement> &, int , int , int);
void evaluar (unsigned ini, unsigned fin, int inc, int (*t)(unsigned),ostream &file);
int funcionAux (unsigned);
    
int main ()
{
	srand(time(NULL));

	ofstream fichero, merge_r;

	int n = 10;
	int i;

	fichero.open ("ficheros.dat");
	evaluar (50, 500,  50, funcionAux, fichero);
	fichero.close();
	return 0;
}

int funcionAux (unsigned n)
{
	vector <VElement> vec_orig (n); 
	vector <VElement> vec_aux (n);
	int a,c;
	unsigned i;

	for (i = 0; i < n; i++)
	{
		vec_orig.push_back(1 + rand()%200);
		vec_orig[i].initNComparison();
		vec_orig[i].initNAssign();
	}

	MezclaOrd (vec_orig, vec_aux, 0, n-1);

	a = VElement::getNAssign ();
	c = VElement::getNComparison ();

	return (a+c);
}

void MezclaOrd (vector<VElement>& v_orig, vector<VElement>& v_aux, int i, int j)
{
	int m;
	if(i < j)
	{
		m = (i + j) / 2;
		MezclaOrd(v_orig, v_aux, i, m);
		MezclaOrd(v_orig, v_aux, m+1, j);
		Mezclar(v_orig, v_aux, i, m, j);

	}
}

void Mezclar(vector<VElement> &v_orig, vector<VElement> &v_aux, int izquierda, int m, int derecha)
{
	int i;
	int j;
	int k;
	int aux;

	i=izquierda;
	j=m+1;
	k=izquierda;

	while((i <= m) && (j <= derecha))
	{
		if(v_orig.at(i)<=v_orig.at(j))
		{
			v_aux.at(k)=v_orig.at(i);
			i++;
		}
		else
		{
			v_aux.at(k)=v_orig.at(j);
			j++;
		}
		k++;
	}
	if(i > m)
	{       
		while(j <= derecha)
		{
			v_aux.at(k)=v_orig.at(j);
			k++;
			j++;
		}
	}

	else
	{
		while(i <= m)
		{
			v_aux.at(k)=v_orig.at(i);
			i++;
			k++;
		}
	}

	for (aux = izquierda; aux <= derecha; aux++)
	{
		v_orig.at(aux)=v_aux.at(aux);
	}
}

void evaluar (unsigned ini, unsigned fin, int inc, int (*f) (unsigned),ostream &file)
{
	unsigned i;
	for (i = ini;i <= fin; i = i + inc)
	{
		file << i << " " << f(i) << endl;
	} 
}
