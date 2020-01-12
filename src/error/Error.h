#pragma once

#include <string>
#include <xlocale>

class Error
{
public:
	Error(std::string description, const int errorCode)
	: m_description(std::move(description)), m_errorCode(errorCode)
	{}

	Error() = default;;

	std::string getDescription() const
	{
		return m_description;
	}

	int getErrorCode() const
	{
		return m_errorCode;
	}

	void setTo(int errorCode, const std::string& description)
	{
		m_errorCode = errorCode;
		m_description = description;
	}

private:
	std::string m_description;
	int m_errorCode{};
};

