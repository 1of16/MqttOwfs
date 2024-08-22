## Location
You can find the configuration file to `/etc/MqttOwfs.conf`.

To specify another folder or configuration file see daemon settings on [How to install](https://github.com/FragJage/MqttOwfs/wiki/How-to-install).

## Sample of configuration file
```
[owfs]
server=127.0.0.1
port=4304
devicesinterval=5
valuesinterval=4
temperaturescale=C
pressurescale=Mbar
uncachedread=false

[mqtt]
server=tcp://127.0.0.1:1883
keepalive=300
topic=owfs

[log]
level=1
destination=cerr

[0589454659845/temperature9]
displayname = TemperatureSalon
round = 1

[0100A5DA59845/ispresent]
displayname = door
refreshinterval = 1
uncachedread = true
```

## owfs section
 - `server` to define owfs server ip address (default 127.0.0.1).
 - `port` to define owfs server port TCP (default 4304).
 - `devicesinterval` specify interval to refresh devices list, in second (default 90)
 - `valuesinterval` specify interval to refresh devices value, in second (default 10)
 - `temperaturescale` (default C)
 - `pressurescale` (default Mbar)
 - `uncachedread` (default false)

## mqtt section
 - `server` to define mqtt server url (default tcp://127.0.0.1:1883)
 - `topic` specify the topic (default owfs)
 - `keepalive` specify keepalive, in second (default 300)

More options in wiki of mqtt daemon library [here](https://github.com/FragJage/MqttDaemon/wiki/Configuration).

## log section
 - `level` to define log level, 1 to 7 (default 1)
 - `destination` to specifie log destination cout, cerr, clog or a file (default cerr)

More options in wiki of mqtt daemon library [here](https://github.com/FragJage/MqttDaemon/wiki/Configuration).

## Comments
To comment a line don't use character # but character ;

## Others sections
Other sections allow you to manually define devices. The name of the section must be the folder to read the owfs device value.
 - `displayname` to modify the device name in the mqtt topic
 - `round` to round the value (1 to round to one decimal place)
 - `refreshinterval` to specify a specific refresh value interval (by default valueinterval in owfs section)
 - `uncachedread` set to true to read uncached value (by default value of uncachedread in owfs section)

Example of section to have a mqtt message for a DS2438, VDD value :
```
[26000026D90000/VDD]
displayname = MyDS2438voltage
round = 1
```
There is specific folder to know if a device is online on the one wire bus : `/ispresent`. It's not use `present` folder of owfs because it's deprecated. This feature rescan one wire.

Example of section to have a mqtt message to know if a DS2401 is online :
```
[0100A5DA59845/ispresent]
displayname = door
refreshinterval = 2
uncachedread = true
```