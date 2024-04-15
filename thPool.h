#pragma once
#include <future>
#include <chrono>
#include <iostream>

#include "blockedQueue.h"

//typedef void (*FuncType) (int*, long, long);
//typedef std::function<void()> task_type;

using task_type = std::function<void()>;
using FuncType = void (*) (int*, long, long);

class ThreadPool
{
public:
    ThreadPool();
    void start();
    void stop();
    std::future<void> push_task(FuncType f, int* arr, long left, long right_bound);
    void threadFunc(int qindex);
private:
    std::vector<std::thread> m_threads;
    std::vector<BlockedQueue<task_type>> m_thread_queues;
    int m_index{0};
    int m_thread_count{0};
};