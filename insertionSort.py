array = [5,2,4,6,1,3,7,86,34,23,54,23,54,23];
def insertionSort(array,elementos):
    j = 1;
    while(j<elementos):
        key = array[j];
        i = j - 1;
        while(i>=0 and array[i] >key):
            array[i+1] = array[i]
            i = i - 1;
        array[i+1] = key
        j+=1
    return array; 
import time;
tiempo1 = time.time(); 
print("El arreglo oder nado : %s " % (insertionSort(array,14)));
print ("El tiempo que tomó : %s " % str(time.time() - tiempo1)); 
