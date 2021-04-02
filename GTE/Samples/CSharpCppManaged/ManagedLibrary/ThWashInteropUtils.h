#pragma once
#include "ManagedObject.h"
#include "../CppLibrary/CppLibrary.h"
using namespace System;


// https://docs.microsoft.com/en-us/cpp/dotnet/how-to-convert-system-string-to-standard-string?view=msvc-160
void MarshalString(String^ s, string& os);
void MarshalString(String^ s, wstring& os);