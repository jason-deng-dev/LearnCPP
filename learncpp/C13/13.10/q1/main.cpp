#include <iostream>

struct RevenueData {
  int adsWatched{};
  int clickRate{};
  double avgEarning{};
};

void printRevenueData(RevenueData& data) {
  std::cout << "Ads watched: " << data.adsWatched << '\n';
  std::cout << "Click rate: " << data.clickRate << "% \n";
  std::cout << "Avg earning: " << data.avgEarning << '\n';
  std::cout << "total earning: "
            << data.adsWatched * (static_cast<double>(data.clickRate)/100) * data.avgEarning << '\n';
}

RevenueData getRevenueData() {
  std::cout << "Enter how many ads were watched: ";
  int adsWatched{};
  std::cin >> adsWatched;
  std::cout << "Enter click rate in % whole number only: ";
  int clickRate{};
  std::cin >> clickRate;
  std::cout << "Enter avg earning per clicked ad: ";
  double avgEarning{};
  std::cin >> avgEarning;
  return {adsWatched, clickRate, avgEarning};
  
}

int main() {

  RevenueData data{getRevenueData()};
  printRevenueData(data);

  return 0;
}
