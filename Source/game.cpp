#include "GameManager.h"
#include "LogManager.h"
#include "WorldManager.h"

#include "Vector.h"
#include "Object.h"
#include "ObjectList.h"
#include "ObjectListIterator.h"

#include "TestObject.h"

#define DEBUG_LOG_MANAGER
#define DEBUG_VECTOR
#define DEBUG_OBJECT_LIST
#define DEBUG_OBJECT_LIST_ITER
#define DEBUG_TEST_OBJECT

int main()
{
	if (GM.startUp() != 0)
	{
		return 0;
	}

#ifdef DEBUG_LOG_MANAGER
	LM.writeLog("\nTESTING LOG MANAGER");

	LM.writeLog("Print Test normal string");
	LM.writeLog("Print Test with number: %d", 10);
	LM.writeLog("Print Test with character: %c", 'h');
	LM.writeLog("Print Test with multiple numbers: %d, %d, %d", 1, 2, 3);
	int n = 125;
	LM.writeLog("Print Test with int variable: %d", n);
	const float f = 12.2f;
	LM.writeLog("Print Test with const float variable: %f", f);

	LM.writeLog("TEST COMPLETE\n");
#endif

#ifdef DEBUG_VECTOR
	LM.writeLog("\nTESTING VECTOR");

	df::Vector v1 = df::Vector(0.0f, 2.0f);
	LM.writeLog("Vector v1: %f, %f", v1.getX(), v1.getY());
	v1.setXY(1, 1);
	LM.writeLog("Vector v1: %f, %f", v1.getX(), v1.getY());
	v1.setX(3);
	LM.writeLog("Vector v1: %f, %f", v1.getX(), v1.getY());
	df::Vector v2 = df::Vector();
	v2.setXY(5, 5);
	LM.writeLog("Vector v2: %f, %f", v2.getX(), v2.getY());
	df::Vector v3 = v1 + v2;
	LM.writeLog("Vector v1 + v2: %f, %f", v3.getX(), v3.getY());


	LM.writeLog("TEST COMPLETE\n");
#endif

#ifdef DEBUG_OBJECT_LIST
	LM.writeLog("\nTESTING OBJECT LIST");

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

#ifdef DEBUG_OBJECT_LIST_ITER
	LM.writeLog("\nTESTING OBJECT LIST ITERATOR");

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

	LM.writeLog("\nTESTING OBJECT LIST cont.");

	objectList.remove(p_object1);
	LM.writeLog("Object removed from objectList.");
	LM.writeLog("objectList count: %d", objectList.getCount());
	objectList.remove(p_object2);
	LM.writeLog("Object removed from objectList.");
	LM.writeLog("objectList count: %d", objectList.getCount());
	objectList.remove(p_object2);
	LM.writeLog("Attempting to remove object from objectList that isn't in it.");
	LM.writeLog("objectList count: %d", objectList.getCount());
	objectList.remove(p_object3);
	LM.writeLog("Object removed from objectList.");
	LM.writeLog("objectList count: %d", objectList.getCount());

	WM.shutDown();
	WM.startUp();

	LM.writeLog("TEST COMPLETE\n");
#endif

#ifdef DEBUG_TEST_OBJECT
	LM.writeLog("\nTESTING WORLD MANAGER OBJECT LIST");

	LM.setFlush();
	new TestObject(0, 0);
	WM.getAllObjects();
	new TestObject(0, 5);
	WM.getAllObjects();
	new TestObject(5, 5);
	WM.getAllObjects();

	GM.run();

	LM.writeLog("TEST COMPLETE\n");
#endif

	GM.shutDown();

	return 1;
}