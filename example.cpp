#include "src/FinnHubAPI.h"
#include <iostream>
int main()
{
    Rivendell::FinnHubAPI api = Rivendell::FinnHubAPI("c0g8rn748v6ob1prm39g"); // { "c0g8rn748v6ob1prm39g" };

    Json::Value *APPLStockQuote = api.StockQuote("AAPL");

    std::cout << APPLStockQuote->toStyledString() << std::endl;
}