#include <iostream>
#include <time.h>
#include <vector>
using namespace std;

void verify(float *carro, float x, vector<double> *llegaron){
    if (*carro >= 300000){
        *llegaron.push_back(*carro);}
    else if(x > 0.8){
        *carro += 830000;}
    else if(x < 0.8 && x > 0.6){
        *carro += 500000;}
    else if(x < 0.6 && x > 0.4){
        *carro += 300000;}
    else if(x < 0.4 && x > 0.2){
        *carro += 100000;}
    else{
        *carro += 200000;}
}
void desplazamiento(float *C1, float *C2, float *C3, float *C4, float *C5, float *C6, float *C7, float *C8){
    // variables
    float x; vector<double> llegaron;
    // Creo una lista, si esta llena, entonces el programa termina.
    while(llegaron.size() < 8){ 
        //C1
        x = rand()%10; x = x/10;
        verify(&*C1, x, &llegaron);
        //C2
        x = rand()%10; x = x/10;
        verify(&*C2, x, &llegaron);
        //C3
        x = rand()%10; x = x/10;
        verify(&*C3, x, &llegaron);
        //C4
        x = rand()%10; x = x/10;
        verify(&*C4, x, &llegaron);
        //C5
        x = rand()%10; x = x/10;
        verify(&*C5, x, &llegaron);
        //C6
        x = rand()%10; x = x/10;
        verify(&*C6, x, &llegaron);
        //C7
        x = rand()%10; x = x/10;
        verify(&*C7, x, &llegaron);
        //C8
        x = rand()%10; x = x/10;
        verify(&*C8, x, &llegaron);
    }
    //----------------------------------
}
int main(){
    // 8 autos, 8 carriles de 300K(300 000m), gana el que llegue a 300km en la menor cantidad de pasos.   
    float Toreto, RayoMc, Mate, GosthRider, BatMovil, BanMystery, CJsBike, LaChama;
    // modulo de random-----------------
    srand(time(NULL));
    desplazamiento(&Toreto, &RayoMc, &Mate, &GosthRider, &BatMovil, &BanMystery , &CJsBike, &LaChama);
}
