/*
 ============================================================================
 Name        : OBJ_TEST.c
 Author      : MDM
 Version     :
 Copyright   : copy to death
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "PARENT_OBJ.h"
#include "CHILD_OBJ.h"
#include "DECEN_OBJ.h"


int main(void) {

    PARENT_OBJ p={0};
    CONSTRUCTOR_PARENT_OBJ(&p);

    CHILD_OBJ c={0};

    CONSTRUCTOR_CHILD_OBJ(&c);

    DECEN_OBJ d={0};
    CONSTRUCTOR_DECEN_OBJ(&d);

    p.pub=
    c.pub=
    d.pub=100;
    PARENT_OBJ *obj_arr[]={&p,(void*)&c,(void*)&d};

    for(int i=0;i<sizeof(obj_arr)/sizeof(PARENT_OBJ *);i++)
    {
        printf("GetPublic!!!::%d\n",obj_arr[i]->GetPublic(obj_arr[i]));
    }
	printf("!!!Hello sizeof!!!::%d..%d..%d\n",(int)sizeof(PARENT_OBJ),(int)sizeof(CHILD_OBJ),(int)sizeof(DECEN_OBJ)); /* prints !!!Hello World!!! */


	return EXIT_SUCCESS;
}
