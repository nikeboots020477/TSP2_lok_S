#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <math.h>
using namespace std;



#define INF 9999999999999999

int jjj(string S){
       int i,j, k;  
vector<int> path;
ifstream data(S);
    int N;
    data>>N;
    float** mm = new float *[N]; 
    for (int i=0; i < N; i++)
        mm[i] = new float [2];

    float** gr = new float *[N]; 
    for (int i=0; i < N; i++)
        gr[i] = new float [N];

    for(int i = 0; i<N;i++){
        data>>mm[i][0];
        data>>mm[i][1];
    }
    data.close();

    for(i=0;i<N;i++)
    for(j=i;j<N;j++)
        if(i!=j){
            gr[i][j] = sqrt(( mm[i][0]-mm[j][0])*(mm[i][0]-mm[j][0]) + (mm[i][1]-mm[j][1])*(mm[i][1]-mm[j][1]));
            gr[j][i] = gr[i][j];
        }
        else gr[i][j]=INF;
    
    for(i=0;i<N;i++) path.push_back(i);

    bool flag;
    for(i=0; i<N-2; i++)
        for(j=i+2; j<N; j++){
        bool flag = false;
        double ml = gr[path[i]][path[i+1]] + gr[path[j]] [path[(j+1)%N]];
        double zz = gr[path[i]][path[j]] + gr[path[i+1]] [path[(j+1)%N]];
        if( ml > zz ){
        reverse(path.begin() + i + 1, path.begin() + j + 1);
        flag = true;
        }

        if(flag){
            j = i+2;
        }
    }

    double len = 0;
    for(i=0; i<N; i++)
        len= len+ gr[path[i]][path[(i+1)%N]];

cout<<len;
cout<<endl;

for(i=0;i<N;i++) cout<<path[i]<<"  ";
    
return 0;
 }

 int main (){ int i;
  float hh[72];
    


float m;
jjj("tsp_136_1");


 
 return 0;
 }