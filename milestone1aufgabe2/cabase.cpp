#include "cabase.h"

#define DEFAULT_WIDTH 50;
#define DEFAULT_HEIGHT 50;

class CAbase {
    CAbase() {
        CAbase(DEFAULT_WIDTH, DEFAULT_HEIGHT);
    }

    CAbase(width, height) {
        CAbase::width = width;
        CAbase::height = height;
    }

    ~CAbase() {
        // empty deconstructor
    }

    setWidth(width) {
        CAbase::width = width;
    }

    getWidth() {
        return CAbase::width;
    }

    setHeight(height) {
        CAbase::height = height;
    }

    getHeight() {
        return CAbase::height;
    }
}
