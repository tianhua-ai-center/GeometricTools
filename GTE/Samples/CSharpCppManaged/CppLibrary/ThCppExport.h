#pragma once

#ifdef THMODULE_DLL
#  define THMODULE_EXPORT __declspec(dllexport)
#else
#  define THMODULE_EXPORT __declspec(dllimport)
#endif