#include <iostream>
#include <vector>
#include <cmath>


//------------------Task 1------------------

//For getting the derivative of the polynomial
std::vector<float> DerivativeOfPoly(const std::vector<float>& coefficients)
{
    std::vector<float> derivative;
    
    for (int i = 0; i < coefficients.size() - 1; ++i)
    {
        derivative.push_back(coefficients[i] * (coefficients.size() - 1 - i));
    }

    return derivative;
}

//For getting the result of the function
float Results(const std::vector<float>& coefficients, float x)
{
    float result = 0.0f;
    
    for (int i = 0; i < coefficients.size() - 1; ++i)
    {
        result += coefficients[i] * std::pow(x, coefficients.size() - 1 - i);
    }

    return result;
}


void Task1()
{
    std::vector<float> coefficients;
    float degree;
    float x;

    //Getting the degree of the polynomial
    std::cout << "Enter the degree of the polynomial: ";
    std::cin >> degree;

    //Adding the coefficients to the vector
    std::cout << "\nEnter the coefficients starting from the highest degree: \n";
    for (int i = 0; i <= degree; ++i)
    {
        float coeff;
        std::cout << "Coefficient for x^" << degree - i << ": ";
        std::cin >> coeff;
        coefficients.push_back(coeff);
    }
    
    //Getting the x value
    std::cout << "\nWhat's x value: ";
    std::cin >> x;

    //We get the velocity from the first derivative
    std::vector<float> derVelocity = DerivativeOfPoly(coefficients);
    //We get the accelartion from the second derivative
    std::vector<float> derAcceleration = DerivativeOfPoly(derVelocity);
    
    //Evaluating the polynomials
    float velocity = Results(derVelocity, x);
    float acceleration = Results(derAcceleration, x);


    std::cout << "Instant velocity at x = " << x << " is: " << velocity << std::endl;
    std::cout << "Instant acceleration at x = " << x << " is: " << acceleration << std::endl;

}

//------------------Task 2------------------
//------------------Equation 1------------------
class Equation1
{
public:
    //Solving for final velocity
    float Eq1FinalVelocity(float& vi, float& acc, float& time)
    {
        return vi + (acc * time);
    }
    //Solving for inicial velocity
    float Eq1InicialVelocity(float& vf, float& acc, float& time)
    {
        return vf - (acc * time);
    }
    //Solving for acceleration
    float Eq1Acceleration(float& vi, float& vf, float& time)
    {
        return (vf - vi) / time;
    }
    //Solving for time
    float Eq1FTime(float& vi, float& acc, float& vf)
    {
        return (vf - vi) / acc;
    }

};


//------------------Equation 2------------------
//Solving for final velocity
float Eq2FinalVelocity(float& vi, float& acc, float& time)
{
    return vi + (acc * time);
}
//Solving for inicial velocity
float Eq2InicialVelocity(float& vf, float& acc, float& time)
{
    return vf - (acc * time);
}
//Solving for acceleration
//------------------Equation 3------------------

//------------------Equation 4------------------

//------------------Equation 5------------------

int main()
{
    Task1();


}