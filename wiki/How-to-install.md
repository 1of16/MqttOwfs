## Files copy

### Linux
After the build, you are in MqttOwfs folder.
- Copy daemon binary to /usr/bin :
`sudo cp src/bin/MqttOwfs /usr/bin`
- Copy configuration file to /etc :
`sudo cp MqttOwfs.conf /etc`

### Windows
(...)

## Start daemon
Before start, see [configuration page](https://github.com/FragJage/MqttOwfs/wiki/Configuration)

`sudo MqttOwfs -start`

or

`sudo MqttOwfs -console` for console mode.

You can stop and restart the daemon with `-stop` and `-restart` option.

## Daemon settings
* You can specify a configuration file with `--configfile` option or `-f`.

For example : `MqttOwfs -start --configfile /home/user/MyOwfsMqtt.conf`

* You can set the debug level and the debug destination with `--loglevel` option or `-l` and `--logdestination` option or `-d`.

For example : `MqttOwfs -console --loglevel 2 --logdestination cout`

Possible values for loglevel : 1 to 7 or FATAL, ERROR, WARNING, INFO, DEBUG, VERBOSE, TRACE

Possible values for logdestination : cout, cerr, clog or a file

## Other parameter
In version 1.1, `-version` display the version's daemon.
