Without configuration file, the MqttOwfs daemon can read DS2405, DS18S20, DS1920, DS2406, DS2407, DS2423, DS2450, DS1921, DS1822, DS2438, DS18B20, DS2408, DS2413, DS18B25, DS2401.

## From v2.0
The topic is made up with the device identifier and the device reading folder :
 - DS2401 : value /IsPresent (Special folder, see Configuration page)
 - DS2405 : value /PIO
 - DS18S20 & DS1920 : value /temperature
 - DS2406 & DS2407 : values /PIO.A and /PIO.B
 - DS2423 : value /counters.A and /counters.B
 - DS2450 : value /PIO.A, /PIO.B, /PIO.C and /PIO.D
 - DS1921 : value /temperature
 - DS1822 : value /temperature
 - DS2438 : value /VDD, /humidity and /temperature
 - DS18B20 : value /temperature
 - DS2408 : value /PIO.BYTE
 - DS2413 : value /PIO.A and /PIO.B

### Example
Without configuration a DS2438 send three topic
1. /owfs/26.123456000000/VDD
1. /owfs/26.123456000000/humidity
1. /owfs/26.123456000000/temperature

To retrieve the old functioning for this device (before v2.0), you can add a new section in configuration file
```
[26.123456000000/VDD]
displayname = 26.123456000000
```
## Before v2.0
The topic is made up only with the device identifier, the value is obtained by reading the folder :
 - DS2401 : value /IsPresent (Special folder, see Configuration page)
 - DS2405 : value /PIO
 - DS18S20 & DS1920 : value /temperature9
 - DS2406 & DS2407 : value /PIO.A
 - DS2423 : value /counters.A
 - DS2450 : value /PIO.A
 - DS1921 : value /temperature9
 - DS1822 : value /temperature9
 - DS2438 : value /VDD
 - DS18B20 : value /temperature9
 - DS2408 : value /PIO.BYTE
 - DS2413 : value /PIO.A
