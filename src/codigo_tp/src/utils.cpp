using namespace std;
#include <vector>

double max_element(vector<double> v){
    double max;
    if(v.size() > 0){
        max = v[0];
        for (size_t i = 0; i < v.size(); i++){
            max = (v[i] > max) ? v[i] : max;
        }
    }
    return max;
}

double min_element(vector<double> v){
    double min;
    if(v.size() > 0){
        min = v[0];
        for (size_t i = 0; i < v.size(); i++){
            min = (v[i] < min) ? v[i] : min;
        }
    }
    return min;
}