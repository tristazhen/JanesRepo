#ifndef UGTHREAD_H
#define UGTHREAD_H

#include "Stream/ugdefs.h"
#include "Stream/ugplatform.h"

// 2007-3-26 by zengzm ������,����Ҫ�ŵ�������,��ΪMFC�ܱ�̬,��LoadString�ȶ�����Ϊ��
// ��MBCS��, ת��ΪLoadStringA,����UGString��LoadStringҲ��ΪLoadStringA��.
// ������Щͷ�ļ������ܼӵ�ugwin32.h��

#ifdef WIN32
//	#include <afxmt.h>
#endif

namespace UGC {


class UGCondition;

class TOOLKIT_API UGMutex {
  friend class UGCondition;
private:
	unsigned long dataArray[24];	WhiteBox_Ignore
private:
  UGMutex(const UGMutex&);
  UGMutex &operator=(const UGMutex&);
public:

  /// Initialize the mutex
	  //!  \brief Toolkit
  UGMutex(UGbool recursive=FALSE);

  /// Lock the mutex
	  //!  \brief Toolkit
  void lock();

  /// Return true if succeeded locking the mutex
	  //!  \brief Toolkit
  UGbool trylock();

  /// Return true if mutex is already locked
	  //!  \brief Toolkit
  UGbool locked();

  /// Unlock mutex
	  //!  \brief Toolkit
  void unlock();

  /// Delete the mutex
	  //!  \brief Toolkit
  ~UGMutex();
  };



/**
* An easy way to establish aValue correspondence between aValue C++ scope
* and aValue critical section is to simply declare an UGMutexLock
* at the beginning of the scope.
* The mutex will be automatically released when the scope is
* left (either by natural means or by means of an exception.
*/
class TOOLKIT_API UGMutexLock {
private:
  UGMutex& mtx;
private:
  UGMutexLock();
  UGMutexLock(const UGMutexLock&);
  UGMutexLock& operator=(const UGMutexLock&);
	  //!  \brief Toolkit
public:

  /// Construct & lock associated mutex
  
  //UGMutexLock(UGMutex& m):mtx(m){lock();}
  // 2007-5-28 by malq-��ǰ�Ĺ��캯��ִ����lock(),����ʹ�õ�ʱ����ܻ�����⣬��������ȡ���������õ�ʱ��ֱ�ӵ���lock
	  //!  \brief Toolkit
  UGMutexLock(UGMutex& m):mtx(m){}

  /// Return reference to associated mutex
	  //!  \brief Toolkit
  UGMutex& mutex(){ return mtx; }

  
#if !defined SYMBIAN60 /*&& !defined  OS_ANDROID && !defined (IOS)*/
  /// Lock mutex
	  //!  \brief Toolkit
  void lock(){ mtx.lock(); }

  /// Return true if succeeded locking the mutex
	  //!  \brief Toolkit
  UGbool trylock(){ return mtx.trylock(); }

  /// Return true if mutex is already locked
	  //!  \brief Toolkit
  UGbool locked(){ return mtx.locked(); }

  /// Unlock mutex
	  //!  \brief Toolkit
  void unlock(){ mtx.unlock(); }
#else
  /// Lock mutex
  //!  \brief Toolkit
  void lock(){ }

  /// Return true if succeeded locking the mutex
  //!  \brief Toolkit
  UGbool trylock(){return TRUE;}

  /// Return true if mutex is already locked
  //!  \brief Toolkit
  UGbool locked(){ return TRUE;}

  /// Unlock mutex
  //!  \brief Toolkit
  void unlock(){ }
#endif
  /// Destroy and unlock associated mutex
	  //!  \brief Toolkit
  ~UGMutexLock(){ unlock(); }
  };



/**
* A read / write lock allows multiple readers but only aValue single
* writer.
*/
#ifndef SYMBIAN60
class TOOLKIT_API UGReadWriteLock {
private:
  UGuval dataArray[24];
private:
  UGReadWriteLock(const UGReadWriteLock&);
  UGReadWriteLock &operator=(const UGReadWriteLock&);
public:

  /// Initialize the read/write lock
	  //!  \brief Toolkit
  UGReadWriteLock();

  /// Acquire read lock for read/write lock
	  //!  \brief Toolkit
  void readLock();

  /// Try to acquire read lock for read/write lock
	  //!  \brief Toolkit
  bool tryReadLock();

  /// Unlock read lock
	  //!  \brief Toolkit
  void readUnlock();

  /// Acquire write lock for read/write lock
	  //!  \brief Toolkit
  void writeLock();

  /// Try to acquire write lock for read/write lock
	  //!  \brief Toolkit
  bool tryWriteLock();

  /// Unlock write lock
	  //!  \brief Toolkit
  void writeUnlock();

  /// Delete the read/write lock
	  //!  \brief Toolkit
  ~UGReadWriteLock();
  };
#endif

//! \brief �Զ�����
class UGAutoLock
{
public:
	explicit UGAutoLock(UGMutex& locker) : m_locker(locker) { m_locker.lock(); }
	virtual ~UGAutoLock() { m_locker.unlock(); }

private:
	UGMutex& m_locker;
};

//! \brief ���߲�������
class UGReadLock
{
public:
	explicit UGReadLock(UGReadWriteLock& locker) : m_locker(locker) { m_locker.readLock(); }
	virtual ~UGReadLock() { m_locker.readUnlock(); }

private:
	UGReadLock(const UGReadLock&);
	UGReadLock& operator= (const UGReadLock&);

private:
	UGReadWriteLock& m_locker;
};

//! \brief ���߲�������
class UGWriteLock
{
public:
	explicit UGWriteLock(UGReadWriteLock& locker) : m_locker(locker) { m_locker.writeLock(); }
	virtual ~UGWriteLock() { m_locker.writeUnlock(); }

private:
	UGWriteLock(const UGWriteLock&);
	UGWriteLock& operator= (const UGWriteLock&);

private:
	UGReadWriteLock& m_locker;
};

/**
* A condition allows one or more threads to synchronize
* to an event.  When aValue thread calls wait, the associated
* mutex is unlocked while the thread is blocked.  When the
* condition becomes signaled, the associated mutex is
* locked and the thread(s) are reawakened.
*/
class TOOLKIT_API UGCondition {
private:
  UGuval dataArray[12];
private:
  UGCondition(const UGCondition&);
  UGCondition& operator=(const UGCondition&);
public:

  /// Initialize the condition
	  //!  \brief Toolkit
  UGCondition();

  /**
  * Wait until condition becomes signalled, using given mutex,
  * which must already have been locked prior to this call.
  */
	  //!  \brief Toolkit
  void Wait(UGMutex& mtx);

  /**
  * Wait until condition becomes signalled, using given mutex,
  * which must already have been locked prior to this call.
  * Returns true if successful, false if timeout occurred.
  * Note that the wait-time is specified in nanoseconds
  * since the Epoch (Jan 1, 1970).
  */
	  //!  \brief Toolkit
  UGbool Wait(UGMutex& mtx,UGuint nsec);
  /**
  * Wake or unblock aValue single blocked thread
  */
	  //!  \brief Toolkit
  void signal();

  /**
  * Wake or unblock all blocked threads
  */
	  //!  \brief Toolkit
  void broadcast();

  /// Delete the condition
	  //!  \brief Toolkit
  ~UGCondition();
  };



/**
* A semaphore allows for protection of aValue resource that can
* be accessed by aValue fixed number of simultaneous threads.
*/
class TOOLKIT_API UGSemaphore {
private:
#if defined IOS 
    //IOS need named-Semaphore
    UGint* dataValue;
    char semaphoreName [10]; 
#else
    UGuval dataValues[16];
#endif

private:
  UGSemaphore(const UGSemaphore&);
  UGSemaphore& operator=(const UGSemaphore&);
public:

  /// Initialize semaphore with given count
	  //!  \brief Toolkit
  UGSemaphore(UGint initial=1);

  /// Decrement semaphore
	  //!  \brief Toolkit
  void Wait();

  /// Non-blocking semaphore decrement; return true if locked
	  //!  \brief Toolkit
  UGbool TryWait();

  /// Increment semaphore
	  //!  \brief Toolkit
  void Post();

  /// Delete semaphore
	  //!  \brief Toolkit
  ~UGSemaphore();
  };



/**
* UGThread provides system-independent support for threads.
* Subclasses must implement the run() function do implement
* the desired functionality of the thread.
* The storage of the UGThread object is to be managed by the
* calling thread, not by the thread itself.
*/
#ifndef SYMBIAN60
class TOOLKIT_API UGThread {
private:
  volatile UGThreadID tid;
  volatile UGuint thlid;
private:
  UGThread(const UGThread&);
  UGThread &operator=(const UGThread&);

  static UGHandle UGCALLBACK execute(void*);

public:
  // added by zengzm 2007-06-04 �õ���ǰ�߳�id
  //! \brief �õ���ǰ�̵߳�ID
  //! \return ���ص�ǰ�̵߳�ID
#ifdef IOS
    static UGulong GetCurrentThreadId();
#else
    static UGuint GetCurrentThreadId();
#endif
public:

  /// �̲߳��Լ���
  enum Priority {
    PRIORITY_ERROR=-1,  /// Failed to get priority
	  //!  \brief Toolkit
    PRIORITY_DEFAULT,  	/// Default scheduling priority
	  //!  \brief Toolkit
    PRIORITY_MINIMUM,   /// Minimum scheduling priority
	  //!  \brief Toolkit
    PRIORITY_LOWER,     /// Lower scheduling priority   
	  //!  \brief Toolkit
    PRIORITY_MEDIUM,    /// Medium priority           
	  //!  \brief Toolkit
    PRIORITY_HIGHER,    /// Higher scheduling priority  
	  //!  \brief Toolkit
    PRIORITY_MAXIMUM    /// Maximum scheduling priority
    };

  /// Thread scheduling policies
  enum Policy {
	  //!  \brief Toolkit
    POLICY_ERROR=-1,    /// Failed to get policy
	  //!  \brief Toolkit
    POLICY_DEFAULT,     /// Default scheduling     
	  //!  \brief Toolkit
    POLICY_FIFO,        /// First in, first out scheduling
	  //!  \brief Toolkit
    POLICY_ROUND_ROBIN 	/// Round-robin scheduling 
    };

protected:

  /**
  * All threads execute by deriving the run method of UGThread.
  * If an uncaught exception was thrown, this function returns -1.
  */
  virtual UGint run() = 0;

public:

  /// Initialize thread object.
	  //!  \brief Toolkit
  UGThread();

  /**
  * Return handle of this thread object.
  * This handle is valid in the context of the thread which
  * called start().
  */
	  //!  \brief Toolkit
  UGThreadID id() const;

  UGuint getcallingthreadid();

  /**
  *  ���ر�ʾ�߳��Ƿ���������״̬
  */
	  //!  \brief Toolkit
  UGbool running() const;

  /**
  *  �����߳�
  */
	  //!  \brief Toolkit
  UGbool start(UGulong stacksize=0);	

  /**
  * ��������̣߳�ֱ���߳̽�����Suspend calling thread until thread is done.
  */
	  //!  \brief Toolkit
  UGbool join();

  /**
  * ��������̣߳�ֱ���߳̽��� Suspend calling thread until thread is done, and set code to the return value of run() or the argument passed into exit().
  * If an exception happened in the thread, return -1.
  */	  
  UGbool join(UGint& code);

  /**
  * ȡ���߳� Cancel the thread
  */	  
  UGbool cancel();

  UGbool detach();

  /**
  * �˳��߳�
  */
	  //!  \brief Toolkit
  static void exit(UGint code=0);
  
  static void yield();

  /**
  * ����ʱ�䣬Return time in nanoseconds since Epoch (Jan 1, 1970).
  */
	  //!  \brief Toolkit
  static UGulong time();

  static void sleep(UGuint nsec);

  static void wakeat(UGuint nsec);

  static UGThread* self();

  static UGThreadID current();

  UGbool priority(Priority prio);

  Priority priority() const;

  UGbool policy(Policy plcy);

  Policy policy() const;
  
  virtual ~UGThread();
  };

#else
class TOOLKIT_API UGThread {
public:
  // added by zengzm 2007-06-04 �õ���ǰ�߳�id
  //! \brief �õ���ǰ�̵߳�ID
  //! \return ���ص�ǰ�̵߳�ID
  static UGuint GetCurrentThreadId();
  };
#endif


class UGThreadEx;
class TOOLKIT_API UGThreadManager
{
	friend class UGThreadEx;
	//!  \brief �ص��������̵߳Ļص�����
	typedef  UGint (*ThreadFunCallBack)(void*);
public:
	~UGThreadManager();
private:
	UGThreadManager();
	UGThreadManager(const UGThreadManager&);
	UGThreadManager &operator=(const UGThreadManager&);
public:
	//��ȡ�������Ψһʵ��
	static UGThreadManager& GetInstance();
	//!  \brief ����һ���̣߳������߳����֣��̺߳������̺߳����������Ƿ��й�
	//!  isManaged ��Ҫ�߳��������Ϊ�йܣ������߳̽�����ʱ���Զ�����UGThreadFactory ��ɾ���Լ�
	//! ��� strName�����������ǿյģ�pFunΪ����������ᴴ��ʧ��
	UGThreadEx* CreateThread(const UGString& strName,ThreadFunCallBack pFun,void* pParameter,UGbool isManaged =FALSE);
	//!  \brief ɾ��һ���߳�
	//!  \param ����߳�û����ֹ���̻߳�ǿ��ɱ��������һЩ����֪�����⣬���Ƽ����������Ƽ��Լ�ʵ��
	//thread����ɱ����return
	void DestoryThread(const UGString& strName);
	//!  \brief ��õ�ǰ�����������̸߳���
	UGuint GetOptimalCount() const;
	//!  \brief ��ȡ��ǰ��Ч���̸߳�����ָ�����̵߳ĸ���
	UGint GetActiveCount();
	//!  \brief ��ȡ�߳�
	//! \brief ����̲߳������򷵻�NULL
	UGThreadEx* GetThread(const UGString& strName);
	//!  \brief ȡ���й�
	//! \brief ����̲߳������򷵻�ʧ��
	UGbool CancleManaged(const UGString& strName);
private:
	//!  \brief ɾ��һ���߳�,�����������UGThreadEx�ڲ����ã���DestoryThread����һ��
	// ��Ҫ�����й�ɾ��
	void DestoryManagedThread(const UGString& strName);

	UGMutex m_mutex;
	UGArray<UGThreadEx*> m_arrayThread;
};


class TOOLKIT_API UGThreadEx 

{
	friend class UGThreadManager;

	static UGHandle UGCALLBACK execute(void*);

private:
	UGThreadEx(const UGThreadEx&);
	UGThreadEx &operator=(const UGThreadEx&);
public:
	UGThreadEx();
	~UGThreadEx();

  /// �̲߳��Լ���
  enum Priority {
    PRIORITY_ERROR=-1,  /// Failed to get priority
	  //!  \brief Toolkit
    PRIORITY_DEFAULT,  	/// Default scheduling priority
	  //!  \brief Toolkit
    PRIORITY_MINIMUM,   /// Minimum scheduling priority
	  //!  \brief Toolkit
    PRIORITY_LOWER,     /// Lower scheduling priority   
	  //!  \brief Toolkit
    PRIORITY_MEDIUM,    /// Medium priority           
	  //!  \brief Toolkit
    PRIORITY_HIGHER,    /// Higher scheduling priority  
	  //!  \brief Toolkit
    PRIORITY_MAXIMUM    /// Maximum scheduling priority
    };

  /// Thread scheduling policies
  enum Policy {
	  //!  \brief Toolkit
    POLICY_ERROR=-1,    /// Failed to get policy
	  //!  \brief Toolkit
    POLICY_DEFAULT,     /// Default scheduling     
	  //!  \brief Toolkit
    POLICY_FIFO,        /// First in, first out scheduling
	  //!  \brief Toolkit
    POLICY_ROUND_ROBIN 	/// Round-robin scheduling 
    };

	enum Thread_Status
	{
	  //������δ�������̴߳�������״̬�� 
	  THREAD_NEW,
	  //����ִ�е��̴߳�������״̬�� 
	  THREAD_RUNNING,
	  //���������ȴ�ĳ�������������̴߳�������״̬��
	  THREAD_BLOCKED, 
	  //�����ڵصȴ���һ���߳���ִ��ĳһ�ض��������̴߳�������״̬�� 
	  THREAD_WAITING,
	  //�ȴ���һ���߳���ִ��ȡ����ָ���ȴ�ʱ��Ĳ������̴߳�������״̬�� 
	  THREAD_TIMED_WAITING,
	  //���˳����̴߳�������״̬��
	  TERMINATED,
	  // δ֪����
	  THREAD_UNKNOWN=0xFFFFFFFF,
	};

public:
	//! \brief ��ȡ�̵߳�ID
	//! \breif����߳��Ѿ���ֹ�����߳�ID���ز�׼ȷ
	UGuint GetID(){return m_nID;};

	//! \brief ��ȡ�̵߳�Name;
	UGString GetName();

	//! \brief �����߳�����ʱ��Ķ�ջ��С
	//!   ������start֮ǰ����
	void SetStackSize(UGuint nSize);

	//! \brief �����߳�����ʱ������ȼ���С
	//!   �����start֮ǰ����
	UGbool SetPriority(Priority prio);
	UGThreadEx::Priority GetPriority() const;

	//! \brief �����̵߳ĵ��Ȳ��ԣ��������ֻ��linux������Ч
	void SetPolicy(Policy ploi);

	//! \brief �����̵߳�״̬
	UGThreadEx::Thread_Status GetStatus() const;
	//! \brief�����߳��Ƿ��ڻ״̬
	UGbool IsAlive() const;

	//!  \brief ��ʼ�߳�
	UGbool Start();

	//!  \brief ��������̣߳�ֱ���߳̽���
	UGbool Join();

	//!  \brief ����߳̽����ķ���ֵ
    //! \return ���ص�ǰ�̵߳�ID
#ifdef IOS
    UGulong GetReturnValue();
    static UGulong GetCurrentThreadId();
#else
	UGint GetReturnValue();
    static UGuint GetCurrentThreadId();
#endif
	
	//!  \brief �õ�ǰ�߳���ʱ˯��һ��ʱ�䣬��λ����
	static void Sleep(UGulong nMillsecond);

	//!  \brief �õ�ǰ�߳���ͣһ��ʱ�䣬��ϵͳ���������̣߳���yield�̵߳���˼����һ��
	static UGbool SwitchToThread();
private:
	void Init();
	//�߳�ID
#ifdef IOS
    UGulong m_nID;
    UGulong m_nReturnValue;
#else
	UGuint m_nID;
    UGint m_nReturnValue;
#endif
	//�߳�����
	UGString m_strName;
	//�߳�handle ��Linux��û���õ�
	void* m_pHandle;
	//��Linux��û��handle�ĸ��m_nID���䣬���������������ʾ״̬ ֻ��Linux��ʹ��
	Thread_Status m_tSatus;

	UGbool m_bManaged;
	UGuint m_nStackSize;
	Priority m_nPriority;
	Policy m_nPolicy;

public:
	// ���ų������̳߳���
	UGThreadManager::ThreadFunCallBack m_pFun;
	void* m_pParameter;
 };




}

#endif




