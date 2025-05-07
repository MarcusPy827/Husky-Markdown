#ifndef COLOR_GEN_HXX
#define COLOR_GEN_HXX

#include "QString"
// #include "../../../../libs/material-color-utilities/cpp/scheme/scheme_neutral.h"
// #include "../../../../libs/material-color-utilities/cpp/utils/utils.h"

class ColorGen {
    public:
        static void generateFromSeed(QString seed, bool isLightMode);
};



#endif //COLOR_GEN_HXX
