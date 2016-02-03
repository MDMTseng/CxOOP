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
    d.pub=30;
    PARENT_OBJ *obj_arr[]={&p,&c,&d};



    printf("!!!Hello GetPublic!!!::%d..%d..%d\n",p.GetPublic(&p),c.GetPublic(&c),d.GetPublic(&d));
	printf("!!!Hello sizeof!!!::%d..%d..%d\n",sizeof(PARENT_OBJ),sizeof(CHILD_OBJ),sizeof(DECEN_OBJ)); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
