//
// Made by Marco
//

#ifndef HTTP_PARSER_HPP_
# define HTTP_PARSER_HPP_

#include <iostream>
#include <vector>
#include "HttpParserException.hpp"
#include "Transform.hpp"
#include "http.h"

#define CRLF "\r\n"
#define SP " "

namespace nz
{
	class HttpParser
	{
	public:
		HttpParser();
		virtual ~HttpParser();

	public:
		zia::api::HttpRequest	GetRequest(const std::vector<std::string> & input);
		zia::api::HttpResponse	GetResponse(const std::vector<std::string> & input);

	private:
		zia::api::http::Method	GetMethodFromString(const std::string & input);
		zia::api::http::Version GetVersionFromString(const std::string & input);

	public:
		zia::api::HttpDuplex	Parse(zia::api::Net::Raw request);
		void					CheckValidity(zia::api::HttpRequest);
	};
}

#endif //HTTP_PARSER_HPP_