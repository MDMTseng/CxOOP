
#ifndef DECEN_OBJ_H_
#define DECEN_OBJ_H_

#include "CxOOP.h"
#include "CHILD_OBJ.h"

#define DECEN_OBJ_PUBLIC_MEMBER_\
        int decendent_data;

#define DECEN_OBJ_PRIVATE_MEMBER_\

#define DECEN_OBJ_PUBLIC_METHOD_(COBJ,MACRO_X)\

#define DECEN_OBJ_PRIVATE_METHOD_(COBJ,MACRO_X)\

#define DECEN_OBJ_OVERRIDE_METHOD_(COBJ,MACRO_X)\
        MACRO_X(COBJ,int,DoAction, COBJ* self)\

#define DECEN_OBJ_DNA_(X1,COBJ)  \
        CHILD_OBJ_DNA_(X1,COBJ)\
        X1(CHILD_OBJ,COBJ)

CxOOP_OBJECT_DECLARE(DECEN_OBJ)

#endif

