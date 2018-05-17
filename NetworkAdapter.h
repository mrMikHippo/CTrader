/*
 * NetworkAdapter.h
 *
 *  Created on: May 17, 2018
 *      Author: hippo
 */

#ifndef NETWORKADAPTER_H_
#define NETWORKADAPTER_H_

#include <string>
#include <curl/curl.h>

/*
 *
 */
struct DataWriter {
	static std::string buf;

	static size_t writer(char *data, size_t size, size_t nmemb, void *ptr) {
		if (data == nullptr) return 0;

		int segsize = size * nmemb;
		buf.append(data, segsize);
		return segsize;
	}
};

/*
 * Network adapter using curl library
 */
class NetworkAdapter {
	CURL *curl;
	std::string url;
	char errbuf[CURL_ERROR_SIZE];

public:
	NetworkAdapter(std::string sname = "https://api.xmrpool.net/pool/stats");

	virtual ~NetworkAdapter();

	void PerformData();
	void PrintData();
};

#endif /* NETWORKADAPTER_H_ */
