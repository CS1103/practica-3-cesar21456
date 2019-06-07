#include <iostream>
#include <deque>

using namespace std;
void funcion(deque<int> c,int n){
    deque<int> deque_de_retorno;
    for (int i=0;i<=c.size()-n;i++){
        auto it = c.begin();

        for (int j=0;j<i;j++){
            it++;
        }

        int min=100;
        for (int k=0;k<n;k++){

            if (*it<min){

                min=*it;

            }
            it++;
        }
        cout<<endl;
        deque_de_retorno.push_back(min);
    }

    for (auto it = deque_de_retorno.begin(); it != deque_de_retorno.end(); it++)
        cout << '\t' << *it;
    cout << '\n';
}

int main() {
    deque<int> a={5,1,4,8,2,4};
    funcion(a,3);
}