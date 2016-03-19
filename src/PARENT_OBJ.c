
#include "PARENT_OBJ.h"
#include <stdio.h>

CxOOP_INHERIT_IMPLEMENT(PARENT_OBJ,NULL_OBJ)

int CONSTRUCTOR_PARENT_OBJ(PARENT_OBJ* obj)
{
	CxOOP_INIT_METHOD(PARENT_OBJ,obj);
    __OMNI__PARENT_OBJ *oobj=(void*)obj;

    printf("@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("p===oobj->GetPublic>>%p\n",(void*)oobj->GetPublic);
    printf("====PARENT_OBJ_GetPublic>>%p\n",PARENT_OBJ_GetPublic);
    printf("%s>>>%p\n================\n",__func__,(void*)CONSTRUCTOR_PARENT_OBJ);
    return 0;
}

int DESTRUCTOR_PARENT_OBJ(PARENT_OBJ* obj)
{
    __OMNI__PARENT_OBJ *oobj=(void*)obj;
    return 0;
}




static int PARENT_OBJ_GetPublic( PARENT_OBJ* a)
{
    printf("%s\n",__func__);
    return a->pub;
}

static int PARENT_OBJ_GetPrivate( PARENT_OBJ* a)
{
    __OMNI__PARENT_OBJ *oobj=(void*)a;
    return 0;
}

static int PARENT_OBJ___GetPrivate( PARENT_OBJ* a)
{
    __OMNI__PARENT_OBJ *oobj=(void*)a;
    return 0;
}

