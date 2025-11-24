#ifndef H_rectangleType // Standard practice to prevent the header file from being included multiple times
#define H_rectangleType
  
#include <iostream> // Needed for using the stream objects (ostream, istream)
using namespace std;

// --- Class Definition: rectangleType ---
class rectangleType
{
        // --- Friend Functions (for Stream I/O) ---
        // These non-member functions need special permission ('friend') to access the private/protected members (length, width).
    friend ostream& operator<<(ostream&, const rectangleType &); // Overloads the output operator (e.g., cout << rectangle)
    friend istream& operator>>(istream&, rectangleType &);      // Overloads the input operator (e.g., cin >> rectangle)

public: // --- PUBLIC INTERFACE: Functions available to users of this class ---
    
    // Setter method: Sets the length and width (usually includes safety checks)
    void setDimension(double l, double w);
    
    // Getter methods: Retrieve the private data. 'const' means they don't change the object.
    double getLength() const;
    double getWidth() const;
    
    // Calculation methods: Compute properties of the rectangle
    double area() const;
    double perimeter() const;

        // --- Overloaded Arithmetic Operators ---
        // These define how rectangles are added, subtracted, and multiplied (usually dimension by dimension).
    rectangleType operator + (const rectangleType &) const;
    rectangleType operator - (const rectangleType &) const;
    rectangleType operator * (const rectangleType&) const;

        // --- Overloaded Increment and Decrement Operators ---
        // These define how the length/width are changed using '++' or '--'.
    rectangleType operator ++ ();          // Pre-increment (e.g., ++rectangle)
    rectangleType operator ++ (int);       // Post-increment (e.g., rectangle++)
    rectangleType operator -- ();          // Pre-decrement (e.g., --rectangle)
    rectangleType operator -- (int);       // Post-decrement (e.g., rectangle--)

      // --- Overloaded Relational Operators ---
      // These define how rectangles are compared (usually based on their area).
    bool operator == (const rectangleType&) const;
    bool operator != (const rectangleType&) const;
    bool operator <= (const rectangleType&) const;
    bool operator < (const rectangleType&) const;
    bool operator >= (const rectangleType&) const;
    bool operator > (const rectangleType&) const;

        // --- Constructors ---
        // Special functions used to create and initialize a rectangle object.
    rectangleType();                      // Default constructor (e.g., length=0, width=0)
    rectangleType(double l, double w);    // Constructor with initial length and width

protected: // --- PROTECTED DATA: Internal state of the rectangle ---
    
    // The variables that store the object's data. They are 'protected,' meaning they can be 
    // accessed by this class and any class that inherits from it.
    double length;
    double width;
};

#endif // Ends the header include guard
