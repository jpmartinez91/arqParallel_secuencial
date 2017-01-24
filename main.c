/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: pato
 *
 * Created on 13 de enero de 2017, 11:06
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_LONG 10000

typedef int Matriz[MAX_LONG][MAX_LONG];

/*
 * 
 */
void llenar_matriz();
int esPrimo(int valor);
void buscar_primos_principal(Matriz a);
int factorial(int valor);
void buscar_primos_secundaria(Matriz a);

int main(int argc, char** argv) {    
    time_t time_start;
    time_t time_end;
    Matriz* a;
    a = (Matriz*) malloc(sizeof (Matriz));
    time(&time_start);
    double start = time_start;
    printf("El tiempo de inicio es %.4lf\n", start);
    llenar_matriz(*a);
    buscar_primos_principal(*a);
    buscar_primos_secundaria(*a);
    time(&time_end);
    double end = time_end;
    printf("El tiempo de fin es %.4lf\n", end);
    double time_final;
    time_final = time_end - time_start;
    printf("Tiempo de ejecucion es: %.4lf\n", time_final);
    return (EXIT_SUCCESS);
}

void llenar_matriz(Matriz a) {
    int i,j;
    for (i = 0; i < MAX_LONG; i++) {
        for ( j = 0; j < MAX_LONG; j++) {
            a[i][j] = (int) (rand() % 11);
            //printf("%d \n", a[i][j]);
        }
    }
}

void buscar_primos_principal(Matriz a) {
    int suma = 0, i, j;
    for ( i = 0; i < MAX_LONG; i++) {
        for(j = 0; j < MAX_LONG; j++) {
            if (i == j) {
                if (esPrimo(a[i][j]) == 1) {
                    int fact = factorial(a[i][j]);
                    suma += fact;
                }
            }
        }
    }
    printf("La sunma principal es %d\n", suma);
}

void buscar_primos_secundaria(Matriz a) {
    printf("===================== \n");
    int suma = 0,i;
    for ( i = 0; i < MAX_LONG; i++) {
        if (esPrimo(a[i][MAX_LONG - i - 1]) == 1) {
            int fact = factorial(a[i][MAX_LONG - i - 1]);
            suma += (long long)fact;            
        }
    }
    printf("suma secundaria %d \n", suma);
}

int esPrimo(int valor) {
    int contador = 0, i;
    if (valor > 1) {
        for (i = 1; i <= valor; i++) {
            if (valor % i == 0) {
                contador++;
            }
        }
        if (contador == 2) {
            return 1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}


int factorial(int valor) {
    int fact = 1,i;
    for (i = 1; i <= valor; i++) {
        fact = fact*i;
    }
    return fact;
}

