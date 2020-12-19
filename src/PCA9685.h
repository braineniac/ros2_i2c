#ifndef PCA9685_H
#define PCA9685_H

#include"I2CDevice.h"

#include<cstdint>
#include<array>

namespace PCA9685
{
    
    class PCA9685: protected I2CDevice::I2CDevice
    {
        public:
            PCA9685(std::uint8_t I2CBus, std::uint8_t I2CAddr);
            ~PCA9685();

            virtual void setFrequency(std::uint16_t frequency);
            virtual int getFrequency() { return this->frequency; }

            virtual void setPWM(std::uint8_t number, std::uint16_t duty);
            virtual int getPWM(std::uint8_t number) { return this->pwm[number]; }

        private:
            std::uint8_t I2CBus, I2CAddress;
            std::array<std::uint16_t, 16U> pwm;
            std::uint16_t frequency;

            int usleep(std::uint16_t time);
    };

    constexpr std::uint32_t INT_CLCK = UINT32_C(27'000'000);

    namespace reg
    {
        /* mode registers */
        constexpr std::uint8_t MODE1 = UINT8_C(0x00);
        constexpr std::uint8_t MODE2 = UINT8_C(0x01);

        /* I2C bus subaddress registers */
        constexpr std::uint8_t SUBADR1 = UINT8_C(0x02);
        constexpr std::uint8_t SUBADR2 = UINT8_C(0x03);
        constexpr std::uint8_t SUBADR3 = UINT8_C(0x04);
        
        /* LED all call I2C address */
        constexpr std::uint8_t ALLCALLADR = UINT8_C(0x05);

        /* LED register addresses */
        constexpr std::uint8_t LED0_ON_L = UINT8_C(0x06);
        constexpr std::uint8_t LED0_ON_H = UINT8_C(0x07);
        constexpr std::uint8_t LED0_OFF_L = UINT8_C(0x08);
        constexpr std::uint8_t LED0_OFF_H = UINT8_C(0x09);

        constexpr std::uint8_t LED1_ON_L = UINT8_C(0x0A);
        constexpr std::uint8_t LED1_ON_H = UINT8_C(0x0B);
        constexpr std::uint8_t LED1_OFF_L = UINT8_C(0x0C);
        constexpr std::uint8_t LED1_OFF_H = UINT8_C(0x0D);

        constexpr std::uint8_t LED2_ON_L = UINT8_C(0x0E);
        constexpr std::uint8_t LED2_ON_H = UINT8_C(0x0F);
        constexpr std::uint8_t LED2_OFF_L = UINT8_C(0x10);
        constexpr std::uint8_t LED2_OFF_H = UINT8_C(0x11);

        constexpr std::uint8_t LED3_ON_L = UINT8_C(0x12);
        constexpr std::uint8_t LED3_ON_H = UINT8_C(0x13);
        constexpr std::uint8_t LED3_OFF_L = UINT8_C(0x14);
        constexpr std::uint8_t LED3_OFF_H = UINT8_C(0x15);

        constexpr std::uint8_t LED4_ON_L = UINT8_C(0x16);
        constexpr std::uint8_t LED4_ON_H = UINT8_C(0x17);
        constexpr std::uint8_t LED4_OFF_L = UINT8_C(0x18);
        constexpr std::uint8_t LED4_OFF_H = UINT8_C(0x19);

        constexpr std::uint8_t LED5_ON_L = UINT8_C(0x1A);
        constexpr std::uint8_t LED5_ON_H = UINT8_C(0x1B);
        constexpr std::uint8_t LED5_OFF_L = UINT8_C(0x1C);
        constexpr std::uint8_t LED5_OFF_H = UINT8_C(0x1D);

        constexpr std::uint8_t LED6_ON_L = UINT8_C(0x1E);
        constexpr std::uint8_t LED6_ON_H = UINT8_C(0x1F);
        constexpr std::uint8_t LED6_OFF_L = UINT8_C(0x20);
        constexpr std::uint8_t LED6_OFF_H = UINT8_C(0x21);

        constexpr std::uint8_t LED7_ON_L = UINT8_C(0x22);
        constexpr std::uint8_t LED7_ON_H = UINT8_C(0x23);
        constexpr std::uint8_t LED7_OFF_L = UINT8_C(0x24);
        constexpr std::uint8_t LED7_OFF_H = UINT8_C(0x25);

        constexpr std::uint8_t LED8_ON_L = UINT8_C(0x26);
        constexpr std::uint8_t LED8_ON_H = UINT8_C(0x27);
        constexpr std::uint8_t LED8_OFF_L = UINT8_C(0x28);
        constexpr std::uint8_t LED8_OFF_H = UINT8_C(0x29);

        constexpr std::uint8_t LED9_ON_L = UINT8_C(0x2A);
        constexpr std::uint8_t LED9_ON_H = UINT8_C(0x2B);
        constexpr std::uint8_t LED9_OFF_L = UINT8_C(0x2C);
        constexpr std::uint8_t LED9_OFF_H = UINT8_C(0x2D);

        constexpr std::uint8_t LED10_ON_L = UINT8_C(0x2E);
        constexpr std::uint8_t LED10_ON_H = UINT8_C(0x2F);
        constexpr std::uint8_t LED10_OFF_L = UINT8_C(0x30);
        constexpr std::uint8_t LED10_OFF_H = UINT8_C(0x31);

        constexpr std::uint8_t LED11_ON_L = UINT8_C(0x32);
        constexpr std::uint8_t LED11_ON_H = UINT8_C(0x33);
        constexpr std::uint8_t LED11_OFF_L = UINT8_C(0x34);
        constexpr std::uint8_t LED11_OFF_H = UINT8_C(0x35);

        constexpr std::uint8_t LED12_ON_L = UINT8_C(0x36);
        constexpr std::uint8_t LED12_ON_H = UINT8_C(0x37);
        constexpr std::uint8_t LED12_OFF_L = UINT8_C(0x38);
        constexpr std::uint8_t LED12_OFF_H = UINT8_C(0x39);

        constexpr std::uint8_t LED13_ON_L = UINT8_C(0x3A);
        constexpr std::uint8_t LED13_ON_H = UINT8_C(0x3B);
        constexpr std::uint8_t LED13_OFF_L = UINT8_C(0x3C);
        constexpr std::uint8_t LED13_OFF_H = UINT8_C(0x3D);

        constexpr std::uint8_t LED14_ON_L = UINT8_C(0x3E);
        constexpr std::uint8_t LED14_ON_H = UINT8_C(0x3F);
        constexpr std::uint8_t LED14_OFF_L = UINT8_C(0x40);
        constexpr std::uint8_t LED14_OFF_H = UINT8_C(0x41);

        constexpr std::uint8_t LED15_ON_L = UINT8_C(0x42);
        constexpr std::uint8_t LED15_ON_H = UINT8_C(0x43);
        constexpr std::uint8_t LED15_OFF_L = UINT8_C(0x44);
        constexpr std::uint8_t LED15_OFF_H = UINT8_C(0x45);

        constexpr std::uint8_t ALL_LED_ON_L = UINT8_C(0xFA);
        constexpr std::uint8_t ALL_LED_ON_H = UINT8_C(0xFB);
        constexpr std::uint8_t ALL_LED_OFF_L = UINT8_C(0xFC);
        constexpr std::uint8_t ALL_LED_OFF_H = UINT8_C(0xFD);
        
        /* prescaler for PWM */
        constexpr std::uint8_t PRE_SCALE = UINT8_C(0xFE);

        /* test mode */
        constexpr std::uint8_t TestMode = UINT8_C(0xFF);
    }

    constexpr std::array<uint8_t, 17> led {
        reg::LED0_ON_L,
        reg::LED1_ON_L,
        reg::LED2_ON_L,
        reg::LED3_ON_L,
        reg::LED4_ON_L,
        reg::LED5_ON_L,
        reg::LED6_ON_L,
        reg::LED7_ON_L,
        reg::LED8_ON_L,
        reg::LED9_ON_L,
        reg::LED10_ON_L,
        reg::LED11_ON_L,
        reg::LED12_ON_L,
        reg::LED13_ON_L,
        reg::LED14_ON_L,
        reg::LED15_ON_L,
        reg::ALL_LED_ON_L
    };

    namespace BIT
    {
        constexpr std::uint8_t SLEEP = UINT8_C(0b1'0000);
        constexpr std::uint8_t RESTART = UINT8_C(0b1000'0000);
        constexpr std::uint8_t AUTO_INC = UINT8_C(0b10'0000);
    }
}

#endif