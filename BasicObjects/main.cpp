/*
 * Basic Objects
 */

/* 
 * File:   main.cpp
 * Author: brash
 *
 * Created on October 25, 2021, 12:46 PM
 */

#include <cstdlib>
#include <vector>

#include "Restaurant.h"

Restaurant getFavorite(vector<Restaurant>& myRestaurants);

int main(int argc, char** argv) {
    
    // Define some objects ... the first two call the default constructor, and the last
    // calls the initialization constructor.
    Restaurant schooners;
    Restaurant moes;
    Restaurant mickydees("MacDonald's",-10000);
    
    mickydees.Print();
    cout << endl;
    
    cout << "Initial Definition of Schooner's" << endl;
    schooners.Print();
    cout << endl;
    
    schooners.SetName("Schooner's");
    schooners.SetRating(4);
    moes.SetName("Moe's");
    moes.SetRating(5);
    
    
    // Define a vector of Restaurant objects, and add our three restaurants to it!!!
    vector<Restaurant> myRestaurants;
    
    myRestaurants.push_back(schooners);
    myRestaurants.push_back(moes);
    myRestaurants.push_back(mickydees);
    
    
    // Figure out the restaurant with the highest rating.
    Restaurant myFavorite;
    
    myFavorite = getFavorite(myRestaurants);
    
    cout << "My favorite restaurant: " << endl;
    cout << myFavorite.GetName() << " -- Rating = " << myFavorite.GetRating() << endl;
    
    return 0;
}

Restaurant getFavorite(vector<Restaurant>& myRestaurants) {
    
    Restaurant bestRestaurant;
    
    int maxRatingIndex = 0;
    int maxRating = -1000000;
    
    cout << "Ratings:" << endl;
    for (int i = 0; i<myRestaurants.size(); i++) {
        myRestaurants[i].Print();
        if (myRestaurants[i].GetRating() > maxRating) {
            maxRatingIndex = i;
            maxRating = myRestaurants[i].GetRating();
        }
    }
    cout << endl;
    
    bestRestaurant = myRestaurants[maxRatingIndex]; // copy!!! This is what "=" does by default.
    
    return bestRestaurant;
}

