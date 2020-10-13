#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <cstdint>

class Matrix
{

    uint32_t rows;
    uint32_t columns;
    uint32_t scale;
    uint32_t ** data;

public:

    Matrix();
    Matrix(uint32_t rows, uint32_t columns);
    ~Matrix();

    void fillWithRandomData();
    void createWithUserData(uint32_t & scale);
    
    void display();
    void allocateData();
    Matrix* createScaleMatrix(uint32_t scale);

    void addElement(uint32_t row, uint32_t column, uint32_t element);
    uint32_t getElement(uint32_t row, uint32_t column);
};

