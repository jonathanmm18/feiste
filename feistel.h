#ifndef FEISTEL_H
#define FEISTEL_H

#include <string>
#include <vector>
#include <strstream>
#include <iostream>
#include "MisFunciones.h"

class feistel{
private:
    string alfabeto, mensaje, men_cifrado;
    string bloq;
    int alfTam,privateKey;
	

public:
    vector <string> bloques,c1, c2 ;
	vector <int> permutacion;
    feistel();

    string cifrado(string);
    string descifrado(string);
    void set_alfTam();
    void set_mensaje(string);

    string get_alfabeto();
    int get_alfTam();
    string get_mensaje();

    vector <string> en_bloques(string, int);
    vector <string> cI_funcion(vector <string>);
    vector <string> cI_funcion_I(vector <string>);

	vector <int> PermInversa();


    string sI(string);
    string sI_I(string);
    string pI(string);
    void separar(vector <string>);

    vector <string>  ci_juntar();
    vector <string>  ci_juntar_I();



};


#endif // FEISTEL_H

