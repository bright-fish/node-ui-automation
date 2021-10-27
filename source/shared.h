#pragma once

#include <napi.h>
#include <uv.h>
#include <Windows.h>
#include <UIAutomation.h>
#include <stdio.h>

#include <comdef.h>
#include <comutil.h>

#ifdef _DEBUG
#define _ATL_DEBUG
#undef _DEBUG
#endif

#include <atlbase.h>
#include <atlsafe.h>

#ifdef _ATL_DEBUG
#define _DEBUG
#undef _ATL_DEBUG
#endif