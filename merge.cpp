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
    
int main ()
{
	srand(time(NULL));
	int n = 10;
	vector <VElement> v_orig; 
	vector <VElement> v_aux;
	int i;

	for (i = 0; i < n; i++)
	{
		v_orig.push_back(1 + rand()%200);
    		cout << v_orig.at(i).get() << " ";
	}

	MezclaOrd (v_orig, v_aux, 0, n-1);
	cout << endl;
	for (i = 0; i < n; i++)
	{
	    	cout << v_orig.at(i).get() << " ";
	}
	cout << endl;

	return 0;
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

	v_aux=v_orig;

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
