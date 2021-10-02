#include "FinnHubAPI.h"

namespace Rivendell
{
	FinnHubAPI::FinnHubAPI(std::string apiToken)
	{
		this->apiToken += apiToken;
	}
	Json::Value *FinnHubAPI::StockSymbolLookup(std::string query)
	{
		std::string url = apiRoot + "/search?" + apiToken;
		ComposeUrl(url, {{"q", query}});
		return GetRequest(url);
	}
	Json::Value *FinnHubAPI::StockSymbols(std::string exchange, std::string mic, std::string securityType, std::string currency)
	{
		std::string url = apiRoot + "/stock/symbol?" + apiToken;
		ComposeUrl(url, {{"exchange", exchange}, {"mic", mic}, {"securityType", securityType}, {"currency", currency}});
		return GetRequest(url);
	}
	Json::Value *FinnHubAPI::CompanyProfile(std::string symbol, std::string isin, std::string cusip)
	{
		std::string url = apiRoot + "/stock/profile?" + apiToken;
		ComposeUrl(url, {{"symbol", symbol}, {"isin", isin}, {"cusip", cusip}});
		return GetRequest(url);
	}
	Json::Value *FinnHubAPI::CompanyProfile2(std::string symbol, std::string isin, std::string cusip)
	{
		std::string url = apiRoot + "/stock/profile2?" + apiToken;
		ComposeUrl(url, {{"symbol", symbol}, {"isin", isin}, {"cusip", cusip}});
		return GetRequest(url);
	}
	Json::Value *FinnHubAPI::CompanyExecutive(std::string symbol)
	{
		std::string url = apiRoot + "/stock/executive?" + apiToken;
		ComposeUrl(url, {{"symbol", symbol}});
		return GetRequest(url);
	}
	Json::Value *FinnHubAPI::MarketNews(std::string category, std::string minId)
	{
		std::string url = apiRoot + "/news?" + apiToken;
		ComposeUrl(url, {{"category", category}, {"minId", minId}});
		return GetRequest(url);
	}
	Json::Value *FinnHubAPI::CompanyNews(std::string symbol, std::string from, std::string to)
	{
		std::string url = apiRoot + "/company-news?" + apiToken;
		ComposeUrl(url, {{"symbol", symbol}, {"from", from}, {"to", to}});
		return GetRequest(url);
	}
	Json::Value *FinnHubAPI::MajorPressReleases(std::string symbol, std::string from, std::string to)
	{
		std::string url = apiRoot + "/press-releases?" + apiToken;
		ComposeUrl(url, {{"symbol", symbol}, {"from", from}, {"to", to}});
		return GetRequest(url);
	}
	Json::Value *FinnHubAPI::NewsSentiment(std::string symbol)
	{
		std::string url = apiRoot + "/news-sentiment?" + apiToken;
		ComposeUrl(url, {{"symbol", symbol}});
		return GetRequest(url);
	}
	Json::Value *FinnHubAPI::Peers(std::string symbol)
	{
		std::string url = apiRoot + "/stock/peers?" + apiToken;
		ComposeUrl(url, {{"symbol", symbol}});
		return GetRequest(url);
	}
	Json::Value *FinnHubAPI::BasicFinancials(std::string symbol, std::string metric)
	{
		std::string url = apiRoot + "/stock/metric?" + apiToken;
		ComposeUrl(url, {{"symbol", symbol}, {"metric", metric}});
		return GetRequest(url);
	}
	Json::Value *FinnHubAPI::Ownership(std::string symbol, std::string limit)
	{
		std::string url = apiRoot + "/stock/ownership?" + apiToken;
		ComposeUrl(url, {{"symbol", symbol}, {"limit", limit}});
		return GetRequest(url);
	}
	Json::Value *FinnHubAPI::FundOwnership(std::string symbol, std::string limit)
	{
		std::string url = apiRoot + "/stock/fund-ownership?" + apiToken;
		ComposeUrl(url, {{"symbol", symbol}, {"limit", limit}});
		return GetRequest(url);
	}
	Json::Value *FinnHubAPI::InsiderTransactions(std::string symbol, std::string from, std::string to)
	{
		std::string url = apiRoot + "/stock/insider-transactions?" + apiToken;
		ComposeUrl(url, {{"symbol", symbol}, {"from", from}, {"to", to}});
		return GetRequest(url);
	}
	Json::Value *FinnHubAPI::FinancialStatements(std::string symbol, std::string statement, std::string freq)
	{
		std::string url = apiRoot + "/stock/financials?" + apiToken;
		ComposeUrl(url, {{"symbol", symbol}, {"statement", statement}, {"freq", freq}});
		return GetRequest(url);
	}
	Json::Value *FinnHubAPI::FinancialsAsReported(std::string symbol, std::string cik, std::string accessNumber, std::string freq)
	{
		std::string url = apiRoot + "/stock/financials-reported?" + apiToken;
		ComposeUrl(url, {{"symbol", symbol}, {"cik", cik}, {"accessNumber", accessNumber}, {"freq", freq}});
		return GetRequest(url);
	}
	Json::Value *FinnHubAPI::RevenueBreakdown(std::string symbol, std::string cik)
	{
		std::string url = apiRoot + "/stock/revenue-breakdown?" + apiToken;
		ComposeUrl(url, {
							{"symbol", symbol},
							{"cik", cik},
						});
		return GetRequest(url);
	}
	Json::Value *FinnHubAPI::SecFilings(std::string symbol, std::string cik, std::string accessNumber, std::string from, std::string to, std::string form)
	{
		std::string url = apiRoot + "/stock/filings?" + apiToken;
		ComposeUrl(url, {{"symbol", symbol}, {"cik", cik}, {"accessNumber", accessNumber}, {"from", from}, {"to", to}, {"form", form}});
		return GetRequest(url);
	}
	Json::Value *FinnHubAPI::InternationalFilings(std::string symbol, std::string country)
	{
		std::string url = apiRoot + "/stock/international-filings?" + apiToken;
		ComposeUrl(url, {
							{"symbol", symbol},
							{"country", country},
						});
		return GetRequest(url);
	}
	Json::Value *FinnHubAPI::SecSentimentAnalysis(std::string accessNumber)
	{
		std::string url = apiRoot + "/stock/filings-sentiment?" + apiToken;
		ComposeUrl(url, {{"accessNumber", accessNumber}});
		return GetRequest(url);
	}
	Json::Value *FinnHubAPI::SimilarityIndex(std::string symbol, std::string cik, std::string freq)
	{
		std::string url = apiRoot + "/stock/similarity-index?" + apiToken;
		ComposeUrl(url, {{"symbol", symbol}, {"cik", cik}, {"freq", freq}});
		return GetRequest(url);
	}
	Json::Value *FinnHubAPI::IpoCalender(std::string from, std::string to)
	{
		std::string url = apiRoot + "/calendar/ipo?" + apiToken;
		ComposeUrl(url, {{"from", from}, {"to", to}});
		return GetRequest(url);
	}
	Json::Value *FinnHubAPI::Dividends(std::string symbol, std::string from, std::string to)
	{
		std::string url = apiRoot + "/stock/dividend?" + apiToken;
		ComposeUrl(url, {{"symbol", symbol}, {"from", from}, {"to", to}});
		return GetRequest(url);
	}
	Json::Value *FinnHubAPI::StockRecommendationTrends(std::string symbol)
	{
		std::string url = apiRoot + "/stock/recommendation?" + apiToken;
		ComposeUrl(url, {{"symbol", symbol}});
		return GetRequest(url);
	}
	Json::Value *FinnHubAPI::StockPriceTarget(std::string symbol)
	{
		std::string url = apiRoot + "/stock/price-target?" + apiToken;
		ComposeUrl(url, {{"symbol", symbol}});
		return GetRequest(url);
	}
	Json::Value *FinnHubAPI::StockUpgradeDowngrade(std::string symbol, std::string from, std::string to)
	{
		std::string url = apiRoot + "/stock/upgrade-downgrade?" + apiToken;
		ComposeUrl(url, {{"symbol", symbol}, {"from", from}, {"to", to}});
		return GetRequest(url);
	}
	Json::Value *FinnHubAPI::StockRevenueEstimates(std::string symbol, std::string freq)
	{
		std::string url = apiRoot + "/stock/revenue-estimate?" + apiToken;
		ComposeUrl(url, {{"symbol", symbol}, {"freq", freq}});
		return GetRequest(url);
	}
	Json::Value *FinnHubAPI::StockEarningsEstimates(std::string symbol, std::string freq)
	{
		std::string url = apiRoot + "/stock/eps-estimate?" + apiToken;
		ComposeUrl(url, {{"symbol", symbol}, {"freq", freq}});
		return GetRequest(url);
	}
	Json::Value *FinnHubAPI::StockEarningsSuprises(std::string symbol, std::string limit)
	{
		std::string url = apiRoot + "/stock/earnings?" + apiToken;
		ComposeUrl(url, {{"symbol", symbol}, {"limit", limit}});
		return GetRequest(url);
	}
	Json::Value *FinnHubAPI::StockEarningsCalendar(std::string symbol, std::string from, std::string to, std::string international)
	{
		std::string url = apiRoot + "/calendar/earnings?" + apiToken;
		ComposeUrl(url, {{"symbol", symbol}, {"from", from}, {"to", to}, {"international", international}});
		return GetRequest(url);
	}
	Json::Value *FinnHubAPI::StockQuote(std::string symbol)
	{
		std::string url = apiRoot + "/quote?" + apiToken;
		ComposeUrl(url, {{"symbol", symbol}});
		return GetRequest(url);
	}
	Json::Value *FinnHubAPI::StockCandles(std::string symbol, std::string resolution, std::string from, std::string to)
	{
		std::string url = apiRoot + "/stock/candle?" + apiToken;
		ComposeUrl(url, {{"symbol", symbol}, {"resolution", resolution}, {"from", from}, {"to", to}});
		return GetRequest(url);
	}
	Json::Value *FinnHubAPI::StockTickData(std::string symbol, std::string date, std::string limit, std::string skip)
	{
		std::string url = apiRoot + "/stock/tick?" + apiToken;
		ComposeUrl(url, {{"symbol", symbol}, {"date", date}, {"limit", limit}, {"skip", skip}});
		return GetRequest(url);
	}

	Json::Value *FinnHubAPI::StockHistoricalNBBO(std::string symbol, std::string date, std::string limit, std::string skip)
	{
		std::string url = apiRoot + "/stock/bbo?" + apiToken;
		ComposeUrl(url, {{"symbol", symbol}, {"date", date}, {"limit", limit}, {"skip", skip}});
		return GetRequest(url);
	}

	Json::Value *FinnHubAPI::StockLastAskBid(std::string symbol)
	{
		std::string url = apiRoot + "/stock/bidask?" + apiToken;
		ComposeUrl(url, {{"symbol", symbol}});
		return GetRequest(url);
	}

	Json::Value *FinnHubAPI::StockSplits(std::string symbol, std::string from, std::string to)
	{
		std::string url = apiRoot + "/stock/split?" + apiToken;
		ComposeUrl(url, {{"symbol", symbol}, {"from", from}, {"to", to}});
		return GetRequest(url);
	}

	Json::Value *FinnHubAPI::StockDividends_2(std::string symbol)
	{
		std::string url = apiRoot + "/stock/dividend2?" + apiToken;
		ComposeUrl(url, {{"symbol", symbol}});
		return GetRequest(url);
	}

	Json::Value *FinnHubAPI::IndicesConstituents(std::string symbol)
	{
		std::string url = apiRoot + "/index/constituents?" + apiToken;
		ComposeUrl(url, {{"symbol", symbol}});
		return GetRequest(url);
	}

	Json::Value *FinnHubAPI::IndicesHistoricalConstituents(std::string symbol)
	{
		std::string url = apiRoot + "/index/historical-constituents?" + apiToken;
		ComposeUrl(url, {{"symbol", symbol}});
		return GetRequest(url);
	}

	Json::Value *FinnHubAPI::EtfProfile(std::string symbol, std::string isin)
	{
		std::string url = apiRoot + "/etf/profile?" + apiToken;
		ComposeUrl(url, {{"symbol", symbol}, {"isin", isin}});
		return GetRequest(url);
	}

	Json::Value *FinnHubAPI::EtfHoldings(std::string symbol, std::string isin, std::string skip)
	{
		std::string url = apiRoot + "/etf/holdings?" + apiToken;
		ComposeUrl(url, {{"symbol", symbol}, {"isin", isin}, {"skip", skip}});
		return GetRequest(url);
	}

	Json::Value *FinnHubAPI::EtfSector(std::string symbol)
	{
		std::string url = apiRoot + "/etf/sector?" + apiToken;
		ComposeUrl(url, {{"symbol", symbol}});
		return GetRequest(url);
	}

	Json::Value *FinnHubAPI::EtfCountry(std::string symbol)
	{
		std::string url = apiRoot + "/etf/country?" + apiToken;
		ComposeUrl(url, {{"symbol", symbol}});
		return GetRequest(url);
	}

	Json::Value *FinnHubAPI::MutualFundsProfile(std::string symbol, std::string isin)
	{
		std::string url = apiRoot + "/mutual-fund/profile?" + apiToken;
		ComposeUrl(url, {{"symbol", symbol}, {"isin", isin}});
		return GetRequest(url);
	}

	Json::Value *FinnHubAPI::MutualFundsHoldings(std::string symbol, std::string isin, std::string skip)
	{
		std::string url = apiRoot + "/mutual-fund/holdings?" + apiToken;
		ComposeUrl(url, {{"symbol", symbol}, {"isin", isin}, {"skip", skip}});
		return GetRequest(url);
	}

	Json::Value *FinnHubAPI::MutualFundsSector(std::string symbol)
	{
		std::string url = apiRoot + "/mutual-fund/sector?" + apiToken;
		ComposeUrl(url, {{"symbol", symbol}});
		return GetRequest(url);
	}

	Json::Value *FinnHubAPI::MutualFundsCountry(std::string symbol)
	{
		std::string url = apiRoot + "/mutual-fund/country?" + apiToken;
		ComposeUrl(url, {{"symbol", symbol}});
		return GetRequest(url);
	}

	Json::Value *FinnHubAPI::ForexExchanges()
	{
		std::string url = apiRoot + "/forex/exchange?" + apiToken;
		return GetRequest(url);
	}

	Json::Value *FinnHubAPI::ForexSymbol(std::string exchange)
	{
		std::string url = apiRoot + "/forex/symbol?" + apiToken;
		ComposeUrl(url, {{"exchange", exchange}});
		return GetRequest(url);
	}

	Json::Value *FinnHubAPI::ForexCandles(std::string symbol, std::string resolution, std::string from, std::string to)
	{
		std::string url = apiRoot + "/forex/candle?" + apiToken;
		ComposeUrl(url, {{"symbol", symbol}, {"resolution", resolution}, {"from", from}, {"to", to}});
		return GetRequest(url);
	}

	Json::Value *FinnHubAPI::ForexRates(std::string base)
	{
		std::string url = apiRoot + "/forex/rates?" + apiToken;
		ComposeUrl(url, {{"base", base}});
		return GetRequest(url);
	}

	Json::Value *FinnHubAPI::CryptoExchanges()
	{
		std::string url = apiRoot + "/crypto/exchange?" + apiToken;
		return GetRequest(url);
	}

	Json::Value *FinnHubAPI::CryptoSymbols(std::string exchange)
	{
		std::string url = apiRoot + "/crypto/symbol?" + apiToken;
		ComposeUrl(url, {{"exchange", exchange}});
		return GetRequest(url);
	}

	Json::Value *FinnHubAPI::CryptoCandles(std::string symbol, std::string resolution, std::string from, std::string to)
	{
		std::string url = apiRoot + "/crypto/candle?" + apiToken;
		ComposeUrl(url, {{"symbol", symbol}, {"resolution", resolution}, {"from", from}, {"to", to}});
		return GetRequest(url);
	}

	Json::Value *FinnHubAPI::PatternRecognition(std::string symbol, std::string resolution)
	{
		std::string url = apiRoot + "/scan/pattern?" + apiToken;
		ComposeUrl(url, {{"symbol", symbol}, {"resolution", resolution}});
		return GetRequest(url);
	}

	Json::Value *FinnHubAPI::Support_Resistance_Level(std::string symbol, std::string resolution)
	{
		std::string url = apiRoot + "/scan/support-resistance?" + apiToken;
		ComposeUrl(url, {{"symbol", symbol}, {"resolution", resolution}});
		return GetRequest(url);
	}
	Json::Value *FinnHubAPI::AggregateIndicators(std::string symbol, std::string resolution)
	{
		std::string url = apiRoot + "/scan/technical-indicator?" + apiToken;
		ComposeUrl(url, {{"symbol", symbol}, {"resolution", resolution}});
		return GetRequest(url);
	}
	Json::Value *FinnHubAPI::TechnicalIndicators(std::string symbol, std::string resolution, std::string from, std::string to, std::string indicator, std::string indicator_fields)
	{
		std::string url = apiRoot + "/indicator?" + apiToken;
		ComposeUrl(url, {{"symbol", symbol}, {"resolution", resolution}, {"from", from}, {"to", to}, {"indicator", indicator}, {"indicator_fields", indicator_fields}});
		return GetRequest(url);
	}

	Json::Value *FinnHubAPI::TranscriptsList(std::string symbol)
	{
		std::string url = apiRoot + "/stock/transcripts/list?" + apiToken;
		ComposeUrl(url, {{"symbol", symbol}});
		return GetRequest(url);
	}

	Json::Value *FinnHubAPI::Transcripts(std::string id)
	{
		std::string url = apiRoot + "/stock/transcripts?" + apiToken;
		ComposeUrl(url, {
							{"id", id},
						});
		return GetRequest(url);
	}

	Json::Value *FinnHubAPI::SocialSentiment(std::string symbol, std::string from, std::string to)
	{
		std::string url = apiRoot + "/stock/social-sentiment?" + apiToken;
		ComposeUrl(url, {{"symbol", symbol}, {"from", from}, {"to", to}});
		return GetRequest(url);
	}
	Json::Value *FinnHubAPI::InvestmentThemes(std::string theme)
	{
		std::string url = apiRoot + "/stock/investment-theme?" + apiToken;
		ComposeUrl(url, {{"theme", theme}});
		return GetRequest(url);
	}

	Json::Value *FinnHubAPI::SupplyChain(std::string symbol)
	{
		std::string url = apiRoot + "/stock/supply-chain?" + apiToken;
		ComposeUrl(url, {{"symbol", symbol}});
		return GetRequest(url);
	}

	Json::Value *FinnHubAPI::CompanyESG(std::string symbol)
	{
		std::string url = apiRoot + "/stock/esg?" + apiToken;
		ComposeUrl(url, {{"symbol", symbol}});
		return GetRequest(url);
	}

	Json::Value *FinnHubAPI::EarningsQualityScore(std::string symbol, std::string freq)
	{
		std::string url = apiRoot + "/stock/earnings-quality-score?" + apiToken;
		ComposeUrl(url, {{"symbol", symbol}, {"freq", freq}});
		return GetRequest(url);
	}

	Json::Value *FinnHubAPI::COVID_19()
	{
		std::string url = apiRoot + "/covid19/us?" + apiToken;
		return GetRequest(url);
	}

	Json::Value *FinnHubAPI::FdaCalendar()
	{
		std::string url = apiRoot + "/fda-advisory-committee-calendar?" + apiToken;
		return GetRequest(url);
	}

	Json::Value *FinnHubAPI::CountryList()
	{
		std::string url = apiRoot + "/country?" + apiToken;
		return GetRequest(url);
	}

	Json::Value *FinnHubAPI::EconomicCalendar()
	{
		std::string url = apiRoot + "/calendar/economic?" + apiToken;
		return GetRequest(url);
	}

	Json::Value *FinnHubAPI::EconomicCodes()
	{
		std::string url = apiRoot + "/economic/code?" + apiToken;
		return GetRequest(url);
	}

	Json::Value *FinnHubAPI::EconomicData(std::string code)
	{
		std::string url = apiRoot + "/economic?" + apiToken;
		ComposeUrl(url, {{"code", code}});
		return GetRequest(url);
	}

	void FinnHubAPI::ComposeUrl(std::string &url, std::map<std::string, std::string> params)
	{

		for (auto [key, value] : params)
		{
			if (value != "")
			{
				url += "&" + key + "=" + value;
			}
		}
	}

}