#pragma once
#include "ManagedObject.h"
#include "../CppLibrary/CppLibrary.h"
using namespace System;


// https://docs.microsoft.com/en-us/cpp/dotnet/how-to-convert-system-string-to-standard-string?view=msvc-160
String^ MarshalNativeString(std::string& os);
void MarshalString(String^ s, std::string& os);
void MarshalString(String^ s, std::wstring& os);

cli::array<Byte>^ MarshalNativeBindaryBuffer(const std::vector<unsigned char>& vector);
void MarshalBindaryBuffer(cli::array<Byte>^ buffer, std::vector<unsigned char>& vector);