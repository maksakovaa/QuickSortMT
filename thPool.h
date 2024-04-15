#pragma once
#include <future>
#include <chrono>
#include <iostream>

#include "blockedQueue.h"

typedef void(*FuncType)(int*, long, long, std::shared_ptr<std::promise<void>>);
typedef std::function<void(int*, long, long, std::shared_ptr<std::promise<void>>)> task_type;

class ThreadPool
{
public:
    using FuncType = std::function<void(int*, long, long, std::shared_ptr<std::promise<void>> )>;
    ThreadPool();
    void start(int* arr, long left, long right_bound, std::shared_ptr<std::promise<void>> prom);
    void stop();
    void push_task(FuncType f, int* arr, long left, long right_bound, std::shared_ptr<std::promise<void>> &prom);
    void threadFunc(int qindex, int* arr, long left, long right_bound, std::shared_ptr<std::promise<void>> &prom);
private:
    std::vector<std::thread> m_threads;
    std::vector<BlockedQueue<task_type>> m_thread_queues;
    int m_index{0};
    int m_thread_count{0};
};