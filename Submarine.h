#ifndef SUBMARINE_H
#define SUBMARINE_H

#include <iostream>
#include <string>
using namespace std;

// submarine class

class Submarine {
    public:
        Submarine();
        Submarine(int f, int a, int c);

        void addFuel(int f);                /* adds f to fuelAmnt */
        void addAir(int a);                 /* adds a to airAmnt */
        void addCrew(int c);                /* adds c to crewAmnt */

        virtual void incFuelCap(int f);     /* increases fuel capacity */
        virtual void incAirCap(int a);      /* increases air capacity */
        virtual void incCrewCap(int c);     /* increases crew capacity */

        virtual void decFuelCap(int f);     /* decreases fuel capacity */
        virtual void decAirCap(int a);      /* decreases air capacity */
        virtual void decCrewCap(int c);     /* decreases crew capacity */

        void removeFuel(int f);             /* removes f from fuelAmnt */
        void removeAir(int a);              /* removes a from airAmnt */
        void removeCrew(int c);             /* removes c from crewAmnt */

        int getFuel();                      /* returns fuelAmnt */
        int getAir();                       /* returns airAmnt */
        int getCrew();                      /* returns crewAmnt */

        int getFuelCap();                   /* returns fuelCapacity */
        int getAirCap();                    /* returns airCapacity */
        int getCrewCap();                   /* returns crewCapacity */

    protected:
        int fuelAmnt;                       /* curr amnt of fuel */
        int airAmnt;                        /* curr amnt of air */
        int crewAmnt;                       /* curr amnt of crew */

        int fuelCapacity = 20;              /* max amnt of fuel */
        int airCapacity = 20;               /* max amnt of air */
        int crewCapacity = 20;              /* max amnt of crew */
};

// implement public

Submarine::Submarine() {
    int f; int a; int c;
    f = (rand() % 10) + 5;
    a = (rand() % 10) + 5;
    c = (rand() % 10) + 5;

    fuelAmnt = f;
    airAmnt = a;
    crewAmnt = c;
}

Submarine::Submarine(int f, int a, int c) {
    fuelAmnt = f;
    airAmnt = a;
    crewAmnt = c;
}

void Submarine::addFuel(int f) {
    int amntAvailable;
    amntAvailable = fuelCapacity - fuelAmnt;

    if (amntAvailable <= f) {
        fuelAmnt = fuelAmnt + f;
        cout << endl; cout << "Added " << f << " gallons of fuel to tank!" << endl; 
        cout << "Current fuel amount: " << fuelAmnt << "/" << fuelCapacity << endl;
    }

    else if (amntAvailable > f) {
        fuelAmnt = fuelAmnt + amntAvailable;
        cout << endl; cout << "Added " << amntAvailable << " gallons of fuel to tank!" << endl;
        cout << "Current fuel amount: " << fuelAmnt << "/" << fuelCapacity << endl;
    }
}

void Submarine::addAir(int a) {
    int amntAvailable;
    amntAvailable = airCapacity - airAmnt;

    if (amntAvailable <= a) {
        airAmnt = airAmnt + a;
        cout << endl; cout << "Added " << a << " gallons of air to tank!" << endl; 
        cout << "Current air amount: " << airAmnt << "/" << airCapacity << endl;
    }

    else if (amntAvailable > a) {
        airAmnt = airAmnt + amntAvailable;
        cout << endl; cout << "Added " << amntAvailable << " gallons of air to tank!" << endl;
        cout << "Current air amount: " << airAmnt << "/" << airCapacity << endl;
    }
}

void Submarine::addCrew(int c) {
    int amntAvailable;
    amntAvailable = crewCapacity - crewAmnt;

    if (amntAvailable <= c) {
        crewAmnt = crewAmnt + c;
        cout << endl; cout << "Added " << c << " members to crew!" << endl; 
        cout << "Current crew amount: " << crewAmnt << "/" << crewCapacity << endl;
    }

    else if (amntAvailable > c) {
        crewAmnt = crewAmnt + amntAvailable;
        cout << endl; cout << "Added " << amntAvailable << " members to crew!" << endl;
        cout << "Current crew amount: " << crewAmnt << "/" << crewCapacity << endl;
    }
}

void Submarine::incFuelCap(int f){
    fuelCapacity = fuelCapacity + f;
}

void Submarine::incAirCap(int a){
    airCapacity = airCapacity + a;
}

void Submarine::incCrewCap(int c){
    crewCapacity = crewCapacity + c;
}  

void Submarine::decFuelCap(int f){
    fuelCapacity = fuelCapacity - f;
}

void Submarine::decAirCap(int a){
    airCapacity = airCapacity - a;
}

void Submarine::decCrewCap(int c){
    crewCapacity = crewCapacity - c;
}

void Submarine::removeFuel(int f) {
    if (f >= fuelAmnt) {
        fuelAmnt = 0;
        cout << endl; cout << "Current fuel amount: " << fuelAmnt << "/" << fuelCapacity << endl;
        cout << "Game End! Better luck next time." << endl;
        // TODO: END GAME !!!!!
    }

    else if (f < fuelAmnt) {
        fuelAmnt = fuelAmnt - f;
        cout << endl; cout << "Used up " << f << " gallons of fuel from tank." << endl;
        cout << "Current fuel amount: " << fuelAmnt << "/" << fuelCapacity << endl;
    }
}

void Submarine::removeAir(int a){
    if (a >= airAmnt) {
        airAmnt = 0;
        cout << endl; cout << "Current air amount: " << airAmnt << "/" << airCapacity << endl;
        cout << "Game End! Better luck next time." << endl;
        // TODO: END GAME !!!!!
    }

    else if (a < fuelAmnt) {
        airAmnt = airAmnt - a;
        cout << endl; cout << "Used up " << a << " gallons of air from tank." << endl;
        cout << "Current air amount: " << airAmnt << "/" << airCapacity << endl;
    }
}

void Submarine::removeCrew(int c){
    if (c >= crewAmnt) {
        crewAmnt = 0;
        cout << endl; cout << "Current crew members: " << crewAmnt << "/" << crewCapacity << endl;
        cout << "Game End! Better luck next time." << endl;
        // TODO: END GAME !!!!!!
    }

    else if (c < crewAmnt) {
        crewAmnt = crewAmnt - c;
        cout << endl; cout << "Lost " << c << " members from crew." << endl;
        cout << "Current crew members: " << crewAmnt << "/" << crewCapacity << endl;
    }
}

int Submarine::getFuel() {
    return fuelAmnt;
}

int Submarine::getAir(){
    return airAmnt;
}

int Submarine::getCrew() {
    return crewAmnt;
}

int Submarine::getFuelCap(){
    return fuelCapacity;
}

int Submarine::getAirCap(){
    return airCapacity;
}

int Submarine::getCrewCap(){
    return crewCapacity;
}

#endif