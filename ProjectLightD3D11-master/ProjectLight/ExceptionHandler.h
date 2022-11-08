#pragma once
#include <exception>
#include <string>


class __Exception :public std::exception
{
public:__Exception(int line ,const char* file)noexcept;
	    const char* what()const noexcept override;
		virtual const char* GetType()const noexcept;
		int GetLine()const noexcept { return line; };
		const std::string& GetFile()const noexcept;
		std::string GetOriginString()const noexcept;
private:int line;
	   std::string file;
protected: mutable std::string whatBuffer;
};