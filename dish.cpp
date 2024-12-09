#include <iostream>
#include <array>
#include <string>
using namespace std;

class Dish
{
private:
    std::string description;

public:
    Dish() : description("something delicious") {}

    Dish(string description) : description(description) {}

    string get_description() const
    {
        return this->description;
    }
};

class DishStack
{
private:
    static const int MAX_SIZE = 10;
    array<Dish, MAX_SIZE> stack;
    int top;

public:
    DishStack() : top(-1) {}

    void push(const Dish &dish)
    {
        if (top >= MAX_SIZE - 1)
        {
            cout << "Stack is full! Cannot push the dish." << endl;
            return;
        }
        stack[++top] = dish;
        cout << "Pushed dish: " << dish.get_description() << endl;
    }

    // Pop a Dish from the stack
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack is empty! Cannot pop." << std::endl;
            return;
        }
        cout << "Popped dish: " << stack[top].get_description() << endl;
        --top; // Decrease top to remove the dish
    }

    // Peek at the top Dish without removing it
    void peek() const
    {
        if (top == -1)
        {
            cout << "Stack is empty! No dish to peek." << endl;
            return;
        }
        cout << "Top dish: " << stack[top].get_description() << endl;
    }

    int size() const
    {
        return top + 1;
    }
};

int main()
{
    // Example usage
    DishStack dishStack;

    // Create some dishes
    Dish dish1("brioche");
    Dish dish2("ciabatta");
    Dish dish3("baguette");
    Dish dish4("focaccia");
    Dish dish5("soda");
    Dish dish6("challah");
    Dish dish7("cornbread");
    Dish dish8("bagel");
    Dish dish9("rye");
    Dish dish10("banana");
    // addidng an 11th to the stack with a max size of 10
    // to prove it will display a message, and not take the 11th item
    Dish dish11("sour dough");

    dishStack.push(dish1);
    dishStack.push(dish2);
    dishStack.push(dish3);
    dishStack.push(dish4);
    dishStack.push(dish5);
    dishStack.push(dish6);
    dishStack.push(dish7);
    dishStack.push(dish8);
    dishStack.push(dish9);
    dishStack.push(dish10);
    dishStack.push(dish11);

    // do this twice to prove that peek does not change the stack
    dishStack.peek();
    dishStack.peek();

    cout << "Stack size: " << dishStack.size() << endl;

    dishStack.pop();
    // check the stack size after popping to prove it worked
    cout << "Stack size: " << dishStack.size() << endl;

    // peek after the pop to prove it removed the top item and went
    // to the next item down
    dishStack.peek();

    // pop everything off the stack, and then one more to prove the pop method will not work
    // on an emepty stack, and display a message instead
    dishStack.pop();
    dishStack.pop();
    dishStack.pop();
    dishStack.pop();
    dishStack.pop();
    dishStack.pop();
    dishStack.pop();
    dishStack.pop();
    dishStack.pop();
    dishStack.pop();

//testing .size() and peek on an empty stack to prove they display correctly
    cout << "Stack size: " << dishStack.size() << endl;
    dishStack.peek();

    return 0;
}