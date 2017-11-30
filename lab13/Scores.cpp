/**
 * Name: Jake Billings
 * Date: 11/30/2017
 * Class: CSCI 1411-001
 * Description: Scores class implementation; the scores class holds three scores
 * Status: compiles and runs on VS, Clion, and csegrid
 */

#include "Scores.h"

//Implement constructors

/**
 * Implement an empty constructor
 */
Scores::Scores() {}

/**
 * Implement a full constructor that accepts all scores
 *
 * @param _scoreOne The value to initialize scoreOne
 * @param _scoreTwo The value to initialize scoreTwo
 * @param _scoreThree The value to initialize scoreThree
 */
Scores::Scores(double _scoreOne, double _scoreTwo, double _scoreThree) {
    this->setScoreOne(_scoreOne);
    this->setScoreTwo(_scoreTwo);
    this->setScoreThree(_scoreThree);
}


//Implement meaningful functions
/**
 * The getAverage() function returns the average of the three scores stored in this
 *  Scores class object.
 *
 * @return a double representation of the average of the three scores
 */
double Scores::getAverage() {
    return (this->getScoreOne() + this->getScoreTwo() + this-> getScoreThree()) / 3;
}

//Implement Getters and Setters for each Score
double Scores::getScoreOne() {
    return scoreOne;
}
void Scores::setScoreOne(double scoreOne) {
    Scores::scoreOne = scoreOne;
}
double Scores::getScoreTwo() {
    return scoreTwo;
}
void Scores::setScoreTwo(double scoreTwo) {
    Scores::scoreTwo = scoreTwo;
}
double Scores::getScoreThree() {
    return scoreThree;
}
void Scores::setScoreThree(double scoreThree) {
    Scores::scoreThree = scoreThree;
}

