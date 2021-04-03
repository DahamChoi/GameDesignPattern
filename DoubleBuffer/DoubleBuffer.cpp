#include "Stage.h"
#include "Comedian.h"

int main()
{
	Stage stage;

	Comedian* c1 = new Comedian("Harry");
	Comedian* c2 = new Comedian("Baldy");
	Comedian* c3 = new Comedian("Chump");

	c1->Face(c2);
	c2->Face(c3);
	c3->Face(c1);

	stage.Add(c3);
	stage.Add(c2);
	stage.Add(c1);

	c1->Slap();
	stage.Update();
	stage.Update();
	stage.Update();
}