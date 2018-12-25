#include <iostream>
#include <fstream>
#include <list>
#include "Translator.h"
using namespace std;


int main() {
    string str = "openDataServer 5400 10\n"
                 "connect 127.0.0.1 5402\n"
                 "var breaks = bind \"/controls/flight/speedbrake\"\n"
                 "var throttle = bind \"/controls/engines/engine/throttle\"\n"
                 "var heading = bind \"/instrumentation/heading-indicator/offset-deg\"\n"
                 "var airspeed = bind \"/instrumentation/airspeed-indicator/indicated-speed-kt\"\n"
                 "var roll = bind \"/instrumentation/attitude-indicator/indicated-roll-deg\"\n"
                 "var pitch = bind \"/instrumentation/attitude-indicator/internal-pitch-deg\"\n"
                 "var rudder = bind \"/controls/flight/rudder\"\n"
                 "var aileron = bind \"/controls/flight/aileron\"\n"
                 "var elevator = bind \"/controls/flight/elevator\"\n"
                 "var alt = bind \"/instrumentation/altimeter/indicated-altitude-ft\"\n"
                 "breaks = 0\n"
                 "throttle = 1\n"
                 "var h0 = heading\n"
                 "while alt < 1000 {\n"
                 "rudder = (h0 - heading)/20\n"
                 "aileron = - roll / 70\n"
                 "elevator = pitch / 50\n"
                 "print alt\n"
                 "sleep 250\n"
                 "}\n"
                 "print \"done\"";

    map<string, Command> symbolTable;
    Translator *t = new Translator(symbolTable);
    list<string> s;
    s = t->lexer(str);
    list<string>::iterator iter;
    for (iter = s.begin(); iter != s.end(); iter++)
        cout << *iter << endl;
    return 0;
}