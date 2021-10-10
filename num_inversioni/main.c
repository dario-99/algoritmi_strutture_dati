#include <stdio.h>
#include <stdlib.h>
void print_vect(int* v, int n){
    for(int i =0; i<n; i++){
        printf("v[%d] = %d\n", i, v[i]);
    }
}
int merge(int *a, int p, int q, int r){   
    int n1 = q-p+1;
    int n2 = r-q;
    int* left = malloc(n1*sizeof(int));
    int* right = malloc(n2*sizeof(int));
    for(int i =0; i<n1; i++){
        left[i] = a[i+p];
    }
    for(int j=0; j<n2;j++){
        right[j] = a[j+q+1];
    }
    //ho caricato i due vettori
    int i=0;
    int j=0;
    int count = 0;
    int ris = 0;
    for(int k = p; k<r+1; k++){
        if (i < n1 && (j >= n2 || (left[i] <= right[j]))){
            a[k] = left[i];
            i++;
            ris += count;
        }
        else{
            a[k]=right[j];
            j++;
            count++;
        }
    }
    return ris;
}
int count_inversion(int *a, int p, int r){
    int count = 0;
    if(p<r){
        int q = (int)((p+r)/2);
        //printf("q = %d\n",q);
        count += count_inversion(a, p, q);
        count += count_inversion(a,q+1,r);
        count += merge(a,p,q,r);
        //printf("temp count = %d, al q=%d\n",count, q);
    }
    return count;
}
int main(){
    int a[] = {8,4,6,5,4};
    int r = 5-1;

    int ris = count_inversion(a,0,r);
    printf("il numero di inversioni e': %d\n", ris);
    print_vect(a, r+1);
}
