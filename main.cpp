/*
  Angel Odiel Treviño Villanueva
  A01336559
  Tarea: Tar08-Audiophobia Fecha: 25/feb  Materia: Diseño de Algoritmos
*/

#include <iostream>
#include <climits>
#include <vector>

using namespace std;

void AlgoritmoFloyd(int D[100][100], int C){
  for(int k = 0; k < C; k++){
    for(int i = 0; i < C; i++){
      for(int j = 0; j < C; j++){
        if(D[i][k] > D[k][j] && D[i][k] <= D[i][j]){
          D[i][j] = D[i][k];
        }else if(D[k][j] > D[i][k] && D[k][j] <= D[i][j]){
          D[i][j] = D[k][j];
        }else{
          D[i][j] = D[i][k] = D[k][j];
        }
      }
    }
  }
}


int main(){

  int cases; //number of cases
  vector<int> Respuestas;
  bool range = true;
  cin >> cases;
  for(int z = 0; z < cases; z++){
    int C; //cantidad de crossings o nodos
    int S; //cantidad de streets o caminos
    int Q; // cantidad de Queries
    cin >> C >> S >> Q;

    //llenar la matriz de adyacentes con maximos y la diagonal mayor con 0
    int D[100][100];
    for(int i = 0; i < C; i++){
      D[i][i] = 0;
      for(int j = i + 1; j < C; j++){
        D[j][i] = D[i][j] = INT_MAX;
      }
    }

    // lee los arcos donde a y b son los caminos y c el valor del arco
    int a, b, c;
    for(int i = 0; i < S; i++){
      cin >> a >> b >> c;
      D[a-1][b-1] = D[b-1][a-1] = c;
    }

    AlgoritmoFloyd(D, C);
    for(int i = 0; i < Q; i++){
      cin >> a >> b;
      if(a <= 0 || b <= 0 || a > C || b > C){//por si se sale afuera del rango
        range = false;
      }
      //para imprimir respuestas
      if(D[a-1][b-1] != INT_MAX && range){
        Respuestas.push_back(D[a-1][b-1]);
      }else{
        Respuestas.push_back(INT_MAX);
      }
      Respuestas.push_back(0);
    }
  }
  //aqui las imprimo
  int iE = 0;
    for(int i = 0; i < cases; i++){
        cout << "Case " << i+1 << ":"<< endl;
        while(Respuestas[iE] != 0){
            if(Respuestas[iE] != INT_MAX)
                cout << Respuestas[iE] << endl;
            else
                cout << "no path" << endl;
            iE++;
        }
        iE++;
    }
  return 0;
}
