// Last updated: 11/2/2025, 10:27:05 PM
class FoodRatings {
public:
    
    unordered_map<string, set<pair<int, string>>>cuisinesToRatingFoodMap;
    unordered_map<string,string> foodToCuisineMap;
    unordered_map<string, int> foodToRatingMap;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++){
            foodToCuisineMap[foods[i]] = cuisines[i];
            foodToRatingMap[foods[i]] = ratings[i];
            cuisinesToRatingFoodMap[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        cuisinesToRatingFoodMap[foodToCuisineMap[food]].erase({-foodToRatingMap[food], food});
        foodToRatingMap[food] = newRating;
        cuisinesToRatingFoodMap[foodToCuisineMap[food]].insert({-newRating, food});

    }
    
    string highestRated(string cuisine) {
        return begin(cuisinesToRatingFoodMap[cuisine])->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */