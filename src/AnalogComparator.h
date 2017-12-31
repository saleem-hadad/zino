//
// Created by Saleem Hadad on 1/1/2018.
//

#ifndef ZINO_AnalogComparator_h
#define ZINO_AnalogComparator_h

class AnalogComparator
{
public:
	AnalogComparator(bool enabled, bool bandgabSelected);
	void refresh();
  void enable();
  void disable();
  void (*output)(bool);

private:
  bool aboveThreshold();
  unsigned char _acd  = 7;
  unsigned char _acbg = 6;
  unsigned char _aco  = 5;
  unsigned char * _acsr = (unsigned char *) 0x50;
};

#endif
