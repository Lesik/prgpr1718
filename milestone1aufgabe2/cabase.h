#ifndef CAbase
#define CAbase

class CAbase {
    private:
    int width;
    int height;
    int** currentworld;
    int** nextgenworld;

    public:
    CAbase();
    CAbase(int width, int height);
    ~CAbase();
}

#endif
