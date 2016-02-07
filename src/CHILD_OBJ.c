
#include "PARENT_OBJ.h"
#include "CHILD_OBJ.h"
#include <stdio.h>

OBJECT_INHERIT_IMPLEMENT(CHILD_OBJ,PARENT_OBJ)

int CONSTRUCTOR_CHILD_OBJ(CHILD_OBJ* obj)
{
    CONSTRUCTOR_PARENT_OBJ((void*)obj);
    OBJECT_INIT_METHOD(CHILD_OBJ,obj);

    __OMNI__CHILD_OBJ *oobj=(void*)obj;

    obj->child_ID=5;
    printf("c===oobj->GetPublic>>%p\n",(void*)oobj->GetPublic);
    printf("====CHILD_OBJ_GetPublic>>%p\n",CHILD_OBJ_GetPublic);
    printf("===oobj->SUPER_GetPublic>>%p\n",oobj->SUPER_GetPublic);
    printf("%s>>>%p\n================\n",__func__,(void*)CONSTRUCTOR_CHILD_OBJ);
    return 0;
}

int DESTRUCTOR_CHILD_OBJ(CHILD_OBJ* obj)
{
    __OMNI__CHILD_OBJ *oobj=(void*)obj;
    return 0;
}



static int CHILD_OBJ_GetPublic( CHILD_OBJ* obj)
{
    __OMNI__CHILD_OBJ *oobj=(void*)obj;

    int ret=oobj->SUPER_GetPublic((void*)oobj)*2;
    printf("%s\n",__func__);
    return ret;
}

