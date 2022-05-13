#pragma once

#include "../Shared.h"

template <class T>
class AutoSafeArray
{
public:
    LPSAFEARRAY m_psa;

    AutoSafeArray() throw() : m_psa(NULL)
    {
    }

    ~AutoSafeArray() throw()
    {
        HRESULT hRes = Destroy();
    }

    AutoSafeArray<T> &operator=(const AutoSafeArray &saSrc)
    {
        *this = saSrc.m_psa;
        return *this;
    }

    AutoSafeArray<T> &operator=(const SAFEARRAY *psaSrc)
    {
        HRESULT hRes = CopyFrom(psaSrc);
        if (FAILED(hRes))
            throw new std::exception("CopyFrom failed. ", hRes);
        return *this;
    }

    operator const SAFEARRAY *() const throw()
    {
        return m_psa;
    }

    operator LPSAFEARRAY() throw()
    {
        return m_psa;
    }

    const typename T& operator[](int nIndex) const
    {
    	return GetAt(nIndex);
    }

    typename T& operator[](int nIndex)
    {
    	return GetAt(nIndex);
    }

    const typename T& operator[](LONG nIndex) const
    {
    	return GetAt(nIndex);
    }

    typename T& operator[](LONG nIndex)
    {
    	return GetAt(nIndex);
    }

    LONG GetLowerBound(UINT uDim = 0) const
    {
        LONG lLBound = 0;
        HRESULT hResult = SafeArrayGetLBound(m_psa, uDim + 1, &lLBound);
        if (FAILED(hResult))
        {
            throw new std::exception("GetLBound failed.", hResult);
        }
        return lLBound;
    }

    LONG GetUpperBound(UINT uDim = 0) const
    {
        LONG lUBound = 0;
        HRESULT hResult = SafeArrayGetUBound(m_psa, uDim + 1, &lUBound);
        if (FAILED(hResult))
        {
            throw new std::exception("GetUBound failed. ", hResult);
        }
        return lUBound;
    }

    ULONG GetCount(UINT uDim = 0) const
    {
        LONG lLBound, lUBound;
        HRESULT hResult = SafeArrayGetLBound(m_psa, uDim + 1, &lLBound);

        if (FAILED(hResult))
        {
            throw new std::exception("GetLBound failed. ", hResult);
        }

        hResult = SafeArrayGetUBound(m_psa, uDim + 1, &lUBound);

        if (FAILED(hResult))
        {
            throw new std::exception("GetUBound Failed. ", hResult);
        }

        return (lUBound - lLBound + 1);
    }

    UINT GetDimensions() const
    {
        return SafeArrayGetDim(m_psa);
    }

    const T &GetAt(LONG lIndex) const
    {
        LONG lLBound = GetLowerBound();
        if ((lIndex < lLBound) || (lIndex > GetUpperBound()))
        {
            throw new std::invalid_argument::exception("Index out of bounds. ")
        }

        return ((T *)m_psa->pvData)[lIndex - lLBound];
    }

    T &GetAt(LONG lIndex)
    {
        if (m_psa == NULL)
        {
            throw new std::exception("Pointer null. ");
        }
        LONG lLBound = GetLowerBound();

        if ((lIndex < lLBound) || (lIndex > GetUpperBound()))
        {
            throw std::invalid_argument::exception("Out of bounds.  ");
        }

        return ((T *)m_psa->pvData)[lIndex - lLBound];
    }

    HRESULT Destroy()
    {
        HRESULT hRes = S_OK;
        if (m_psa != NULL)
        {
            hRes = Unlock();
            if (SUCCEEDED(hRes))
            {
                hRes = SafeArrayDestroy(m_psa);
                if (SUCCEEDED(hRes))
                    m_psa = NULL;
            }
        }
        return hRes;
    }

protected:
    HRESULT Lock()
    {
        return SafeArrayLock(m_psa);
    }
    HRESULT Unlock()
    {
        return SafeArrayUnlock(m_psa);
    }
};