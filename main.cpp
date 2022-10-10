#include <iostream>
#include <time.h>
#include <vector>
using namespace std;

bool verify(float *recorrido, int index, vector<int> &pasos){
    float x = float(rand()%10) / 10;

    if (x > 0.8) {
        *recorrido += 83;}
    else if (x <= 0.8 && x > 0.6) {
        *recorrido += 50;}
    else if (x <= 0.6 && x > 0.4) {
        *recorrido += 30;}
    else if (x <= 0.4 && x > 0.2) {
        pasos[index] += 2;}
    else {
        *recorrido -= 10;}

    if (*recorrido >= 300000) {
        return true;
    }
    return false;
}


void ganadores(vector<int> llegaron, vector<int> pasos) {
    string nombres[8] = {"Toreto", "RayoMc", "Mate", "GhostRider", "BatMovil", "MysteryMachine", "CJsBike", "LaChama"};
    for (int i=0; i<8; i++) {
        cout << "Llego en " << i << " puesto: " << nombres[llegaron[i]] << endl;
    }
}


 void desplazamiento(vector<float> &recorridos, vector<int> &pasos){
    // variables
    vector<int> llegaron;    
    vector<int> siguen = {0, 1, 2, 3, 4, 5, 6, 7};

    // Lista del orden de llegada. Cuando todos llegan el programa termina
    while(llegaron.size() < 8) { 
        for (const int &i : siguen) {
            if (verify(&recorridos[i], i, pasos)) {
                siguen.erase(siguen.begin()+i);
                llegaron.push_back(i);
            }
            pasos[i]++;
        }
    }
    // Fin
    ganadores(llegaron, pasos);
}


int main(){
    srand(time(NULL));
    // 8 autos, 8 carriles de 300K(300 000m), gana el que llegue a 300km en la menor cantidad de pasos.
    vector<float> recorridos = {0,0,0,0,0,0,0,0};
    vector<int> pasos = {0,0,0,0,0,0,0,0};

    // main loop
    desplazamiento(recorridos, pasos);

    return 0;
}
