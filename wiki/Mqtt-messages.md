## Emitted messages
When a device value change, MqttOwfs send a mqtt message on topic owfs/deviceName with the value.
The topic name can be modify in the configuration file, on mqtt section, the device name can be modify on others sections with displayname value.

## Received messages for the daemon
You can send mqtt messages on owfs/command
 - REQUEST resend all devices values
 - REFRESH_DEVICES refresh the devices list
 - REFRESH_VALUES refresh devices values (resend only if the values has changed)

## Received messages for device
You can send mqtt messages on owfs/command/devicename to change the value of a device
(this feature is not tested)