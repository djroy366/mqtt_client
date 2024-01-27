# mqtt_client
a mqtt client, inspired by github.com/LiamBindle/MQTT-C


The main difference is, for every connection a different thread is made

**mqtt_dsp_init()** // this initialises the client thread





enum MQTTErrors mqtt_dsp_init(struct mqtt_client* client,void (*publish_response_callback)(void** state,struct mqtt_response_publish *publish))
