
#include "PARENT_OBJ.h"


int CONSTRUCTOR_PARENT_OBJ(PARENT_OBJ* obj)
{
    OBJECT_INIT_METHOD(PARENT_OBJ,obj);
    __OMNI__PARENT_OBJ *oobj=obj;

    printf("p===oobj->GetPublic>>%p\n",oobj->GetPublic);
    printf("====PARENT_OBJ_GetPublic>>%p\n",PARENT_OBJ_GetPublic);
    printf("%s>>>%d\n================\n",__func__,CONSTRUCTOR_PARENT_OBJ);

}

int DESTRUCTOR_PARENT_OBJ(PARENT_OBJ* obj)
{
    __OMNI__PARENT_OBJ *oobj=obj;
}




int PARENT_OBJ_GetPublic( PARENT_OBJ* a)
{
    printf("%s\n",__func__);
    return a->pub;
}

int PARENT_OBJ_GetPrivate( PARENT_OBJ* a)
{
    __OMNI__PARENT_OBJ *oobj=a;
}

int PARENT_OBJ___GetPrivate( PARENT_OBJ* a)
{
    __OMNI__PARENT_OBJ *oobj=a;
}

