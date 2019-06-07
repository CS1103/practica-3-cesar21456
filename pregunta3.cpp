#include <iostream>
#include <map>
#include <string.h>
#include <fstream>

using namespace std;
class  seccion{
    map<string,int> mapa;
public:
    void funcion(ifstream &direccion){
        string primera_cosa;

        while (direccion>>primera_cosa){

            if (primera_cosa=="C"){
                string nombre;
                int puntaje;
                direccion>>nombre;
                direccion>>puntaje;
                mapa[nombre]=puntaje;





            }
            else{
                if (primera_cosa=="L"){
                    string nombre;
                    direccion>>nombre;
                    if (nombre=="All"){
                        for (auto it=mapa.begin(); it!=mapa.end(); ++it)
                            cout << it->first << " => " << it->second << '\n';
                        cout<<"aqui termino la funcion"<<endl;
                    }
                    else{
                        for (auto it=mapa.begin(); it!=mapa.end(); ++it)
                            if (it->first==nombre){
                                cout << it->first << " => " << it->second << '\n';
                                cout<<"aqui termino la funcion"<<endl;
                            }
                    }




                }
                else{
                    if (primera_cosa=="D"){
                        string nombre;
                        direccion>>nombre;
                        mapa.erase(nombre);
                    }
                }
            }
        }
    }


};




int main() {
    ifstream a;
    a.open("texto.txt");
    seccion b;
    b.funcion(a);
}