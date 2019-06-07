#include <iostream>
#include <vector>
#include<stdlib.h>
#include<time.h>

using namespace std;
template <typename A>
class matriz{
    A **matrizz;
    int filas;
    int columnas;
public:
    A** get_matriz()const {
        return matrizz;
    }
    int get_filas() const {
        return filas;
    }
    int get_columnas()const {
        return columnas;
    }
    void imprimir_matriz(){
        for (int i=0;i<filas;i++){
            for (int j=0;j<columnas;j++){
                cout<<matrizz[i][j]<<" ";
            }
            cout<<endl;
        }



    }
    matriz(A a, A b):columnas(b),filas(a){
        matrizz=new A*[filas];
        for (int i=0;i<filas;i++){
            matrizz[i]=new A[columnas];
        }
        for(int i=0;i<filas;i++){
            for (int j=0;j<columnas;j++){
                matrizz[i][j]=0;
            }
        }

    }

    void set_valores_random(){
        for(int i=0;i<filas;i++){
            for (int j=0;j<columnas;j++){
                matrizz[i][j]=rand()%10;
            }
        }
    }


    ~matriz(){
        for (int i=0;i<filas;i++){
            delete matrizz[i];
        }
        delete matrizz;
    }

    matriz<A> operator+( const matriz<A>& matriz2){
        matriz <A>Z(filas,columnas);
        if (this->columnas==matriz2.get_columnas() and this->filas==matriz2.get_filas() ){

            for (int i=0;i<this->filas;i++){
                for (int j=0;j<this->columnas;j++){

                    Z.matrizz[i][j]=this->matrizz[i][j]+matriz2.matrizz[i][j];
                }
            }
            Z.imprimir_matriz();
            return Z;
        }
        else{
            cout<<"las filas y columnas que se ingresaron fueron diferentes"<<endl;
            return Z;
        }

    }
    };









int main() {
    srand(time(NULL));

    matriz<int> a(3,4);
    matriz<int> b(3,4);
    //matriz<int> c(3,4);
    a.set_valores_random();
    b.set_valores_random();


    a.imprimir_matriz();
    cout<<endl;
    b.imprimir_matriz();
    cout<<endl;

    auto c=a+b;
    c.imprimir_matriz();
}