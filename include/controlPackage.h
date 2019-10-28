struct controlStruct
{
    int speed;       // Between -512 and 512
    int bearing;     // Between -512 and 512
    bool honk;       // True if pressed
    bool headlights; // True to activate headlights
};

extern controlStruct pkg; // Control instructions from remote
void printPackage();      // Print control package to Serial