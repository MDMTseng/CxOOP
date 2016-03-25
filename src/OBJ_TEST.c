/*
 ============================================================================
 Name        : OBJ_TEST.c
 Author      : MDM
 Version     :
 Copyright   : copy to death
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stddef.h>
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

    printf("CxOOP_INHERIT_DEPTH(PARENT_OBJ):%d\n",CxOOP_INHERIT_DEPTH(PARENT_OBJ));
    printf("CxOOP_INHERIT_DEPTH(CHILD_OBJ):%d\n",CxOOP_INHERIT_DEPTH(CHILD_OBJ));
    printf("CxOOP_INHERIT_DEPTH(DECEN_OBJ):%d\n",CxOOP_INHERIT_DEPTH(DECEN_OBJ));

    char *ss[]={CxOOP_INHERIT_HISTORY_NAME(DECEN_OBJ)};
    int i;
    printf("\n");
    printf("CxOOP_INHERIT_HISTORY_NAME(DECEN_OBJ)\n");
    for(i=0;i<sizeof(ss)/sizeof(ss[0]);i++)
    {
        printf(">>>%s\n",ss[i]);
    }
	printf("\n");


    p.pub=
    c.pub=
    d.pub=100;
    PARENT_OBJ *obj_arr[]={&p,CxOOP_DCAST(PARENT_OBJ,&c) ,DCAST(PARENT_OBJ,&d)};

    for(i=0;i<sizeof(obj_arr)/sizeof(obj_arr[0]);i++)
    {
        printf("GetPublic!!!::%d\n",obj_arr[i]->GetPublic(obj_arr[i]));
    }
	printf("!!!Hello sizeof!!!::%d..%d..%d\n",(int)sizeof(PARENT_OBJ),(int)sizeof(CHILD_OBJ),(int)sizeof(DECEN_OBJ));


	return EXIT_SUCCESS;
}
