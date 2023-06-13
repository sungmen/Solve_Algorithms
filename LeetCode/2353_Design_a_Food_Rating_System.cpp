class FoodRatings {
public:
    map<string, int> food;
    map<string, map<pair<int, string>, int>> m;
    map<pair<int, string>, string> findM;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++)
        {
            food[foods[i]] = -ratings[i];
            m[cuisines[i]][{-ratings[i], foods[i]}] = 1;
            findM[{-ratings[i], foods[i]}] = cuisines[i];
        }
    }
    
    void changeRating(string food_, int newRating) {
        int c = food[food_];
        food[food_] = -newRating;
        string cuisine = findM[{c, food_}];
        findM.erase({c, food_});
        m[cuisine].erase({c, food_});
        m[cuisine][{-newRating, food_}] = 1;
        findM[{-newRating, food_}] = cuisine;
    }
    
    string highestRated(string cuisine) {
        return m[cuisine].begin()->first.second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */