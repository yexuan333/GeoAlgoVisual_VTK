#pragma once

#include <fstream>
#include <string>

class StreamUtil
{
public:
    void static GetDouble(std::ifstream& IS, double& theValue)
    {
        theValue = 0.;
        if (IS.eof()) 
            return;

        char buffer[256];
        buffer[0] = '\0';
        std::streamsize anOldWide = IS.width(256);
        IS >> buffer;
        IS.width(anOldWide);
        theValue = strtod(buffer, NULL);
    }
    void static GetInt(std::ifstream& IS, int& theValue)
    {
        theValue = 0.;
        if (IS.eof())
            return;

        char buffer[256];
        buffer[0] = '\0';
        std::streamsize anOldWide = IS.width(256);
        IS >> buffer;
        IS.width(anOldWide);
        theValue = std::stoi(buffer);
    }
};
