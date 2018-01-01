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

#ifndef ZINO_ANALOGCOMPARATOR_H
#define ZINO_ANALOGCOMPARATOR_H

class AnalogComparator
{
public:
  /*
    AnalogComparator constructor:
    @params:
    void
    @return:
    void
  */
  AnalogComparator();

  /*
    AnalogComparator constructor:
    @params:
    bool enabled
    bool bandgabSelected
    @return:
    void
  */
	AnalogComparator(bool enabled, bool bandgabSelected);

  /*
    init method:
    @params:
    bool enabled
    bool bandgabSelected
    @return:
    void
  */
  void init(bool enabled, bool bandgabSelected);

  /*
    refresh method:
    @params:
    void
    @return:
    void
    ---
    Should be placed in the main loop of the program.
  */
	void refresh();

  /*
    enable method:
    @params:
    void
    @return:
    void
    ---
    Used to enable the AnalogComparator functionality.
  */
  void enable();

  /*
    disable method:
    @params:
    void
    @return:
    void
    ---
    Used to disable the AnalogComparator functionality
    once you disable the comparator it will stop all
    its functionalities, reading from Pin7 PortD.
  */
  void disable();

  /*
    enableBandgab method:
    @params:
    void
    @return:
    void
    ---
    Use it to set the negative(-) terminal of the
    comparator which is Pin6 on PortD as the
    reference voltage level 1.1v.
  */
  void enableBandgab();

  /*
    disableBandgab method:
    @params:
    void
    @return:
    void
    ---
    Use it to disable the usage of internal bandgab 1.1v
    as the negative(-) terminal of the comparator. By
    disabling it, you have to set the reference by
    yourself on Pin6 PortD so that it works.
  */
  void disableBandgab();

  /*
    callback pointer function:
    @params:
    bool aboveThreshold
    @return:
    void
    ---
    Used as callback function to higher level where you
    can get the updated status of the comparator by
    setting it equal to the pointer of function.
  */
  void (*callback)(bool);

private:
  /*
    aboveThreshold method:
    @params:
    void
    @return:
    void
    ---
    Used internally to check the current status of the
    comparator if it's above the required threshold.
  */
  bool aboveThreshold();

  // The pin's location in the _acsr register.
  unsigned char _acd  = 7;

  // The pin's location in the _acsr register.
  unsigned char _acbg = 6;

  // The pin's location in the _acsr register.
  unsigned char _aco  = 5;

  // The AnalogComparator status register address.
  unsigned char * _acsr = (unsigned char *) 0x50;
};

#endif
