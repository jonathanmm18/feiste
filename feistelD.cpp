// feistelD.cpp: define el punto de entrada de la aplicación de consola.
//
#include "stdafx.h"
using namespace std;

template <typename Type>
ostream& operator << (ostream &o,const vector <Type> &v)
{
    for(int i = 0; i < v.size(); i++)
    {
        o << v[i] << endl;

    }

    return o;
}

int _tmain(int argc, _TCHAR* argv[])
{
    string mensaje ="starwarslamisioncontinua@de@la@casaz",cifrado,descrifrado;
    feistel f;


    f.cifrado(mensaje);
	for(int i = 0; i < f.permutacion.size();i++ )cout<< f.permutacion[i] << '\n';


	//cout << f.bloques <<endl;
	cout << f.c1 << endl;
	cout << endl;
	cout << f.c2 << endl;

	for (int j = 0; j < f.c1.size(); j++ )
	{
		string g;
		g = f.sI(f.c1[j]);
		cout << g << endl;
	}

	for (int w = 0; w < f.c1.size(); w++ )
	{
		string g;
		g = f.pI(f.c1[w]);
		cout << g << endl;
	}
    cout << "MENSAJE ORIGINAL: " << mensaje << endl;
	

    cifrado = f.get_mensaje();
    cout << "MENSAJE CIFRADO: " << cifrado << endl;

	//descrifrado = f.descifrado(cifrado);

    //cout << "MENSAJE DESCIFRADO: " << descrifrado << endl;
	return 0;
}

