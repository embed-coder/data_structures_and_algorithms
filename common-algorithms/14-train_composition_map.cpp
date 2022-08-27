/* 
A TrainComposition is built by attaching and detaching wagons from the left and the right sides, efficiently with respect to time used.

For example, if we start by attaching wagon 7 from the left followed by attaching wagon 13, again from the left, we get a composition of two wagons (13 and 7 from left to right). Now the first wagon that can be detached from the right is 7 and the first that can be detached from the left is 13.

Implement a TrainComposition that models this problem.

train
 */
#include <stdexcept>
#include <iostream>
#include <unordered_map>

using namespace std;
class TrainComposition
{
private:
    // {wagonId {left, right}}
    unordered_map<int, pair<int, int>> mWagons;
    int mWagonId;
public:
    void attachWagonFromLeft(int wagonId)
    {
        unordered_map<int, pair<int, int>>::const_iterator got = mWagons.find(wagonId);
        if (got == mWagons.end()) { // not found
            mWagons.insert({mWagonId, {0, 0}});
            mWagons[mWagonId].first = wagonId;
        } else { // found
            cout << "Wagon was already attached to the Train" << endl;
        }
    }

    void attachWagonFromRight(int wagonId)
    {
        unordered_map<int, pair<int, int>>::const_iterator got = mWagons.find(wagonId);
        if (got == mWagons.end()) { // not found
            mWagons.insert({mWagonId, {0, 0}});
            mWagons[mWagonId].second = wagonId;
        } else { // found
            cout << "Wagon was already attached to the Train" << endl;
        }
    }

    int detachWagonFromLeft()
    {
        int ret;
        unordered_map<int, pair<int, int>>::const_iterator got = mWagons.find(mWagonId);
        if (got == mWagons.end()) { // not found
            mWagons.insert({mWagonId, {0, 0}});
            mWagons[mWagonId].first = wagonId;
        } else { // found
            cout << "Wagon was already attached to the Train" << endl;
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