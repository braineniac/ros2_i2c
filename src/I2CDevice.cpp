#include"I2CDevice.h"

#include<cstdint>
#include<fcntl.h>
#include<sys/ioctl.h>
#include<unistd.h>
#include<linux/i2c-dev.h>
#include<array>


namespace I2CDevice
{
   I2CDevice::I2CDevice(std::uint8_t bus, std::uint8_t device)
   {
      this->file=-1;
      this->bus = bus;
      this->device = device;
      this->open();
   }

   int I2CDevice::I2CDevice::open()
   {
      std::string bus_name = "/dev/i2c-" + std::to_string(this->bus);
      if((this->file=::open(bus_name.c_str(), O_RDWR)) < 0)
      {
         perror("I2C: failed to open the bus\n");
         return 1;
      }
      if(ioctl(this->file, I2C_SLAVE, this->device) < 0)
      {
         perror("I2C: Failed to connect to the device\n");
         return 1;
      }
      return 0;
   }

   int I2CDevice::writeRegister(std::uint8_t regAddr, std::uint8_t value)
   {
      unsigned char buffer[2];
      buffer[0] = regAddr;
      buffer[1] = value;
      if(::write(this->file, buffer, 2) != 2)
      {
         perror("I2C: Failed write to the device\n");
         return 1;
      }
      return 0;
   }

   int I2CDevice::writeRegisters(std::uint8_t regAddr, std::array<uint8_t, 4> values)
   {
      unsigned char buffer[5];
      buffer[0] = regAddr;
      buffer[1] = values[0];
      buffer[2] = values[1];
      buffer[3] = values[2];
      buffer[4] = values[3];
      if(::write(this->file, buffer, 5) != 5)
      {
         perror("I2C: Failed write to the device\n");
         return 1;
      }
      return 0;
   }

   int I2CDevice::readRegister(std::uint8_t regAddr)
   {
      unsigned char buffer[1];
      buffer[1] = regAddr;
      if(::read(this->file, buffer, 1) != 1)
      {
         perror("I2C: Failed to read in the value.\n");
         return 1;
      }
      return buffer[0];
   }

   void I2CDevice::close()
   {
      ::close(this->file);
      this->file = -1;
   }

   I2CDevice::~I2CDevice()
   {
      if(this->file!=-1) this->close();
   }
}
