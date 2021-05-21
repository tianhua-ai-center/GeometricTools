#include "ThWashInteropUtils.h"
#include "clix.hpp"

void MarshalString(String^ s, std::string& os) {
	os = clix::marshalString<clix::E_UTF8>(s);
}

void MarshalString(String^ s, std::wstring& os) {
	os = clix::marshalString<clix::E_UTF16>(s);
}

String^ MarshalNativeString(std::string& os)
{
	return gcnew String(os.c_str());
}

void MarshalBindaryBuffer(cli::array<Byte>^ buffer, std::vector<unsigned char>& vector)
{
	pin_ptr<unsigned char> pinPoints = &buffer[0];
	unsigned char* result = pinPoints;
	vector.insert(vector.begin(), result, result + buffer->Length);
}

cli::array<Byte>^ MarshalNativeBindaryBuffer(std::vector<unsigned char>& nbuffer)
{
	cli::array<Byte>^ buffer = gcnew cli::array<Byte>(nbuffer.size());
	Marshal::Copy((IntPtr)nbuffer.data(), buffer, 0, nbuffer.size());
	return buffer;
}