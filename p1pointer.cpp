#include <iostream>
using namespace std;

void ganti(int *p){
    *p=50;
}

int main(){
    int *p, *q, *r;
    int n = 10;
    p = &n; //kalo pake & itu ngakses ke alamatnya n
    *p = 5;
    //cout << *p << endl; // nilai p
    //cout << n << endl; // nilai n
    //cout << p << endl; //alamat p
    //cout << &n << endl; // alamat n

    //int array [3] = {10, 20, 30};
    //int i;
    //int *k;

    //k = array;
    //for (i=0; i<3 ; i++) {
   //     cout << *(k+i) << " ";
    //}
   // cout << *array; //ngarahin ke nilai pertama yg disimpen sama array (10)
    //cout << *(array+1); //nilai kedua (20)


    //char kota[]= "Yogyakarta";
    //cout << kota << endl;
    //char *j = kota;
    //cout << *j;
    //int i;
    //for (i=0; i<10; i++){
    //    cout << *(j+i) << " ";
    //}

    //int x = 10;
    //cout << x << endl;
    //ganti (&x);
    //cout << x << endl;
    //cout << &x << endl;


   // int x = 20;
    //int *i = &x;
    //int **ii = &i;
    //cout << **ii << endl;

    int i;
    int array[5] = {5, 10 , 15, 20, 25};
    int *k;
    k = array; 
    for (i=0; i<5; i++){
        cout << *(k+i) << " ";
    }

    int max = *k;
    int min = *k;
    for (int i=0; i<5; i++){
        if (*(k+i)>max){
            max = *(k+i);
        }
        if (*(k+i)<min){
            min = *(k+i);
        }
    }
    cout << "Nilai Max: " << max << endl;
    cout << "Nilai Min: " << min << endl;

    int jumlah = 0
    for (i=0; i<5; i++){
        jumlah = 
    }
    return 0;
}