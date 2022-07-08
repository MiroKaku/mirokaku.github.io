/*Windows 8.1 x64 Checked Build*/
          typedef struct _KPROCESS                          // 42 elements, 0x2C8 bytes (sizeof)
          {
/*0x000*/     struct _DISPATCHER_HEADER Header;             // 分发头, 使进程称为可等待对象
/*0x018*/     struct _LIST_ENTRY ProfileListHead;           // 当该进程参与性能分析 (profiling) 时, 作为一个节点加入到全局的性能分析进程列表 KiProfileListHead 中
/*0x028*/     UINT64       DirectoryTableBase;              // 进程的页面映射表的物理地址, 在进行进程切换的时候, 会将此值赋值给 CR3 寄存器
/*0x030*/     struct _LIST_ENTRY ThreadListHead;            // 进程中所有线程的 KTHREAD 链表
/*0x040*/     ULONG32      ProcessLock;                     // 用于保护 KPROCESS 中的成员
/*0x044*/     ULONG32      Spare0;
/*0x048*/     struct _KAFFINITY_EX Affinity;                // 指定了该进程的线程可以在哪些处理器上运行, 其二进制表示的每一位分别对应于当前机器上的一个处理器或核
/*0x0F0*/     struct _LIST_ENTRY ReadyListHead;             // 当前进程的就绪线程队列,
/*0x100*/     struct _SINGLE_LIST_ENTRY SwapListEntry;      // 当一个进程要被换出内存时, 它通过此域加入到以 KiProcessOutSwapListHead 为链头的单链表中;
                                                            // 当一个进程要被换入内存时, 它通过此域加入到以 KiProcessInSwapListHead 为链头的单链表中.
/*0x108*/     struct _KAFFINITY_EX ActiveProcessors;        // 记录了当前进程正在哪些处理器上运行
              union
              {
                  struct
                  {
/*0x1B0*/             LONG32       AutoAlignment : 1;       // 内存访问对齐设置, 此值会传递到线程的数据结构中
/*0x1B0*/             LONG32       DisableBoost : 1;
/*0x1B0*/             LONG32       DisableQuantum : 1;
/*0x1B0*/             LONG32       AffinitySet : 1;
/*0x1B0*/             ULONG32      DeepFreeze : 1;
/*0x1B0*/             ULONG32      TimerVirtualization : 1;
/*0x1B0*/             ULONG32      CheckStackExtents : 1;
/*0x1B0*/             ULONG32      ActiveGroupsMask : 20;
/*0x1B0*/             LONG32       ReservedFlags : 5;
                  };
/*0x1B0*/         LONG32       ProcessFlags;
              };
                                                            // BasePriority 和 QuantumReset 都是该进程中的线程的调度参数
/*0x1B4*/     CHAR         BasePriority;                    // 指定一个进程中的线程的基本优先级, 所有的线程在启动时都会继承进程的 BasePriority 值
/*0x1B5*/     CHAR         QuantumReset;                    // 指定一个进程中线程的基本时限重置值
/*0x1B6*/     UINT8        Visited;
/*0x1B7*/     union _KEXECUTE_OPTIONS Flags;                // 设置一个进程的内存执行选项
/*0x1B8*/     ULONG32      ThreadSeed[20];                  // 为该进程的线程选择适当的理想处理器 (IdealProcessor), 在每个线程被初始化的时候, 都指定此进程的 ThreadSeed 值作为它的理想处理器, 然后ThreadSeed 域又被设置一个新的值, 以便该进程的下一个线程使用.
                                                            // 这里的理想处理器是指在多处理器环境下, 每个线程都有一个优先选择的处理器
/*0x208*/     UINT16       IdealNode[20];                   // 用于为一个进程选择优先的处理器节点, 这是在进程初始化时设定的. 这里的处理器节点是 NUMA（非一致的内存访问）结构中的概念
/*0x230*/     UINT16       IdealGlobalNode;
/*0x232*/     UINT16       Spare1;
/*0x234*/     union _KSTACK_COUNT StackCount;               // 记录了当前进程中有多少个线程的栈位于内存中
/*0x238*/     struct _LIST_ENTRY ProcessListEntry;          // 用于将当前系统中所有具有活动线程的进程串成一个链表, 链表头为KiProcessListHead
/*0x248*/     UINT64       CycleTime;                       // 周期时间
/*0x250*/     UINT64       ContextSwitches;
/*0x258*/     struct _KSCHEDULING_GROUP* SchedulingGroup;
/*0x260*/     ULONG32      FreezeCount;
/*0x264*/     ULONG32      KernelTime;                      // 分别记录了一个进程对象在内核模式和用户模式下所花的时间. 进程的 KernelTime 和 UserTime 时间值等于其所属线程的对应 KernelTime 和UserTime 值的和.
/*0x268*/     ULONG32      UserTime;                        // 但是, 由于仅当一个线程结束时才更新其进程的这两个时间值, 所以, 若一个进程中尚未有任何一个线程结束, 则这两个域中的值为 0
/*0x26C*/     UINT16       LdtFreeSelectorHint;
/*0x26E*/     UINT16       LdtTableLength;                  // LDT 长度
/*0x270*/     union _KGDTENTRY64 LdtSystemDescriptor;       // LDT 系统描述符
/*0x280*/     VOID*        LdtBaseAddress;                  // LDT 基址
/*0x288*/     struct _FAST_MUTEX LdtProcessLock;            // 进程的 LDT 锁
/*0x2C0*/     VOID*        InstrumentationCallback;
          }KPROCESS, *PKPROCESS;