#include "src/FinnHubAPI.h"
#include <iostream>
int main()
{
    Rivendell::FinnHubAPI api = Rivendell::FinnHubAPI("YOUR_API_KEY");

    Json::Value *APPLStockQuote = api.StockQuote("AAPL");

    std::cout << APPLStockQuote->toStyledString() << std::endl;

    Json::Value *APPLFinancialStatements = api.FinancialStatements("AAPL", "bs", "annual");

    std::cout << APPLFinancialStatements->toStyledString() << std::endl;
}