
#ifndef CHILD_OBJ_H_
#define CHILD_OBJ_H_

#include "CxOOP.h"
#include "PARENT_OBJ.h"

#define CHILD_OBJ_PUBLIC_MEMBER_\
        int child_ID;

#define CHILD_OBJ_PRIVATE_MEMBER_\

#define CHILD_OBJ_PUBLIC_METHOD_(OBJ,MACRO_X)\

#define CHILD_OBJ_PRIVATE_METHOD_(OBJ,MACRO_X)\

#define CHILD_OBJ_OVERRIDE_METHOD_(OBJ,MACRO_X)\
        MACRO_X(OBJ,int,DoAction, OBJ* a)\

#define CHILD_OBJ_DNA_(X,X0)  \
        (X,X0,CHILD_OBJ)\
        PARENT_OBJ_DNA_(X,X0)

CxOOP_OBJECT_DECLARE(CHILD_OBJ)


#endif
