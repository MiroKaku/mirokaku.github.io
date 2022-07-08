/*Windows 8.1 x64 Checked Build*/
          typedef struct _PEB                                               // 102 elements, 0x388 bytes (sizeof)
          {
/*0x000*/     UINT8        InheritedAddressSpace;
/*0x001*/     UINT8        ReadImageFileExecOptions;
/*0x002*/     UINT8        BeingDebugged;                                   // 进程是否被调试
              union
              {
/*0x003*/         UINT8        BitField;
                  struct
                  {
/*0x003*/             UINT8        ImageUsesLargePages : 1;
/*0x003*/             UINT8        IsProtectedProcess : 1;
/*0x003*/             UINT8        IsImageDynamicallyRelocated : 1;
/*0x003*/             UINT8        SkipPatchingUser32Forwarders : 1;
/*0x003*/             UINT8        IsPackagedProcess : 1;
/*0x003*/             UINT8        IsAppContainer : 1;
/*0x003*/             UINT8        IsProtectedProcessLight : 1;
/*0x003*/             UINT8        SpareBits : 1;
                  };
              };
/*0x004*/     UINT8        Padding0[4];
/*0x008*/     VOID*        Mutant;
/*0x010*/     VOID*        ImageBaseAddress;                                // 进程映像基址
/*0x018*/     struct _PEB_LDR_DATA* Ldr;                                    // 由 PELoader 填充, 包含很多 PE 中包含的信息, 一般用来Ring3枚举加载的模块
/*0x020*/     struct _RTL_USER_PROCESS_PARAMETERS* ProcessParameters;       // 指向参数块, 包含有环境变量和当前目录等..在打开文件的时候, 如果给定的只是相对路径名, 那么就会以里面的 CurrentDirectory 为起点, 形成绝对路径.
/*0x028*/     VOID*        SubSystemData;
/*0x030*/     VOID*        ProcessHeap;                                     // 指向进程堆首地址, 每个程序新建时默认堆使用
/*0x038*/     struct _RTL_CRITICAL_SECTION* FastPebLock;                    // PEB 锁
/*0x040*/     VOID*        AtlThunkSListPtr;
/*0x048*/     VOID*        IFEOKey;
              union
              {
/*0x050*/         ULONG32      CrossProcessFlags;
                  struct
                  {
/*0x050*/             ULONG32      ProcessInJob : 1;
/*0x050*/             ULONG32      ProcessInitializing : 1;
/*0x050*/             ULONG32      ProcessUsingVEH : 1;
/*0x050*/             ULONG32      ProcessUsingVCH : 1;
/*0x050*/             ULONG32      ProcessUsingFTH : 1;
/*0x050*/             ULONG32      ReservedBits0 : 27;
                  };
              };
/*0x054*/     UINT8        Padding1[4];
              union
              {
/*0x058*/         VOID*        KernelCallbackTable;                         // 从内核“回调”用户空间的函数表
/*0x058*/         VOID*        UserSharedInfoPtr;
              };
/*0x060*/     ULONG32      SystemReserved[1];
/*0x064*/     ULONG32      AtlThunkSListPtr32;
/*0x068*/     VOID*        ApiSetMap;
/*0x070*/     ULONG32      TlsExpansionCounter;
/*0x074*/     UINT8        Padding2[4];
/*0x078*/     VOID*        TlsBitmap;                                       // 代表TLS位图
/*0x080*/     ULONG32      TlsBitmapBits[2];
/*0x088*/     VOID*        ReadOnlySharedMemoryBase;
/*0x090*/     VOID*        SparePvoid0;
/*0x098*/     VOID**       ReadOnlyStaticServerData;
/*0x0A0*/     VOID*        AnsiCodePageData;                                // 这三个好像是 Nls 表
/*0x0A8*/     VOID*        OemCodePageData;
/*0x0B0*/     VOID*        UnicodeCaseTableData;
/*0x0B8*/     ULONG32      NumberOfProcessors;                              // 处理器/核心 数量
/*0x0BC*/     ULONG32      NtGlobalFlag;                                    // Nt 全局标记, 开启调试时, 会包含值 0x70, 具体定义在 WRK-v1.2\public\sdk\inc\ntexapi.h 的 2657 行
/*0x0C0*/     union _LARGE_INTEGER CriticalSectionTimeout;
/*0x0C8*/     UINT64       HeapSegmentReserve;                              // 堆的默认保留大小
/*0x0D0*/     UINT64       HeapSegmentCommit;                               // 堆的默认提交大小
/*0x0D8*/     UINT64       HeapDeCommitTotalFreeThreshold;                  // 解除提交的总空闲块阈值
/*0x0E0*/     UINT64       HeapDeCommitFreeBlockThreshold;                  // 解除提交的单块阈值
/*0x0E8*/     ULONG32      NumberOfHeaps;                                   // 进程堆的数量
/*0x0EC*/     ULONG32      MaximumNumberOfHeaps;                            // ProcessHeaps 数组目前的大小
/*0x0F0*/     VOID**       ProcessHeaps;                                    // 一个数组, 记录了每一个堆的地址
/*0x0F8*/     VOID*        GdiSharedHandleTable;
/*0x100*/     VOID*        ProcessStarterHelper;
/*0x108*/     ULONG32      GdiDCAttributeList;
/*0x10C*/     UINT8        Padding3[4];
/*0x110*/     struct _RTL_CRITICAL_SECTION* LoaderLock;
/*0x118*/     ULONG32      OSMajorVersion;                                  // 系统主版本
/*0x11C*/     ULONG32      OSMinorVersion;                                  // 系统次版本
/*0x120*/     UINT16       OSBuildNumber;                                   // 系统构建号
/*0x122*/     UINT16       OSCSDVersion;
/*0x124*/     ULONG32      OSPlatformId;                                    // 系统平台, VER_PLATFORM_WIN32_NT (2)
/*0x128*/     ULONG32      ImageSubsystem;                                  // 映像子系统, 在PE中有定义..例如, IMAGE_SUBSYSTEM_NATIVE(1), IMAGE_SUBSYSTEM_WINDOWS_GUI(2), IMAGE_SUBSYSTEM_WINDOWS_CUI(3)
/*0x12C*/     ULONG32      ImageSubsystemMajorVersion;                      // 映像子系统主版本
/*0x130*/     ULONG32      ImageSubsystemMinorVersion;                      // 映像子系统次版本
/*0x134*/     UINT8        Padding4[4];
/*0x138*/     UINT64       ActiveProcessAffinityMask;                       // 处理器亲和性掩码
/*0x140*/     ULONG32      GdiHandleBuffer[60];
/*0x230*/     FUNCT_00BC_028C_PostProcessInitRoutine_DispatchAddress_FinishRoutine* PostProcessInitRoutine;
/*0x238*/     VOID*        TlsExpansionBitmap;
/*0x240*/     ULONG32      TlsExpansionBitmapBits[32];
/*0x2C0*/     ULONG32      SessionId;                                       // 会话id
/*0x2C4*/     UINT8        Padding5[4];
/*0x2C8*/     union _ULARGE_INTEGER AppCompatFlags;                         // 下面这4个是应用程序兼容性相关字段
/*0x2D0*/     union _ULARGE_INTEGER AppCompatFlagsUser;
/*0x2D8*/     VOID*        pShimData;
/*0x2E0*/     VOID*        AppCompatInfo;
/*0x2E8*/     struct _UNICODE_STRING CSDVersion;                            // 字符串, 例如 Service Pack 3
/*0x2F8*/     struct _ACTIVATION_CONTEXT_DATA* ActivationContextData;
/*0x300*/     struct _ASSEMBLY_STORAGE_MAP* ProcessAssemblyStorageMap;
/*0x308*/     struct _ACTIVATION_CONTEXT_DATA* SystemDefaultActivationContextData;
/*0x310*/     struct _ASSEMBLY_STORAGE_MAP* SystemAssemblyStorageMap;
/*0x318*/     UINT64       MinimumStackCommit;
/*0x320*/     struct _FLS_CALLBACK_INFO* FlsCallback;                       // 纤程回调?
/*0x328*/     struct _LIST_ENTRY FlsListHead;
/*0x338*/     VOID*        FlsBitmap;                                       // 纤程位图?
/*0x340*/     ULONG32      FlsBitmapBits[4];
/*0x350*/     ULONG32      FlsHighIndex;
/*0x354*/     UINT8        _PADDING0_[0x4];
/*0x358*/     VOID*        WerRegistrationData;
/*0x360*/     VOID*        WerShipAssertPtr;
/*0x368*/     VOID*        pUnused;
/*0x370*/     VOID*        pImageHeaderHash;
              union
              {
/*0x378*/         ULONG32      TracingFlags;
                  struct
                  {
/*0x378*/             ULONG32      HeapTracingEnabled : 1;
/*0x378*/             ULONG32      CritSecTracingEnabled : 1;
/*0x378*/             ULONG32      LibLoaderTracingEnabled : 1;
/*0x378*/             ULONG32      SpareTracingBits : 29;
                  };
              };
/*0x37C*/     UINT8        Padding6[4];
/*0x380*/     UINT64       CsrServerReadOnlySharedMemoryBase;
          }PEB, *PPEB;