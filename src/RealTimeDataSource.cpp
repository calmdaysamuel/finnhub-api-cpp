#include "RealTimeDataSource.h"

namespace Rivendell
{
	std::size_t callback(const char *in, std::size_t size, std::size_t num, std::string *out)
	{
		const std::size_t totalBytes(size * num);
		out->append(in, totalBytes);
		return totalBytes;
	}
	Json::Value *RealTimeDataSource::GetRequest(std::string url)
	{
		CURL *curl = curl_easy_init();

		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_IPRESOLVE, CURL_IPRESOLVE_V4);
		curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
		long int httpCode(0); //Having this as a normal int will cause a segmentation fault for some requests being too large.
		std::unique_ptr<std::string> httpData(new std::string());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, httpData.get());
		curl_easy_perform(curl);
		curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);
		curl_easy_cleanup(curl);

		Json::CharReaderBuilder builder;
		int sourceLength = httpData->length();

		const std::unique_ptr<Json::CharReader> reader(builder.newCharReader());

		Json::Value *parsed = new Json::Value();
		std::string err;
		reader->parse(httpData->c_str(), httpData->c_str() + sourceLength, parsed, &err);

		return parsed;
	}
}