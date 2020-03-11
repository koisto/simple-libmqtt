#include <mosquitto.h>

int main (void)
{
	struct mosquitto * m_pMqtt;

    mosquitto_lib_init();
    m_pMqtt = mosquitto_new(NULL, true, NULL);
    
    mosquitto_connect(m_pMqtt, "localhost", 1883, 500);
    
    
    
    
    
    mosquitto_disconnect(m_pMqtt);

    mosquitto_destroy(m_pMqtt);
    mosquitto_lib_cleanup();

	return 0;
}
