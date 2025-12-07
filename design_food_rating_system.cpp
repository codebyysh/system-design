#include <iostream>
#include <unordered_set>
using namespace std;

class FoodRatings {
public:
    unordered_map<string , int> food_rating; 
    unordered_map<string , unordered_set<pair<int , string>>> cuisine_rating_food; 
    unordered_map<string , string> food_cuisine; 

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size(); 
        for (int i = 0; i < n; i++) {
            string food    = foods[i]; 
            string cuisine = cuisines[i]; 
            int rating     = ratings[i]; 

            cuisine_rating_food[cuisine].insert({-rating , food}); 
            food_cuisine[food] = cuisine; 
            food_rating[food] = rating; 
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = food_cuisine[food]; 
        int old_rating = food_rating[food]; 

        food_rating[food] = newRating; 

        cuisine_rating_food[cuisine].erase({-old_rating , food}); 
        cuisine_rating_food[cuisine].insert({-newRating, food}); 
    }
    
    string highestRated(string cuisine) {
        return begin(cuisine_rating_food[cuisine])->second; 
    }
};

int main() {
    vector<string> foods    = {"kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"};
    vector<string> cuisines = {"korean", "japanese", "japanese", "greek", "japanese", "korean"};
    vector<int> ratings     = {9, 12, 8, 15, 14, 7};

    FoodRatings foodRatings(foods, cuisines, ratings);

    cout << foodRatings.highestRated("korean")   << endl; // kimchi
    cout << foodRatings.highestRated("japanese") << endl; // ramen

    foodRatings.changeRating("sushi", 16);
    cout << foodRatings.highestRated("japanese") << endl; // sushi

    foodRatings.changeRating("ramen", 16);
    cout << foodRatings.highestRated("japanese") << endl; // ramen (lexicographically smaller than sushi)

    return 0;
}