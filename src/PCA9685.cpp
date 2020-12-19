#include"PCA9685.h"

#include<cstdint>
#include<array>
#include<time.h>

namespace PCA9685
{

    PCA9685::PCA9685(std::uint8_t I2CBus, std::uint8_t I2CAddr): I2CDevice(I2CBus, I2CAddr)
    {
        this->I2CAddress = I2CAddress;
        this->I2CBus = I2CBus;
        std::fill(this->pwm.begin(), this->pwm.end(), static_cast<std::uint16_t>(0U));
        this->frequency = 200; // board default

        uint8_t mode1 = readRegister(reg::MODE1);
        mode1 |= BIT::RESTART;
        writeRegister(reg::MODE1, mode1);
    }

    void PCA9685::setPWM(std::uint8_t number, std::uint16_t duty)
    {
        uint8_t mode1 = readRegister(reg::MODE1);
        mode1 |= BIT::AUTO_INC;
        writeRegister(reg::MODE1, mode1);

        uint8_t reg_h = (duty>>8) & 0x0F;
        uint8_t reg_l = duty & 0xFF;
        std::array<uint8_t, 4> values {0x00, 0x00, reg_l, reg_h};
        writeRegisters(led[number], values);
        
        mode1 &= ~BIT::AUTO_INC;
        writeRegister(reg::MODE1, mode1);
    }

    void PCA9685::setFrequency(std::uint16_t frequency)
    {
        uint8_t mode1 = readRegister(reg::MODE1);
        mode1 |= BIT::SLEEP;
        writeRegister(reg::MODE1, mode1);

        uint16_t prescale {0};
        prescale = static_cast<std::uint16_t>((INT_CLCK) / (4096 * frequency)) - 1;
        writeRegister(reg::PRE_SCALE, prescale);

        mode1 &= ~BIT::SLEEP;
        mode1 |= BIT::RESTART;
        writeRegister(reg::MODE1, mode1);
        usleep(500);
    }

    int PCA9685::usleep(std::uint16_t time)
    {
        struct timespec req, rem;
        req.tv_sec = 0;
        req.tv_nsec = time * 1'000;
        
        if (::nanosleep(&req, &rem) < 0) return -1;

        return 0;
    }

    PCA9685::~PCA9685() {}

}