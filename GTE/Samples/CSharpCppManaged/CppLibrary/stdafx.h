#pragma once
#include <vector>
#include <string>
#include <memory>
#include <iostream>
using namespace std;

#ifdef THMODULE_DLL
#  define THMODULE_EXPORT __declspec(dllexport)
#else
#  define THMODULE_EXPORT __declspec(dllimport)
#endif
