#include <Blinky.h>
#include <AnalogComparator.h>

Blinky led;
AnalogComparator comparator;

void comparatorOutput(bool aboveThreshold)
{
  if (! aboveThreshold) { return; }

  //blink LED only if the comparatorOutput aboveThreshold
  led[0].refresh();
}

void setup()
{
  comparator.init(true, true); //enabled, bandgabSelected
  led[0].init(Pin(PortB, 0), 600, 650);
}

void loop()
{
  comparator.refresh();
}
