## Prerequisites
 - Git
 - CMake
 - GNU Make
 - C++11 builder

You can launch this command to get it : 
`sudo apt-get install build-essential git cmake make gcc`

## Dependency
MqttOwfs use Paho MQTT C++ Library a wrapper for Paho MQTT C Library. If you can not find these libraries on standard linux repository, you can build these with :
```
git clone https://github.com/eclipse/paho.mqtt.c.git
cd paho.mqtt.c
mkdir build && cd build
cmake -DPAHO_WITH_SSL=TRUE -DPAHO_BUILD_DOCUMENTATION=FALSE -DPAHO_BUILD_SAMPLES=FALSE -DPAHO_ENABLE_TESTING=FALSE ..
make && sudo make install
cd ../..
git clone https://github.com/eclipse/paho.mqtt.cpp.git
cd paho.mqtt.cpp
mkdir build && cd build
cmake -DPAHO_WITH_SSL=TRUE -DPAHO_MQTT_C_PATH=../../paho.mqtt.c ..
make && sudo make install
sudo ldconfig
```
To any problems see readme.md on https://github.com/eclipse/paho.mqtt.cpp.

## Build MqttOwfs
```
git clone https://github.com/FragJage/MqttOwfs
cd MqttOwfs
git submodule init
git submodule update --recursive
cmake . -G"Unix Makefiles"
make
```
If `git submodule update --recursive` failed (all subfolders of dependencies are empty), you can try `git submodule foreach git pull`.