#include "ThWashInteropUtils.h"

void MarshalString(String^ s, std::string& os) {
	using namespace Runtime::InteropServices;
	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
}

void MarshalString(String^ s, std::wstring& os) {
	using namespace Runtime::InteropServices;
	const wchar_t* chars =
		(const wchar_t*)(Marshal::StringToHGlobalUni(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
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