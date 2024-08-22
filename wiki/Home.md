# Welcome to the MqttOwfs wiki!

## Introduction
MqttOwfs is a daemon to send Mqtt message for state device and receive Mqtt command for input device. MqttOwfs use owserver, the backend component of the OWFS 1-wire bus control system. See http://owfs.org/ for more information on OWFS 1-wire bus control system.

## Main features
 - Automatic detection of devices 
 - Supported device without configuration file DS2405, DS18S20, DS1920, DS2406, DS2407, DS2423, DS2450, DS1921, DS1822, DS2438, DS18B20, DS2408, DS2413, DS18B25
 - All devices are supported by simple configuration file
 - Possibility to set temperature and pressure unit
 - OWFS can be installed to another server
 - Mqtt provider can be installed to another server
 - Supported mqtt authentication

## How to
 - [How to build](https://github.com/FragJage/MqttOwfs/wiki/How-to-build)
 - [How to install](https://github.com/FragJage/MqttOwfs/wiki/How-to-install)
 - [How to configure](https://github.com/FragJage/MqttOwfs/wiki/Configuration)

## Breaking change on v2.0
 - Breaking change on default reading values, see  [Default reading values](https://github.com/FragJage/MqttOwfs/wiki/Default-reading-values)