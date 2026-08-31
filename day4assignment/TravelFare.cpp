// //2. Calculate Travel Fare
// Create a Booking class to store bookingid, source, destination, distance,fare
// Add all required functions(copy constructor parametrised constructor with default values, setter, getter methods)
// And overload calculateFare().
// Overload << and >> operator to accept and display Booking class object
// The function should calculate the fare in different ways:
// Calculate fare based only on the distance travelled.
// Calculate fare based on distance and vehicle type.
// Calculate fare based on distance, vehicle type, and number of passengers.
// Calculate fare for a premium booking with additional service charges.
// Task: Use function overloading to provide different versions of calculateFare().
#include <iostream>
#include <cstring>
using namespace std;
class Booking{
    private:
        int bid;
        char* source;
        char* destination;
        double distance;
        double fare;
    public:
        Booking(int id=0, const char* src="Unknown", const char* dest="Unknown", double dist=0.0, double f=0.0)
        {
            bid = id;
            source = new char[strlen(src) + 1];
            strcpy(source, src);
            destination = new char[strlen(dest) + 1];
            strcpy(destination, dest);
            distance = dist;
            fare = f;
        }
        void setData(int id, const char* src, const char* dest, double dist, double f)
        {
            bid = id;
            source = new char[strlen(src) + 1];
            strcpy(source, src);
            destination = new char[strlen(dest) + 1];
            strcpy(destination, dest);
            distance = dist;
            fare = f;
        }
        void displayData()
        {
            cout<<"Booking ID: "<<bid<<endl;
            cout<<"Source: "<<source<<endl;
            cout<<"Destination: "<<destination<<endl;
            cout<<"Distance: "<<distance<<endl;
            cout<<"Fare: "<<fare<<endl;

        }
        double calculateFare()
        {
            return distance * 10; // base fare calculation
        }
        double calculateFare(double vehicleType)
        {
            return (distance * 10) * vehicleType; // fare based on vehicle type
        }
        double calculateFare(double vehicleType, int passengers)
        {
            return ((distance * 10) * vehicleType) + (passengers * 5); // fare based on vehicle type and passengers
        }
        double calculateFare(double vehicleType, int passengers, double serviceCharge)
        {
            return ((distance * 10) * vehicleType) + (passengers * 5) + serviceCharge; // premium fare calculation
        }
        
        friend ostream& operator<<(ostream& out, const Booking& b);
        friend istream& operator>>(istream& in, Booking& b);
        

};


istream& operator>>(istream& in, Booking& b)
{
    char src[100], dest[100];

    cout<<"Enter Booking ID: ";
    in>>b.bid;
    cout<<"Enter Source: ";
    in>>src;
    b.source = new char[strlen(src) + 1];
    strcpy(b.source, src);

    cout<<"Enter Destination: ";
    in>>dest;
    b.destination = new char[strlen(dest) + 1];
    strcpy(b.destination, dest);

    cout<<"Enter Distance: ";
    in>>b.distance;
    cout<<"Enter Fare: ";
    in>>b.fare;
    return in;
}
ostream& operator<<(ostream& out, const Booking& b)
{
    out<<"Booking ID: "<<b.bid<<endl;
    out<<"Source: "<<b.source<<endl;
    out<<"Destination: "<<b.destination<<endl;
    out<<"Distance: "<<b.distance<<endl;
    out<<"Fare: "<<b.fare<<endl;
    return out;
}
int main()
{
    Booking b1;
    cin>>b1;
    b1.displayData();
    cout<<b1;

    return 0;
}
