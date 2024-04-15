#pragma once
#include "thPool.h"

class RequestHandler
{
public:
    RequestHandler();
    ~RequestHandler();
    std::future<void> pushRequest(FuncType f, int* arr, long left, long right_bound);
private:
    ThreadPool m_tpool;
};