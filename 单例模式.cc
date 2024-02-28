
// 单例模式应该是类设计者的责任，而不是类使用者的责任
// 1.懒汉单例模式（线程不安全）
// 2.懒汉单例模式（双检查锁，线程安全）
// 3.饿汉单例模式
// 4.Meyers' Singleton



// 1.懒汉单例模式（线程不安全）
class Singleton
{
public:
    static Singleton &GetInstance()
    {
        if(instance_ == nullptr)
        {
            instance_ = new Singleton();
        }
        return instance_;
    }
private:
    Singleton() {}
    // 静态变量instance初始化不要放在头文件中, 如果多个文件包含singleton.h会出现重复定义问题
    static Singleton *instance_;
};



// 2.懒汉单例模式（双检查锁，线程安全）
// 锁前检查
// 锁后检查
class Singleton
{
public:
    static Singleton *GetInstance()
    {
        if(instance_ == nullptr)
        {
            mutex_.lock();
            if(instance_ == nullptr)  // 双重检查
            {
                instance_ = new Singleton(); 
                // 可能会出现内存reorder，开辟内存+构造函数+赋值给指针，导致另一个线程返回instance_指向的内存没有调用构造函数
            }
            mutex_.unlock();
        }
        return instance_;
    }
private:
    Singleton() {}
    static Singleton *instance_;
    static std::mutex mutex_;
};




// 3.饿汉单例模式       类加载时就会创建对象
class Singleton
{
public:
    static Singleton *GetInstance()
    {
        return instance_;
    }
private:
    Singleton() {}
    static Singleton *instance_;
};
// Singleton.cpp
#include Singleton.h
Singleton *Singleton::instance_ = new Singleton();  




// 4.Meyers' Singleton    将单例对象作为局部static对象定义在函数内部
// 静态声明的变量，声明时的赋值仅在，声明的首次被执行
class Singleton
{
public:
    static Singleton &GetInstance()
    {
        static Singleton instance_;
        return instance_;
    }
    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;
private:
    Singleton() {}
};