
#ifndef DECEN_OBJ_H_
#define DECEN_OBJ_H_

#include "CxOOP.h"
#include "CHILD_OBJ.h"

#define DECEN_OBJ_PUBLIC_MEMBER_\
        int decendent_data;

#define DECEN_OBJ_PRIVATE_MEMBER_\

#define DECEN_OBJ_PUBLIC_METHOD_(OBJ,MACRO_X)\

#define DECEN_OBJ_PRIVATE_METHOD_(OBJ,MACRO_X)\

#define DECEN_OBJ_OVERRIDE_METHOD_(OBJ,MACRO_X)\
        MACRO_X(OBJ,int,DoAction, OBJ* a)\

#define DECEN_OBJ_DNA_(X,X0) \
        (X,X0,DECEN_OBJ)\
        CHILD_OBJ_DNA_(X,X0)


CxOOP_OBJECT_DECLARE(DECEN_OBJ)

#endif

