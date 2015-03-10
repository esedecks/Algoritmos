#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BILLION     1E9 
void imprimir(int* array,int elementos){
  int j = 0;
  puts("");  
  for (; j<elementos; j++)
    printf(" %d ", *(array+j)); 
  puts(""); 
}
double insertionSort(int* array, int elementos){
  int j,i,key ;
  struct timespec tiempo1,tiempo2; 
  clock_gettime(CLOCK_REALTIME, &tiempo1);
 
  for(j=1; j < elementos; j++){
    key = array[j]; 
    i = j - 1;
    while( i >= 0 && array[i]>key){
      array[i+1] = array[i]; 
      i = i - 1;  
    }
    array[i+1] = key; 
  }/*end for*/
 
 
 
  clock_gettime(CLOCK_REALTIME, &tiempo2);
  double tiempoTotal = (tiempo2.tv_sec + tiempo2.tv_nsec / BILLION) - (tiempo1.tv_sec + tiempo1.tv_nsec / BILLION); 
  return tiempoTotal; 
}
int leerEnteros(int* arreglo){
  FILE* fints = fopen("../enteros.txt","r"); 
  if(!fints){
    fprintf(stderr,"Error no se pudo abrir el archivo"); 
    exit(1); 
  }
  int z = 0 ;
  char buff[8]; 
  while(fgets(buff,sizeof(buff),fints)){
    if(buff[0] == '\n') continue; 
    arreglo[z] = atoi(buff);
    ++z; 
  }
  fclose(fints); 
  return z; 
}
int main(){
  int arreglo[1300];
  int intsRead = leerEnteros(arreglo); 
  printf("Enteros leidos : %d\n",intsRead); 
  imprimir(arreglo,intsRead);
  printf("Tiempo que tardó en ordenar el arreglo: %.21f\n",insertionSort(arreglo,intsRead)); 
  imprimir(arreglo,intsRead); 
}


