#include <iostream>
#include <time.h>
#include <vector>

using namespace std;


int menosPasos(vector<int> pasos) {
    int menor = 0;
    for (int i=0; i<pasos.size(); i++) {
        if (pasos[i] < pasos[menor])
        menor = i;
    }
    return menor;
}


bool verify(int *recorrido, int index, vector<int> &pasos) {
    float x = float(rand()%100) / 100.0;

    if (x > 0.8)
        *recorrido += 83;
    else if (x <= 0.8 && x > 0.6)
        *recorrido += 50;
    else if (x <= 0.6 && x > 0.4)
        *recorrido += 30;
    else if (x <= 0.4 && x > 0.2)
        pasos[index] += 2;
    else 
        *recorrido -= 10;

    if (*recorrido >= 300000)
        return true;
    return false;
}


void ganadores(vector<int> llegaron, vector<int> pasos, vector<string> nombres) {
    // obteniendo el primer lugar
    int primero = menosPasos(pasos);
    cout << "Ganador: " << nombres[primero] << ", cantidad de pasos: " << pasos[primero] << " pasos" << endl;
    pasos.erase(pasos.begin()+primero);
    nombres.erase(nombres.begin()+primero);

    // obteniendo el segundo lugar
    int segundo = menosPasos(pasos);
    cout << "2do puesto: " << nombres[segundo] << ", cantidad de pasos: " << pasos[segundo] << " pasos" << endl;    
    pasos.erase(pasos.begin()+segundo);
    nombres.erase(nombres.begin()+segundo);

    // obteniendo el tercer lugar
    int tercero = menosPasos(pasos);
    cout << "3er puesto: " << nombres[tercero] << ", cantidad de pasos: " << pasos[tercero] << " pasos" << endl;
}


 void desplazamiento(vector<int> &recorridos, vector<int> &pasos, vector <int> &llegaron) {
    vector<int> siguen = {0, 1, 2, 3, 4, 5, 6, 7};

    // Lista del orden de llegada. Cuando todos llegan el programa termina
    while(llegaron.size() < 8) { 
        for (auto i = siguen.begin(); i != siguen.end(); i++) {
            pasos[*i]++;
            if (verify(&(recorridos[*i]), *i, pasos)) {
                llegaron.push_back(*i);
                siguen.erase(i);
                i--;
            }
        }
    }
}


int main(){
    srand(time(NULL));
    // 8 autos, 8 carriles de 300K(300 000m), gana el que llegue a 300km en la menor cantidad de pasos.
    vector<string> nombres = {"RayoMcQueen", "Mate", "Francesco", "Strip Weathers", "Chick Hicks", "Jackson Storm", "Guido"};
    vector<int> recorridos(8, 0);
    vector<int> pasos(8, 0);
    vector<int> llegaron;
    
    // main loop
    desplazamiento(recorridos, pasos, llegaron);

    // final de la carrera
    ganadores(llegaron, pasos, nombres);
    return 0;
}
