
#ifndef OURSERVER_MAIN1_H
#define OURSERVER_MAIN1_H

#include <iostream>
#include "Main.h"

bool time_out = false;

using namespace boot;

int main(int argc, char *argv[])
{
    Main main1;
    main1.main(argc,argv);
    return 0;
}

#endif //OURSERVER_MAIN1_H

