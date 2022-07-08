/*Windows 8.1 x64 Checked Build*/
           typedef struct _TEB                                                  // 112 elements, 0x1820 bytes (sizeof)
           {
/*0x000*/      struct _NT_TIB NtTib;                                            // 线程信息块, TIB 第一个字段是 ExceptionList, 在应用软件的异常处理起着关键作用
/*0x038*/      VOID*        EnvironmentPointer;
/*0x040*/      struct _CLIENT_ID ClientId;                                      // 客户id, 包含进程 id 和线程 id
/*0x050*/      VOID*        ActiveRpcHandle;                                    // 活动的 RPC 句柄
/*0x058*/      VOID*        ThreadLocalStoragePointer;                          // TLS 数组
/*0x060*/      struct _PEB* ProcessEnvironmentBlock;                            // PEB 指针
/*0x068*/      ULONG32      LastErrorValue;                                     // LastError (GetLastError 从这里获取)
/*0x06C*/      ULONG32      CountOfOwnedCriticalSections;                       // 所拥有的临界区计数
/*0x070*/      VOID*        CsrClientThread;
/*0x078*/      VOID*        Win32ThreadInfo;
/*0x080*/      ULONG32      User32Reserved[26];
/*0x0E8*/      ULONG32      UserReserved[5];
/*0x0FC*/      UINT8        _PADDING0_[0x4];
/*0x100*/      VOID*        WOW32Reserved;
/*0x108*/      ULONG32      CurrentLocale;                                      // 当前地区
/*0x10C*/      ULONG32      FpSoftwareStatusRegister;
/*0x110*/      VOID*        SystemReserved1[54];
/*0x2C0*/      LONG32       ExceptionCode;                                      // 异常代码
/*0x2C4*/      UINT8        Padding0[4];
/*0x2C8*/      struct _ACTIVATION_CONTEXT_STACK* ActivationContextStackPointer;
/*0x2D0*/      UINT8        SpareBytes[24];
/*0x2E8*/      ULONG32      TxFsContext;
/*0x2EC*/      UINT8        Padding1[4];
/*0x2F0*/      struct _GDI_TEB_BATCH GdiTebBatch;
/*0x7D8*/      struct _CLIENT_ID RealClientId;
/*0x7E8*/      VOID*        GdiCachedProcessHandle;
/*0x7F0*/      ULONG32      GdiClientPID;
/*0x7F4*/      ULONG32      GdiClientTID;
/*0x7F8*/      VOID*        GdiThreadLocalInfo;
/*0x800*/      UINT64       Win32ClientInfo[62];
/*0x9F0*/      VOID*        glDispatchTable[233];
/*0x1138*/     UINT64       glReserved1[29];
/*0x1220*/     VOID*        glReserved2;
/*0x1228*/     VOID*        glSectionInfo;
/*0x1230*/     VOID*        glSection;
/*0x1238*/     VOID*        glTable;
/*0x1240*/     VOID*        glCurrentRC;
/*0x1248*/     VOID*        glContext;
/*0x1250*/     ULONG32      LastStatusValue;
/*0x1254*/     UINT8        Padding2[4];
/*0x1258*/     struct _UNICODE_STRING StaticUnicodeString;
/*0x1268*/     WCHAR        StaticUnicodeBuffer[261];
/*0x1472*/     UINT8        Padding3[6];
/*0x1478*/     VOID*        DeallocationStack;
/*0x1480*/     VOID*        TlsSlots[64];
/*0x1680*/     struct _LIST_ENTRY TlsLinks;
/*0x1690*/     VOID*        Vdm;
/*0x1698*/     VOID*        ReservedForNtRpc;
/*0x16A0*/     VOID*        DbgSsReserved[2];
/*0x16B0*/     ULONG32      HardErrorMode;
/*0x16B4*/     UINT8        Padding4[4];
/*0x16B8*/     VOID*        Instrumentation[11];
/*0x1710*/     struct _GUID ActivityId;
/*0x1720*/     VOID*        SubProcessTag;
/*0x1728*/     VOID*        PerflibData;
/*0x1730*/     VOID*        EtwTraceData;
/*0x1738*/     VOID*        WinSockData;                                        // Winsock 数据
/*0x1740*/     ULONG32      GdiBatchCount;
               union
               {
/*0x1744*/         struct _PROCESSOR_NUMBER CurrentIdealProcessor;
/*0x1744*/         ULONG32      IdealProcessorValue;
                   struct
                   {
/*0x1744*/             UINT8        ReservedPad0;
/*0x1745*/             UINT8        ReservedPad1;
/*0x1746*/             UINT8        ReservedPad2;
/*0x1747*/             UINT8        IdealProcessor;
                   };
               };
/*0x1748*/     ULONG32      GuaranteedStackBytes;
/*0x174C*/     UINT8        Padding5[4];
/*0x1750*/     VOID*        ReservedForPerf;
/*0x1758*/     VOID*        ReservedForOle;
/*0x1760*/     ULONG32      WaitingOnLoaderLock;
/*0x1764*/     UINT8        Padding6[4];
/*0x1768*/     VOID*        SavedPriorityState;
/*0x1770*/     UINT64       ReservedForCodeCoverage;
/*0x1778*/     VOID*        ThreadPoolData;
/*0x1780*/     VOID**       TlsExpansionSlots;
/*0x1788*/     VOID*        DeallocationBStore;
/*0x1790*/     VOID*        BStoreLimit;
/*0x1798*/     ULONG32      MuiGeneration;
/*0x179C*/     ULONG32      IsImpersonating;
/*0x17A0*/     VOID*        NlsCache;
/*0x17A8*/     VOID*        pShimData;
/*0x17B0*/     UINT16       HeapVirtualAffinity;
/*0x17B2*/     UINT16       LowFragHeapDataSlot;
/*0x17B4*/     UINT8        Padding7[4];
/*0x17B8*/     VOID*        CurrentTransactionHandle;
/*0x17C0*/     struct _TEB_ACTIVE_FRAME* ActiveFrame;
/*0x17C8*/     VOID*        FlsData;
/*0x17D0*/     VOID*        PreferredLanguages;
/*0x17D8*/     VOID*        UserPrefLanguages;
/*0x17E0*/     VOID*        MergedPrefLanguages;
/*0x17E8*/     ULONG32      MuiImpersonation;
               union
               {
/*0x17EC*/         UINT16       CrossTebFlags;
/*0x17EC*/         UINT16       SpareCrossTebBits : 16;
               };
               union
               {
/*0x17EE*/         UINT16       SameTebFlags;
                   struct
                   {
/*0x17EE*/             UINT16       SafeThunkCall : 1;
/*0x17EE*/             UINT16       InDebugPrint : 1;
/*0x17EE*/             UINT16       HasFiberData : 1;
/*0x17EE*/             UINT16       SkipThreadAttach : 1;
/*0x17EE*/             UINT16       WerInShipAssertCode : 1;
/*0x17EE*/             UINT16       RanProcessInit : 1;
/*0x17EE*/             UINT16       ClonedThread : 1;
/*0x17EE*/             UINT16       SuppressDebugMsg : 1;
/*0x17EE*/             UINT16       DisableUserStackWalk : 1;
/*0x17EE*/             UINT16       RtlExceptionAttached : 1;
/*0x17EE*/             UINT16       InitialThread : 1;
/*0x17EE*/             UINT16       SessionAware : 1;
/*0x17EE*/             UINT16       SpareSameTebBits : 4;
                   };
               };
/*0x17F0*/     VOID*        TxnScopeEnterCallback;
/*0x17F8*/     VOID*        TxnScopeExitCallback;
/*0x1800*/     VOID*        TxnScopeContext;
/*0x1808*/     ULONG32      LockCount;
/*0x180C*/     ULONG32      SpareUlong0;
/*0x1810*/     VOID*        ResourceRetValue;
/*0x1818*/     VOID*        ReservedForWdf;
           }TEB, *PTEB;
