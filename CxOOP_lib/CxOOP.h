#ifndef C_X_OOP_H_
#define C_X_OOP_H_

#define CxOOP__METHOD__DECLARE(PREFIX,RET,FUNCNAME,...)\
        static RET PREFIX##_##FUNCNAME ( __VA_ARGS__ );
#define CxOOP__METHOD__SPAN(PREFIX,RET,FUNCNAME,...)\
        RET (* FUNCNAME )( __VA_ARGS__ );
#define CxOOP__METHOD__OVERRIDE_SPAN(PREFIX,RET,FUNCNAME,...)\
        RET (* SUPER_##FUNCNAME )( __VA_ARGS__ );

#define CxOOP_STRUCT_PRIDELCARE_(CLASSNAME)\
		CLASSNAME##_PUBLIC_MEMBER_\
		CLASSNAME##_PUBLIC_METHOD_(CLASSNAME,CxOOP__METHOD__SPAN);\
		const char CLASSNAME##_priv_member_space[sizeof(struct _PRIVATE_MEMBER_##CLASSNAME)];\
		const char CLASSNAME##_priv_method_space[sizeof(struct _PRIVATE_METHOD_##CLASSNAME)];\

#define CxOOP_INHERIT_DECLARE(CLASSNAME,CLASS_SUPER) \
        typedef struct _##CLASSNAME CLASSNAME;\
        typedef struct ___OMNI__##CLASSNAME __OMNI__##CLASSNAME;\
        struct  _PRIVATE_METHOD_##CLASSNAME\
        {\
            CLASSNAME##_PRIVATE_METHOD_(CLASSNAME,CxOOP__METHOD__SPAN)\
            CLASSNAME##_OVERRIDE_METHOD_(CLASSNAME,CxOOP__METHOD__OVERRIDE_SPAN)\
        };\
        struct  _PRIVATE_MEMBER_##CLASSNAME\
        {\
            CLASSNAME##_PRIVATE_MEMBER_\
        };\
        struct ___OMNI__##CLASSNAME/* A struct to access all members, use it carefully */\
        {\
            CLASS_SUPER##_INH_\
            CLASSNAME##_PUBLIC_MEMBER_\
            CLASSNAME##_PUBLIC_METHOD_(CLASSNAME,CxOOP__METHOD__SPAN)\
            CLASSNAME##_PRIVATE_MEMBER_\
            CLASSNAME##_PRIVATE_METHOD_(CLASSNAME,CxOOP__METHOD__SPAN)\
            CLASSNAME##_OVERRIDE_METHOD_(CLASSNAME,CxOOP__METHOD__OVERRIDE_SPAN)\
        };\
        struct _##CLASSNAME/* A struct to provide encapsulation */\
        {\
            CLASS_SUPER##_INH_\
            CxOOP_STRUCT_PRIDELCARE_(CLASSNAME)\
        };\
        int CONSTRUCTOR_##CLASSNAME( CLASSNAME * obj);\
        int DESTRUCTOR_##CLASSNAME( CLASSNAME * obj);

#define CxOOP__METHOD__SETTING(PREFIX,RET,FUNCNAME,...)\
        omni_obj_____->FUNCNAME=PREFIX##_##FUNCNAME;\

#define CxOOP__METHOD__OVERRIDE_SETTING(PREFIX,RET,FUNCNAME,...)\
        omni_obj_____->SUPER_##FUNCNAME=(void*)omni_obj_____->FUNCNAME;\
        omni_obj_____->FUNCNAME=(void*)PREFIX##_##FUNCNAME;\

#define CxOOP_INHERIT_IMPLEMENT(CLASSNAME,CLASS_SUPER) \
        CLASSNAME##_PUBLIC_METHOD_(CLASSNAME,CxOOP__METHOD__DECLARE)\
        CLASSNAME##_PRIVATE_METHOD_(CLASSNAME,CxOOP__METHOD__DECLARE)\
        CLASSNAME##_OVERRIDE_METHOD_(CLASSNAME,CxOOP__METHOD__DECLARE)\

#define CxOOP_INIT_METHOD(CLASSNAME,obj_ptr)\
        __OMNI__##CLASSNAME *omni_obj_____=(void*)obj;\
        CLASSNAME##_PUBLIC_METHOD_(CLASSNAME,CxOOP__METHOD__SETTING)\
        CLASSNAME##_PRIVATE_METHOD_(CLASSNAME,CxOOP__METHOD__SETTING)\
        CLASSNAME##_OVERRIDE_METHOD_(CLASSNAME,CxOOP__METHOD__OVERRIDE_SETTING)\

#define NULL_OBJ_INH_

#endif  //C_X_OOP_H_

