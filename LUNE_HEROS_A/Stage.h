#ifndef _STAGE
#define _STAGE

#include "Drawable.h"
#include "Resizable.h"

class Stage : public Drawable, Resizable
{

private:

public:



	virtual void Draw();

	virtual void ReSize(float x, float y);

};


#endif