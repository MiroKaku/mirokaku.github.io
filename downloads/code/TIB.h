/*Windows 8.1 x64 Checked Build*/
          typedef struct _NT_TIB                                    // 8 elements, 0x38 bytes (sizeof)
          {
/*0x000*/     struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList; // 异常处理链
/*0x008*/     VOID*        StackBase;                               // 用户栈基(高)地址
/*0x010*/     VOID*        StackLimit;                              // 用户栈低地址(限制)
/*0x018*/     VOID*        SubSystemTib;
              union
              {
/*0x020*/         VOID*        FiberData;                           // 纤程信息
/*0x020*/         ULONG32      Version;
              };
/*0x028*/     VOID*        ArbitraryUserPointer;
/*0x030*/     struct _NT_TIB* Self;                                 // TIB/TEB 结构起点的指针, 用于在用户层通过 FS/GS 寄存器获取指针
          }NT_TIB, *PNT_TIB;
