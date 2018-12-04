namespace havr
{

class Uart
{
public:
    void configure();
    void send(uint8_t byte);
    bool send(const char * data, uint16_t length);
    uint8_t receive();
};

}
