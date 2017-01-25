#pragma once

#include <pthread.h>

template <class T>
class ThreadLocalPointer
{
public:

    ThreadLocalPointer()
    {
        pthread_key_create(&m_key, NULL);
    }
    
    ~ThreadLocalPointer()
    {
        pthread_key_delete(m_key);
    }
    
    void SetValue(T* _value)
    {
        pthread_setspecific(m_key, reinterpret_cast<const void*>(_value));
    }
    
    T* GetValue()
    {
        return reinterpret_cast<T*>(pthread_getspecific(m_key));
    }
    
private:

    pthread_key_t m_key;
};
