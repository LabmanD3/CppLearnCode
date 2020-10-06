#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <mutex>
#include <queue>
#include <thread>
#include <vector>
#include <utility>
#include <functional>
#include <condition_variable>

class ThreadPool 
{
public:
    // 线程池能同时处理的数量
    static const int kInitThreadsSize = 3;
    // 任务优先级
    enum taskPriority {level0, level1, level2};
    typedef std::function<void()> Task;
    typedef std::pair<taskPriority, Task> TaskPair;

    ThreadPool();
    ~ThreadPool();

    ThreadPool(const ThreadPool&) = delete;
    const ThreadPool& operator=(const ThreadPool&) = delete;

    void start();
    void stop();
    void addTask(const Task&);
    void addTask(const TaskPair&);

private:
    struct TaskPriorityCmp {
        bool operator() (const ThreadPool::TaskPair p1, const ThreadPool::TaskPair p2) {
            return p1.first > p2.first;
        }
    };
    typedef std::vector<std::thread*> Threads;
    typedef std::priority_queue<TaskPair, std::vector<TaskPair>, TaskPriorityCmp> Tasks;
    // 互斥锁
    std::mutex m_mutex;
    // 条件变量
    std::condition_variable m_cv;
    // 是否启动线程池
    bool m_isStarted;
    // 线程组（线程池）
    Threads m_threads;
    // 任务队列
    Tasks m_tasks;


};



#endif