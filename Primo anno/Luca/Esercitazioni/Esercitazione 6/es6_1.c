#include <stdio.h>
#include <stdlib.h>

int main (int argc, char * argv[]) {
    
    int N = atoi(argv[1]) ;
    int K = atoi(argv[2]) ;
    FILE * data ;
    char lettera ;
    int numero ;
    float reale ;
    
    if (argc != 3) {
        exit (EXIT_FAILURE) ;
    }
    
    data = fopen("data.txt", "r") ;
    int j = 0 ;
    
    for (int i = 0; i < K; i++) {
        fscanf(data, "%c %d %f\n", &lettera, &numero, &reale) ;
        
        if (N == numero) {
            printf("Lettera: %c\n", lettera) ;
            printf("Numero: %d\n", numero) ;
            printf("Reale: %f\n", reale) ;
            j = 1 ;
        }
    }
    
    if (j == 0) {
        printf("%d non è presente nei dati\n", N) ;
    }

    
    fclose(data) ;
    
    //printf("%d\n", N) ;
    
    exit (EXIT_SUCCESS) ;
}
