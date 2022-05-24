#include <iostream>
#include <vector>

using namespace std;

class simple_linear_regression{
    
    public:
    
    double beta_0;
    double beta_1;
    
    void fit(vector<double> x, vector<double> y){
            
            double mean_x = 0.0;
            double mean_y = 0.0;
            for(auto i: x)
                mean_x += i;
            for(auto i: y)
                mean_y += i;
            
            mean_x /= x.size();
            mean_y /= y.size();
            
            double covariance = 0.0;
            double sum_sq = 0.0;
            for(int i = 0;i<x.size();i++){
               covariance += ((y[i] - mean_y) * (x[i] - mean_x));
                sum_sq += ((x[i] - mean_x)*(x[i] - mean_x));
              };
              
              beta_1 = covariance/sum_sq;
              beta_0 = mean_y - beta_1*mean_x;
        };
        
        vector<double> predict(vector<double> x){
            
            vector<double> y(x.size());
            
            for(int i=0;i<x.size();i++)
                y[i] = x[i]*beta_1+beta_0;
            
            return y;
            };
    };
    

int main()
{

    
return 0;    
}
