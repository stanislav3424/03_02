#include <iostream>

class Counter
{
  private:

    int val{1};

  public:

    void add()
    {
        val = ++val;
    }
    void subtract()
    {
        val = --val;
    }
    int GetCounter()
    {
        return val;
    }
    Counter(int val) : val(val)
    {
    }
    Counter() = default;
};

Counter printQuestion()
{
    std::string inputStr{};
    int inputInt{};
    std::cout << "Вы хотите указать начальное значение счётчика? Если да +, или любое значение для работы по умолчанию: ";
    std::cin >> inputStr;
    if (inputStr == "+")
    {
        std::cout << "Введите начальное значение счётчика: ";
        std::cin >> inputInt;
        return Counter(inputInt);
    }
    else
    {
        return Counter();
    }
}

bool select(Counter &local)
{
    std::string inputStr{};
    std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
    std::cin >> inputStr;

    if (inputStr == "+")
    {
        local.add();
    }
    else if (inputStr == "-")
    {
        local.subtract();
    }
    else if (inputStr == "=")
    {
        std::cout << "Текущее значение счётчика: " << local.GetCounter() << std::endl;
    }
    else if (inputStr == "x")
    {
        return false;
    }
    else
    {
        std::cout << "NotValid" << std::endl;
    }

    return true;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    Counter counter_1 = printQuestion();
    while (select(counter_1))
    {
    }
    std::cout << "До свидания!";
    return 0;

}
