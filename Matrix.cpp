#include "Matrix.h"

Matrix::Matrix()
    : rows(0), columns(0), data(NULL)
{
}

Matrix::Matrix(uint32_t rows, uint32_t columns)
{
    this->rows = rows;
    this->columns = columns;
    allocateData();
}

Matrix::~Matrix()
{
    for (uint32_t i = 0; i < rows; i++)
    {
        delete[] data[i];
    }
    delete[] data;
}


void Matrix::allocateData()
{
    data = new uint32_t *[rows];
    for (uint32_t i = 0; i < rows; i++)
    {
        data[i] = new uint32_t[columns];
    }
}

void Matrix::fillWithRandomData()
{
    for (uint32_t i = 0; i < rows; i++)
    {
        for (uint32_t j = 0; j < columns; j++)
        {
            data[i][j] = (rand() % 100) + 1;
        }
    }
}

void Matrix::createWithUserData(uint32_t & scale)
{
    std::cout << "put rows number" << std::endl;
    std::cin >> rows;
    std::cout << "put columns number" << std::endl;
    std::cin >> columns;
    std::cout << "put scale number" << std::endl;
    std::cin >> scale;
    allocateData();
}

void Matrix::display()
{
    for (uint32_t i = 0; i < rows; i++)
    {
        for (uint32_t j = 0; j < columns; j++)
        {
            std::cout << data[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

Matrix *Matrix::createScaleMatrix(uint32_t scale)
{
    uint32_t rows = scale * this->rows;
    uint32_t columns = scale * this->columns;
    Matrix *pScaledMatrix = new Matrix(rows, columns);

    for (uint32_t i = 0; i < rows; i++)
    {
        for (uint32_t j = 0; j < columns; j++)
        {
            uint32_t di = i / scale;
            uint32_t dj = j / scale;
            pScaledMatrix->addElement(i, j, data[di][dj]);

        }
    }
    return pScaledMatrix;
}

void Matrix::addElement(uint32_t row, uint32_t column, uint32_t element)
{
    data[row][column] = element;
}

uint32_t Matrix::getElement(uint32_t row, uint32_t column)
{
    return data[row][column];
}
