#ifndef OBJ_MACRO_H_
#define OBJ_MACRO_H_

#define NULL_OBJ_INH_

#define __METHOD__DECLARE(PREFIX,RET,FUNCNAME,...)\
        RET  PREFIX##_##FUNCNAME ( __VA_ARGS__ );
#define __METHOD__SPAN(PREFIX,RET,FUNCNAME,...)\
        RET (* FUNCNAME )( __VA_ARGS__ );

#define OBJECT_INHERIT_STRUCT_PRIDELCAREX_(CLASSNAME)\
        CLASSNAME##_PUBLIC_METHOD_(CLASSNAME,__METHOD__SPAN);\
        char CLASSNAME##priv_method_space[sizeof(struct _PRIVATE_METHOD_##CLASSNAME)+sizeof(struct _OVERRIDE_METHOD_##CLASSNAME)];\
        CLASSNAME##_PUBLIC_MEMBER_\
        char CLASSNAME##priv_member_space[sizeof(struct _PRIVATE_MEMBER_##CLASSNAME)];\

#define __METHOD__OVERRIDE_SPAN(PREFIX,RET,FUNCNAME,...)\
        RET (* SUPER_##FUNCNAME )( __VA_ARGS__ );
#define __METHOD__SETTING(PREFIX,RET,FUNCNAME,...)\
        omni_obj_____->FUNCNAME=PREFIX##_##FUNCNAME;\

#define __METHOD__OVERRIDE_SETTING(PREFIX,RET,FUNCNAME,...)\
        omni_obj_____->SUPER_##FUNCNAME=omni_obj_____->FUNCNAME;\
        omni_obj_____->FUNCNAME=PREFIX##_##FUNCNAME;\

#define OBJECT_INIT_METHOD(CLASSNAME,obj_ptr)\
        __OMNI__##CLASSNAME *omni_obj_____=(__OMNI__##CLASSNAME*)obj;\
        CLASSNAME##_PUBLIC_METHOD_(CLASSNAME,__METHOD__SETTING)\
        CLASSNAME##_PRIVATE_METHOD_(CLASSNAME,__METHOD__SETTING)\
        CLASSNAME##_OVERRIDE_METHOD_(CLASSNAME,__METHOD__OVERRIDE_SETTING)\

#define OBJECT_INHERIT(CLASSNAME,CLASS_SUPER) \
        typedef struct _##CLASSNAME CLASSNAME;\
        typedef struct ___OMNI__##CLASSNAME __OMNI__##CLASSNAME;\
        CLASSNAME##_PUBLIC_METHOD_(CLASSNAME,__METHOD__DECLARE)/*declare the function first*/\
        struct  _PUBLIC_METHOD_##CLASSNAME\
        {\
            CLASSNAME##_PUBLIC_METHOD_(CLASSNAME,__METHOD__SPAN)\
        };\
        CLASSNAME##_PRIVATE_METHOD_(CLASSNAME,__METHOD__DECLARE)/*declare the function first*/\
        struct  _PRIVATE_METHOD_##CLASSNAME\
        {\
            CLASSNAME##_PRIVATE_METHOD_(CLASSNAME,__METHOD__SPAN)\
        };\
        CLASSNAME##_OVERRIDE_METHOD_(CLASSNAME,__METHOD__DECLARE)/*declare the function first*/\
        struct  _OVERRIDE_METHOD_##CLASSNAME\
        {\
            CLASSNAME##_OVERRIDE_METHOD_(CLASSNAME,__METHOD__OVERRIDE_SPAN)\
        };\
        struct  _PRIVATE_MEMBER_##CLASSNAME\
        {\
            CLASSNAME##_PRIVATE_MEMBER_\
        };\
        struct  _PUBLIC_MEMBER_##CLASSNAME\
        {\
            CLASSNAME##_PUBLIC_MEMBER_\
        };\
        struct ___OMNI__##CLASSNAME\
        {\
            CLASS_SUPER##_INH_\
            CLASSNAME##_PUBLIC_METHOD_(CLASSNAME,__METHOD__SPAN)\
            CLASSNAME##_PRIVATE_METHOD_(CLASSNAME,__METHOD__SPAN)\
            CLASSNAME##_OVERRIDE_METHOD_(CLASSNAME,__METHOD__OVERRIDE_SPAN)\
            CLASSNAME##_PUBLIC_MEMBER_\
            CLASSNAME##_PRIVATE_MEMBER_\
        };\
        struct _##CLASSNAME\
        {\
            CLASS_SUPER##_INH_\
            CLASSNAME##_PUBLIC_METHOD_(CLASSNAME,__METHOD__SPAN);\
            char CLASSNAME##priv_method_space[sizeof(struct _PRIVATE_METHOD_##CLASSNAME)+sizeof(struct _OVERRIDE_METHOD_##CLASSNAME)];\
            CLASSNAME##_PUBLIC_MEMBER_\
            char CLASSNAME##priv_member_space[sizeof(struct _PRIVATE_MEMBER_##CLASSNAME)];\
        };\
        int CONSTRUCTOR_##CLASSNAME( CLASSNAME * obj);\
        int DESTRUCTOR_##CLASSNAME( CLASSNAME * obj);
#endif  //OBJ_MACRO_H_
