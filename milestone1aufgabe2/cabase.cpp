#include "cabase.h"

#define DEFAULT_WIDTH 50;
#define DEFAULT_HEIGHT 50;

CAbase::CAbase() {
    CAbase(DEFAULT_WIDTH, DEFAULT_HEIGHT);
}

CAbase::CAbase(int width, int height) {
    CAbase::width = width;
    CAbase::height = height;
}

CAbase::~CAbase() {
    // empty deconstructor
}

CAbase::setWidth(int width) {
    CAbase::width = width;
}

int CAbase::getWidth() {
    return CAbase::width;
}

CAbase::setHeight(int height) {
    CAbase::height = height;
}

int CAbase::getHeight() {
    return CAbase::height;
}
