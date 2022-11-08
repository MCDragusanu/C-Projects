#include "ExceptionHandler.h"

__Exception::__Exception(int line, const char* file)noexcept
	:line(line),
	file(file)
{

}
const char* __Exception::what()const noexcept
{
	std::ostringstream oss;
	oss << GetType() << std::endl<<GetOriginString();
	whatBuffer = oss.str();
	return whatBuffer.c_str();

}
const char* __Exception::GetType()const noexcept
{
	return "__Exception";
}
const std::string&  __Exception::GetFile()const noexcept
{
	return file;
}
std::string __Exception::GetOriginString()const noexcept
{
	std::ostringstream oss;
	oss << "[File]" << file << std::endl<<"[Line]"<<line;
	return oss.str();
}