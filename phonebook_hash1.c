#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_hash1.h"


int hashFunction(char *str)
{
    /*BKDR*/
    int seed = 31;
    int hash = 0;
    while(*str)
        hash = hash * seed + (*str++);

    /*RS*
    	unsigned int b = 378551;
    	unsigned int a = 63689;
    	unsigned int hash = 0;
    	while(*str){
    		hash = hash * a + (*str++);
    		a *= b;
    	}
    */
    /*DJB*
    	unsigned hash = 5381;
    	while(*str)
    		hash += (hash << 5) + (*str++);
    */
    /*SDBM*
    	int hash = 0;
    	while(*str)
    		hash -= (hash << 6) + (hash << 16) + (*str++);
    */
    /*JS*
    	unsigned int hash = 1315423911;
    	while(*str)
    		hash ^= (hash << 5) + (hash >> 2) + (*str++);
    */
    return (hash & (MAX_HASH_TABLE_SIZE-1));
}

entry *findName(char lastName[], entry *pHead)
{
    int hash = hashFunction(lastName);
    pHead  = hashTable[hash];
    while(pHead != NULL) {
        if(strcasecmp(lastName, pHead->lastName) == 0)
            return pHead;
        pHead = pHead->pNext;
    }
    return NULL;
}

entry *append(char lastName[], entry *e)
{
    int hash = hashFunction(lastName);
    entry *newEntry = (entry *)malloc(sizeof(entry));
    strcpy(newEntry->lastName, lastName);
    if(hashTable[hash] != NULL)
        newEntry->pNext = hashTable[hash];
    else
        newEntry->pNext = NULL;
    hashTable[hash] = newEntry;
    return e;
}

