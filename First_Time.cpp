#include <iostream>
#include <string>

int main()
{
    std::cout << "C++ 环境已就绪！\n";
    std::cout << "请输入你的名字：";

    std::string name;
    std::getline(std::cin, name);

    if (name.empty())
    {
        name = "C++ 学习者";
    }

    std::cout << "你好，" << name << "!\n\n";
    std::cout << "按 Enter 键退出...";
    std::cin.get();

    return 0;
}
