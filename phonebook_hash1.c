#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_hash1.h"


int hashFunction(char *str) //BKDR
{
    int seed = 31;
    int hash = 0;
    while(*str)
        hash = hash * seed + (*str++);
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

