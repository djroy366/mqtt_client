# mqtt_client
a mqtt client, inspired by github.com/LiamBindle/MQTT-C


The main difference is, for every connection a different thread is made

**mqtt_dsp_init()** // this initialises the client thread

	return type : MQTTErrors 
		    : return MQTT_OK tf everything worked out well.

	arguments   : mqtt-client * , callBack function.



    -Function Prototype -

        enum MQTTErrors mqtt_dsp_init(struct mqtt_client* client,void (*publish_response_callback)(void** state,struct mqtt_response_publish *publish))


Example initiation of the client -

        sub=(struct mqtt_client *)malloc(sizeof(struct mqtt_client));
        pub=(struct mqtt_client *)malloc(sizeof(struct mqtt_client));

        pub->ip       = "EXAMPLE_IP";
        pub->topic       = "EXAMPLE_TOPIC";
        pub->port       = "EXAMPLE_PORT";
        pub->pub_or_sub =  1;                     // 1 for pub 
        pub->user_name  = "EXAMPLE_BROKER_NAME";
        pub->password   = "EXAMPLE_BROKER_PASSWORD";

 	sub->ip       = "EXAMPLE_IP";
        sub>topic       = "EXAMPLE_TOPIC";
        sub>port       = "EXAMPLE_PORT";
        sub>pub_or_sub =  0;                     // 0 for sub
        sub>user_name  = "EXAMPLE_BROKER_NAME";
        sub>password   = "EXAMPLE_BROKER_PASSWORD";


        mqtt_dsp_init(pub,NULL);
        mqtt_dsp_init(sub,publish_callback1);
