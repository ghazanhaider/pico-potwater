# Potwater app for Raspberry Pi pico-w

# This app wakes up every few minutes, connects to WIFI and updates an influxdb database using HTTP POST
# The pico has a DHT11 connected to it as well as soil humidity sensors.
# A future feature will involve pump transducers to pump in water.
# The measurements and water supply should be charted in influxdb.

```
mkdir build
cd build

cmake -DWIFI_SSID='xxxxxx' -DWIFI_PASSWORD='xxxxxxxx' -DPICO_BOARD=pico_w -DAUTH_TOKEN="xxxxxxxx" -DSECRET_URI="/xxxxx" ..
make -j8

picotool load -f potwater.uf2
picotool reboot
```
