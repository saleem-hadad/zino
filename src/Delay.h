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

#ifndef ZINO_DELAY_H
#define ZINO_DELAY_H

class Delay
{
public:
    /*
	Delay constructor:
	@params:
	void
	@return:
	void
    ---
    The default duration of the delay will be set
    to 1000 ms. You can override the threshold
    value using init method in the setup.
	*/
    Delay();

    /*
	Delay constructor:
	@params:
	int duration
	@return:
	void
	*/
    Delay(int duration);

    /*
	init method:
	@params:
	int duration
	@return:
	void
	---
	Used to update the default threshold of the delay
	object. Please note that the time interval is
	determined in ms, e.g. 1 s = to 1000 ms.
	*/
    void init(int duration);

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
      Used to force enable the delay functionality.
    */
    void enable();

    /*
      enable method:
      @params:
      void
      @return:
      void
      ---
      Used to force disable the delay functionality.
    */
    void disable();

    /*
      callback pointer function:
      @params:
      void
      @return:
      void
      ---
      Used as callback function to higher level where you
      can get a notification when the time interval is
      fired, where other logic not affected at all.
    */
    void (*callback)(void);

private:
    // A boolian indicator to track the current status.
    bool _enabled = true;

    // The time interval used as a threshold to fire.
    unsigned long _threshold = 1000;

    // The time used to track the delay time interval.
    unsigned long _previous = 0;
};

#endif
