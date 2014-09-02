#ifndef MISFUNCIONES_H
#define MISFUNCIONES_H
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <strstream>
#include <iostream>
#include <stdlib.h>
#include <time.h> 

#include "MisFunciones.h"



using namespace std;

template <typename Type>
ostream& operator << (ostream &o,const vector <string> &v)
{
    for(int i = 0; i < v.size(); i++)
    {
        o << v[i] << ' ';

    }

    return o;
}


template <typename Type>
Type mod(Type a, Type b)
{
      Type r, q;
      q = a/b;
     // if(a == 0)return b;
      if (a < 0)
      {  
		  if((a*-1) < b )
		  {
           	return r = (b) + a;
          }
          else{
          q--;
		  }
	  }
     
      return  r = a - (q*b);
};

template < typename Type>
vector<int> vecStringTovecInt(vector<string> lista)
{
	vector<int> num;

    int num1;
	for(unsigned int i=0; i < lista.size(); i++)
    {
        num1 = atoi(lista[i].c_str());
		//cout << num1 <<endl;
        num.push_back(num1);
    }
    return num;
};
template <typename Type>
Type vecToString(vector<string> a)
{
	Type cadena;
	for(unsigned int i=0; i < a.size(); i++){
			cadena += a[i];
	}
	return cadena;
}

template <typename Type>
vector <int> stringVecInt(string cad)
{
    vector<int> num;

    int num1;
    for(unsigned int i=0; i < cad.length(); i++)
    {
        num1 = cad[i] - '0';
        num.push_back(num1);
    }
    return num;

}

template <typename Type>
string Stringen64(string mensaje)
{
    int cad = mensaje.size(),j,k;
    cad *= 8;
    k = 64;
    j = 1;



    for(; k < cad ; )
    {
        k = 64;
        j++;
        k*=j;

    }
  
	if(k != cad){
        int tamanoReal = k - mensaje.size();
        string cad1(tamanoReal, 'k');

        mensaje += cad1;
    }
    return mensaje;
}
template <typename Type>
int buscarVec(vector<int> lista, int valor) 
{
	for(int i = 0; i < lista.size(); i++)
	{
		if(valor == lista[i]) return 1;
	}
	return 0;
}

template <typename Type>
vector <int> cadPermutacion(int tam)
{
  int P1,  j = 0, num;
 
  vector<int> cad;
  srand (time(NULL));

  while(cad.size() < tam)
  {
	  P1 = rand() % tam + 1;
	 
	  while(buscarVec<bool>(cad,P1) == 1)
	  {
		    P1 = rand() % tam + 1;
	  }
	  cad.push_back(P1);

  }
    
  return cad;

}

template <typename Type>
void guardar(vector<Type> fuente, string fileName)
{
	 ofstream myfile;
    //myfile.open ("/home/harry/build-filesC-Desktop-Debug");
    myfile.open (fileName);

    for(unsigned int i = 0; i < fuente.size() ; i++)
    {
        myfile << fuente[i] << '\n';

    }
        myfile.close();
}

template <typename Type>
vector<Type> read(string fileName )
{
	ifstream readfile(fileName);
    vector <Type> lineas;
    string d;
    if (readfile.is_open())
     {
       while ( getline (readfile,d) )
       {
         lineas.push_back(d);
         //cout << d << endl;
       }
       readfile.close();
   }
    return lineas;
}

template <typename Type>
int buscarPosicion(vector<int> lista, int num)
{
	int i,j;
	j = 1;
	for(i = 0;i < lista.size(); i++ ) 
	{ 
		//cout << num << " --> " << lista[i] << "  = " << i << endl;
		if(lista[i] == num)return i;
	}

	
}


#endif // MISFUNCIONES_H
