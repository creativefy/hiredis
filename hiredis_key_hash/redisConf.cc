///
/// @file    redisConf.cc
/// @author  
/// @date    2018-08-10 18:17:32
///
#include "redisConf.h"
#include <stdlib.h>
#include <json/json.h>
#include <string>
#include <iostream>
#include <fstream>

using std::ifstream;
using std::cout;
using std::endl;
namespace cc
{


	RedisConf::RedisConf() {
		getConf();
	}

	void RedisConf::getConf() {
		ifstream ifs;
		ifs.open("redisConf.json");
		if(!ifs.good()) {
			cout << "open RedisConf.json error" << endl;
			exit(EXIT_FAILURE);
		}

		Json::Value root;
		Json::Reader reader;
		if(!reader.parse(ifs, root, false)) {
			cout << "RedisConf json reader error" << endl;
			exit(EXIT_FAILURE);
		}

		_ip = root["IP"].asString();
		_port = root["PORT"].asInt();
		ifs.close();
	}

	string RedisConf::getIP() {
		return _ip;
	}

	int RedisConf::getPort() {
		return _port;
	}

}//end of namespace
