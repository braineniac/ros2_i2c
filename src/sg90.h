#ifndef SG90_H
#define SG90_H

#include"PCA9685.h"
#include<cstdint>

namespace sg90
{
    class sg90: protected PCA9685::PCA9685
    {
        public:
            sg90(uint8_t I2CBus, uint8_t I2CAddr, uint8_t number);
            ~sg90();

            virtual void setPos(uint8_t pos_deg);
            virtual uint8_t getPos() { return this->pos; };

        private:
            uint8_t pos, number;
    };

}

#endif