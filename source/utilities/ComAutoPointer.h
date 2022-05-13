#pragma once

#include "../Shared.h"

// template

template <class T>
class ComAutoPointer
{
public:
    T *p;

    ComAutoPointer() noexcept
    {
        p = NULL;
    }

    ComAutoPointer(T *lp) noexcept
    {
        p = lp;

        if (p != NULL)
        {
            p->AddRef();
        }
    }

    ComAutoPointer(const ComAutoPointer<T> &lp) throw() : ComAutoPointer(lp.p)
    {
    }

    ~ComAutoPointer() noexcept
    {
        if (p)
        {
            p->Release();
        }
    }

    T *operator->() const noexcept
    {
        return p;
    }

    T **operator&() noexcept
    {
        return &p;
    }

    operator T *() const noexcept
    {
        return p;
    }

    T &operator*() const
    {
        return *p;
    }

    T *operator=(T *lp) noexcept
    {
        if (this->p != lp)
        {
            ComAutoPointer<T>(lp).Swap(*this);
        }
        return *this;
    }

    T *operator=(const ComAutoPointer<T> &lp) noexcept
    {
        if (this->p != lp.p)
        {
            ComAutoPointer(lp).Swap(*this);
        }
        return *this;
    }

    T *operator=(ComAutoPointer<T> &&lp) noexcept
    {
        if (this->p != lp.p)
        {
            ComAutoPointer(lp).Swap(*this);
        }
        return *this;
    }

    bool operator!() const noexcept
    {
        return (p == NULL);
    }

    void Swap(ComAutoPointer<T> &other)
    {
        T *pTemp = p;
        p = other.p;
        other.p = pTemp;
    }

    void Release() noexcept
    {
        T *pTemp = p;
        if (pTemp)
        {
            p = NULL;
            pTemp->Release();
        }
    }

    HRESULT CoCreateInstance(REFCLSID rclsid, LPUNKNOWN pUnkOuter = NULL, DWORD dwClsContext = CLSCTX_ALL) noexcept
    {
        return ::CoCreateInstance(rclsid, pUnkOuter, dwClsContext, __uuidof(T), (void **)&p);
    }
};