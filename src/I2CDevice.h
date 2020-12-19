#ifndef I2CDEVICE_H
#define I2CDEVICE_H

#include<cstdint>
#include<array>

namespace I2CDevice
{
    class I2CDevice
    {
        public:
            I2CDevice(std::uint8_t bus, std::uint8_t device);
            virtual ~I2CDevice();

            virtual int open();
            virtual void close();
            
            virtual int readRegister(std::uint8_t regAddr);
            virtual int writeRegister(std::uint8_t regAddr, std::uint8_t value);
            virtual int writeRegisters(std::uint8_t regAddr, std::array<std::uint8_t, 4> values);
            
        private:
            std::uint8_t bus, device;
            int file;
    };
}

#endif