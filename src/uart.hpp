namespace havr
{

class Uart
{
public:
    void configure();
    void send(uint8_t byte);
    uint8_t receive();
};

}
