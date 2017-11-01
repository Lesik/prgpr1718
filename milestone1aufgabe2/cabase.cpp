#include "cabase.h"

#define DEFAULT_WIDTH 50;
#define DEFAULT_HEIGHT 50;

cabase::cabase() {
    cabase(DEFAULT_WIDTH, DEFAULT_HEIGHT);
}

cabase::cabase(int width, int height) {
    cabase::width = width;
    cabase::height = height;
}

cabase::~cabase() {
    // empty deconstructor
}

cabase::setWidth(int width) {
    cabase::width = width;
}

int cabase::getWidth() {
    return cabase::width;
}

cabase::setHeight(int height) {
    cabase::height = height;
}

int cabase::getHeight() {
    return cabase::height;
}
