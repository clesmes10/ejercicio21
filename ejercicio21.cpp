#include <iostream>
using namespace std;


void d(double *uv, double xmin, double deltax, int n);
 

void d(double *u, double xmin, double deltax, int n){
  double x;
  int i;
  for(i=0; i<n; ++i){
    x = xmin +i;
      if(x > 0.75 && x <=1.25){
	u[i] = 1.0;
      }else{
	u[i]=0.0;
      }
  }
}

int main(){
  double C = 1.0;
  double T = 0.5;
  double x = 3;
  double deltax = 0.1;
  double deltat = 0.01;
  double *u;
  double *uv;
  double *ui;
  double xmin = 0.0;
  double xmax = 2.0;
  int numerox = (xmax-xmin)/(deltax+1);
  int enet = T/deltat + 1;
  int enex = x/deltax + 1;
  int i;
  int j;
  int equis = 0;
  uv = new double[numerox];
  ui = new double[numerox];
  u = new double[numerox];
  d(uv, xmin, deltax, numerox);
  d(ui, xmin, deltax, numerox);
  for(i=0; i<enet; ++i){
    u[0] = 0;
    u[numerox-1]=0;
    for(i=1; i< numerox-1;++i){
      u[i] = uv[i]-C*deltat*(uv[i+1]-uv[i])/deltax;
      
    }
    for(i=0; i< numerox; ++i){
      uv[i] = u[i];
    }
  }
  for(i=0; i< numerox; ++i){
    equis = i*deltax;
    cout << x << " " << ui[i] << " " << u[i] << endl;
  }
    

  
  return 0;
}
