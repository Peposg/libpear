#ifndef LIBPEAR_H
#define LIBPEAR_H

//define: pairs, key and value 
typedef struct{
    char* key;
    char* value;
}pear;

//define: table which stores pairs
typedef struct{
    int size;
    int count;
    pear** pears;
}pear_t;

//define: creation of new table
pear_t* pt_new();

//define: deletion of "pt" table
void pt_delete(pear_t* pt);

//define: generation of hash
int pt_hash(char* k, int prime, int size);

//define: double hashing 
int pt_get_hash(char* k, int apt, int size);

//define: insertion of pair
void insert_p(pear_t* pt, char* k, char* v);

//define: search of key in hash table
char* search_p(pear_t* pt, char* k);

//define: deletion of pair using key
int delete_p(pear_t* pt, char* k);

//define: resize of hash table
pear_t* pt_resize(pear_t* pt, int n_size);

 #endif