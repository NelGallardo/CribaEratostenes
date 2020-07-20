#include <stdio.h>
#include <stdlib.h>

int* Eratostenes(int *);
void MostrarVector(int *, int);

int main(){
    int *c,n;
    printf("\n\t%cHasta que n%cmero quieres saber los primos?",168,163);
    printf("\n\t--> ");
        scanf("%d",&n);
    n=abs(n);
    c=Eratostenes(&n);
    printf("\n\tEstos son los primos hasta el %d",n);
    MostrarVector(c,n);
    printf("\n\t");
    system("pause");
    return 0;
}

int* Eratostenes(int *n){
    int *c;
        c=(int*)malloc((*n)*sizeof(int));
    int i,j,k;
    // Rellena todas las posiciones con numeros naturales.
    for(i=0;i<*n;i++){
        c[i]=i+1;
    }
    // Elimina los múltiplos de un número i
    i=0;
    while(i<(*n)){
        if(c[i]!=1){
           j=i+1;
            while(j<(*n)){
                if(c[j]%c[i]==0){
                    for(k=j;k<(*n);k++){
                        c[k]=c[k+1];
                    }
                    *n=*n-1;
                }
                else{
                    j++;
                }
            }
        }
        else{
            for(k=i;k<(*n);k++){
                c[k]=c[k+1];
            }
            *n=*n-1;
        }
        i++;
    }
    return c;
}

void MostrarVector(int *v, int n){
    int i;
    for(i=0;i<n;i++){
        if(i%10==0){
            printf("\n\t");
        }
        printf("%d ",v[i]);
    }
}
