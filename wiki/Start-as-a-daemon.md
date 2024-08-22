## Start MqttOwfs as daemon with init.d

### Configuration
Copy `MqttOwfs` to `/usr/bin`. 
Create file named `mqttowfs` in `/etc/init.d` with content below.

```
#!/bin/sh

### BEGIN INIT INFO
# Provides:          MqttOwfs
# Required-Start:    mosquitto
# Required-Stop:     mosquitto
# Default-Start:     2 3 4 5
# Default-Stop:      0 1 6
# Short-Description: Mqtt bridge for Owfs
# Description:       Start and stop a bridge between mqtt and owfs.
### END INIT INFO

DESC="Mqtt bridge for Owfs"
NAME="MqttOwfs"
DAEMON=/usr/bin/$NAME
PIDFILE=/var/run/$NAME.pid

# Gracefully exit if the package has been removed.
test -x $DAEMON || exit 0

. /lib/lsb/init-functions

d_start() {
    $DAEMON -start
    sleep 1
    pidofproc -p $PIDFILE $DAEMON >/dev/null
}

d_stop() {
   $DAEMON -stop
   sleep 1
}

d_status() {
    pidofproc -p $PIDFILE $DAEMON > /dev/null
}

case "$1" in
    start)
        log_daemon_msg "Starting $DESC" "$NAME"
        d_start
        log_end_msg $?
        ;;
    stop)
        log_daemon_msg "Stopping $DESC" "$NAME"
        d_stop
        log_end_msg $?
        ;;
    restart|force-reload)
        log_daemon_msg "Restarting $DESC" "$NAME"
        d_status && d_stop
        d_start
        log_end_msg $?
        ;;
    status)
        d_status
        if [ $? -eq 0 ];then
            log_success_msg "$NAME is running"
        else
            log_failure_msg "$NAME is not running"
        fi
        ;;
    *)
        echo "Usage: /etc/init.d/$NAME {start|stop|restart|force-reload|status}" >&2
        exit 1
        ;;
esac

exit 0
```

- Go to init.d folder : `cd /etc/init.d`
- Give execution permission : `sudo chmod 755 mqttowfs`
- Add daemon in start list : `sudo update-rc.d mqttowfs defaults 97 03`

### Common commands
- Manual start
```
   cd /etc/init.d
   sudo ./mqttowfs start
```
- Manual stop
```
   cd /etc/init.d
   sudo ./mqttowfs stop
```
