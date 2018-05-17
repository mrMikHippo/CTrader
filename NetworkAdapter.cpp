/*
 * NetworkAdapter.cpp
 *
 *  Created on: May 17, 2018
 *      Author: hippo
 */

#include "NetworkAdapter.h"
#include <iostream>
#include <string.h>

using namespace std;

string DataWriter::buf = "";

NetworkAdapter::NetworkAdapter(string sname) :
	url(sname)
{
	cout << "Connecting to \"" << sname << "\"" << endl;
	// Initialize curl
	curl  = curl_easy_init();
	if (!curl) {
		cout << "Couldn't init curl!" << endl;
		return;
	}

	// Set error buffer for error messages
	curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, errbuf);
	// Set the target URL
	curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
	// Receive data to The DataWriter
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, DataWriter::writer);

}

NetworkAdapter::~NetworkAdapter() {
	curl_easy_cleanup(curl);
}

void NetworkAdapter::PerformData()
{
	errbuf[0] = 0;
	CURLcode res = curl_easy_perform(curl);
	if (res != CURLE_OK) {
		cerr << "libcurl: " << res << endl;
		cerr << errbuf << endl;
		cerr << curl_easy_strerror(res) << endl;
	}
}

void NetworkAdapter::PrintData()
{
	cout << DataWriter::buf << endl;
}




