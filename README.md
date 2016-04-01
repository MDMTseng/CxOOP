# Hello CxOOP
A simple MACRO (~70 lines) let you write oop with C easier and cleaner

## You Can Do:
 - Public/Private member
 - Public/Private method
 - Object inherit
 - Object downcasting with inheritance checking
 - method override
 - call super method



## Object declaration

### Object: PARENT
#### Public member: 
int pub; int pubArr[5];
#### Private member: 
float priv;
#### Public method:
void parentPubMethod(PARENT* self, int param1, int param2);<br />
int parentPubMethod2(PARENT* self, int param1, int param2);
#### Private method:
int parentPrivMethod(PARENT*  self, float param1, char param2);


----------

    #include "CxOOP.h"
    
    #define PARENT_DNA_(X1,COBJ)
    
    #define PARENT_PUBLIC_MEMBER_\
            int pub;\
            int pubArr[5];
    
    #define PARENT_PRIVATE_MEMBER_\
            float priv;
    
    #define PARENT_PUBLIC_METHOD_(COBJ,MACRO_X)\
            MACRO_X(COBJ, void, parentPubMethod, COBJ* self, int param1, int param2)\
            MACRO_X(COBJ, int, parentPubMethod2, COBJ* self, int param1, int param2)\
    
    #define PARENT_PRIVATE_METHOD_(COBJ,MACRO_X)\
            MACRO_X(COBJ, int, parentPrivMethod, COBJ* self, float param1, char param2)\
    
    #define PARENT_OVERRIDE_METHOD_(COBJ,MACRO_X)\
            
    
    CxOOP_OBJECT_DECLARE(PARENT)

## Object implementation

----------

    #include "PARENT.h"
    CxOOP_DECLARE_METHOD(PARENT)
    
    int CONSTRUCTOR_PARENT(PARENT* obj)
    {
        CxOOP_INIT_METHOD(PARENT,obj);
        return 0;
    }
    
    int DESTRUCTOR_PARENT(PARENT* obj)
    {
        return 0;
    }
    //All methods name will be [Object Name]_[Method name]
    static void PARENT_parentPubMethod(PARENT* self, int param1, int param2)
    {
    	self->pub=0;//do you wanna do
    }
    static int PARENT_parentPubMethod2(PARENT* self, int param1, int param2)
    {
    	return self->pub;//do you wanna do
    }
    static int PARENT_parentPrivMethod(PARENT*  self, float param1, char param2)
    {
    	self->pub=0;//do you wanna do
        //self->priv=0; You cannot access private attribute directly
        __OMNI__PARENT *oself=(void*)self;//switch to omni scope
        oself->priv=0;//now you can change that
        
        return 0;
    }
    

