
#include "DECEN_OBJ.h"
#include <stdio.h>

CxOOP_INHERIT_IMPLEMENT(DECEN_OBJ,CHILD_OBJ)
int CONSTRUCTOR_DECEN_OBJ(DECEN_OBJ* obj)
{
    CONSTRUCTOR_CHILD_OBJ((void*)obj);
    CxOOP_INIT_METHOD(DECEN_OBJ,obj);


    __OMNI__DECEN_OBJ *oobj=(void*)obj;

    printf("d===oobj->GetPublic>>%p\n",(void*)oobj->GetPublic);
    printf("====CHILD_OBJ_GetPublic>>%p\n",DECEN_OBJ_GetPublic);
    printf("===oobj->SUPER_GetPublic>>%p\n",oobj->SUPER_GetPublic);
    printf("%s>>>%p\n================\n",__func__,(void*)CONSTRUCTOR_DECEN_OBJ);

    return 0;
}

int DESTRUCTOR_DECEN_OBJ(DECEN_OBJ* obj)
{
    __OMNI__DECEN_OBJ *oobj=(void*)obj;
    return 0;
}


static int DECEN_OBJ_GetPublic( DECEN_OBJ* obj)
{
    __OMNI__DECEN_OBJ *oobj=(void*)obj;

    int ret=oobj->SUPER_GetPublic((void*)oobj)+20;
    printf("%s\n",__func__);
    return ret;
}
