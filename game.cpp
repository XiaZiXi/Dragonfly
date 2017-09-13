#include "GameManager.h"
#include "LogManager.h"

#include "Object.h"
#include "ObjectList.h"
#include "ObjectListIterator.h"

#define DEBUG_OBJECT_LIST

int main()
{
	if (GM.startUp() != 0)
	{
		return 0;
	}

#ifdef DEBUG_OBJECT_LIST
	df::Object *p_object1 = new df::Object();
	p_object1->setType("square");
	LM.writeLog("Object created with Type: %s", p_object1->getType().c_str());
	df::Object *p_object2 = new df::Object();
	p_object2->setType("circle");
	LM.writeLog("Object created with Type: %s", p_object2->getType().c_str());
	df::Object *p_object3 = new df::Object();
	p_object3->setType("triangle");
	LM.writeLog("Object created with Type: %s", p_object3->getType().c_str());

	df::ObjectList objectList = df::ObjectList();
	objectList.insert(p_object1);
	LM.writeLog("Object added to objectList.");
	LM.writeLog("objectList count: %d", objectList.getCount());
	objectList.insert(p_object2);
	LM.writeLog("Object added to objectList.");
	LM.writeLog("objectList count: %d", objectList.getCount());
	objectList.insert(p_object3);
	LM.writeLog("Object added to objectList.");
	LM.writeLog("objectList count: %d", objectList.getCount());

	df::ObjectListIterator objListIter = df::ObjectListIterator(&objectList);
	for (int i = 0; i <= objectList.getCount(); i++)
	{
		bool isDone = objListIter.isDone();
		LM.writeLog("objListIter isDone: %d", isDone);
		if (isDone)
		{
			break;
		}
		else
		{
			std::string objType = objListIter.currentObject()->getType();
			LM.writeLog("objListIter current Object's type: %s", objType.c_str());
			objListIter.next();
		}
	}
#endif

	GM.shutDown();

	return 1;
}