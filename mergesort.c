#include<stdio.h>
#include<math.h>



void printArray(int array[], int i, int f){
  int c ; 
  for(c=i; c<=f; c++)
    printf("%d |",array[c]);
  puts(""); 
}
void merge(int array[],int p, int q, int r){
   
  int n1 = q-p+1; 
  int n2 = r-q; 
  int k = p; 
  int i = 0; 
  int j = 0; 
  int lowHalf[n1], highHalf[n2]; 
  

  for(; i<n1;k++,i++)
    lowHalf[i] = array[k];
   

  for(;j<n2; j++,k++)
    highHalf[j] = array[k]; 
  
  i = j = 0; 
  k = p; 
  while(i<n1 && j< n2){
    if(lowHalf[i]< highHalf[j] ){
      array[k] = lowHalf[i]; 
      i++; 
    }else {
      array[k] = highHalf[j]; 
      j++; 
    }
    k++; 
  }
  while(i<n1){
    array[k] = lowHalf[i]; 
    i++; 
    k++; 
  }
  while(j<n2){
    array[k] = highHalf[j]; 
    j++; 
    k++; 
  }
}
void mergeSort(int array[],int p, int r){
  if(p>=r)
    return ; 
  int q = floor((p+r)/2);
  mergeSort(array,p,q);  
  mergeSort(array,q+1,r); 
  merge(array,p,q,r); 
}


int main(){
  int array[] = {12,-9,3,7,14,0,6,2,10,5};
  
  int size = (sizeof(array)/sizeof(array[0])); 
  printArray(array,0,size-1);
  mergeSort(array,0,size-1); 
  printArray(array,0,size-1);
}
