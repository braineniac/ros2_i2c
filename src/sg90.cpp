#include"sg90.h"

#include<cstdint>

namespace sg90
{
    sg90::sg90(uint8_t I2CBus, uint8_t I2CAddr, uint8_t number): PCA9685::PCA9685(I2CBus, I2CAddr)
    {
        this->pos = 0;
        this->number = number;
    }

    void sg90::setPos(uint8_t pos_deg)
    {
        this->pos = pos_deg;
        uint16_t duty = static_cast<uint16_t>((380. / 180) * pos_deg + 0.5) + 100;
        setPWM(this->number, duty);
    }

    sg90::~sg90() {}
}

int main()
{
    sg90::sg90 sg90_osci(2, 0x70, 16);
    //sg90::sg90 sg90_servo(2, 0x70, 0);
    uint8_t pos = 0;
    sg90_osci.setPos(pos);
    //sg90_servo.setPos(pos);
}