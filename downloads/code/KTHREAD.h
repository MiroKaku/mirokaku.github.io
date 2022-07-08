/*Windows 8.1 x64 Checked Build*/
          typedef struct _KTHREAD                                            // 162 elements, 0x5D0 bytes (sizeof)
          {
/*0x000*/     struct _DISPATCHER_HEADER Header;                              // 分发头, 使其成为可等待对象
/*0x018*/     VOID*        SListFaultAddress;                                // 与用户模式互锁单链表 POP 操作 (KeUserPopEntrySListFault函数) 的错误处理有关, 它记录了上一次用户模式互锁单链表 POP 操作发生页面错误的地址
/*0x020*/     UINT64       QuantumTarget;
                                                                             // 有四个域用于内核栈的维护, 它们分别是: InitialStack, StackLimit, KernelStack 和StackBase
                                                                             // 在线程初始化时, InitialStack 和 StackBase 是相等的, 都指向原始的内核栈高地址
/*0x028*/     VOID*        InitialStack;                                     // 记录了原始的内核栈位置
/*0x030*/     VOID*        StackLimit;                                       // 记录了内核栈的低地址
/*0x038*/     VOID*        StackBase;                                        // 记录了当前内核栈的基地址
/*0x040*/     UINT64       ThreadLock;                                       // 一个自旋锁, 用于保护线程数据成员
/*0x048*/     UINT64       CycleTime;                                        // 周期时间
/*0x050*/     ULONG32      CurrentRunTime;                                   // 当前运行时间
/*0x054*/     ULONG32      ExpectedRunTime;                                  // 预期运行时间
/*0x058*/     VOID*        KernelStack;                                      // 记录了真正内核调用栈的开始位置, 由于在内核栈的顶部区域还记录了浮点处理器保存区和一个异常陷阱帧,
                                                                             // 所以 KernelStack 的位置比 InitialStack 要低一些 (KTRAP_FRAME_LENGTH + sizeof(FX_SAVE_AREA))
/*0x060*/     struct _XSAVE_FORMAT* StateSaveArea;
/*0x068*/     struct _KSCHEDULING_GROUP* SchedulingGroup;
/*0x070*/     union _KWAIT_STATUS_REGISTER WaitRegister;
/*0x071*/     UINT8        Running;
/*0x072*/     UINT8        Alerted[2];                                       // 一个数组, 指定了该线程在每一种警告模式下是否可以被唤醒, 数组的含义是指该线程分别在内核模式和用户模式下是否可以被唤醒
              union
              {
                  struct
                  {
/*0x074*/             ULONG32      KernelStackResident : 1;                  // 该线程的内核栈是否驻留在内存中, 当内核栈被换出内存时, 该值将被置成 FALSE, 当换入内存时再置成TRUE
/*0x074*/             ULONG32      ReadyTransition : 1;
/*0x074*/             ULONG32      ProcessReadyQueue : 1;                    // 一个线程是否在所属进程 KPROCESS 对象的 ReadyListHead 链表中, TRUE 表示在此链表中, FALSE 表示不在
/*0x074*/             ULONG32      WaitNext : 1;                             // 表示这个线程马上要调用一个内核等待函数, 它的用途是在发出了一个信号 (比如释放了一个信号量对象) 以后,
                                                                             // 接下来该线程会马上调用等待函数, 所以它不必解除线程调度器锁
                                                                             // KeSetEvent 的 Wait 参数就是这个
/*0x074*/             ULONG32      SystemAffinityActive : 1;
/*0x074*/             ULONG32      Alertable : 1;                            // 一个线程是否可以被唤醒, 当一个线程正在等待时, 如果它的 Alertable 值为 TRUE, 则它可以被唤醒
/*0x074*/             ULONG32      UserStackWalkActive : 1;
/*0x074*/             ULONG32      ApcInterruptRequest : 1;
/*0x074*/             ULONG32      QuantumEndMigrate : 1;
/*0x074*/             ULONG32      UmsDirectedSwitchEnable : 1;
/*0x074*/             ULONG32      TimerActive : 1;
/*0x074*/             ULONG32      SystemThread : 1;                         // 是否为系统线程
/*0x074*/             ULONG32      ProcessDetachActive : 1;
/*0x074*/             ULONG32      CalloutActive : 1;
/*0x074*/             ULONG32      ScbReadyQueue : 1;
/*0x074*/             ULONG32      ApcQueueable : 1;                         // 是否可以插入APC
/*0x074*/             ULONG32      ReservedStackInUse : 1;
/*0x074*/             ULONG32      UmsPerformingSyscall : 1;
/*0x074*/             ULONG32      ApcPendingReload : 1;
/*0x074*/             ULONG32      Reserved : 13;
                  };
/*0x074*/         LONG32       MiscFlags;
              };
              union
              {
                  struct
                  {
/*0x078*/             ULONG32      AutoAlignment : 1;                        // 继承自 KPROCESS, 内存访问对其设置
/*0x078*/             ULONG32      DisableBoost : 1;
/*0x078*/             ULONG32      UserAffinitySet : 1;
/*0x078*/             ULONG32      AlertedByThreadId : 1;
/*0x078*/             ULONG32      QuantumDonation : 1;
/*0x078*/             ULONG32      EnableStackSwap : 1;                      // 本线程的内核栈是否允许被换出
/*0x078*/             ULONG32      GuiThread : 1;                            // 是否 GUI 线程
/*0x078*/             ULONG32      DisableQuantum : 1;
/*0x078*/             ULONG32      ChargeOnlySchedulingGroup : 1;
/*0x078*/             ULONG32      DeferPreemption : 1;
/*0x078*/             ULONG32      QueueDeferPreemption : 1;
/*0x078*/             ULONG32      ForceDeferSchedule : 1;
/*0x078*/             ULONG32      SharedReadyQueueAffinity : 1;
/*0x078*/             ULONG32      FreezeCount : 1;
/*0x078*/             ULONG32      TerminationApcRequest : 1;
/*0x078*/             ULONG32      AutoBoostEntriesExhausted : 1;
/*0x078*/             ULONG32      EtwStackTraceApcInserted : 8;
/*0x078*/             ULONG32      ReservedFlags : 8;
                  };
/*0x078*/         LONG32       ThreadFlags;
              };
/*0x07C*/     ULONG32      Spare0;
/*0x080*/     ULONG32      SystemCallNumber;                                 // 进行系统调用时的系统调用号
/*0x084*/     ULONG32      Spare1;
/*0x088*/     VOID*        FirstArgument;                                    // 进行系统调用时的首个调用参数
/*0x090*/     struct _KTRAP_FRAME* TrapFrame;                                // 系统空间堆栈上的陷阱帧
              union
              {
/*0x098*/         struct _KAPC_STATE ApcState;                               // 指定了一个线程的APC信息, 包括APC 链表, 是否正在处理 APC 或者是否有内核 APC 或用户 APC 正在等待等信息
                  struct
                  {
/*0x098*/             UINT8        ApcStateFill[43];
/*0x0C3*/             CHAR         Priority;                                 // 包含了该线程的优先级值, 这是指它的动态优先级, 即在执行过程中可能由于某些原因而调整过的优先级
/*0x0C4*/             ULONG32      UserIdealProcessor;
                  };
              };
/*0x0C8*/     INT64        WaitStatus;                                       // 记录了等待的结果状态
/*0x0D0*/     struct _KWAIT_BLOCK* WaitBlockList;                            // 成员指向一个以 KWAIT_BLOCK 为元素的链表, 其中的 KWAIT_BLOCK 对象指明了哪个线程在等待哪个分发器对象
                                                                             // 对于一个线程而言, WaitBlockList 域以及每个 KWAIT_BLOCK 对象中的 WaitListEntry 域构成了一个双链表, 指明了该线程正在等待哪些分发器对象
                                                                             // 而对于每个分发器对象而言, 它又有另一个KWAIT_BLOCK链表指明了哪些线程正在等待它。
              union
              {
/*0x0D8*/         struct _LIST_ENTRY WaitListEntry;                          // 一个线程节点加入到某个链表中.
                                                                             // 例如, KPROCESS 的 ReadyListHead 域时曾提到, 在进程被换入内存过程中, 就绪状态的线程将被加入到以进程的 ReadyListHead 域为链表头的双链表中,
                                                                             // 链表中的节点即为线程的 WaitListEntry 域
/*0x0D8*/         struct _SINGLE_LIST_ENTRY SwapListEntry;                   // 被用于当线程的内核栈需要被换入时, 插入到以全局变量 KiStackInSwapListHead 为链表头的单链表中.
                                                                             // 另外, 当一个线程处于 DeferredReady 状态时, 其 SwapListEntry 将被插入到某个处理器的DeferredReadyListHead 链表中 (参见 KiInsertDeferredReadyList 和KiProcessDeferredReadyList 内核函数)
              };
/*0x0E8*/     struct _DISPATCHER_HEADER* Queue;                              // 一个队列分发器对象, 如果不为NULL, 则表示当前线程正在处理此队列对象中的项
/*0x0F0*/     VOID*        Teb;                                              // 线程环境块, TEB结构包含了在用户地址空间中需要访问的各种信息
/*0x0F8*/     UINT64       RelativeTimerBias;
/*0x100*/     struct _KTIMER Timer;                                          // 这是附在一个线程上的定时器, 当一个线程在执行过程中需要定时器时,
                                                                             // 比如实现可超时的等待函数 (KeWaitForSingleObject 或 KeWaitForMultipleObjects), 就会用到此定时器对象.
              union
              {
/*0x140*/         struct _KWAIT_BLOCK WaitBlock[4];                          // 包含4 个 KWAIT_BLOCK 成员的数组, 其中第4 项专门用于可等待的定时器对象
                  struct
                  {
/*0x140*/             UINT8        WaitBlockFill4[20];
/*0x154*/             ULONG32      ContextSwitches;
/*0x158*/             UINT8        _PADDING0_[0xA8];
                  };
                  struct
                  {
/*0x140*/             UINT8        WaitBlockFill5[68];
/*0x184*/             UINT8        State;
/*0x185*/             CHAR         NpxState;
/*0x186*/             UINT8        WaitIrql;
/*0x187*/             CHAR         WaitMode;
/*0x188*/             UINT8        _PADDING1_[0x78];
                  };
                  struct
                  {
/*0x140*/             UINT8        WaitBlockFill6[116];
/*0x1B4*/             ULONG32      WaitTime;
/*0x1B8*/             UINT8        _PADDING2_[0x48];
                  };
                  struct
                  {
/*0x140*/             UINT8        WaitBlockFill7[164];
                      union
                      {
                          struct
                          {
/*0x1E4*/                     INT16        KernelApcDisable;
/*0x1E6*/                     INT16        SpecialApcDisable;
                          };
/*0x1E4*/                 ULONG32      CombinedApcDisable;
                      };
                  };
                  struct
                  {
/*0x140*/             UINT8        WaitBlockFill8[40];
/*0x168*/             struct _KTHREAD_COUNTERS* ThreadCounters;
/*0x170*/             UINT8        _PADDING3_[0x90];
                  };
                  struct
                  {
/*0x140*/             UINT8        WaitBlockFill9[88];
/*0x198*/             struct _XSTATE_SAVE* XStateSave;
/*0x1A0*/             UINT8        _PADDING4_[0x60];
                  };
                  struct
                  {
/*0x140*/             UINT8        WaitBlockFill10[136];
/*0x1C8*/             VOID*        Win32Thread;                                // 本线程的 W32THREAD 结构
/*0x1D0*/             UINT8        _PADDING5_[0x30];
                  };
                  struct
                  {
/*0x140*/             UINT8        WaitBlockFill11[176];
/*0x1F0*/             struct _UMS_CONTROL_BLOCK* Ucb;
/*0x1F8*/             struct _KUMS_CONTEXT_HEADER* Uch;
                  };
              };
/*0x200*/     VOID*        TebMappedLowVa;
/*0x208*/     struct _LIST_ENTRY QueueListEntry;                               // 记录了线程在处理一个队列项时加入到队列对象的线程链表中的节点地址
              union
              {
/*0x218*/         ULONG32      NextProcessor;                                  // 处理器调度的选择
                  struct
                  {
/*0x218*/             ULONG32      NextProcessorNumber : 31;                   // 下一个处理器号
/*0x218*/             ULONG32      SharedReadyQueue : 1;
                  };
              };
/*0x21C*/     LONG32       QueuePriority;
/*0x220*/     struct _KPROCESS* Process;                                       // 所属进程 KPROCESS
              union
              {
/*0x228*/         struct _GROUP_AFFINITY UserAffinity;                         // 线程的用户亲和性, 此值初始时也继承自进程对象的Affinity 值, 以后可通过内核函数KeSetAffinityThread 改变
                  struct
                  {
/*0x228*/             UINT8        UserAffinityFill[10];
/*0x232*/             CHAR         PreviousMode;
/*0x233*/             CHAR         BasePriority;
                      union
                      {
/*0x234*/                 CHAR         PriorityDecrement;
                          struct
                          {
/*0x234*/                     UINT8        ForegroundBoost : 4;
/*0x234*/                     UINT8        UnusualBoost : 4;
                          };
                      };
/*0x235*/             UINT8        Preempted;
/*0x236*/             UINT8        AdjustReason;
/*0x237*/             CHAR         AdjustIncrement;
                  };
              };
              union
              {
/*0x238*/         struct _GROUP_AFFINITY Affinity;                             // 线程的处理器亲和性, 此值初始时继承自进程对象的Affinity 值. 为线程指定的处理器集合必须是其进程的亲和性处理器集合的子集.
                                                                               // 在线程执行过程中, 其 Affinity 值可能有两种设置:
                                                                               // 一是系统亲和性,  当该线程执行系统任务时通过 KeSetSystemAffinityThread 函数来设置
                                                                               // 二是线程本身的亲和性, 称为用户亲和性, 通过 KeRevertToUserAffinityThread 函数来设置
                  struct
                  {
/*0x238*/             UINT8        AffinityFill[10];
/*0x242*/             UINT8        ApcStateIndex;                              // 指明了当前的 APC 状态在ApcStatePointer 域中的索引
/*0x243*/             UINT8        WaitBlockCount;
/*0x244*/             ULONG32      IdealProcessor;
                  };
              };
/*0x248*/     struct _KAPC_STATE* ApcStatePointer[2];                          // 数组元素的类型是指向 KAPC_STATE 的指针, 其两个元素分别指向线程对象的 ApcState 和SavedApcState 域, 而这两个域分别位于两个union 中
              union
              {
/*0x258*/         struct _KAPC_STATE SavedApcState;
                  struct
                  {
/*0x258*/             UINT8        SavedApcStateFill[43];
/*0x283*/             UINT8        WaitReason;
/*0x284*/             CHAR         SuspendCount;
/*0x285*/             CHAR         Saturation;
/*0x286*/             UINT16       SListFaultCount;
                  };
              };
              union
              {
/*0x288*/         struct _KAPC SchedulerApc;
                  struct
                  {
/*0x288*/             UINT8        SchedulerApcFill0[1];
/*0x289*/             UINT8        ResourceIndex;
/*0x28A*/             UINT8        _PADDING6_[0x56];
                  };
                  struct
                  {
/*0x288*/             UINT8        SchedulerApcFill1[3];
/*0x28B*/             UINT8        QuantumReset;
/*0x28C*/             UINT8        _PADDING7_[0x54];
                  };
                  struct
                  {
/*0x288*/             UINT8        SchedulerApcFill2[4];
/*0x28C*/             ULONG32      KernelTime;
/*0x290*/             UINT8        _PADDING8_[0x50];
                  };
                  struct
                  {
/*0x288*/             UINT8        SchedulerApcFill3[64];
/*0x2C8*/             struct _KPRCB* WaitPrcb;
/*0x2D0*/             UINT8        _PADDING9_[0x10];
                  };
                  struct
                  {
/*0x288*/             UINT8        SchedulerApcFill4[72];
/*0x2D0*/             VOID*        LegoData;
/*0x2D8*/             UINT8        _PADDING10_[0x8];
                  };
                  struct
                  {
/*0x288*/             UINT8        SchedulerApcFill5[83];
/*0x2DB*/             UINT8        CallbackNestingLevel;
/*0x2DC*/             ULONG32      UserTime;
                  };
              };
/*0x2E0*/     struct _KEVENT SuspendEvent;
/*0x2F8*/     struct _LIST_ENTRY ThreadListEntry;                              // 代表了一个双链表上的节点, 当一个线程被创建时, 它会被加入到进程对象的ThreadListHead 链表中
/*0x308*/     struct _LIST_ENTRY MutantListHead;                               // 一个链表头, 该链表中包含了所有属于该线程的突变体对象 (mutant, 对应于 API 中的互斥体mutex 对象)
                                                                               // 由于突变体对象是有所有权的, 一旦被某个线程等到, 则其所有权归该线程所有, 它也被连接到MutantListHead 链表中
/*0x318*/     struct _SINGLE_LIST_ENTRY LockEntriesFreeList;
/*0x320*/     struct _KLOCK_ENTRY LockEntries[6];
/*0x560*/     struct _SINGLE_LIST_ENTRY PropagateBoostsEntry;
/*0x568*/     struct _SINGLE_LIST_ENTRY IoSelfBoostsEntry;
/*0x570*/     UINT8        PriorityFloorCounts[16];
/*0x580*/     ULONG32      PriorityFloorSummary;
/*0x584*/     LONG32       AbCompletedIoBoostCount;
/*0x588*/     INT16        AbReferenceCount;
/*0x58A*/     UINT8        AbFreeEntryCount;
/*0x58B*/     UINT8        AbWaitEntryCount;
/*0x58C*/     ULONG32      ForegroundLossTime;
              union
              {
/*0x590*/         struct _LIST_ENTRY GlobalForegroundListEntry;
                  struct
                  {
/*0x590*/             struct _SINGLE_LIST_ENTRY ForegroundDpcStackListEntry;
/*0x598*/             UINT64       InGlobalForegroundList;
                  };
              };
/*0x5A0*/     INT64        ReadOperationCount;                                 // 剩下这几个字段的含义同 EPROCESS 中一样
/*0x5A8*/     INT64        WriteOperationCount;
/*0x5B0*/     INT64        OtherOperationCount;
/*0x5B8*/     INT64        ReadTransferCount;
/*0x5C0*/     INT64        WriteTransferCount;
/*0x5C8*/     INT64        OtherTransferCount;
          }KTHREAD, *PKTHREAD;