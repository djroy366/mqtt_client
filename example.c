#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include "mqtt.h"
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>


struct mqtt_client* sub;
struct mqtt_client* pub;


//info_callback
void publish_callback1(void** unused, struct mqtt_response_publish *published)
{   


	char messageBuffer[400];

	/* note that published->topic_name is NOT null-terminated (here we'll change it to a c-string) */
	char* topic_name = (char*) malloc(published->topic_name_size + 1);
	memcpy(topic_name, published->topic_name, published->topic_name_size);
	topic_name[published->topic_name_size] = '\0';
	printf("\n////////START///////\n\nReceived publish('%s'): %s\n\n", topic_name, (const char*) published->application_message);
	memset(messageBuffer,0,sizeof(messageBuffer));
	memcpy(messageBuffer,(char*)published->application_message,published->application_message_size);

}



//publish_files_function
//CUSTOM function
void publish(struct mqtt_client *client,char *topic,char* buffer){
	struct mqtt_client *client_publishFiles=client;
	mqtt_publish(pub,topic, buffer, strlen(buffer) + 1, MQTT_PUBLISH_QOS_1);
	printf("Published:%s\n",buffer);
	if (pub->error != MQTT_OK) {
		fprintf(stderr, "error: %s\n", mqtt_error_str(pub->error));
		exit_example(EXIT_FAILURE, pub->sockfd, &pub->client_daemon);
	}
}




// MAIN
int main(){

	pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;


	sub=(struct mqtt_client *)malloc(sizeof(struct mqtt_client));
	pub=(struct mqtt_client *)malloc(sizeof(struct mqtt_client));

	pub->ip       = "10.19.100.140";
	pub->topic       = "gateway_info";
	pub->port       = "1883";
	pub->pub_or_sub =  0;
	pub->user_name  = "lte_gateway";
	pub->password   = "lte_gateway";

	sub->ip       = "10.19.100.140";
	sub->topic       = "will_msg";
	sub->port       = "1883";
	sub->pub_or_sub =  0;
	sub->user_name  = "lte_gateway";
	sub->password   = "lte_gateway";


	mqtt_dj_init(pub,NULL);
	mqtt_dj_init(sub,publish_callback1);



	while(1) {
		publish(pub,"topic","hi");

		sleep(2);
	}
}

