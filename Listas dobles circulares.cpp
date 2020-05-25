#include <iostream>
#include "DoubleCircularList.cpp"

int main()
{
    DoubleCircularList<double> list;

    list.InsertInOrder(15.8);
    list.InsertInOrder(16.8);
    list.InsertInOrder(16.8);
    list.InsertInOrder(16.8);
    //std::cout << list.Quantity() << std::endl; 
    list.Show();
    std::cout << "=========================================" << std::endl;
    list.Remove(15.8);
    std::cout << "Borro el 15.8" << std::endl;
    list.Show();
    std::cout << "==============================================" << std::endl;
    std::cout << "Ahora borros los 16.8" << std::endl;
    list.Remove(16.8);
    list.Show();
    std::cout << "=========================================" << std::endl;
    list.InsertLast(3.2);
    list.InsertLast(5.3);
    list.Show();

    std::cout << "Hello World!\n";
    return 1;
}
