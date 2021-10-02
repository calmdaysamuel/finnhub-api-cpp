# finnhub-api-cpp

Considered leaving a star if you find this library useful

Unofficial C++ library for the Finnhub Financial Data API

This library provides an easy to use interface for requesting data from the Finnhub API.

The documentation for the official API can be found here: https://finnhub.io/docs/api, and should be used to as a refernce to understand input parameters.

This library depends on two libraries that need to need manually installed:

Libcurl: https://curl.haxx.se/docs/install.html

```shell
vcpkg install curl
```

Jsoncpp: https://github.com/open-source-parsers/jsoncpp

```shell
vcpkg install jsoncpp
```

Why use this library over the official API:

This library makes it easy to request any piece of data from the Finnhub API
in only two lines of code.

- Step 1: Initialize the API with your Finhubb API token
- Step 2: Use the in built functions to request tHE data you want

###### Example 1: Request Apple(AAPL) stock quote

```c++
int main()
{
	Rivendell::FinnHubAPI api = Rivendell::FinnHubAPI("YOUR_API_TOKEN");

	Json::Value* APPLStockQuote = api.StockQuote("AAPL");

	std::cout << APPLStockQuote->toStyledString() << std::endl;
}
```

###### Output:

```json
// Reference the Official Finnhub documentation to see feild definitions
{
  "c": 142.65000000000001,
  "d": 1.1499999999999999,
  "dp": 0.81269999999999998,
  "h": 142.91999999999999,
  "l": 139.11009999999999,
  "o": 141.90000000000001,
  "pc": 141.5,
  "t": 1633118403
}
```

###### Example 2: Request to premium data without premium subscription

```c++
int main()
{
	Rivendell::FinnHubAPI api = Rivendell::FinnHubAPI("YOUR_API_TOKEN");

	Json::Value* APPLFinancialStatements = api.FinancialStatements("AAPL", "bs", "annual");

	std::cout << APPLFinancialStatements->toStyledString() << std::endl;

}
```

###### Output:

```json
// Reference the Official Finnhub documentation to see feild definitions
{
  "error": "You don't have access to this resource."
}
```

###### Function Signatures

```c++
//Stock Fundamentals
Json::Value *StockSymbolLookup(std::string query);
Json::Value *StockSymbols(std::string exchange, std::string mic = "", std::string securityType = "", std::string currency = "");
Json::Value *CompanyProfile(std::string symbol = "", std::string isin = "", std::string cusip = "");
Json::Value *CompanyProfile2(std::string symbol = "", std::string isin = "", std::string cusip = "");
Json::Value *CompanyExecutive(std::string symbol);
Json::Value *MarketNews(std::string category, std::string minId = "");
Json::Value *CompanyNews(std::string symbol, std::string from, std::string to);
Json::Value *MajorPressReleases(std::string symbol, std::string from = "", std::string to = "");
Json::Value *NewsSentiment(std::string symbol);
Json::Value *Peers(std::string symbol);
Json::Value *BasicFinancials(std::string symbol, std::string metric);
Json::Value *Ownership(std::string symbol, std::string limit = "");
Json::Value *FundOwnership(std::string symbol, std::string limit = "");
Json::Value *InsiderTransactions(std::string symbol, std::string from = "", std::string to = "");
Json::Value *FinancialStatements(std::string symbol, std::string statement, std::string freq);
Json::Value *FinancialsAsReported(std::string symbol = "", std::string cik = "", std::string accessNumber = "", std::string freq = "");
Json::Value *RevenueBreakdown(std::string symbol = "", std::string cik = "");
Json::Value *SecFilings(std::string symbol = "", std::string cik = "", std::string accessNumber = "", std::string from = "", std::string to = "", std::string form = "");
Json::Value *InternationalFilings(std::string symbol = "", std::string country = "");
Json::Value *SecSentimentAnalysis(std::string accessNumber);
Json::Value *SimilarityIndex(std::string symbol = "", std::string cik = "", std::string freq = "annual");
Json::Value *IpoCalender(std::string from, std::string to);
Json::Value *Dividends(std::string symbol, std::string from, std::string to);

//Stock Estimates
Json::Value *StockRecommendationTrends(std::string symbol);
Json::Value *StockPriceTarget(std::string symbol);
Json::Value *StockUpgradeDowngrade(std::string symbol = "", std::string from = "", std::string to = "");
Json::Value *StockRevenueEstimates(std::string symbol, std::string freq = "quarterly");
Json::Value *StockEarningsEstimates(std::string symbol, std::string freq = "quarterly");
Json::Value *StockEarningsSuprises(std::string symbol, std::string limit = "");
Json::Value *StockEarningsCalendar(std::string symbol = "", std::string from = "", std::string to = "", std::string international = "false");

//Stock Price
Json::Value *StockQuote(std::string symbol);
Json::Value *StockCandles(std::string symbol, std::string resolution, std::string from, std::string to);
Json::Value *StockTickData(std::string symbol, std::string date, std::string limit, std::string skip);
Json::Value *StockHistoricalNBBO(std::string symbol, std::string date, std::string limit, std::string skip);
Json::Value *StockLastAskBid(std::string symbol);
Json::Value *StockSplits(std::string symbol, std::string from, std::string to);
Json::Value *StockDividends_2(std::string symbol);

//ETF & Indices
Json::Value *IndicesConstituents(std::string symbol);
Json::Value *IndicesHistoricalConstituents(std::string symbol);
Json::Value *EtfProfile(std::string symbol = "", std::string isin = "");
Json::Value *EtfHoldings(std::string symbol = "", std::string isin = "", std::string skip = "");
Json::Value *EtfSector(std::string symbol);
Json::Value *EtfCountry(std::string symbol);

//Mutual Funds
Json::Value *MutualFundsProfile(std::string symbol = "", std::string isin = "");
Json::Value *MutualFundsHoldings(std::string symbol = "", std::string isin = "", std::string skip = "");
Json::Value *MutualFundsSector(std::string symbol);
Json::Value *MutualFundsCountry(std::string symbol);

//Forex
Json::Value *ForexExchanges();
Json::Value *ForexSymbol(std::string exchange);
Json::Value *ForexCandles(std::string symbol, std::string resolution, std::string from, std::string to);
Json::Value *ForexRates(std::string base = "EUR");

//Crypto
Json::Value *CryptoExchanges();
Json::Value *CryptoSymbols(std::string exchange);
Json::Value *CryptoCandles(std::string symbol, std::string resolution, std::string from, std::string to);

//Technical Analysis
Json::Value *PatternRecognition(std::string symbol, std::string resolution);
Json::Value *Support_Resistance_Level(std::string symbol, std::string resolution);
Json::Value *AggregateIndicators(std::string symbol, std::string resolution);
Json::Value *TechnicalIndicators(std::string symbol, std::string resolution, std::string from, std::string to, std::string indicator, std::string indicator_fields = ""); //TODO: fix indicator fields

//Alternative Data
Json::Value *TranscriptsList(std::string symbol);
Json::Value *Transcripts(std::string id);
Json::Value *SocialSentiment(std::string symbol, std::string from = "", std::string to = "");
Json::Value *InvestmentThemes(std::string theme);
Json::Value *SupplyChain(std::string symbol);
Json::Value *CompanyESG(std::string symbol);
Json::Value *EarningsQualityScore(std::string symbol, std::string freq);
Json::Value *COVID_19();
Json::Value *FdaCalendar();

//Economic
Json::Value *CountryList();
Json::Value *EconomicCalendar();
Json::Value *EconomicCodes();
Json::Value *EconomicData(std::string code);
```

#### Completed:

##### Stock Fundamentals

- Symbol Lookup: https://finnhub.io/docs/api/symbol-search
- Stock Symbols: https://finnhub.io/docs/api/stock-symbols
- Company Profile: https://finnhub.io/docs/api/stock-symbols
- Company Profile 2: https://finnhub.io/docs/api/stock-symbols
- Company Executive: https://finnhub.io/docs/api/stock-symbols
- Market News: https://finnhub.io/docs/api/market-news
- Company News: https://finnhub.io/docs/api/market-news
- Press Releases: https://finnhub.io/docs/api/market-news
- News Sentiment: https://finnhub.io/docs/api/news-sentiment
- Peers: https://finnhub.io/docs/api/company-peers
- Basic Financials: https://finnhub.io/docs/api/company-basic-financials
- Ownership: https://finnhub.io/docs/api/ownership
- Fund Ownership: https://finnhub.io/docs/api/fund-ownership
- Insider Transactions: https://finnhub.io/docs/api/insider-transactions
- Financials: https://finnhub.io/docs/api/financials
- Financials As Reported: https://finnhub.io/docs/api/financials-reported
- Revenue Breakdown: https://finnhub.io/docs/api/revenue-breakdown
- SEC Filings: https://finnhub.io/docs/api/filings
- International Filings: https://finnhub.io/docs/api/international-filings
- SEC Sentiment Analysis: https://finnhub.io/docs/api/filings-sentiment
- Similarity Index: https://finnhub.io/docs/api/similarity-index
- IPO Calendat: https://finnhub.io/docs/api/ipo-calendar
- Dividends: https://finnhub.io/docs/api/stock-dividends

##### Stock Estimates

- Recommedation Trends: https://finnhub.io/docs/api/recommendation-trends
- Price Target: https://finnhub.io/docs/api/price-target
- Upgrade Downgrade: https://finnhub.io/docs/api/upgrade-downgrade
- Revenue Estimates: https://finnhub.io/docs/api/company-revenue-estimates
- EPS Estimates: https://finnhub.io/docs/api/company-eps-estimates
- EPS Surprises: https://finnhub.io/docs/api/company-earnings
- Earnings Calendar: https://finnhub.io/docs/api/earnings-calendar

##### ETFS & indices

- Indices Constituents: https://finnhub.io/docs/api/indices-constituents
- Historical Constituents: https://finnhub.io/docs/api/indices-historical-constituents
- ETFs Profile: https://finnhub.io/docs/api/etfs-profile
- ETFs Holdings: https://finnhub.io/docs/api/etfs-holdings
- ETFs Sector: https://finnhub.io/docs/api/etfs-sector-exposure
- ETFs Country: https://finnhub.io/docs/api/etfs-country-exposure

##### Mutual Funds:

- Mutual Funds Profile: https://finnhub.io/docs/api/mutual-fund-profile
- Mutual Funds Holdings: https://finnhub.io/docs/api/mutual-fund-holdings
- Mutual Funds Sector: https://finnhub.io/docs/api/mutual-fund-sector-exposure
- Mutual Funds Country: https://finnhub.io/docs/api/mutual-fund-country-exposure

##### Forex

- Exchanges: https://finnhub.io/docs/api/forex-exchanges
- Symbols: https://finnhub.io/docs/api/forex-symbols
- Candles: https://finnhub.io/docs/api/forex-candles
- All Rates: https://finnhub.io/docs/api/forex-rates

##### Crypto

- Exchanges: https://finnhub.io/docs/api/crypto-exchanges
- Symbols: https://finnhub.io/docs/api/crypto-symbols
- CandlesHigh Usage: https://finnhub.io/docs/api/crypto-candles

##### Technical Analysis

- Pattern Recognition: https://finnhub.io/docs/api/pattern-recognition
- Support/Resistance: https://finnhub.io/docs/api/support-resistance
- Aggregate Indicators: https://finnhub.io/docs/api/aggregate-indicator
- Technical Indicators: https://finnhub.io/docs/api/technical-indicator

##### Alternative Data

- Transcripts List: https://finnhub.io/docs/api/transcripts-list
- Transcripts: https://finnhub.io/docs/api/earnings-call-transcripts-api
- Social Sentiment: https://finnhub.io/docs/api/social-sentiment
- Investment Themes: https://finnhub.io/docs/api/investment-themes-thematic-investing
- Supply Chain: https://finnhub.io/docs/api/supply-chain-relationships
- Company ESG: https://finnhub.io/docs/api/company-esg-score-api
- Earnings Quality Score: https://finnhub.io/docs/api/company-earnings-quality-score-api
- COVID-19: https://finnhub.io/docs/api/covid-19
- FDA Calendar: https://finnhub.io/docs/api/fda-committee-meeting-calendar

##### Economic

- Country List: https://finnhub.io/docs/api/country
- Economic Calendar: https://finnhub.io/docs/api/economic-calendar
- Economic Codes: https://finnhub.io/docs/api/economic-code
- Economic: https://finnhub.io/docs/api/economic-data

##### TO DO:

- Trades Websocket client: https://finnhub.io/docs/api/websocket-trades
- News Websocket client: https://finnhub.io/docs/api/websocket-news
- Generate Doxygen Documentation
- CSV Support
