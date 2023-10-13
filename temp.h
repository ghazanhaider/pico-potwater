struct dht_reading {
    float humidity;
    float temp_celsius;
};

struct data_t;

void read_temp(struct dht_reading *, uint);

