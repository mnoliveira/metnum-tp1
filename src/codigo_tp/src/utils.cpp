using namespace std;
#include <vector>
#include <math.h>  

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

vector<double> normalize(const vector<double>& arr) {
    vector<double> output{};
    double mod = 0.0;

    for (size_t i = 0; i < arr.size(); ++i) {
        mod += arr[i] * arr[i];
    }

    double mag = sqrt(mod);

    if (mag == 0) {
        // throw logic_error("The input vector is a zero vector");
        return vector<double>{};
    }

    for (size_t i = 0; i < arr.size(); ++i) {
        output[i] = arr[i] / mag;
    }

    return output;
}