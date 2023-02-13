#include <iostream>
// dynamic allocation with single 'new' statement

int* create2Dint(int rows, int cols){
    if (rows <= 0 || cols <= 0)
    {
        return NULL;
    }

    int* mat = new int [rows * cols];     
    
    for (int i = 0; i < rows; i++)
    {   for (int j = 0; j < cols; j++)
        {
            *((mat + i) + j) = rand()%100;
        }   
    }
    
    return mat;
    
}



void free2DInt(int* mat, int rows, int cols){
    if (mat != NULL)
    {
        delete [] mat;      // 전체 mat만 해제
    }
}

void print2DInt(int *mat, int rows, int cols){
    
    printf("rows = %d, cols = %d\n", rows, cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d\t", *((mat + i) + j));
        }
        printf("\n");
    }
}

int main(){
    int *mat;
    int rows, cols;

    printf("Enter rows and cols : ");
    scanf("%d%d", &rows, &cols);

    mat = create2Dint(rows, cols);
    print2DInt(mat, rows, cols);
    free2DInt(mat, rows, cols);
}