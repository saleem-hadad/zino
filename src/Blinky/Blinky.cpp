#include "Blinky.h"

void Blinky::initialize(char port, char pin, unsigned int onTime, unsigned int offTime)
{
  if(port == 'B')
  {
    this->portDirection = (unsigned char *) 0x24;
    this->portWriter = (unsigned char *) 0x25;
  }else if(port == 'C')
  {
    this->portDirection = (unsigned char *) 0x27;
    this->portWriter = (unsigned char *) 0x28;
  }else if(port == 'D')
  {
    this->portDirection = (unsigned char *) 0x2A;
    this->portWriter = (unsigned char *) 0x2B;
  }
  
  this->pin = pin;
  *this->portDirection = 1 << this->pin;
  this->onTime = onTime;
  this->offTime = offTime;
}

void Blinky::refresh(void)
{
  unsigned long currentTime = millis();

  if(! ((*this->portWriter) & (1 << this->pin)))
  {
    if (currentTime - this->previousTime >= this->offTime)
    {
      *this->portWriter |= (1 << this->pin);
      this->previousTime = currentTime;
    }
  }else
  {
    if(currentTime - this->previousTime >= this->onTime)
    {
      *this->portWriter &= ~(1 << this->pin);
      this->previousTime = currentTime;
    }
  }
}
