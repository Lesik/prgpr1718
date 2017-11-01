#include "cabase.h"

#define DEFAULT_WIDTH 50;
#define DEFAULT_HEIGHT 50;

CAbase::CAbase() {
    CAbase(DEFAULT_WIDTH, DEFAULT_HEIGHT);
}

CAbase::CAbase(width, height) {
}

CAbase::~CAbase() {
    // empty deconstructor
}

CAbase::setWidth(width) {
    CAbase::width = width;
}

CAbase::getWidth() {
    return CAbase::width;
}

CAbase::setHeight(height) {
    CAbase::height = height;
}

CAbase::getHeight() {
    return CAbase::height;
}
