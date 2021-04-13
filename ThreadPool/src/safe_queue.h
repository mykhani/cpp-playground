#ifndef SAFE_QUEUE_H
#define SAFE_QUEUE_H

#include <thread>
#include <queue>
#include <memory>
#include <mutex>
#include <condition_variable>

template <typename T>
class safe_queue {
private:
    std::mutex m_mutex;
    std::condition_variable m_condition;
    std::queue<std::shared_ptr<T>> m_queue;
public:
    void push(const T &value) {
        std::lock_guard<std::mutex> lock {m_mutex};
        m_queue.push(std::make_shared<T>(value));
        m_condition.notify_one();
    }
    
    void push(T &&value) {
    	std::lock_guard<std::mutex> lock {m_mutex};
    	m_queue.push(std::shared_ptr<T>{new T{std::move(value)}});
    	m_condition.notify_one();
    }

    std::shared_ptr<T> pop();
    bool pop(T &ref);
    
    std::shared_ptr<T> wait_pop() {
        std::shared_ptr<T> ret;
        std::unique_lock<std::mutex> lock {m_mutex};
        
        if (m_queue.empty()) {
            m_condition.wait(lock, [this]() {return !m_queue.empty();});
        }
        
        ret = m_queue.front();
        
        m_queue.pop();
        
        return ret;
    }
    
    void wait_pop(T &value) {
        std::unique_lock<std::mutex> lock {m_mutex};
        
        m_condition.wait(lock, [this]() {return !m_queue.empty();});
        
        std::shared_ptr<T> ret;
        
        ret = m_queue.front();
        
        m_queue.pop();
        
        value = *ret;
    }
    
    bool empty() {
        std::unique_lock<std::mutex> lock {m_mutex};
        return m_queue.empty();
    }
    
};

#endif // SAFE_QUEUE_H
