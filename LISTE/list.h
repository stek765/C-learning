#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct linked_list{
	//quello che vuoi
	int dato;
	// - - -
	struct linked_list *next;
};

typedef struct linked_list ELEMENT;
typedef ELEMENT *LINK;

