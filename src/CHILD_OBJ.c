
#include "PARENT_OBJ.h"
#include "CHILD_OBJ.h"


int CONSTRUCTOR_CHILD_OBJ(CHILD_OBJ* obj)
{
    CONSTRUCTOR_PARENT_OBJ(obj);
    OBJECT_INIT_METHOD(CHILD_OBJ,obj);

    __OMNI__CHILD_OBJ *oobj=obj;
    //oobj->priv=999;


    printf("c===oobj->GetPublic>>%p\n",oobj->GetPublic);
    printf("====CHILD_OBJ_GetPublic>>%p\n",CHILD_OBJ_GetPublic);
    printf("===oobj->SUPER_GetPublic>>%p\n",oobj->SUPER_GetPublic);
    printf("%s>>>%d\n================\n",__func__,CONSTRUCTOR_CHILD_OBJ);

}

int DESTRUCTOR_CHILD_OBJ(CHILD_OBJ* obj)
{
    __OMNI__CHILD_OBJ *oobj=obj;
}



int CHILD_OBJ_GetPublic( CHILD_OBJ* obj)
{
    __OMNI__CHILD_OBJ *oobj=obj;

    int ret=oobj->SUPER_GetPublic(oobj)*2;
    printf("%s\n",__func__);
    return ret;
}

