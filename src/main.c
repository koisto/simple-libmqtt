#include <mosquitto.h>
#include <unistd.h>
#include <stdio.h>

void message_callback(struct mosquitto * mosq, void * obj , const struct mosquitto_message * message)
{
	printf("%d %s %s\r\n", message->mid, message->topic, (char *)message->payload);
}


int main (void)
{
	struct mosquitto * m_pMqtt;

    mosquitto_lib_init();
    m_pMqtt = mosquitto_new(NULL, true, NULL);
    
    mosquitto_connect(m_pMqtt, "localhost", 1883, 500);
    
//    mosquitto_publish_callback_set(m_pMqtt, );
//    mosquitto_subscribe_callback_set(m_pMqtt, );
    mosquitto_message_callback_set(m_pMqtt, message_callback);
    
    
    mosquitto_loop_start(m_pMqtt);
    
    sleep(1);
    
    mosquitto_subscribe(m_pMqtt, NULL, "testtopic", 0);
    
    sleep(1);
    
    mosquitto_publish(m_pMqtt, NULL, "testtopic", 6, "hello", 0, false);

    sleep(1);
    
    mosquitto_publish(m_pMqtt, NULL, "testtopic", 6, "12345", 0, false);
    
    sleep(1);
    

    mosquitto_loop_stop(m_pMqtt, true);
    
    mosquitto_disconnect(m_pMqtt);

    mosquitto_destroy(m_pMqtt);
    mosquitto_lib_cleanup();

	return 0;
}
