#include <iostream>
#include <random>

int main() 
{   
    int start = 1;
    while (true)
    {
        if (start == 0)
        {
            std::cout << "End";
            return 0;
        }

        {
            std::mt19937 generator(std::random_device{}());

            int fAnswer, twAnswer, thAnswer, choice, gen;
            std::cout << "Welcome\n\n choice diff \n\n easy(1-50) - 1 \n medium(1-100) - 2 \n hard(0-500) - 3 \n exit - 0\n";
            if (!(std::cin >> choice))
            {
                std::cout << "wrong";
                break;
            }
            switch (choice)
            {
            case 1:
            {
                std::uniform_int_distribution<int> f(1, 50);
                gen = f(generator);
                std::cout << "guess the number: \n\n";
                while (true)
                {
                    if (!(std::cin >> fAnswer))
                    {
                        std::cout << "wrong ";
                        break;
                    }
                    else if (fAnswer == gen)
                    {
                        std::cout << "yeap ";
                        start = 0;
                        break;
                    }
                    else if (fAnswer > gen)
                    {
                        std::cout << "too big\n";
                    }
                    else
                    {
                        std::cout << "too small\n";
                    }
                    std::cout << gen << " answer\n";
                }
                break;
            }
            case 2:
            {
                std::uniform_int_distribution<int> f(1, 100);
                gen = f(generator);
                std::cout << "guess the number: \n\n";
                while (true)
                {
                    if (!(std::cin >> twAnswer))
                    {
                        std::cout << "wrong ";
                        break;
                    }
                    else if (twAnswer == gen)
                    {
                        std::cout << "yeap ";
                        start = 0;
                        break;
                    }
                    else if (twAnswer > gen)
                    {
                        std::cout << "too big\n";
                    }
                    else
                    {
                        std::cout << "too small\n";
                    }
                    std::cout << gen << " answer\n";
                }
                break;
            }
            case 3:
            {
                std::uniform_int_distribution<int> f(1, 500);
                gen = f(generator);
                std::cout << "guess the number: \n\n";
                while (true)
                {
                    if (!(std::cin >> thAnswer))
                    {
                        std::cout << "wrong ";
                        break;
                    }
                    else if (thAnswer == gen)
                    {
                        std::cout << "yeap ";
                        start = 0;
                        break;
                    }
                    else if (thAnswer > gen)
                    {
                        std::cout << "too big\n";
                    }
                    else
                    {
                        std::cout << "too small\n";
                    }
                    //std::cout << gen << " answer\n";
                }
                break;
            }
            case 0:
                start = 0;
                break;
            }
            }
        }
    }
    