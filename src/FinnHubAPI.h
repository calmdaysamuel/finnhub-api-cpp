#pragma once
#include "RealTimeDataSource.h"

namespace Rivendell
{
	class FinnHubAPI : private RealTimeDataSource
	{
	private:
		std::string apiRoot = "https://finnhub.io/api/v1";
		std::string apiToken = "token=";

	public:
		FinnHubAPI(std::string apiToken);
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

		//WebSocket

		//Helpers
	private:
		void ComposeUrl(std::string &url, std::map<std::string, std::string> params);
	};
}
