//
// Created by Chen Qingzhi on 2022/4/30.
//

#ifndef HW9_CONTROLLER_H
#define HW9_CONTROLLER_H

#include <algorithm>
#include <vector>
#include <set>
using namespace std;


class controller {
public:
    controller();

private:
    vector<long long> data_with_reps;
    set<long long> data_wo_reps;
};


#endif //HW9_CONTROLLER_H
