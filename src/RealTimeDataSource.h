#pragma once
#include <string>
#include <map>
#include <json/json.h>
#include <curl/curl.h>
namespace Rivendell
{
	class RealTimeDataSource
	{
	public:
		Json::Value *GetRequest(std::string url);
	};
}
