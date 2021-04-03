#include "Unit.h"
#include "Grid.h"

void Unit::Move(float x, float y)
{
	MyGrid->Move(this, x, y);
}