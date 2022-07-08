/*Windows 8.1 x64 Checked Build*/
          typedef struct _ETHREAD                                              // 100 elements, 0x778 bytes (sizeof)
          {
/*0x000*/     struct _KTHREAD Tcb;                                             // 线程控制块, 因为是 ETHREAD 的第一个字段, 所以 KTHREAD 和 ETHREAD 的地址是一样的
/*0x5D0*/     union _LARGE_INTEGER CreateTime;                                 // 创建时间
              union
              {
/*0x5D8*/         union _LARGE_INTEGER ExitTime;                               // 退出时间
/*0x5D8*/         struct _LIST_ENTRY KeyedWaitChain;                           // 用于带键事件的等待链表
              };
/*0x5E8*/     VOID*        ChargeOnlySession;
              union
              {
/*0x5F0*/         struct _LIST_ENTRY PostBlockList;                            // 头节点, 该链表中的各个节点类型为PCM_POST_BLOCK, 它被用于一个线程向配置管理器登记注册表键的变化通知
                  struct
                  {
/*0x5F0*/             VOID*        ForwardLinkShadow;
/*0x5F8*/             VOID*        StartAddress;                               // 包含了线程的启动地址, 这是真正的线程启动地址
                  };
              };
              union
              {
/*0x600*/         struct _TERMINATION_PORT* TerminationPort;                   // 链表头, 当一个线程退出时, 系统会通知所有已经登记过要接收其终止事件的那些端口
/*0x600*/         struct _ETHREAD* ReaperLink;                                 // 单链表节点, 它仅在线程退出时使用. 当线程被终止时, 该节点将被挂到 PsReaperListHead 链表上, 所以在线程回收器 (reaper) 的工作项目 (WorkItem) 中该线程的内核栈得以收回
/*0x600*/         VOID*        KeyedWaitValue;                                 // 带键事件的键值
              };
/*0x608*/     UINT64       ActiveTimerListLock;                                // ActiveTimerListHead 链表的自旋锁
/*0x610*/     struct _LIST_ENTRY ActiveTimerListHead;                          // 双链表的头, 链表中包含了当前线程的所有定时器
/*0x620*/     struct _CLIENT_ID Cid;                                           // 客户id, 包含 进程id 和 线程id
              union
              {
/*0x630*/         struct _KSEMAPHORE KeyedWaitSemaphore;                       // 信号量对象, 用于处理带键的事件
/*0x630*/         struct _KSEMAPHORE AlpcWaitSemaphore;                        // 信号量对象, 用于 ALPC 应答通知
              };
/*0x650*/     union _PS_CLIENT_SECURITY_CONTEXT ClientSecurity;
/*0x658*/     struct _LIST_ENTRY IrpList;                                      // 双链表头, 其中包含了当前线程所有正在处理但尚未完成的 I/O 请求 (IRP 对象)
/*0x668*/     UINT64       TopLevelIrp;                                        // 指向线程的顶级IRP, 它或者指向 NULL 或一个 IRP
                                                                               // 或者包含了 fsrtl.h 中定义的标记 FSRTL_FAST_IO_TOP_LEVEL_IRP 或 FSRTL_FSP_TOP_LEVEL_IRP.
                                                                               // 仅当一个线程的 I/O 调用层次中最顶级的组件是文件系统时, 才指向当前IRP
/*0x670*/     struct _DEVICE_OBJECT* DeviceToVerify;                           // 指向一个待检验的设备对象, 当磁盘或 CD-ROM 设备的驱动程序发现自从上一次该线程访问该设备以来, 该设备似乎有了变化, 就会设置线程的 DeviceToVerify 域, 从而使最高层的驱动程序, 比如文件系统, 可以检测到设备的变化
/*0x678*/     VOID*        Win32StartAddress;                                  // Windows 子系统的启动地址
/*0x680*/     VOID*        LegacyPowerObject;
/*0x688*/     struct _LIST_ENTRY ThreadListEntry;                              // 挂入 EPROCESS 中的线程链表
/*0x698*/     struct _EX_RUNDOWN_REF RundownProtect;                           // 线程的停止保护锁, 对于跨线程引用 TEB 结构或者挂起线程的执行等操作, 需要获得此锁才能进行, 以避免在操作过程中线程被销毁
/*0x6A0*/     struct _EX_PUSH_LOCK ThreadLock;                                 // 用于保护线程的数据属性, 例如 PspLockThreadSecurityExclusive 和 PspLockThreadSecurityShared 利用该域来保护线程的安全属性
/*0x6A8*/     ULONG32      ReadClusterSize;                                    // 指明了在一次I/O操作中读取多少个页面, 用于页面交换文件和内存映射文件的读操作
/*0x6AC*/     LONG32       MmLockOrdering;
/*0x6B0*/     LONG32       CmLockOrdering;
              union
              {
/*0x6B4*/         ULONG32      CrossThreadFlags;                               // 一些针对跨线程访问的标志位
                  struct
                  {
/*0x6B4*/             ULONG32      Terminated : 1;
/*0x6B4*/             ULONG32      ThreadInserted : 1;
/*0x6B4*/             ULONG32      HideFromDebugger : 1;
/*0x6B4*/             ULONG32      ActiveImpersonationInfo : 1;
/*0x6B4*/             ULONG32      HardErrorsAreDisabled : 1;
/*0x6B4*/             ULONG32      BreakOnTermination : 1;
/*0x6B4*/             ULONG32      SkipCreationMsg : 1;
/*0x6B4*/             ULONG32      SkipTerminationMsg : 1;
/*0x6B4*/             ULONG32      CopyTokenOnOpen : 1;
/*0x6B4*/             ULONG32      ThreadIoPriority : 3;
/*0x6B4*/             ULONG32      ThreadPagePriority : 3;
/*0x6B4*/             ULONG32      RundownFail : 1;
/*0x6B4*/             ULONG32      UmsForceQueueTermination : 1;
/*0x6B4*/             ULONG32      ReservedCrossThreadFlags : 15;
                  };
              };
              union
              {
/*0x6B8*/         ULONG32      SameThreadPassiveFlags;                         // 一些只有在PASSIVE级别上才可以访问的标志位, 并且只能被该线程自身访问, 所以对这些标志位的访问不需要互锁操作
                  struct
                  {
/*0x6B8*/             ULONG32      ActiveExWorker : 1;
/*0x6B8*/             ULONG32      MemoryMaker : 1;
/*0x6B8*/             ULONG32      ClonedThread : 1;
/*0x6B8*/             ULONG32      KeyedEventInUse : 1;
/*0x6B8*/             ULONG32      SelfTerminate : 1;
                  };
              };
              union
              {
/*0x6BC*/         ULONG32      SameThreadApcFlags;                             // 一些在 APC 中断级别上被该线程自身访问的标志位, 同样地对这些标志位的访问也不需要互锁操作
                  struct
                  {
                      struct
                      {
/*0x6BC*/                 UINT8        HardFaultBehavior : 1;
/*0x6BC*/                 UINT8        StartAddressInvalid : 1;
/*0x6BC*/                 UINT8        EtwCalloutActive : 1;
/*0x6BC*/                 UINT8        OwnsProcessWorkingSetExclusive : 1;
/*0x6BC*/                 UINT8        OwnsProcessWorkingSetShared : 1;
/*0x6BC*/                 UINT8        OwnsSystemCacheWorkingSetExclusive : 1;
/*0x6BC*/                 UINT8        OwnsSystemCacheWorkingSetShared : 1;
/*0x6BC*/                 UINT8        OwnsSessionWorkingSetExclusive : 1;
                      };
                      struct
                      {
/*0x6BD*/                 UINT8        OwnsSessionWorkingSetShared : 1;
/*0x6BD*/                 UINT8        OwnsProcessAddressSpaceExclusive : 1;
/*0x6BD*/                 UINT8        OwnsProcessAddressSpaceShared : 1;
/*0x6BD*/                 UINT8        SuppressSymbolLoad : 1;
/*0x6BD*/                 UINT8        Prefetching : 1;
/*0x6BD*/                 UINT8        OwnsVadExclusive : 1;
/*0x6BD*/                 UINT8        OwnsChangeControlAreaExclusive : 1;
/*0x6BD*/                 UINT8        OwnsChangeControlAreaShared : 1;
                      };
                      struct
                      {
/*0x6BE*/                 UINT8        OwnsPagedPoolWorkingSetExclusive : 1;
/*0x6BE*/                 UINT8        OwnsPagedPoolWorkingSetShared : 1;
/*0x6BE*/                 UINT8        OwnsSystemPtesWorkingSetExclusive : 1;
/*0x6BE*/                 UINT8        OwnsSystemPtesWorkingSetShared : 1;
/*0x6BE*/                 UINT8        TrimTrigger : 2;
/*0x6BE*/                 UINT8        Spare2 : 2;
                      };
                      struct
                      {
/*0x6BF*/                 UINT8        SystemPagePriorityActive : 1;
/*0x6BF*/                 UINT8        SystemPagePriority : 3;
/*0x6BF*/                 UINT8        Spare3 : 4;
                      };
                  };
              };
/*0x6C0*/     UINT8        CacheManagerActive;
/*0x6C1*/     UINT8        DisablePageFaultClustering;                         // 用于控制页面交换的聚集与否
/*0x6C2*/     UINT8        ActiveFaultCount;                                   // 包含了正在进行之中的页面错误数量
/*0x6C3*/     UINT8        LockOrderState;
/*0x6C4*/     UINT8        _PADDING0_[0x4];
/*0x6C8*/     UINT64       AlpcMessageId;
              union
              {
/*0x6D0*/         VOID*        AlpcMessage;
/*0x6D0*/         ULONG32      AlpcReceiveAttributeSet;
              };
/*0x6D8*/     LONG32       ExitStatus;                                         // 退出状态码
/*0x6DC*/     UINT8        _PADDING1_[0x4];
/*0x6E0*/     struct _LIST_ENTRY AlpcWaitListEntry;
/*0x6F0*/     ULONG32      CacheManagerCount;
/*0x6F4*/     ULONG32      IoBoostCount;
/*0x6F8*/     struct _LIST_ENTRY BoostList;
/*0x708*/     struct _LIST_ENTRY DeboostList;
/*0x718*/     UINT64       BoostListLock;
/*0x720*/     UINT64       IrpListLock;                                        // IrpListLock 的锁
/*0x728*/     VOID*        ReservedForSynchTracking;
/*0x730*/     struct _SINGLE_LIST_ENTRY CmCallbackListHead;
/*0x738*/     struct _GUID* ActivityId;
/*0x740*/     struct _SINGLE_LIST_ENTRY SeLearningModeListHead;
/*0x748*/     VOID*        VerifierContext;
/*0x750*/     ULONG32      KernelStackReference;
/*0x754*/     UINT8        _PADDING2_[0x4];
/*0x758*/     VOID*        AdjustedClientToken;                                // 线程的 Token
/*0x760*/     ULONG32      UserFsBase;                                         // fs 寄存器基址?
/*0x764*/     UINT8        _PADDING3_[0x4];
/*0x768*/     UINT64       UserGsBase;                                         // gs 寄存器基址?
/*0x770*/     VOID*        PicoContext;
          }ETHREAD, *PETHREAD;