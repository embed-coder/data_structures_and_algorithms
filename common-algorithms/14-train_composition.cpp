/* 
A TrainComposition is built by attaching and detaching wagons from the left and the right sides, efficiently with respect to time used.

For example, if we start by attaching wagon 7 from the left followed by attaching wagon 13, again from the left, we get a composition of two wagons (13 and 7 from left to right). Now the first wagon that can be detached from the right is 7 and the first that can be detached from the left is 13.

Implement a TrainComposition that models this problem.

train
 */
#include <stdexcept>
#include <iostream>

// class Wagon
// {
// public:
//     int mWagonNumber = -1;
//     Wagon *left;
//     Wagon *right;

//     Wagon(int wagon_number = -1) : mWagonNumber(wagon_number) {}
// };

typedef struct Wagon
{
    int mWagonNumber;
    Wagon *left;
    Wagon *right;

    Wagon(int wagon_number = -1) : mWagonNumber(wagon_number) {}
}Wagon;

class TrainComposition
{
private:
    Wagon *mpWagons;
public:
    TrainComposition() {
        mpWagons = new Wagon();
    }

    void attachWagonFromLeft(int wagonId)
    {
        Wagon *p_wagons_tmp = mpWagons;
        if (mpWagons->mWagonNumber != -1) {
            while (p_wagons_tmp->left) {
                p_wagons_tmp = p_wagons_tmp->left;
            }
            p_wagons_tmp->left = new Wagon(wagonId);
        } else {
            mpWagons->mWagonNumber = wagonId;
        }
    }

    void attachWagonFromRight(int wagonId)
    {
        Wagon *p_wagons_tmp = mpWagons;
        if (mpWagons->mWagonNumber != -1) {
            while (p_wagons_tmp->right) {
                p_wagons_tmp = p_wagons_tmp->right;
            }
            p_wagons_tmp->right = new Wagon(wagonId);
        } else {
            mpWagons->mWagonNumber = wagonId;
        }
    }

    int detachWagonFromLeft()
    {
        int ret;
        Wagon *p_wagons_tmp = mpWagons;
        if (mpWagons->mWagonNumber != -1) {
            while (p_wagons_tmp->left) {
                p_wagons_tmp = p_wagons_tmp->left;
            }
            ret = p_wagons_tmp->mWagonNumber;
            mpWagons = p_wagons_tmp->right;
            delete(p_wagons_tmp);
        } else {
            mpWagons->mWagonNumber = -1;
        }
        return ret;
    }

    int detachWagonFromRight()
    {
        int ret;
        Wagon *p_wagons_tmp = mpWagons;
        if (mpWagons->mWagonNumber != -1) {
            while (p_wagons_tmp->right) {
                p_wagons_tmp = p_wagons_tmp->right;
            }
            ret = p_wagons_tmp->mWagonNumber;
            mpWagons = p_wagons_tmp->left;
            delete(p_wagons_tmp);
        } else {
            mpWagons->mWagonNumber = -1;
        }
        return ret;
    }
};

#ifndef RunTests
int main()
{
    TrainComposition train;
    train.attachWagonFromLeft(7);
    train.attachWagonFromLeft(13);
    std::cout << train.detachWagonFromRight() << "\n"; // 7 
    std::cout << train.detachWagonFromLeft() << "\n"; // 13
}
#endif