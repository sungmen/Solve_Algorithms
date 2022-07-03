class UndergroundSystem {
public:
    map<pair<string,string>, pair<double, double>> re;
    map<int, pair<string, int>> li;
    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        li[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        if (re.find({li.find(id)->second.first, stationName}) != re.end()) {
                re[{li.find(id)->second.first, stationName}] = {(re.find({li.find(id)->second.first, stationName})->second.first + ((t - li.find(id)->second.second))), re.find({li.find(id)->second.first, stationName})->second.second+1.0};
            } else {
                re[{li.find(id)->second.first, stationName}] = {((t - li.find(id)->second.second)),1.0};
            }
        
    }
    
    double getAverageTime(string startStation, string endStation) {
        return re.find({startStation, endStation})->second.first/re.find({startStation, endStation})->second.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */