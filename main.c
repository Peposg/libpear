#include "libpear.h"
#include <stdio.h>

int main(){
    // create table
    pear_t* pt = pt_new();
    printf("Table created. Size: %d, Count: %d\n", pt->size, pt->count);

    // insert
    insert_p(pt, "name", "alice");
    insert_p(pt, "age", "25");
    insert_p(pt, "city", "london");
    printf("Inserted 3 items. Count: %d\n", pt->count);

    // search existing
    printf("Search 'name': %s\n", search_p(pt, "name"));
    printf("Search 'age': %s\n", search_p(pt, "age"));
    printf("Search 'city': %s\n", search_p(pt, "city"));

    // search non existing
    printf("About to search country\n");
    char* r = search_p(pt, "country");
    printf("Search done\n");
    if(r != NULL){
        printf("Search 'country': %s\n", r);
    } else {
        printf("Search 'country': not found\n");
    }

    // delete
    delete_p(pt, "age");
    printf("Deleted 'age'. Count: %d\n", pt->count);

    // search deleted
    char* d = search_p(pt, "age");
    printf("Search 'age' after delete: %s\n", d ? d : "not found");

    // resize
    printf("\n--- Resize Test ---\n");
    printf("Before resize. Size: %d, Count: %d\n", pt->size, pt->count);
    pt_resize(pt, 100);
    printf("After resize. Size: %d, Count: %d\n", pt->size, pt->count);
    // check items still exist after resize
    printf("Search 'name' after resize: %s\n", search_p(pt, "name") ? search_p(pt, "name") : "not found");
    printf("Search 'city' after resize: %s\n", search_p(pt, "city") ? search_p(pt, "city") : "not found");

    // delete table
    pt_delete(pt);
    printf("Table deleted.\n");

    return 0;
}