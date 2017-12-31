//
// Created by Saleem Hadad on 1/1/2018.
//

#ifndef ZINO_Delay_h
#define ZINO_Delay_h

class Delay
{
public:
  Delay();
	Delay(int duration);
  void init(int duration);
	void refresh();
  void enable();
  void disable();
  void (*callback)(void);

private:
  bool _enabled = true;
  int _threshold = 1000;
  unsigned long _previous = 0;
};

#endif
