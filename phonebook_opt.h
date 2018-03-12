#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16
#define MAX_HASH_TABLE_SIZE (1 << 15)

/* small struct and hash function*/
#define HASH1 1
typedef struct __PHONE_BOOK_ENTRY {
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
} fatEntry;

typedef struct __PHONE_BOOK_LASTNAME_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    fatEntry *data;
    struct __PHONE_BOOK_LASTNAME_ENTRY *pNext;
} entry;

entry *hashTable[MAX_HASH_TABLE_SIZE];

entry *findName(char lastName[], entry *pHead);
entry *append(char lastName[], entry *e);
int hashFuction(char *str);

#endif
