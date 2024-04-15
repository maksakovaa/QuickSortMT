#include "reqHandler.h"

RequestHandler::RequestHandler()
{
    m_tpool.start();
}
RequestHandler::~RequestHandler()
{
    m_tpool.stop();
}

std::future<void> RequestHandler::pushRequest(FuncType f, int* arr, long left, long right_bound)
{
    return m_tpool.push_task(f, arr, left, right_bound);
}