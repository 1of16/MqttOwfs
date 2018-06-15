#include <thread>
#include <map>
#include <cassert>
#ifdef WIN32
#include <WinSock2.h>		// To stop windows.h including winsock.h
#endif
#include "Plateforms/Plateforms.h"
#include "UnitTest/UnitTest.h"
#include "MqttBase\MqttClient.h"
#include "../src/MqttOwfs.h"


class TestMqttOwfs : public TestClass<TestMqttOwfs>, public MqttClient::IMqttMessage
{
public:
	TestMqttOwfs();
	~TestMqttOwfs();
	static void ThreadStart(MqttOwfs* pMqttOwfs);
	static void ThreadConf(MqttOwfs* pMqttDev);
	void on_message(const std::string& topic, const std::string& message);

	bool Start();
	bool DeviceRefresh();
	bool DeviceSet();
	bool Commands();
	bool CoverageConfig();
	bool Stop();

private:
	void waitMsg(size_t maxMsg, int maxTime);
	MqttOwfs mqttOwfs;
	MqttClient mqttClient;
	std::map<std::string, std::string> m_Messages;
};
