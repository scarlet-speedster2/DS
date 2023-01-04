#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"avl.h"
#include"io.h"


char* getName(avl t){

	switch(t->m){
		
		case 1:
			return "January";
			break;
			
		case 2:
			return "February";
			break;
		case 3:
			return "March";
			break;
		case 4:
			return "April";
			break;
		case 5:
			return "May";
			break;
		case 6:
			return "June";
			break;
		case 7:
			return "July";
			break;
		case 8:
			return "Augest";
			break;
		case 9:
			return "September";
			break;
		case 10:
			return "Ocotober";
			break;
		case 11:
			return "November";
			break;
		case 12:
			return "December";
			break;
	}
}
char* getParent(avl t){

	if(t -> parent != NULL){
	switch(t->parent->m){

		
		case 1:
			return "January";
			break;
			
		case 2:
			return "February";
			break;
		case 3:
			return "March";
			break;
		case 4:
			return "April";
			break;
		case 5:
			return "May";
			break;
		case 6:
			return "June";
			break;
		case 7:
			return "July";
			break;
		case 8:
			return "Augest";
			break;
		case 9:
			return "September";
			break;
		case 10:
			return "Ocotober";
			break;
		case 11:
			return "November";
			break;
		case 12:
			return "December";
			break;
	}
}
return "Null";
}

int getMonth(){
	
	char* month;
	printf("\nEnter the month");
	scanf("%ms",&month);

	if(0 == strcmp("jan",month)){
		return 1;
	}
	else if(0 == strcmp("feb",month)){
		return 2;
	}
	else if(0 == strcmp("mar",month))
		return 3;
	else if(0 == strcmp("apr",month))
		return 4;
	else if(0 == strcmp("may",month))
		return 5;
	else if(0 == strcmp("jun",month))
		return 6;
	else if(0 == strcmp("jul",month))
		return 7;
	else if(0 == strcmp("agu",month))
		return 8;
	else if(0 == strcmp("sep",month))
		return 9;
	else if(0 == strcmp("oct",month))
		return 10;
	else if(0 == strcmp("nov",month))
		return 11;
	else 
		return 12;
}	

