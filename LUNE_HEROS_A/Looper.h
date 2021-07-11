#ifndef _LOOPER
#define _LOOPER

class Looper
{
private:

	int loopDelay;
	int lastMilliSecond;

public:

	Looper();
	Looper(int loopDelay);

};

#endif
