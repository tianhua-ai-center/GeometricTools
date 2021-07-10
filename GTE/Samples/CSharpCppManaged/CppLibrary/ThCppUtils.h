#pragma once

namespace gte
{
    template<class T>
    T* GetInstance(void* ptr)
    {
        return reinterpret_cast<T*>(ptr);
    }
}