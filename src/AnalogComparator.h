/*
 .----------------.  .----------------.  .-----------------. .----------------.
| .--------------. || .--------------. || .--------------. || .--------------. |
| |   ________   | || |     _____    | || | ____  _____  | || |     ____     | |
| |  |  __   _|  | || |    |_   _|   | || ||_   \|_   _| | || |   .'    `.   | |
| |  |_/  / /    | || |      | |     | || |  |   \ | |   | || |  /  .--.  \  | |
| |     .'.' _   | || |      | |     | || |  | |\ \| |   | || |  | |    | |  | |
| |   _/ /__/ |  | || |     _| |_    | || | _| |_\   |_  | || |  \  `--'  /  | |
| |  |________|  | || |    |_____|   | || ||_____|\____| | || |   `.____.'   | |
| |              | || |              | || |              | || |              | |
| '--------------' || '--------------' || '--------------' || '--------------' |
 '----------------'  '----------------'  '----------------'  '----------------'

 Created by: Saleem Hadad
 Date: 1/1/2018
 Github: https://github.com/saleem-hadad/zino
*/

#ifndef ZINO_AnalogComparator_h
#define ZINO_AnalogComparator_h

class AnalogComparator
{
public:
  AnalogComparator();
	AnalogComparator(bool enabled, bool bandgabSelected);
  void init(bool enabled, bool bandgabSelected);
	void refresh();
  void enable();
  void disable();
  void enableBandgab();
  void disableBandgab();
  void (*output)(bool);

private:
  bool aboveThreshold();
  unsigned char _acd  = 7;
  unsigned char _acbg = 6;
  unsigned char _aco  = 5;
  unsigned char * _acsr = (unsigned char *) 0x50;
};

#endif
