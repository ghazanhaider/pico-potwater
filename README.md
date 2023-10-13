# Potwater app for Raspberry Pi pico_w

This app wakes up every few minutes, connects to WIFI and updates an influxdb database using HTTP POST
The pico has a DHT11 connected to it as well as soil humidity sensors.
It adds its internal ADC temp as well to the data.
A future feature will involve pump transducers to pump in water.
The measurements and water supply should be charted in influxdb.

It is implemented in the tcp raw api instead of http_client which seems to hurt the pico timers for some reason.
The tcp api lets us do HTTP POST as well which the http_client is not able to do.

Input variables needed for CMAKE:
- Wifi SSID and password
- InfluxDB org and bucket name
- InfluxDB host fqdn and port (http, no https yet)
- Auth Token for a user that can write to the above bucket

Also #defined in the code are:
- TIMER_INTERVAL (currently set to 10 seconds)
- DHT_PIN 15 (gpio 15)


If the board hangs after a while, you're running out of PBUF_POOL or another memory pool.
In lwipopts.h, uncomment LWIP_DEBUG=1 near the bottom and check again.
All std/err outputs go to the usb device, not the usart0 device.

```
mkdir build
cd build

cmake -DWIFI_SSID='xxxxxx' -DWIFI_PASSWORD='xxxxxxxx' -DPICO_BOARD=pico_w -DAUTH_TOKEN="xxxxxxxx" -DREMOTE_URL="/api/v2/write?org=ExampleOrg&bucket=DataBucket" -DREMOTE_HOST="influxdb.example.com" -DREMOTE_PORT=80 ..
make -j8

picotool load -f potwater.uf2
picotool reboot
```


## Code structure

main():
- initializes board
- collects data
- calls upload() periodically

upload():
- creates new pcb
- sets up tcp pcb callbacks connected() and recv()
- dns_gethostbyname() with callback dns_found_callback()

dns_found_callback():
- tcp_connect()s

<COMPLETE THIS>
