#include "libpear.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define SIZE 53
#define PRIME 151
#define PRIME1 163

//function: creation of new hash table which take array of pair pointers
pear_t* pt_new(){
    pear_t* pt = (pear_t*)malloc(sizeof(pear_t));
    pt->size = SIZE;
    pt->count = 0;
    pt->pears = (pear**)calloc(pt->size, sizeof(pear*));
    return pt;
}

//function: deletion of given hash table
void pt_delete(pear_t* pt){
    for(int i = 0; i < pt->size; i++){
        if(pt->pears[i] != NULL){
        free(pt->pears[i]->key);
        free(pt->pears[i]->value);
        free(pt->pears[i]);
        pt->pears[i] = NULL;
        }
    }
    free(pt->pears);
    free(pt);
}

//function: generation of hash code for each char
int pt_hash(char* k, int prime, int size){
    int i = 0, h = 0;
    while(k[i] != '\0'){
        h = (h * prime + (long)k[i]) % size;
        i++;
    }
    return (int)h; 
}

//function: double hashing function
int pt_get_hash(char* k, int apt, int size){
    int h1 = pt_hash(k, PRIME, size);
    int h2 = pt_hash(k, PRIME1, size);
    return (h1 + apt * h2)%size;
}

//function: insertion of a pair
void insert_p(pear_t* pt, char* k, char* v){

    pear* p = (pear*)malloc(sizeof(pear));
    p->key = strdup(k);
    p->value = strdup(v);
    
    for(int apt = 0; apt < pt->size; apt++){
        int r = pt_get_hash(k,apt,pt->size);
        if(pt->pears[r] == NULL) {pt->pears[r] = p; break;}
    }
    
    pt->count++;
}

//function: searching of a pair using key
char* search_p(pear_t* pt, char* k){
    int r;

    for(int apt = 0; apt < pt->size; apt++){
        r = pt_get_hash(k,apt,pt->size);
        if(pt->pears[r] != NULL && 0 == strcmp(pt->pears[r]->key,k))return pt->pears[r]->value;
        else continue;
    }

    return NULL;
}

//function: deletion of a pair using key
int delete_p(pear_t* pt, char* k){

    for(int apt = 0; apt < pt->size; apt++){
        int r = pt_get_hash(k,apt,pt->size);
        if(pt->pears[r] != NULL && 0 == strcmp(pt->pears[r]->key,k)){
            free(pt->pears[r]->value);
            free(pt->pears[r]->key);
            free(pt->pears[r]);
            pt->pears[r]=NULL;
            pt->count--;
            return 0;
        }
    }

    return 1;

}

//function: allows you to resize the hash table
pear_t* pt_resize(pear_t* pt, int n_size){
    
    pear_t* n_pt = (pear_t*)malloc(sizeof(pear_t));
    n_pt->size = n_size;
    n_pt->count = 0;
    n_pt->pears = (pear**)calloc(n_size, sizeof(pear*));
            
    for(int i = 0; i < pt->size; i++){
        if(pt->pears[i] != NULL){
            insert_p(n_pt, pt->pears[i]->key, pt->pears[i]->value);
        }
    }
    
    pt->pears = n_pt->pears;
    pt->size = n_pt->size;
    pt->count = n_pt->count;
    n_pt->pears = NULL;
    n_pt->size = 0;
    
    pt_delete(n_pt);
    
    return pt;
}