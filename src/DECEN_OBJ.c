
#include "DECEN_OBJ.h"


int CONSTRUCTOR_DECEN_OBJ(DECEN_OBJ* obj)
{
    CONSTRUCTOR_CHILD_OBJ(obj);
    OBJECT_INIT_METHOD(DECEN_OBJ,obj);


    __OMNI__DECEN_OBJ *oobj=obj;

    printf("d===oobj->GetPublic>>%p\n",oobj->GetPublic);
    printf("====CHILD_OBJ_GetPublic>>%p\n",DECEN_OBJ_GetPublic);
    printf("===oobj->SUPER_GetPublic>>%p\n",oobj->SUPER_GetPublic);
    printf("%s>>>%d\n================\n",__func__,CONSTRUCTOR_DECEN_OBJ);


}

int DESTRUCTOR_DECEN_OBJ(DECEN_OBJ* obj)
{
    __OMNI__DECEN_OBJ *oobj=obj;
}


int DECEN_OBJ_GetPublic( DECEN_OBJ* obj)
{
    __OMNI__DECEN_OBJ *oobj=obj;

    int ret=oobj->SUPER_GetPublic(oobj)+20;
    printf("%s\n",__func__);
    return ret;
}
