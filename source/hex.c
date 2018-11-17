#include "hex.h"

int Init(HASH * hash){
	int ret = 1 ;
	
	hash->len = MAX ;
	
	int i ;
	for(i = 0 ; i < hash->len ; i ++){
		hash->key[i] = NULL ;
		hash->value[i] = NULL ;
	}
	for(i = 0 ; i < hash->len ; i ++){
		if((hash->key[i] != '\0' ) || (hash->value[i] != '\0')){	
			ret = 0 ;
		}
	}
	return ret ;
}

int isFull(HASH * hash){
	int ret = 1 ;
	int i ;
	for(i = 0 ; i < hash->len ; i ++){
		if(hash->key[i] == '\0'){
			ret = 0 ;
			goto OUT ;
		}
	}
OUT :	
	return ret ;
}
int isEmpty(HASH * hash){
	int ret = 1 ;
	int i ;
	for(i = 0 ; i < hash->len ; i ++){
		if(hash->key[i] != '\0'){
			ret = 0 ;
			goto OUT ;
		}
	}
OUT :	
	return ret ;
}

int Insert(HASH * hash , char * strKey , char * strValue){
	int ret = 1 ;
	
	if(isFull(hash)){
		ret = -1 ;
		goto OUT ;
	}
	int i ;
	for(i = 0 ; i < hash->len ; i ++){
		if(hash->key[i] == '\0'){
			hash->key[i] = strKey ;
			hash->value[i] = strValue ;
			break ;
		}
	}
	
OUT :	
	return ret ;
}

int Delstr(HASH * hash , char * strKey){
	int ret = 0 ;
	
	if(isEmpty(hash)){
		ret = -1 ;
		goto OUT ;
	}
	
	int i ;
	for(i = 0 ; i < hash->len ; i ++){
		if(hash->key[i] == strKey){
			hash->key[i] = NULL ;
			hash->value[i] = NULL ;
			ret = 1 ;
			goto OUT ;
		}
	}
	ret = -2 ;
	
OUT :
	return ret ;
}

void PrintHash(HASH * hash){
	int i ;
	for(i = 0 ; i < hash->len ; i ++){
		printf("key[%d]: %s ----- value[%d]: %s\n" , i , hash->key[i] , i , hash->value[i] ) ;
	}
}


