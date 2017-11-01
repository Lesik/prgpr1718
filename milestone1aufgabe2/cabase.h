#ifndef cabase
#define cabase

class cabase {
    private:
        int width;
        int height;
        int** currentworld;
        int** nextgenworld;

    public:
        cabase();
        cabase(int width, int height);
        ~cabase();
};

#endif
