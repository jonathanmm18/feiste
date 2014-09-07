#include "feistel.h"
template <typename Type>
ostream& operator << (ostream &o,const vector <Type> &v)
{
    for(int i = 0; i < v.size(); i++)
    {
        o << v[i] << endl;

    }

    return o;
}

feistel::feistel(){alfabeto = "abcdefghijklmnopqrstuvwxyz ";}

void feistel::set_alfTam(){alfTam = get_alfabeto().size();}
void feistel::set_mensaje(string msj){ mensaje = msj;}
string feistel::get_alfabeto(){return alfabeto;}
int feistel::get_alfTam(){return alfTam;}
string feistel::get_mensaje(){return mensaje;}

vector <string> feistel::en_bloques(string cadena, int n){
        unsigned int x = 0;
        int a;
        int b = 0;
        int d = n;

        for(; x < cadena.size() ;)
        {
            if(cadena.size()- x < n ){
            a = cadena.size()- x;
            x += a;
            }
            else{
            x += n;
            }
            bloques.push_back(cadena.substr(b,d));
            b = x;
        }
        int modCadenaSize =  mod((int)cadena.size(),n);
        if(modCadenaSize > 0)
        {
            string last = bloques.back(),cadena(n-modCadenaSize,'k');
            bloques.pop_back();
            last+=cadena;
            bloques.push_back(last);
        }
        
        return bloques;
}

string feistel::sI(string m){
        unsigned int j;
        string mn;
		int alf = unsigned(this->get_alfabeto().size());
        for(unsigned int i = 0; i < m.size(); i++)
        {
            j = this->get_alfabeto().find(m[i]);
            j = mod<int>( ( mod<int>(j,alf)	+  mod<int>(privateKey,alf)), alf  );
            mn +=  this->get_alfabeto()[j];
        }

        return mn;

}
string feistel::sII(string m){
        unsigned int j;
        string mn;
		int alf = unsigned(this->get_alfabeto().size());
        for(unsigned int i = 0; i < m.size(); i++)
        {
            j = this->get_alfabeto().find(m[i]);
            j = mod<int>( ( mod<int>(j,alf)	-  mod<int>(privateKey,alf)), alf  );
            mn +=  this->get_alfabeto()[j];
        }

        return mn;

}
string feistel::pI(string m){
        string p;
        for(unsigned int i=0; i < permutacion.size(); i++)
        {
			 p+= m.at(permutacion[i]);
        }
        return p;
}

string feistel::pII(string m){
        string p;
        for(unsigned int i=0; i < permutacionI.size(); i++)
        {
			 p+= m.at(permutacionI[i]);
        }
        return p;
}

void feistel::separar(vector <string> m){
        for(int i = 0; i < m.size(); i++){
            if(i%2==0){
                c1.push_back(m[i]);}
            else {c2.push_back(m[i]);}
        }

    }

vector <string>  feistel::ci_juntar(){
        vector <string> s;
        for(int k = 0; (c1.size()>= k) || (c2.size() >= k); k++){
            if(c2.size() <= k){}else{
                 s.push_back(c2[k]);};
            if(c1.size()<= k){}else{
                 s.push_back(c1[k]);};
        }

        return s;
    }


 vector <string> feistel::cI_funcion(vector <string> cI)
 {
	 vector <string> temp;
	 temp = cI;
	 for(int i =0; i < cI.size(); i++)
	 {
			temp[i] = this->sI(cI[i]);
			//cout << this->sI(cI[i]) << endl;
			temp[i] = this->pI(temp[i]);
	 
	 }
	 return temp;

}



 string feistel::cifrado(string men){

        mensaje = Stringen64<string>(men);

		cout << Stringen64<string>(men) << endl;

		int numBloques = mensaje.length()/16;

		bloques = this->en_bloques(mensaje,numBloques);

        this->separar(bloques);
		
		cout << bloques << endl;
		
		permutacion = cadPermutacion<int>(numBloques-1);

		string file("permutacion.feistel");
		guardar<int>(permutacion,file);
		
		//cout << c1 << endl;

		 privateKey = 1;

        //cadPermutacion = perm;


        c1 = this->cI_funcion(c1);
		//cout << c1 << endl;

        c2 = this->cI_funcion(c2);
        bloques = this->ci_juntar();

		//cout << bloques << endl;

        mensaje = vecToString<string>(bloques);

        // ************BORRAR DATOS

        bloques.erase(bloques.begin(),bloques.begin()+bloques.size());
        c1.erase(c1.begin(),c1.begin()+c1.size());
        c2.erase(c2.begin(),c2.begin()+c2.size());


		

       
        return mensaje;
    }

vector <string> feistel::cI_funcion_I(vector <string> cI){
     
	 vector <string> temp;
	 temp = cI;
	 for(int i =0; i < cI.size(); i++)
	 {
			temp[i] = this->sII(cI[i]);
			//cout << "esto es sI_I: " << i << " : " << this->sI(cI[i]) << endl;
			temp[i] = this->pII(temp[i]);	 

	 }
	 return temp;

}

vector <string>  feistel::ci_juntar_I(){
        vector <string> s;
        for(int k = 0; (c1.size()>= k) || (c2.size() >= k); k++){
            if(c1.size() <= k){}else{
                 s.push_back(c2[k]);};
            if(c2.size()<= k){}else{
                 s.push_back(c1[k]);};
        }

        return s;
    }

 vector<int> feistel::PermInversa()
{
	vector<int> temp,temp1 ;
	vector<string> temp2;
	int j=1;

	string file("permutacion.feistel"), DesPerm("despermutacion.feistel");
    temp2 = read<string>(file);
	//cout << temp2 << endl;
	temp = vecStringTovecInt<void>(temp2);

	for(int i = 0; i < temp.size() ; i++)
	{
		temp1.push_back(buscarPosicion<void>(temp, j));
		j++;
	}
	guardar<int>(temp1,DesPerm);
	
	return temp1;
}

string feistel::descifrado(string men){

        string descrifrado;

		mensaje = Stringen64<string>(men);
		//cout << "mensaje: \n" <<men;
		int numBloques = mensaje.length()/16;
		//cout << c1 << endl;

		bloques = this->en_bloques(mensaje,numBloques);


        this->separar(bloques);
       // string perm("3102");


		permutacionI = PermInversa();
		//cout << c1 << endl;

        privateKey = 1;
        //scadPermutacion = perm; 

		c1 = this->cI_funcion_I(c1);
		//cout << "\n c1: \n" << c1 << endl;
      


        c2 = this->cI_funcion_I(c2);


        bloques = this->ci_juntar_I();


        descrifrado = vecToString<string>(bloques);

        // ************BORRAR DATOS

        bloques.erase(bloques.begin(),bloques.begin()+bloques.size());
        c1.erase(c1.begin(),c1.begin()+c1.size());
        c2.erase(c2.begin(),c2.begin()+c2.size());



        return descrifrado;


    }
