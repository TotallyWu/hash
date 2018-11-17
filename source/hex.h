#ifndef _HEX_H_
#define _HEX_H_

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 5

typedef struct {
	char * key[MAX] ;
	char * value[MAX] ;
	int len ;
}HASH;

extern int Init(HASH * hash) ;
extern int Insert(HASH * hash , char * strKey , char * strValue) ;
extern int Delstr(HASH * hash , char * strKey) ;
extern void PrintHash(HASH * hash) ;

#endif
