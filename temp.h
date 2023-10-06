typedef struct {
    float humidity;
    float temp_celsius;
} dht_reading;

void read_temp(dht_reading *, uint);

