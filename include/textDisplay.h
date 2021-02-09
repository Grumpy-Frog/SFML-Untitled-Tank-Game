#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include "entity.h"

class textDisplay: public entity
{
    public:
        textDisplay();
        virtual ~textDisplay();

        string myString = "Default\n";

        int counter = 0;
        int lifeTime = 100;
        int movementSpeed = 2;
        bool destroy = false;

        void update();
        //void updateMovement();


    protected:

    private:
};;

#endif // TEXTDISPLAY_H
