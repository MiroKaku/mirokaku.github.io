/*Windows 8.1 x64 Checked Build*/
          typedef struct _EPROCESS                                  // 161 elements, 0x6B8 bytes (sizeof)
          {
/*0x000*/     struct _KPROCESS Pcb;                                 // 进程控制块, 因为是 EPROCESS 的第一个字段, 所以 KPROCESS 和 EPROCESS 的地址是一样的
/*0x2C8*/     struct _EX_PUSH_LOCK ProcessLock;                     // 与 KPROCESS 中的自旋锁同名, 但它们的类型不同, 保护的成员也不同. 这里的 ProcessLock 域是一个推锁 (push lock) 对象, 用于保护EPROCESS 中的数据成员
/*0x2D0*/     union _LARGE_INTEGER CreateTime;                      // 进程创建时间
/*0x2D8*/     struct _EX_RUNDOWN_REF RundownProtect;                // 进程的停止保护锁, 当一个进程到最后被销毁时, 它要等到所有其他进程和线程已经释放了此锁, 才可以继续进行
/*0x2E0*/     HANDLE       UniqueProcessId;                         // 进程id
/*0x2E8*/     struct _LIST_ENTRY ActiveProcessLinks;                // 活动进程链表, 表头是全局变量PsActiveProcessHead
              union
              {
/*0x2F8*/         ULONG32      Flags2;
                  struct
                  {
/*0x2F8*/             ULONG32      JobNotReallyActive : 1;
/*0x2F8*/             ULONG32      AccountingFolded : 1;
/*0x2F8*/             ULONG32      NewProcessReported : 1;
/*0x2F8*/             ULONG32      ExitProcessReported : 1;
/*0x2F8*/             ULONG32      ReportCommitChanges : 1;
/*0x2F8*/             ULONG32      LastReportMemory : 1;
/*0x2F8*/             ULONG32      ForceWakeCharge : 1;
/*0x2F8*/             ULONG32      CrossSessionCreate : 1;
/*0x2F8*/             ULONG32      NeedsHandleRundown : 1;
/*0x2F8*/             ULONG32      RefTraceEnabled : 1;
/*0x2F8*/             ULONG32      DisableDynamicCode : 1;
/*0x2F8*/             ULONG32      EmptyJobEvaluated : 1;
/*0x2F8*/             ULONG32      DefaultPagePriority : 3;
/*0x2F8*/             ULONG32      PrimaryTokenFrozen : 1;
/*0x2F8*/             ULONG32      ProcessVerifierTarget : 1;
/*0x2F8*/             ULONG32      StackRandomizationDisabled : 1;
/*0x2F8*/             ULONG32      AffinityPermanent : 1;
/*0x2F8*/             ULONG32      AffinityUpdateEnable : 1;
/*0x2F8*/             ULONG32      PropagateNode : 1;
/*0x2F8*/             ULONG32      ExplicitAffinity : 1;
/*0x2F8*/             ULONG32      ProcessExecutionState : 2;
/*0x2F8*/             ULONG32      DisallowStrippedImages : 1;
/*0x2F8*/             ULONG32      HighEntropyASLREnabled : 1;
/*0x2F8*/             ULONG32      ExtensionPointDisable : 1;
/*0x2F8*/             ULONG32      ForceRelocateImages : 1;
/*0x2F8*/             ULONG32      ProcessStateChangeRequest : 2;
/*0x2F8*/             ULONG32      ProcessStateChangeInProgress : 1;
/*0x2F8*/             ULONG32      DisallowWin32kSystemCalls : 1;
                  };
              };
              union
              {
/*0x2FC*/         ULONG32      Flags;
                  struct
                  {
/*0x2FC*/             ULONG32      CreateReported : 1;
/*0x2FC*/             ULONG32      NoDebugInherit : 1;
/*0x2FC*/             ULONG32      ProcessExiting : 1;
/*0x2FC*/             ULONG32      ProcessDelete : 1;
/*0x2FC*/             ULONG32      ControlFlowGuardEnabled : 1;
/*0x2FC*/             ULONG32      VmDeleted : 1;
/*0x2FC*/             ULONG32      OutswapEnabled : 1;
/*0x2FC*/             ULONG32      Outswapped : 1;
/*0x2FC*/             ULONG32      ForkFailed : 1;
/*0x2FC*/             ULONG32      Wow64VaSpace4Gb : 1;
/*0x2FC*/             ULONG32      AddressSpaceInitialized : 2;
/*0x2FC*/             ULONG32      SetTimerResolution : 1;
/*0x2FC*/             ULONG32      BreakOnTermination : 1;
/*0x2FC*/             ULONG32      DeprioritizeViews : 1;
/*0x2FC*/             ULONG32      WriteWatch : 1;
/*0x2FC*/             ULONG32      ProcessInSession : 1;
/*0x2FC*/             ULONG32      OverrideAddressSpace : 1;
/*0x2FC*/             ULONG32      HasAddressSpace : 1;
/*0x2FC*/             ULONG32      LaunchPrefetched : 1;
/*0x2FC*/             ULONG32      Background : 1;
/*0x2FC*/             ULONG32      VmTopDown : 1;
/*0x2FC*/             ULONG32      ImageNotifyDone : 1;
/*0x2FC*/             ULONG32      PdeUpdateNeeded : 1;
/*0x2FC*/             ULONG32      VdmAllowed : 1;
/*0x2FC*/             ULONG32      ProcessRundown : 1;
/*0x2FC*/             ULONG32      ProcessInserted : 1;
/*0x2FC*/             ULONG32      DefaultIoPriority : 3;
/*0x2FC*/             ULONG32      ProcessSelfDelete : 1;
/*0x2FC*/             ULONG32      SetTimerResolutionLink : 1;
                  };
              };
/*0x300*/     UINT64       ProcessQuotaUsage[2];                    // 指一个进程的内存使用量和尖峰使用量.
/*0x310*/     UINT64       ProcessQuotaPeak[2];                     // 指一个进程的尖峰使用量.
                                                                    // 这两个域是数组, 其中的元素分别对应于非换页内存池, 换页内存池和交换文件中的内存使用情况.
                                                                    // 这两个数组是在 PspChargeQuota 函数中计算的

/*0x320*/     UINT64       PeakVirtualSize;                         // 虚拟内存大小的尖峰值
/*0x328*/     UINT64       VirtualSize;                             // 进程的虚拟内存大小
/*0x330*/     struct _LIST_ENTRY SessionProcessLinks;               // 会话进程链表, 当进程加入到一个系统会话中时, 其 SessionProcessLinks 域将作为一个节点加入到该会话的进程链表中
              union
              {
/*0x340*/         VOID*        ExceptionPortData;                   // 异常端口句柄, 当一个进程中的线程发生用户模式异常时,
                                                                    // 内核的异常处理例程在处理异常过程中, 将向该进程的异常端口或调试端口发送消息,
                                                                    // 从而使这些端口的接收方 (调试器或 Windows 子系统) 能够处理该异常
/*0x340*/         UINT64       ExceptionPortValue;
/*0x340*/         UINT64       ExceptionPortState : 3;
              };
/*0x348*/     struct _EX_FAST_REF Token;                            // 快速引用, 指向该进程的访问令牌, 用于该进程的安全访问检查
/*0x350*/     UINT64       WorkingSetPage;                          // 包含进程工作集的页面
/*0x358*/     struct _EX_PUSH_LOCK AddressCreationLock;             // 当内核代码需要对虚拟地址空间进行操作时, 它必须在 AddressCreationLock 上执行锁操作, 完成以后再解锁
/*0x360*/     struct _EX_PUSH_LOCK PageTableCommitmentLock;         //
/*0x368*/     struct _ETHREAD* RotateInProgress;
/*0x370*/     struct _ETHREAD* ForkInProgress;                      // 正在复制地址空间的那个线程, 仅当在地址空间复制过程中, 此域才会被赋值, 在其他情况下为 NULL
/*0x378*/     struct _EJOB* CommitChargeJob;                        //
/*0x380*/     struct _RTL_AVL_TREE CloneRoot;                       // 指向一个平衡树的根, 当进程地址空间复制时, 此树被创建, 创建出来以后, 一直到进程退出的时候才被销毁. 完全是为了支持 fork 语义而引入
/*0x388*/     UINT64       NumberOfPrivatePages;                    // 进程私有页面的数量
/*0x390*/     UINT64       NumberOfLockedPages;                     // 被锁住页面的数量
/*0x398*/     VOID*        Win32Process;                            // Win32k 进程结构体, 仅 GUI 进程有效
/*0x3A0*/     struct _EJOB* Job;                                    // 只有当一个进程属于一个 Job (作业) 的时候, 它才会指向一个_EJOB 对象
/*0x3A8*/     VOID*        SectionObject;                           // 为可执行程序映像创建的文件映射区对象
/*0x3B0*/     VOID*        SectionBaseAddress;                      // 映射区对象基址
/*0x3B8*/     ULONG32      Cookie;                                  // 存放的是一个代表该进程的随机值, 当第一次通过 NtQueryInformationProcess 函数获取此 Cookie 值的时候, 系统会生成一个随机值, 以后就用该值代表此进程
/*0x3BC*/     UINT8        _PADDING0_[0x4];
/*0x3C0*/     struct _PAGEFAULT_HISTORY* WorkingSetWatch;           // 用于监视一个进程的页面错误, 一旦启用了页面错误监视功能 (由全局变量PsWatchEnabled 开关来控制),
                                                                    // 则每次发生页面错误都会将该页面错误记录到 WorkingSetWatch 域的WatchInfo 成员数组中,
                                                                    // 直至数组满为止 (参见 PsWatchWorkingSet 函数的代码)
/*0x3C8*/     VOID*        Win32WindowStation;                      // 一个进程所属的窗口站的句柄. 由于句柄的值是由每个进程的句柄表来决定的,
                                                                    // 所以两个进程即使同属于一个窗口站, 它们的 Win32WindowStation 值也可能不同, 但指向的窗口站对象是相同的.
                                                                    // 窗口站是由 Windows 子系统来管理和控制的
/*0x3D0*/     VOID*        InheritedFromUniqueProcessId;            // 父进程id
/*0x3D8*/     VOID*        LdtInformation;                          // LDT 局部描述符表
/*0x3E0*/     UINT64       OwnerProcessId;                          //
/*0x3E8*/     struct _PEB* Peb;                                     // 进程环境块, 位于进程地址空间的内存块, 其中包含了有关进程地址空间中的堆和系统模块等信息
/*0x3F0*/     VOID*        Session;                                 // 向进程所在的系统会话, 实际上它是一个指向 MM_SESSION_SPACE 的指针, 每个进程在初始创建地址空间时会加入到当前的系统会话中
/*0x3F8*/     VOID*        AweInfo;                                 // 指向 AWEINFO 结构的指针, 其目的是支持 AWE (Address Windowing Extension, 地址窗口扩展)
/*0x400*/     struct _EPROCESS_QUOTA_BLOCK* QuotaBlock;             // 配额块
                                                                    // Windows 系统中的配额块相互串起来构成了一个双链表, 每个配额块都可以被多个进程共享,                                // 所以有一个引用计数值用来说明当前有多少个进程在使用这一配额块.
                                                                    // 配额块中主要定义了非换页内存池, 换页内存池和交换文件中的内存配额限制.
                                                                    // 系统的默认配额块为 PspDefaultQuotaBlock, 所有配额块构成的双链表的表头为 PspQuotaBlockList
/*0x408*/     struct _HANDLE_TABLE* ObjectTable;                    // 进程句柄表
/*0x410*/     VOID*        DebugPort;                               // 调试端口
/*0x418*/     VOID*        Wow64Process;                            // Wow64Process 指向 32 位的 PEB32 的指针. 在 Wow64 程序中, 进程有两个 PEB, 一个是 64 位的, 一个是 32 位的.
/*0x420*/     VOID*        DeviceMap;                               // 指向进程使用的设备表, 通常情况下同一个会话中的进程共享同样的设备表
/*0x428*/     VOID*        EtwDataSource;
/*0x430*/     UINT64       PageDirectoryPte;                        // 顶级页目录页面的页表项
/*0x438*/     UINT8        ImageFileName[15];                       // 进程的映像文件名, 仅包含最后一个路径分隔符之后的字符串, 不超过 16 个字符 (含最后的结尾空字符)
/*0x447*/     UINT8        PriorityClass;                           // 进程优先级类别, 在 WRK 中包含以下类别:
                                                                    // 0: 未知, 1: 空闲, 2: 普通, 3: 高, 4: 实时, 5: 普通之下, 6: 普通之上
/*0x448*/     VOID*        SecurityPort;                            // 安全端口, 指向该进程与 lsass 进程之间的跨进程通信端口
/*0x450*/     struct _SE_AUDIT_PROCESS_CREATION_INFO SeAuditProcessCreationInfo; // 包含了创建进程时指定的进程映像全路径名
/*0x458*/     struct _LIST_ENTRY JobLinks;                          // 通过此节点, 一个 Job 中的所有进程构成了一个链表. 在 Windows 中, 所有的 Job 构成了一个双链表, 其链表头为全局变量 PspJobList; 每个 Job 中的进程又构成了一个双链表。
/*0x468*/     VOID*        HighestUserAddress;                      // 最高用户空间地址
/*0x470*/     struct _LIST_ENTRY ThreadListHead;                    // 双链表的头节点, 该链表包含了一个进程中的所有线程.
                                                                    // KPROCESS 结构中也有一个 ThreadListHead 域, 它所指的链表包含了各个子线程的 KTHREAD 结构中的 ThreadListEntry 节点
/*0x480*/     ULONG32      ActiveThreads;                           // 记录了当前进程有多少个活动线程. 当该值减为0 时, 所有的线程都将退出, 于是进程也退出
/*0x484*/     ULONG32      ImagePathHash;
/*0x488*/     ULONG32      DefaultHardErrorProcessing;              // 指定了默认的硬件错误处理
/*0x48C*/     LONG32       LastThreadExitStatus;                    // 最后一个线程的退出状态
/*0x490*/     struct _EX_FAST_REF PrefetchTrace;                    // 指向与该进程关联的一个预取痕迹结构, 以支持该进程的预取
/*0x498*/     VOID*        LockedPagesList;                         // 一个指向LOCK_HEADER 结构的指针, 该结构包含了一个链表头, Windows 通过此链表来记录哪些页面已被锁住.
                                                                    // base\ntos\mm\iosup.c 中有一组函数用于管理此链表, 例如 MiAddMdlTracker, MiFreeMdlTracker 和 MiUpdateMdlTracker 等
/*0x4A0*/     union _LARGE_INTEGER ReadOperationCount;              // 记录了当前进程 NtReadFile  系统服务被调用的次数
/*0x4A8*/     union _LARGE_INTEGER WriteOperationCount;             // 记录了当前进程 NtWriteFile  系统服务被调用的次数
/*0x4B0*/     union _LARGE_INTEGER OtherOperationCount;             // 记录了除读和写操作以外的其他 I/O 服务的次数
/*0x4B8*/     union _LARGE_INTEGER ReadTransferCount;               // 记录了 I/O 读操作完成的次数
/*0x4C0*/     union _LARGE_INTEGER WriteTransferCount;              // 记录了 I/O 写操作完成的次数
/*0x4C8*/     union _LARGE_INTEGER OtherTransferCount;              // 记录了 I/O 非读写操作完成的次数
/*0x4D0*/     UINT64       CommitChargeLimit;                       // 已提交页面数量的限制值, 如果是0 则表示没有限制. 在WRK中, 默认的限制值为0
/*0x4D8*/     UINT64       CommitCharge;                            // 包含了一个进程的虚拟内存已提交的页面数量
/*0x4E0*/     UINT64       CommitChargePeak;                        // 尖峰时刻的已提交页面数量
/*0x4E8*/     struct _MMSUPPORT Vm;                                 // Windows 为每个进程管理虚拟内存的重要数据结构成员
/*0x5C0*/     struct _LIST_ENTRY MmProcessLinks;                    // 所有拥有自己地址空间的进程都将加入到一个双链表中, 链表头是全局变量 MmProcessList
                                                                    // 当进程地址空间被初始创建时, MmProcessLinks 节点被加入到此全局链表中
                                                                    // 当进程地址空间被销毁时, 该节点脱离此链表.
                                                                    // 此全局链表的存在使得 Windows 系统可以方便地执行一些全局的内存管理任务。
/*0x5D0*/     ULONG32      ModifiedPageCount;                       // 记录了该进程中已修改页面的数量
/*0x5D4*/     LONG32       ExitStatus;                              // 进程的退出状态
/*0x5D8*/     struct _RTL_AVL_TREE VadRoot;                         // 指向一个平衡二叉树的根, 用于管理该进程的虚拟地址空间
/*0x5E0*/     VOID*        VadHint;
/*0x5E8*/     UINT64       VadCount;
/*0x5F0*/     UINT64       VadPhysicalPages;
/*0x5F8*/     UINT64       VadPhysicalPagesLimit;
/*0x600*/     struct _ALPC_PROCESS_CONTEXT AlpcContext;
/*0x620*/     struct _LIST_ENTRY TimerResolutionLink;
/*0x630*/     struct _PO_DIAG_STACK_RECORD* TimerResolutionStackRecord;
/*0x638*/     ULONG32      RequestedTimerResolution;
/*0x63C*/     ULONG32      SmallestTimerResolution;
/*0x640*/     union _LARGE_INTEGER ExitTime;                        // 进程退出时间
/*0x648*/     struct _INVERTED_FUNCTION_TABLE* InvertedFunctionTable;
/*0x650*/     struct _EX_PUSH_LOCK InvertedFunctionTableLock;
/*0x658*/     ULONG32      ActiveThreadsHighWatermark;
/*0x65C*/     ULONG32      LargePrivateVadCount;
/*0x660*/     struct _EX_PUSH_LOCK ThreadListLock;
/*0x668*/     VOID*        WnfContext;
/*0x670*/     UINT64       Spare0;
/*0x678*/     UINT8        SignatureLevel;
/*0x679*/     UINT8        SectionSignatureLevel;
/*0x67A*/     struct _PS_PROTECTION Protection;
/*0x67B*/     UINT8        SpareByte20[1];
              union
              {
/*0x67C*/         ULONG32      Flags3;
/*0x67C*/         ULONG32      Minimal : 1;
              };
/*0x680*/     LONG32       SvmReserved;
/*0x684*/     UINT8        _PADDING1_[0x4];
/*0x688*/     VOID*        SvmReserved1;
/*0x690*/     UINT64       SvmReserved2;
/*0x698*/     UINT64       LastFreezeInterruptTime;
/*0x6A0*/     struct _PROCESS_DISK_COUNTERS* DiskCounters;
/*0x6A8*/     VOID*        PicoContext;
/*0x6B0*/     ULONG32      KeepAliveCounter;
/*0x6B4*/     ULONG32      NoWakeKeepAliveCounter;
          }EPROCESS, *PEPROCESS;