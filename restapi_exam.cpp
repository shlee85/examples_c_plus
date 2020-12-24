#include <iostream>
using namespace std;

#include "D:\DSB_WORK\Encoder\vcpkg\installed\x64-windows\include\cpprest\http_client.h"
#include "D:\DSB_WORK\Encoder\vcpkg\installed\x64-windows\include\cpprest\filestream.h"

//#pragma comment(lib, "cpprest120_2_4")	    // windows only
using namespace utility;                    // Common utilities like string conversions
using namespace web;                        // Common features like URIs.
using namespace web::http;                  // Common HTTP functionality
using namespace web::http::client;          // HTTP client features
using namespace concurrency::streams;       // Asynchronous streams


void GetHttp()
{
	http_client client(U("http://en.cppreference.com/w/"));
	auto resp = client.request(U("GET")).get();

	wcout << U("STATUS : ") << resp.status_code() << endl;
	wcout << "content-type : " << resp.headers().content_type() << endl;
	wcout << resp.extract_string(true).get() << endl;
}

void GetHttpAsync()
{
	http_client client(U("http://en.cppreference.com/w/"));

	client.request(U("GET")).then([](http_response resp) {
		wcout << U("STATUS : ") << resp.status_code() << endl;
		wcout << "content-type : " << resp.headers().content_type() << endl;

		resp.extract_string(true).then([](string_t sBoby) {
			wcout << sBoby << endl;
			}).wait();

		}).wait();

}


void GetJson()
{
	//http_client client(U("http://date.jsontest.com/"));  //"U"는 _T와 비슷한 UNICODE 및 MBCS환경의 문자열 타입을 스위칭 해주는 매크로.
	http_client client(U("http://10.10.16.4:3000/users/"));  //"U"는 _T와 비슷한 UNICODE 및 MBCS환경의 문자열 타입을 스위칭 해주는 매크로.

	http_request req(methods::GET);

	client.request(req).then([=](http_response r) {
		wcout << U("STATUS : ") << r.status_code() << endl;
		wcout << "content-type : " << r.headers().content_type() << endl;

		wcout << endl;
		//{
		//		"time": "11:25:23 AM",
		//		"milliseconds_since_epoch" : 1423999523092,
		//		"date" : "02-15-2015"
		//}

		r.extract_json(true).then([](json::value v) {
			wcout << "tile mode : " << v.at(U("tile_mode")).as_string() << endl;
			wcout << "tile mode : " << v.at(U("web_srv_mode")).as_string() << endl;
			wcout << "tile mode : "  << v.at(U("addr")).as_string() << endl;
			}).wait();

		}).wait();

}

int main(int argc, char* argv[])
{
	wcout.imbue(locale("kor"));  // windows only

	//GetHttp();
	//GetHttpAsync();
	GetJson();

	return 0;
}