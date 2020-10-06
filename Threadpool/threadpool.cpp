#include "threadpool.h"

ThreadPool::ThreadPool()
{

}

ThreadPool::~ThreadPool()
{
    if(m_isStarted) {
        stop();
    }
}