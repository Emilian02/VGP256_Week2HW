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
class Equation2
{
public:
    //Solving for average velocity
    float Eq2AverageVelocity(float& vi, float& vf)
    {
        return (vi + vf) / 2;
    }
    //Solving for final velocity
    float Eq2FinalVelocity(float& vi, float& av)
    {
        return (2 * av) - vi;
    }
    //Solving for inicial velocity
    float Eq2InicialVelocity(float& vf, float& av)
    {
        return (2 * av) - vf;
    }


};

//------------------Equation 3------------------
class Equation3
{
public:
    //Solving for displacement
    float Eq3Displacement(float& vi, float& vf, float& time)
    {
        return ((vi + vf) * time) / 2;
    }
    //Solving for final velocity
    float Eq3FinalVelocity(float& vi, float& x, float& time)
    {
        return ((2 * x) / time) - vi;
    }
    //Solving for inicial velocity
    float Eq3InicialVelocity(float& vf, float& x, float& time)
    {
        return ((2 * x) / time) - vf;
    }
    //Solving for time
    float Eq3FTime(float& vi, float& vf, float& x)
    {
        return (2 * x) / (vi + vf);
    }
};

//------------------Equation 4------------------
class Equation4
{
public:
    //Solving for displacement
    float Eq4Displacement(float& vi, float& acc, float& time)
    {
        return (vi * time) + (acc * pow(time, 2)) / 2;
    }
    //Solving for acceleration
    float Eq4FAcceleration(float& vi, float& x, float& time)
    {
        return (2 * (x - (vi * time))) / pow(time, 2);
    }
    //Solving for inicial velocity
    float Eq4InicialVelocity(float& acc, float& x, float& time)
    {
        return (x - (acc * pow(time, 2)) / 2) / time;
    }
    //Solving for time
    void  Eq4FTime(float& vi, float& x, float& acc)
    {
        float a = 0.5f * acc;
        float b = vi;
        float c = x;

        //Calculating discrimant
        float discrimant = b * b - 4 * a * c;

        if (discrimant < 0)
        {
            std::cout << "There's no real solution for this time" << std::endl;
        }

        //Calultaing the time
        discrimant = sqrt(discrimant);
        float t1 = (-b + discrimant) / (2 * a);
        float t2 = (-b - discrimant) / (2 * a);

        std::cout << "Possible times are: " << t1 << " and " << t2 << std::endl;
    }
};

//------------------Equation 5------------------
class Equation5
{
public:
    //Solving for final velocity
    float Eq5FinalVelocity(float& vi, float& acc, float& x)
    {
        float vf = pow(vi, 2) + (2 * acc * x);
        return pow(vf, 2);
    }
    //Solving for inicial velocity
    float Eq5InicialVelocity(float& vf, float& acc, float& x)
    {
        float vi = pow(vf, 2) - (2 * acc * x);
        return pow(vi, 2);
    }
    //Solving for acceleration
    float Eq5Acceleration(float& vi, float& vf, float& x)
    {
        return (pow(vf, 2) - pow(vi, 2)) / (2 * x);
    }
    //Solving for displacement
    float Eq5Displacement(float& vi, float& acc, float& vf)
    {
        return (pow(vf, 2) - pow(vi, 2)) / (2 * acc);
    }
};

int main()
{
    Task1();


}