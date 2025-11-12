class counterType
{
public:  // --- PUBLIC INTERFACE: These are the actions the user can perform on a counter object. ---

    void initializeCounter();
      // Function to initialize the counter to 0.

    void setCounter(int x = 0);
      // Function to set the counter to a new value 'x'.
      // Note: If 'x' is negative, the counter is reset to 0, ensuring non-negative values.

    void incrementCounter();
      // Function to increase the counter's value by 1.

    void decrementCounter();
      // Function to decrease the counter's value by 1. 
      // Note: It includes a rule to prevent the counter from going below zero.

    int getCounter() const;
      // Accessor (Getter) function: Returns the current value of the private 'counter'.
      // 'const' means this function does not change the counter's value.

    void print() const;
      // Function to display the value of the counter.
      // 'const' means this function does not change the counter's value.

    counterType(int x = 0);
      // Constructor: This is the special function used when creating a new counter object.
      // It allows you to set an initial value (like 5) or defaults to 0 if no value is given.

private: // --- PRIVATE DATA: This is the internal state of the counter object. ---
    
    // The actual variable that stores the count. It can only be accessed or changed
    // through the public functions defined above, ensuring data integrity.
    int counter; 
};
