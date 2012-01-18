#pragma once
#include "gregorian.h"

namespace lab2 {

class Rebecca :
	public Gregorian
{
public:
	Rebecca(void);
	~Rebecca(void);

	const virtual int day() const;
};

}

